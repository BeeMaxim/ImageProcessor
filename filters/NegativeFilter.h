#pragma once

#include "Filter.h"

class NegativeFilter: public Filter {
public:
    NegativeFilter() = default;
    void Process(Picture &image) const override;
};
