#include "CropFilter.h"

CropFilter::CropFilter(size_t width, size_t height) {
    width_ = width;
    height_ = height;
}

void CropFilter::Process(Picture& image) const {
    size_t crop_height = std::min(height_, image.GetHeight());
    size_t crop_width = std::min(width_, image.GetWidth());
    std::vector<std::vector<Pixel>> new_matrix(crop_height,
                                               std::vector<Pixel>(crop_width));
    for (size_t i = 0; i < crop_height; ++i) {
        for (size_t j = 0; j < crop_width; ++j) {
            new_matrix[crop_height - i - 1][j] = image.matrix[image.GetHeight() - i - 1][j];
        }
    }
    image.matrix = std::move(new_matrix);
    image.UpdateHeader();
}
