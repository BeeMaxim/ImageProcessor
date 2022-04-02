#include "EdgeDetectionFilter.h"
#include "GrayScaleFilter.h"

EdgeDetectionFilter::EdgeDetectionFilter(double threshold) {
    threshold_ = threshold;
}

void EdgeDetectionFilter::Process(Picture& image) const {
    GrayScaleFilter filter;
    filter.Process(image);

    std::vector<std::vector<int>> matrix = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
    ProcessWithMatrix(image, matrix);

    std::vector<std::vector<Pixel>> old_matrix = image.matrix;
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            if (image.matrix[i][j].red > threshold_) {
                image.matrix[i][j] = Pixel(1, 1, 1);
            } else {
                image.matrix[i][j] = Pixel(0, 0, 0);
            }
        }
    }
}
