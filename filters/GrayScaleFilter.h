#pragma once

#include "Filter.h"

class GrayScaleFilter: public Filter {
public:
    GrayScaleFilter() = default;
    void Process(Picture& image) const override;
};
