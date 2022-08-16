#include "Image.h"

Image::Image(uint64_t width, uint64_t height, const vector<Color> &vec) : width_(width), height_(height){
    colors_in_ = vec;
}
Image::~Image() {}
void Image::SetColor(uint64_t b, const Color& color) {
    this->colors_in_[b].red = color.red;
    this->colors_in_[b].green = color.green;
    this->colors_in_[b].blue = color.blue;
}
uint64_t const Image::GetSize() const {
    return this->width_ * this->height_;
}
const Color& Image::GetColor(uint64_t& b, uint64_t& a) const{
    return this->colors_in_[b * width_ + a];
}
const vector<Color> Image::GetAllColor() const{
    return this->colors_in_;
}
void Image::SetAllColor(const vector<Color>& color) {
    this->colors_in_ = color;
}
const uint64_t Image::GetW() const{
    return this->width_;
}
const uint64_t Image::GetH() const{
    return this->height_;
}
const Color& Image::GetColor(uint64_t a) const {
    return this->colors_in_[a];
}