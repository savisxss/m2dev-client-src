#include <cstdint>
#include <map>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <zstd.h>
#include <argparse.hpp>

#include <gcm.h>
#include <modes.h>
#include <osrng.h>
#include <secblock.h>
#include <camellia.h>

constexpr std::array<uint8_t, 32> PACK_KEY = {
	0x00,0x11,0x22,0x33, 0x44,0x55,0x66,0x77,
	0x88,0x99,0xAA,0xBB, 0xCC,0xDD,0xEE,0xFF,
	0x01,0x23,0x45,0x67, 0x89,0xAB,0xCD,0xEF,
	0xFE,0xDC,0xBA,0x98, 0x76,0x54,0x32,0x10
};

#pragma pack(push, 1)
struct TPackFileHeader
{
	uint64_t	entry_num;
	uint64_t	data_begin;
	uint8_t     iv[CryptoPP::Camellia::BLOCKSIZE];
};
struct TPackFileEntry
{
	char		file_name[FILENAME_MAX];
	uint64_t	offset;
	uint64_t	file_size;
	uint64_t	compressed_size;
	uint8_t		encryption;
};
#pragma pack(pop)

int main(int argc, char* argv[])
{
	argparse::ArgumentParser program("PackMaker");

	program.add_argument("--input")
		.required()
		.help("Input folder to pack");

	program.add_argument("--output")
		.default_value("")
		.help("Output path to place newly created pack file");

	try {
		program.parse_args(argc, argv);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		std::cerr << program;
		std::exit(EXIT_FAILURE);
	}

	std::filesystem::path input = program.get<std::string>("--input"), output = program.get<std::string>("--output");

	// we just normalize it here, because if it has a trailing slash, filename() will be empty
	// otherwise it returns the last part of the path
	if (input.filename().empty()) {
		input = input.parent_path();
	}

	output /= input.filename().replace_extension(".pck");

	std::ofstream ofs(output, std::ios::binary);
	if (!ofs.is_open()) {
		std::cerr << "Failed to open output file: " << output << std::endl;
		return EXIT_FAILURE;
	}

	std::map<std::filesystem::path, TPackFileEntry> entries;

	for (auto entry : std::filesystem::recursive_directory_iterator(input)) {
		if (!entry.is_regular_file())
			continue;

		std::filesystem::path relative_path = std::filesystem::relative(entry.path(), input);
		
		TPackFileEntry& file_entry = entries[relative_path];
		memset(&file_entry, 0, sizeof(file_entry));
		file_entry.file_size = entry.file_size();

		constexpr std::string_view ymir_work_prefix = "ymir work/";
		std::string rp_str = relative_path.generic_string();
		if (rp_str.compare(0, ymir_work_prefix.size(), ymir_work_prefix) == 0) {
			rp_str = (std::filesystem::path("d:/ymir work/") / rp_str.substr(ymir_work_prefix.size())).generic_string();
		}

		rp_str.copy(file_entry.file_name, sizeof(file_entry.file_name) - 1);
	}

	TPackFileHeader header;
	memset(&header, 0, sizeof(header));
	header.entry_num = entries.size();
	header.data_begin = sizeof(TPackFileHeader) + sizeof(TPackFileEntry) * entries.size();

	CryptoPP::AutoSeededRandomPool rnd;
	rnd.GenerateBlock(header.iv, sizeof(header.iv));

	ofs.write((const char*) &header, sizeof(header));
	ofs.seekp(header.data_begin, std::ios::beg);

	uint64_t offset = header.data_begin;
	for (auto& [path, entry] : entries) {
		std::ifstream ifs(input / path, std::ios::binary);
		if (!ifs.is_open()) {
			std::cerr << "Failed to open input file: " << (input / path) << std::endl;
			return EXIT_FAILURE;
		}

		static std::vector<char> buffer;
		buffer.resize(entry.file_size);

		if (!ifs.read(buffer.data(), entry.file_size)) {
			std::cerr << "Failed to read input file: " << (input / path) << std::endl;
			return EXIT_FAILURE;
		}

		size_t compress_bound = ZSTD_compressBound(entry.file_size);
		static std::vector<char> compressed_buffer;
		compressed_buffer.resize(compress_bound);

		entry.compressed_size = ZSTD_compress(compressed_buffer.data(), compress_bound, buffer.data(), entry.file_size, 17);
		if(ZSTD_isError(entry.compressed_size)) {
			std::cerr << "Failed to compress input file: " << (input / path) << " error: " << ZSTD_getErrorName(entry.compressed_size) << std::endl;
			return EXIT_FAILURE;
		}

		entry.offset = offset;
		entry.encryption = 0;

		ofs.write(compressed_buffer.data(), entry.compressed_size);
		offset += entry.compressed_size;
	}

	std::vector<char> entry_buffer(sizeof(TPackFileEntry) * entries.size());
	char* ptr = entry_buffer.data();
	for (auto& [path, entry] : entries) {
		memcpy(ptr, &entry, sizeof(entry));
		ptr += sizeof(entry);
	}

	CryptoPP::CTR_Mode<CryptoPP::Camellia>::Encryption encryption;
	encryption.SetKeyWithIV(PACK_KEY.data(), PACK_KEY.size(), header.iv, CryptoPP::Camellia::BLOCKSIZE);
	encryption.ProcessData((uint8_t*)entry_buffer.data(), (uint8_t*)entry_buffer.data(), entry_buffer.size());

	ofs.seekp(sizeof(TPackFileHeader), std::ios::beg);
	ofs.write(entry_buffer.data(), entry_buffer.size());
	
	return EXIT_SUCCESS;
}