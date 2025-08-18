#include "Stdafx.h"
#include "SampleFileCache.hpp"
#include "EterBase/Debug.h"
#include "EterLib/ResourceManager.h"

#include "EterPack/StdAfx.h"
#include "EterPack/EterPackManager.h"

SampleFilePtr SampleFileCache::Get(std::string_view filename)
{
    const auto it = m_samples.find(filename);
    if (it != m_samples.end())
        return it->second;

    LPCVOID pData;
    CMappedFile mappedFile;

    if(!CEterPackManager::instance().Get(mappedFile, filename.data(), &pData))
    {
        TraceError("Failed to open %s", filename);
        return nullptr;
    }

    std::vector<uint8_t> fileData;
    fileData.resize(mappedFile.Size());
    memcpy(fileData.data(), pData, mappedFile.Size());

	auto sample = std::make_shared<SampleFile>(filename, std::move(fileData));
	m_samples.emplace(sample->GetFilename(), sample);
	return sample;
}
