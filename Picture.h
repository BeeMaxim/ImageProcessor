#pragma once

#include <cstdint>
#include <vector>
#include "Pixel.h"

class Picture {
public:
    Picture(std::vector<std::vector<Pixel>> matrix, std::vector<unsigned char> header);
    void UpdateHeader();
    void WriteToHeader(size_t index, int value);
    size_t ShiftX(size_t x, double shift) const;
    size_t ShiftY(size_t y, double shift) const;
    size_t GetWidth() const;
    size_t GetHeight() const;

    std::vector<std::vector<Pixel>> matrix;
    std::vector<unsigned char> header;
private:
    size_t width_ = 0;
    size_t height_ = 0;
    size_t Shift(size_t coord, size_t edge, double shift) const;
};
