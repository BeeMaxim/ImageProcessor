#include "SquareFilter.h"
#include <math.h>

SquareFilter::SquareFilter(size_t square_size) {
    square_size_ = square_size;
}

void SquareFilter::Process(Picture& image) const {
    for (size_t i = 0; i < image.GetHeight(); i += square_size_) {
        for (size_t j = 0; j < image.GetWidth(); j += square_size_) {
            size_t pixels_cnt = 0;
            Pixel pixels_sum = {0, 0, 0};
            for (size_t y = i; y < image.ShiftY(i, square_size_); ++y) {
                for (size_t x = j; x < image.ShiftX(j, square_size_); ++x) {
                    pixels_sum = pixels_sum + image.matrix[y][x];
                    ++pixels_cnt;
                }
            }
            for (size_t y = i; y < image.ShiftY(i, square_size_); ++y) {
                for (size_t x = j; x < image.ShiftX(j, square_size_); ++x) {
                    image.matrix[y][x] = pixels_sum / pixels_cnt;
                }
            }
        }
    }
}
