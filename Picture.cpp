#include "Picture.h"
#include <math.h>

Picture::Picture(std::vector<std::vector<Pixel>> matrix, std::vector<unsigned char> header) {
    width_ = matrix[0].size();
    height_ = matrix.size();
    this->matrix = std::move(matrix);
    this->header = std::move(header);
}

void Picture::WriteToHeader(size_t index, int value) {
    for (size_t i = index; i < index + 4; ++i) {
        header[i] = static_cast<unsigned char>(value);
        value /= 256;
    }
}

void Picture::UpdateHeader() {
    width_ = matrix[0].size();
    height_ = matrix.size();
    WriteToHeader(18, static_cast<int>(GetWidth()));
    WriteToHeader(22, static_cast<int>(GetHeight()));
    size_t bitmap_size = ((3 * GetWidth() + 3) / 4) * 4 * GetHeight();
    WriteToHeader(38, static_cast<int>(bitmap_size));
    WriteToHeader(2, static_cast<int>(bitmap_size) + 54);
}

size_t Picture::Shift(size_t coord, size_t edge, double shift) const {
    if (shift >= 0) {
        return std::min(static_cast<size_t>(coord + round(shift)), edge);
    } else if (round(-shift) <= coord) {
        return coord - round(-shift);
    } else {
        return 0;
    }
}

size_t Picture::ShiftX(size_t x, double shift) const {
    return Shift(x, GetWidth(), shift);
}

size_t Picture::ShiftY(size_t y, double shift) const {
    return Shift(y, GetHeight(), shift);
}

size_t Picture::GetWidth() const {
    return width_;
}

size_t Picture::GetHeight() const {
    return height_;
}
