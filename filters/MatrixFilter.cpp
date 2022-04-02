#include "MatrixFilter.h"

void MatrixFilter::ProcessWithMatrix(Picture& image, const std::vector<std::vector<int>>& matrix)  const {
    std::vector<std::vector<Pixel>> old_matrix = image.matrix;
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            image.matrix[i][j] = old_matrix[i][j] * matrix[1][1] +
                                 old_matrix[i == 0 ? 0 : i - 1][j] * matrix[0][1] +
                                 old_matrix[i][std::min(j + 1, image.GetWidth() - 1)] * matrix[1][2] +
                                 old_matrix[std::min(i + 1, image.GetHeight() - 1)][j] * matrix[2][1] +
                                 old_matrix[i][j == 0 ? 0 : j - 1] * matrix[1][0];
            image.matrix[i][j].Normalize();
        }
    }
}

