#pragma once

class Pixel {
public :
    Pixel() = default;
    Pixel(double red, double green, double blue);
    void Invert();
    Pixel operator+(const Pixel& other) const;
    Pixel operator*(double value) const;
    Pixel operator/(double value) const;
    void Normalize();
    double red = 0;
    double green = 0;
    double blue = 0;
};
