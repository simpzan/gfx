#pragma once
#include <string>
#include <vector>
#include <memory>

std::vector<char> readFile(const std::string& filename);

class StbImage {
public:
    static std::unique_ptr<StbImage> load(const char *file);
    ~StbImage();

    void *data() { return pixels; }
    int size() { return width * height * 4; }
    int width, height, channels;

private:
    StbImage(void *pixels, int width, int height, int channels)
            : pixels(pixels), width(width), height(height), channels(channels) {}
    void *pixels = nullptr;
};

#include <stdio.h>
#define LOG_PRINT(level, format, args...) \
    printf("%c %s:%d " format "\n", level, __FUNCTION__, __LINE__, ##args)
#define LOGD(format, args...) LOG_PRINT('D', format, ##args)
#define LOGI(format, args...) LOG_PRINT('I', format, ##args)
#define LOGE(format, args...) LOG_PRINT('E', format, ##args)
#define TRACE() LOGD("")
