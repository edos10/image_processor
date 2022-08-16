#ifndef IMAGE_PROCESSOR_IMAGE_H
#define IMAGE_PROCESSOR_IMAGE_H

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "Color.h"
using namespace std;


class Image {
public:
    Image(uint64_t width, uint64_t height, const vector<Color>& vec);
    ~Image();
    const Color& GetColor(uint64_t& b, uint64_t& a) const;
    const Color& GetColor(uint64_t a) const;
    const vector<Color> GetAllColor() const;
    const uint64_t GetSize() const;
    const uint64_t GetW() const;
    const uint64_t GetH() const;
    void SetColor(uint64_t a, const Color& color);
    void SetAllColor(const vector<Color>& color);
protected:
    size_t width_;
    size_t height_;
    vector<Color> colors_in_;
};

#endif //IMAGE_PROCESSOR_IMAGE_H
