#include "BMPWriter.h"
#include <fstream>
#include <math.h>

void Write(const std::string& path, const Picture& image) {
    std::ofstream out_stream;
    out_stream.open(path, std::ios_base::binary | std::ofstream::trunc);

    for (size_t i = 0; i < 54; ++i) {
        out_stream << image.header[i];
    }

    size_t paddings = (4 - (3 * image.GetWidth()) % 4) % 4;

    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            out_stream << static_cast<unsigned char>(round(255 * image.matrix[i][j].red)) <<
                       static_cast<unsigned char>(round(255 * image.matrix[i][j].green)) <<
                       static_cast<unsigned char>(round(255 * image.matrix[i][j].blue));
            if (image.GetWidth() - j == 1) {
                unsigned char padding = 0;
                for (size_t u = 0; u < paddings; ++u) {
                    out_stream << padding;
                }
            }
        }
    }
}
