#include "StdAfx.h"
#include "GuildMarkClient.h"
#include "PythonNetworkStream.h"
#include "../EterBase/lzo.h"
#include "stb_image.h"

CGuildMarkClient& CGuildMarkClient::Instance() {
    static CGuildMarkClient instance;
    return instance;
}

void CGuildMarkClient::UploadMark(uint32_t guild_id, const std::vector<uint8_t>& data,
                                 const std::string& format, UploadCallback callback) {
    if (data.empty() || data.size() > 1024 * 1024) {
        if (callback) {
            callback(false, "Invalid data size");
        }
        return;
    }

    if (!ValidateImageFormat(data, format)) {
        if (callback) {
            callback(false, "Invalid image format");
        }
        return;
    }

    m_upload_callbacks[guild_id] = callback;

    TPacketCGGuildMarkUpload packet;
    packet.header = HEADER_CG_GUILD_MARK_UPLOAD_NEW;
    packet.guild_id = guild_id;
    packet.data_size = data.size();
    packet.crc32 = 0;

    strncpy(reinterpret_cast<char*>(packet.format), format.c_str(), sizeof(packet.format));
    packet.format[sizeof(packet.format) - 1] = '\0';

    CPythonNetworkStream& stream = CPythonNetworkStream::Instance();
    if (!stream.Send(sizeof(packet), &packet)) {
        if (callback) {
            callback(false, "Failed to send packet header");
        }
        return;
    }

    if (!stream.Send(data.size(), data.data())) {
        if (callback) {
            callback(false, "Failed to send image data");
        }
        return;
    }
}

void CGuildMarkClient::RequestMark(uint32_t guild_id, DownloadCallback callback) {
    auto cached = GetCachedMark(guild_id);
    if (cached) {
        if (callback) {
            callback(cached);
        }
        return;
    }

    m_download_callbacks[guild_id] = callback;

    TPacketCGGuildMarkRequest packet;
    packet.header = HEADER_CG_GUILD_MARK_REQUEST;
    packet.guild_id = guild_id;

    CPythonNetworkStream& stream = CPythonNetworkStream::Instance();
    stream.Send(sizeof(packet), &packet);
}

void CGuildMarkClient::DeleteMark(uint32_t guild_id) {
    TPacketCGGuildMarkDelete packet;
    packet.header = HEADER_CG_GUILD_MARK_DELETE;
    packet.guild_id = guild_id;

    CPythonNetworkStream& stream = CPythonNetworkStream::Instance();
    stream.Send(sizeof(packet), &packet);

    m_cached_marks.erase(guild_id);
}

std::shared_ptr<GuildMarkInfo> CGuildMarkClient::GetCachedMark(uint32_t guild_id) {
    auto it = m_cached_marks.find(guild_id);
    if (it != m_cached_marks.end()) {
        return it->second;
    }
    return nullptr;
}

void CGuildMarkClient::ClearCache() {
    m_cached_marks.clear();
}

void CGuildMarkClient::OnUploadResult(uint32_t guild_id, uint8_t result, uint32_t mark_id) {
    auto it = m_upload_callbacks.find(guild_id);
    if (it != m_upload_callbacks.end()) {
        bool success = (result == GUILD_MARK_UPLOAD_SUCCESS);
        std::string error;

        switch (result) {
            case GUILD_MARK_UPLOAD_INVALID_FORMAT:
                error = "Invalid image format";
                break;
            case GUILD_MARK_UPLOAD_TOO_LARGE:
                error = "Image too large";
                break;
            case GUILD_MARK_UPLOAD_SERVER_ERROR:
                error = "Server error";
                break;
            case GUILD_MARK_UPLOAD_NO_PERMISSION:
                error = "No permission";
                break;
            default:
                error = "Unknown error";
                break;
        }

        if (it->second) {
            it->second(success, error);
        }

        m_upload_callbacks.erase(it);
    }
}

void CGuildMarkClient::OnMarkData(const GuildMarkInfo& mark) {
    auto mark_info = std::make_shared<GuildMarkInfo>(mark);

    if (mark.compressed_size < mark.original_size) {
        mark_info->data = DecompressData(mark.data, mark.original_size);
    }

    m_cached_marks[mark.guild_id] = mark_info;

    auto it = m_download_callbacks.find(mark.guild_id);
    if (it != m_download_callbacks.end()) {
        if (it->second) {
            it->second(mark_info);
        }
        m_download_callbacks.erase(it);
    }
}

void CGuildMarkClient::OnMarkUpdate(uint32_t guild_id, uint8_t update_type) {
    switch (update_type) {
        case 0: // GUILD_MARK_UPDATE_UPLOADED
        case 2: // GUILD_MARK_UPDATE_MODIFIED
            m_cached_marks.erase(guild_id);
            break;
        case 1: // GUILD_MARK_UPDATE_DELETED
            m_cached_marks.erase(guild_id);
            break;
    }
}

std::vector<uint8_t> CGuildMarkClient::DecompressData(const std::vector<uint8_t>& data, uint32_t size) {
    // Use LZO decompression like original system
    CLZObject lzo_obj;
    if (CLZO::Instance().Decompress(lzo_obj, data.data())) {
        std::vector<uint8_t> decompressed(lzo_obj.GetSize());
        memcpy(decompressed.data(), lzo_obj.GetBuffer(), lzo_obj.GetSize());
        return decompressed;
    }

    // Return original data if decompression fails
    return data;
}

bool CGuildMarkClient::ValidateImageFormat(const std::vector<uint8_t>& data, const std::string& format) {
    if (data.size() < 8) {
        return false;
    }

    // Check PNG signature
    if (format == "png") {
        const uint8_t png_sig[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
        return memcmp(data.data(), png_sig, 8) == 0;
    }

    // Check JPEG signature
    else if (format == "jpg" || format == "jpeg") {
        return data[0] == 0xFF && data[1] == 0xD8;
    }

    // Check GIF signature
    else if (format == "gif") {
        return (memcmp(data.data(), "GIF87a", 6) == 0) ||
               (memcmp(data.data(), "GIF89a", 6) == 0);
    }

    // Check BMP signature
    else if (format == "bmp") {
        return data[0] == 'B' && data[1] == 'M';
    }

    // Try to load with stb_image as fallback
    int width, height, channels;
    unsigned char* img = stbi_load_from_memory(data.data(), data.size(), &width, &height, &channels, 0);
    if (img) {
        stbi_image_free(img);
        return true;
    }

    return false;
}