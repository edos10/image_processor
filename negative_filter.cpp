#include "negative_filter.h"

void Negative::Apply(Image& image){
    for (auto i = 0; i < image.GetSize(); i++) {
        float r = 1 - image.GetColor(i).red;
        float g = 1 - image.GetColor(i).green;
        float b = 1 - image.GetColor(i).blue;
        Color color = {r, g, b};
        image.SetColor(i, color);
    }
}
