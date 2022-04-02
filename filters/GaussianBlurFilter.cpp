#include "GaussianBlurFilter.h"
#include <numbers>
#include <math.h>

using namespace std::numbers;

GaussianBlurFilter::GaussianBlurFilter(double sigma) {
    sigma_ = sigma;
}

void GaussianBlurFilter::ProcessInOneAx(Picture& image, double l_shift_x, double r_shift_x, double l_shift_y,
                                        double r_shift_y) const {
    std::vector<std::vector<Pixel>> old_matrix = image.matrix;
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            image.matrix[i][j] = {0, 0, 0};
            double weight_sum = 0;
            for (size_t y = image.ShiftY(i, l_shift_y); y < image.ShiftY(i, r_shift_y); ++y) {
                for (size_t x = image.ShiftX(j, l_shift_x); x < image.ShiftX(j, r_shift_x); ++x) {
                    size_t sq_delta_y = (y - i) * (y - i) + (x - j) * (x - j);
                    double weight = std::exp(-static_cast<double>(sq_delta_y) /
                                             (2 * sigma_ * sigma_)) /
                                    std::sqrt(2 * pi * sigma_ * sigma_);
                    image.matrix[i][j] = image.matrix[i][j] + old_matrix[y][x] * weight;
                    weight_sum += weight;
                }
            }
            image.matrix[i][j] = image.matrix[i][j] / weight_sum;
        }
    }
}

void GaussianBlurFilter::Process(Picture& image) const {
    ProcessInOneAx(image, -3 * sigma_, 3 * sigma_ + 1, 0, 1);
    ProcessInOneAx(image, 0, 1, -3 * sigma_, 3 * sigma_ + 1);
}
