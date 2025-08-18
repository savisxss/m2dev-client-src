#pragma once

#include "SampleFile.hpp"

#include <unordered_map>

class SampleFileCache
{
public:
    SampleFilePtr Get(std::string_view filename);

private:
    std::unordered_map<std::string_view, SampleFilePtr> m_samples;
};

