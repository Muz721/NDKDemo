//
// Created by Administrator on 2018/11/8.
//

#ifndef NDKDEMO_MAIN_H
#define NDKDEMO_MAIN_H

#include <jni.h>
#include <string>
#include <android/log.h>
#include <string.h>
#include "Md5Utils.h"
#include "ImageBrightness.h"
using namespace std;

class main {
public:
    main();

    ~main();

    int add(int a, int b);

    static int max(int a, int b);

};

extern "C" JNICALL {
JNIEXPORT jint
Java_com_muz_ndkdemo_util_NDKUtils_maxMainJNI(JNIEnv *env);

JNIEXPORT jstring
Java_com_muz_ndkdemo_util_NDKUtils_stringFromMainJNI(JNIEnv *env);

JNIEXPORT jintArray Java_com_muz_ndkdemo_util_NDKUtils_imageBrightnessJNI(JNIEnv *env,jobject /* this */, jintArray buffer, jint width, jint height);
}
#define  LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, "NTag", __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, "Ntag", __VA_ARGS__)

extern void logV(const char *log);

extern void logD(char *log);

extern void logI(char *log);

extern void logW(char *log);

extern void logE(char *log);

#endif //NDKDEMO_MAIN_H
