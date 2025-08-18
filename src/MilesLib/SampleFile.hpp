#pragma once

#include <memory>
#include "EterBase/StdAfx.h"
#include <string_view>

#include "EterPack/StdAfx.h"
#include "EterPack/EterPackmanager.h"

class SampleFile
{
  public:
    SampleFile(std::string_view filename, std::vector<uint8_t>&& data);

    const std::string &GetFilename() const
    {
        return m_filename;
    }

    const void *GetData() const;
    uint32_t GetSize() const;

  private:
    std::string m_filename;
    std::vector<uint8_t> fileData;
};

using SampleFilePtr = std::shared_ptr<SampleFile>;

