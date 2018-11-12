//
// Created by Administrator on 2018/11/12.
//
#ifndef NDKDEMO_IMAGE_BRIGHTNESS_H
#define NDKDEMO_IMAGE_BRIGHTNESS_H
#include <jni.h>
#include <android/bitmap.h>

class ImageBrightness {
public:
static int* brightness(int* source , int width , int height );
};


#endif //NDKDEMO_IMAGE_BRIGHTNESS_H
