#include "SharpeningFilter.h"

void SharpeningFilter::Process(Picture& image) const {
    std::vector<std::vector<int>> matrix = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    ProcessWithMatrix(image, matrix);
}
