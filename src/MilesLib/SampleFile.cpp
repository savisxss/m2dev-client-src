#include "Stdafx.h"
#include "SampleFile.hpp"

SampleFile::SampleFile(std::string_view filename, std::vector<uint8_t>&& data)
    : m_filename(filename), fileData(std::forward<std::vector<uint8_t>>(data))
{
}

const void *SampleFile::GetData() const
{
    return fileData.data();
}

uint32_t SampleFile::GetSize() const
{
    return fileData.size();
}