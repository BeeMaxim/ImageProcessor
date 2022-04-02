#include "NegativeFilter.h"

void NegativeFilter::Process(Picture& image) const {
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            image.matrix[i][j].Invert();
        }
    }
}

