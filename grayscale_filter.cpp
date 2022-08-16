#include "grayscale_filter.h"

void Grayscale::Apply(Image& image) {
    for (size_t i = 0; i < image.GetSize(); ++i) {
        float value = 0.299 * image.GetColor(i).red + 0.587 * image.GetColor(i).green + 0.114 * image.GetColor(i).blue;
        Color color = {value, value, value};
        image.SetColor(i, color);
    }
}
