#pragma once

#include "filters/Filter.h"

#include <string>
#include <memory>

class FilterFactory {
public:
    FilterFactory() = default;
    std::unique_ptr<Filter> CreateFilter(const std::string& type, const std::vector<double>& params);
};
