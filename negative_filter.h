#ifndef CPP_PILOT_HSE_NEGATIVE_FILTER_H
#define CPP_PILOT_HSE_NEGATIVE_FILTER_H
#include "Filters.h"

class Negative : public Filter {
public:
    virtual void Apply(Image& image) final;
};

#endif //CPP_PILOT_HSE_NEGATIVE_FILTER_H
