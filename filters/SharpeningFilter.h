#pragma once

#include "MatrixFilter.h"

class SharpeningFilter: public MatrixFilter {
public:
    SharpeningFilter() = default;
    void Process(Picture& image) const override;
};
