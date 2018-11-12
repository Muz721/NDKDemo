//
// Created by Administrator on 2018/11/12.
//
#include <android/bitmap.h>
#include "ImageBrightness.h"

int *ImageBrightness::brightness(int *source, int width, int height) {
    float brightness = 0.2f, contrast = 0.2f;
    int bab = (int) (255 * brightness);
    int a, r, g, b;
    //实际设置的对比度
    int cab = (int) (contrast * 65536) + 1;
    int x = 0 , y = 0;
    for(x = 0; x < width; x++){
        for (y = 0; y < height ; ++y) {
            //获取每个像素点的颜色值
            int  color = source[y * width + x];
            a = (color >> 24) & 0xFF;
            r = (color >> 16) & 0xFF;
            g = (color >> 8) & 0xFF;
            b = color & 0xFF;

            int rr = r - bab;
            int gr = g - bab;
            int br = b - bab;

            r = rr > 255 ? 255 : (rr < 0 ? 0 : rr);
            g = gr > 255 ? 255 : (gr < 0 ? 0 : gr);
            b = br > 255 ? 255 : (br < 0 ? 0 : br);

            int ri = ((r - 128) * cab) >> 16 + 128;
            int gi = ((g - 128) * cab) >> 16 + 128;
            int bi = ((b - 128) * cab) >> 16 + 128;

            r = rr > 255 ? 255 : (rr < 0 ? 0 : rr);
            g = gr > 255 ? 255 : (gr < 0 ? 0 : gr);
            b = br > 255 ? 255 : (br < 0 ? 0 : br);

            //设置图像像素点的调整后的色值
            int newColor = (a << 24) | (r << 16) | (g << 8) | b;
            source[y * width + x] = newColor;
        }
    }
    return source;
}
