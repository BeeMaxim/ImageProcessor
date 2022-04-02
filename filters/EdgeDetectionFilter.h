#pragma once

#include "MatrixFilter.h"

class EdgeDetectionFilter: public MatrixFilter {
public:
    EdgeDetectionFilter(double threshold);
    void Process(Picture& image) const;
private:
    double threshold_;
};
