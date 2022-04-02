#pragma once

#include "Filter.h"

class MatrixFilter : public Filter {
public:
    void ProcessWithMatrix(Picture& image, const std::vector<std::vector<int>>& matrix) const;
    virtual ~MatrixFilter() = default;
};
