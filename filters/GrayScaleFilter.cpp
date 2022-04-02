#include "GrayScaleFilter.h"

void GrayScaleFilter::Process(Picture& image) const {
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            Pixel& pixel = image.matrix[i][j];
            double value = 0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue;
            image.matrix[i][j] = Pixel(value, value, value);
        }
    }
}
