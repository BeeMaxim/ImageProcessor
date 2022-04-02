#include <algorithm>
#include "Pixel.h"

Pixel::Pixel(double red, double green, double blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void Pixel::Invert() {
    red = 1 - red;
    green = 1 - green;
    blue = 1 - blue;
}

Pixel Pixel::operator+(const Pixel& other) const {
    return {red + other.red, green + other.green, blue + other.blue};
}

Pixel Pixel::operator*(double value) const {
    return {red * value, green * value, blue * value};
}

Pixel Pixel::operator/(double value) const {
    return {red / value, green / value, blue / value};
}

void Pixel::Normalize() {
    red = std::min(1., std::max(0., red));
    green = std::min(1., std::max(0., green));
    blue = std::min(1., std::max(0., blue));
}
