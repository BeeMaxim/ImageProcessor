#pragma once

#include "Filter.h"

class CropFilter: public Filter {
public:
    CropFilter() = delete;
    CropFilter(size_t width, size_t height);
    void Process(Picture& image) const override;
private:
    size_t width_;
    size_t height_;
};
