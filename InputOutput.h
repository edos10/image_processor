#ifndef IMAGE_PROCESSOR_INPUTOUTPUT_H
#define IMAGE_PROCESSOR_INPUTOUTPUT_H

#include "Image.h"

class InputOutput{
public:
    struct BITMAP_file_header {
        unsigned char byte1;
        unsigned char byte2;
        unsigned short reserve1;
        unsigned short reserve2;
        unsigned long size;
        unsigned long end_bytes;
    };
    struct BITMAP_info_header {
        unsigned int number_bytes;
        int width;
        int height;
        unsigned short planes;
        unsigned short bits_per_pixel;
        unsigned int compr;
        unsigned int bitmap_data;
        int pixel_horyzontal;
        int pixel_vertical;
        unsigned int colors_palette;
        unsigned int color_important;
    };
    Image Input(const char* path);
    void Create(const char* path, Image& image) const;
private:
    int size_file_header = 14;
    int size_info_header = 40;
};

#endif //IMAGE_PROCESSOR_INPUTOUTPUT_H
