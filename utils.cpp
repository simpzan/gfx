
#include "utils.h"
#include <iostream>
#include <fstream>

std::vector<char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t) file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}


#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


StbImage::~StbImage() {
    if (pixels) {
        LOGI("free image %p", pixels);
        stbi_image_free((stbi_uc *)pixels);
    }
}

std::unique_ptr<StbImage> StbImage::load(const char *file) {
    int width, height, channels;
    stbi_uc* pixels = stbi_load(file, &width, &height, &channels, STBI_rgb_alpha);
    if (!pixels) return nullptr;
    LOGI("loaded image %p", pixels);
    std::unique_ptr<StbImage> image(new StbImage(pixels, width, height, channels));
    return image;
}