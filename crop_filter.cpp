//
// Created by riabo on 23.03.2022.
//

#include "crop_filter.h"

//void Crop::cropping(const size_t& a, const size_t& b, Image &image) {
//
//}

//Crop::Crop(uint64_t a, uint64_t b) : width_(a), height_(b){}
//void Crop::Apply(Image &image) {
//    vector<Color> t = image.GetAllColor();
//    Image image1(width_, height_, t);
//    uint64_t counter = 0;
//    vector<Color> current;
//    uint64_t i = 0;
//    const uint64_t size = height_ * width_;
//    while (i != size) {
//        if (counter % width_ != 0) {
//            current.push_back(image.GetColor(i));
//        } else {
//            t.insert(t.end(), current.begin(), current.end());
//            current.clear();
//        }
//        ++counter;
//       ++i;
//    }
//    image1.SetAllColor(t);
//    image.Setter(image1);
//}