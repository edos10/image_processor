#include "InputOutput.h"

void InputOutput::Create(const char* path, Image& image) const {
    ofstream bmp;
    bmp.open(path, ios::binary);
    unsigned char bmp_padding[3] = { 0, 0, 0 };

    const unsigned int padding = (4 - (image.GetW() * 3) % 4) % 4;
    const size_t file_size = size_file_header + size_info_header + image.GetW() * image.GetH() * 3 + padding * image.GetH();
    const size_t size_file_header = 14;
    const size_t size_info_header = 40;
    unsigned char bmp_header[size_file_header];
    unsigned char bmp_info[size_info_header];


    bmp_header[0] = 'B';
    bmp_header[1] = 'M';
    bmp_header[2] = file_size;
    bmp_header[3] = file_size >> 8;
    bmp_header[4] = file_size >> 16;
    bmp_header[5] = file_size >> 24;
    bmp_header[6] = 0;
    bmp_header[7] = 0;
    bmp_header[8] = 0;
    bmp_header[9] = 0;
    bmp_header[10] = size_file_header + size_info_header;
    bmp_header[11] = 0;
    bmp_header[12] = 0;
    bmp_header[13] = 0;


    bmp_info[0] = size_info_header;
    bmp_info[1] = 0;
    bmp_info[2] = 0;
    bmp_info[3] = 0;
    bmp_info[4] = image.GetW();
    bmp_info[5] = image.GetW() >> 8;
    bmp_info[6] = image.GetW() >> 16;
    bmp_info[7] = image.GetW() >> 24;
    bmp_info[8] = image.GetH();
    bmp_info[9] = image.GetH() >> 8;
    bmp_info[10] = image.GetH() >> 16;
    bmp_info[11] = image.GetH() >> 24;
    bmp_info[12] = 1;
    bmp_info[13] = 0;
    bmp_info[14] = 24;
    for (size_t i = 15; i < 40; ++i) {
        bmp_info[i] = 0;
    }
    bmp.write((char*)bmp_header, size_file_header);
    bmp.write((char*)bmp_info, size_info_header);

    for (uint64_t i = 0; i < image.GetH(); ++i) {
        for (uint64_t j = 0; j < image.GetW(); ++j) {
            unsigned char r = static_cast<unsigned char>(image.GetColor(i, j).red * 255.0f);
            unsigned char g = static_cast<unsigned char>(image.GetColor(i, j).green * 255.0f);
            unsigned char b = static_cast<unsigned char>(image.GetColor(i, j).blue * 255.0f);
            unsigned char c[3] = { b, g, r };
            bmp.write((char*)c, 3);
        }
        bmp.write((char*)bmp_padding, padding);
    }
    bmp.close();
}
Image InputOutput::Input(const char* input) {
    ifstream file_read(input, ios::binary);
    InputOutput::BITMAP_file_header header;
    const size_t size_file_header = 14;
    const size_t size_info_header = 40;
    file_read.read((char*)&header, size_file_header);
    InputOutput::BITMAP_info_header info;
    file_read.read((char*)&info, size_info_header);

    uint64_t height_in_ = info.height;
    uint64_t width_in_ = info.width;
    vector<Color> colors_input_;
    cout << "a;";
    colors_input_.resize(info.height * info.width);
    unsigned int padding = (4 - (width_in_ * 3) % 4) % 4;
    for (uint64_t i = 0; i < height_in_; ++i) {
        for (uint64_t j = 0; j < width_in_; ++j) {
            unsigned char one_color[3];
            file_read.read((char*)one_color, 3);
            colors_input_[i * width_in_ + j].red = static_cast<float>(one_color[2]) / 255.0f;
            colors_input_[i * width_in_ + j].green = static_cast<float>(one_color[1]) / 255.0f;
            colors_input_[i * width_in_ + j].blue = static_cast<float>(one_color[0]) / 255.0f;
        }
        file_read.ignore(padding);
    }
    file_read.close();
    Image image(width_in_, height_in_, colors_input_);
    return image;
}
