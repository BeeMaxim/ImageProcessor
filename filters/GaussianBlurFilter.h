#pragma once

#include "Filter.h"

class GaussianBlurFilter : public Filter {
public:

    GaussianBlurFilter(double sigma);

    void Process(Picture& image) const override;

private:
    double sigma_;

    void ProcessInOneAx(Picture &image, double l_shift_x, double r_shift_x, double l_shift_y, double r_shift_y) const;
};
