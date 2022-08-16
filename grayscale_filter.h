#ifndef IMAGE_PROCESSOR_GRAYSCALE_FILTER_H
#define IMAGE_PROCESSOR_GRAYSCALE_FILTER_H

#include "Filters.h"
class Grayscale : public Filter {
public:
    void Apply(Image& image) final;
};


#endif //IMAGE_PROCESSOR_GRAYSCALE_FILTER_H
