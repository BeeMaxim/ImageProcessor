#pragma once

#include "../Picture.h"
#include <string>

Picture Read(const std::string& path);
uint32_t BytesToInt(const std::vector<unsigned char>& bytes, size_t index, size_t len);