#include "Stdafx.h"
#include "MSSFileAPI.hpp"

#include "EterBase/Timer.h"
#include "EterBase/Utils.h"

#include "EterPack/StdAfx.h"
#include "EterPack/EterPackManager.h"

#include <mss.h>

#include <mutex>
#include <memory>
#include <algorithm>
#include <unordered_map>

namespace
{
	enum ESeekType
	{
		SEEK_TYPE_BEGIN,
		SEEK_TYPE_CURRENT,
		SEEK_TYPE_END
	};

	struct CSeekPackFile
	{
		std::vector<uint8_t> packFile;

		U32 seek_position;

		~CSeekPackFile()
		{
			seek_position = 0;
		}

		U32 Seek(S32 offset, U32 type)
		{
			switch (type)
			{
				case SEEK_TYPE_BEGIN:
					if (offset > packFile.size())
						offset = packFile.size();

					seek_position = offset;
					break;

				case SEEK_TYPE_CURRENT:
					seek_position = MIN(seek_position + offset, packFile.size());
					break;

				case SEEK_TYPE_END:
					seek_position = MAX(0, packFile.size() - offset);
					break;
			}

			return seek_position;
		}

		BOOL Read(void* dest, int bytes)
		{
			if (seek_position + bytes > packFile.size())
				return FALSE;

			memcpy(dest, (const char*)packFile.data() + seek_position, bytes);
			seek_position += bytes;
			return TRUE;
		}
	};
	static std::unordered_map<U32, CSeekPackFile> gs_SoundFile;
	static std::vector<U32> gs_FreeIndexes;
	static U32 gs_SoundFileIndex = 0;
	static std::mutex gs_SoundFileMutex;

	U32 AILCALLBACK open_callback(MSS_FILE const* filename, UINTa* file_handle)
	{
		std::lock_guard<std::mutex> lock(gs_SoundFileMutex);

		U32 index = 0;
		if (!gs_FreeIndexes.empty())
		{
			index = gs_FreeIndexes.back();
			gs_FreeIndexes.pop_back();
		}
		else
		{
			index = ++gs_SoundFileIndex;
		}

		LPCVOID pData;
		CMappedFile mappedFile;
		if (!CEterPackManager::instance().Get(mappedFile, filename, &pData))
			return 0;

		gs_SoundFile[index].packFile.resize(mappedFile.Size());
		memcpy(gs_SoundFile[index].packFile.data(), pData, mappedFile.Size());

		*file_handle = index;
		return 1;
	}

	void AILCALLBACK close_callback(UINTa file_handle)
	{
		std::lock_guard<std::mutex> l(gs_SoundFileMutex);

		gs_SoundFile.erase(file_handle);
		gs_FreeIndexes.push_back(file_handle);
	}

	S32 AILCALLBACK seek_callback(UINTa file_handle, S32 offset, U32 type)
	{
		auto it = gs_SoundFile.find(file_handle);
		if (it == gs_SoundFile.end())
			return 0;

		return it->second.Seek(offset, type);
	}

	U32 AILCALLBACK read_callback(UINTa file_handle, void* buffer, U32 bytes)
	{
		auto it = gs_SoundFile.find(file_handle);
		if (it == gs_SoundFile.end())
			return 0;

		DWORD dwRealSize = MIN(it->second.packFile.size(), bytes);
		it->second.Read(buffer, dwRealSize);
		return dwRealSize;
	}
}

void RegisterMilesFileAPI()
{
    AIL_set_file_callbacks(open_callback, close_callback,
                           seek_callback, read_callback);
}
