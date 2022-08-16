#ifndef IMAGE_PROCESSOR_FILTERS_H
#define IMAGE_PROCESSOR_FILTERS_H
#include "Image.h"
class Filter{
public:
    virtual void Apply(Image& image) = 0;
};

#endif //IMAGE_PROCESSOR_FILTERS_H
