#pragma once

#include "../Picture.h"

class Filter {
public:
    virtual void Process(Picture& image) const = 0;
    virtual ~Filter() = default;
};