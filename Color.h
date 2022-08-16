#ifndef IMAGE_PROCESSOR_COLOR_H
#define IMAGE_PROCESSOR_COLOR_H


struct Color {
    float red = 0;
    float green = 0;
    float blue = 0;
    float reserved = 0;
    Color();
    Color(float a, float b, float c);
    ~Color();
};


#endif //IMAGE_PROCESSOR_COLOR_H
