#include "Image.h"
#include "InputOutput.h"
#include "Filters.h"
#include "grayscale_filter.h"
#include "negative_filter.h"
#include "controller.h"
#include "crop_filter.h"
#include <vector>

int main(int argc, char* argv[]) {
    //test1 - как нужно тестировать - пример командной строки внизу.
    // ./image_processor (path)\\(нужное имя bmp_24).bmp (path)\\result.bmp
    //path обязательно полный, начиная например с C:\\..
    const char* in_path = argv[2];
    const char* out_path = argv[argc - 1];
    InputOutput copy1;
    Image image1(copy1.Input(in_path));
    copy1.Create(out_path, image1);
    //test2 - применение фильтров negative grayscale
    //negative
    Image image2(copy1.Input(in_path));
    const size_t width = image2.GetW();
    const size_t height = image2.GetH();
    vector<Color> colors = image2.GetAllColor();
    Image image(width, height, colors);
    Negative negative;
    negative.Apply(image);
    Grayscale grayscale;
    grayscale.Apply(image);
    copy1.Create(out_path, image);
}
