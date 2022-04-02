#pragma once

#include "Filter.h"

class SquareFilter : public Filter {
public:
    SquareFilter(size_t square_size);
    void Process(Picture& image) const override;
private:
    size_t square_size_;
};
