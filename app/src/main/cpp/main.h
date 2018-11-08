//
// Created by Administrator on 2018/11/8.
//

#ifndef NDKDEMO_MAIN_H
#define NDKDEMO_MAIN_H
#include <jni.h>
#include <string>
#include <>
using namespace std;

class main {
public:
    main();
    ~main();

    int add(int a, int b);
    static int max(int a,int b);

};
extern "C" JNICALL{
JNIEXPORT jint
 Java_com_muz_ndkdemo_util_NDKUtils_maxMainJNI(JNIEnv *env);

JNIEXPORT jstring
Java_com_muz_ndkdemo_util_NDKUtils_stringFromMainJNI(JNIEnv *env);
}

#endif //NDKDEMO_MAIN_H
