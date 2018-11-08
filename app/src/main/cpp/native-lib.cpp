#include <jni.h>
#include <string>
#include "main.h"
using namespace std;
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_maxJNI(JNIEnv *env) {
    int a = 4;
    int b = 3;
    int c = a > b ? a : b;
    return c;
};

extern "C"
JNIEXPORT jint
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_addJNI(JNIEnv *env, jobject /* this */, jint a, jint b) {
    int c = a + b;
    return c;
};
extern "C"
JNIEXPORT jboolean
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_isMaxJNI(JNIEnv *env, jobject /* this */, jint a, jint b) {
    jboolean c = (jboolean) (a > b);
    return c;
};

bool maxOther(int a);

extern "C"
JNIEXPORT jboolean
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_isMaxOtherJNI(JNIEnv *env, jobject /* this */, jint a, jint b) {
    int c = a > b ? a : b;
    return (jboolean) maxOther(c);
};

bool maxOther(int a) {
    return a > 33;
}

extern "C"
JNIEXPORT jintArray
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_arrayJNI(JNIEnv *env, jobject /* this */, jint a, jint b) {
    int c = a > b ? a : b;
    jintArray array = env->NewIntArray(3);
    int ss[] = {a, b, c};
    env->SetIntArrayRegion(array, 0, 3, ss);
    return array;
};

extern "C"
JNIEXPORT jintArray
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_arrayArrayJNI(JNIEnv *env, jobject /* this */, jintArray array) {
    jint * carr;
    carr = env->GetIntArrayElements(array, false);
    int size = env->GetArrayLength(array);
    for (int i = 0; i <size-1 ; i++) {
        for (int j = i+1; j <size; j++) {
            if (carr[i]<carr[j]){
                int other = carr[i];
                carr[i] = carr[j];
                carr[j] = other;
            }
        }
    }
    env->SetIntArrayRegion(array, 0, size, carr);
    env ->ReleaseIntArrayElements(array,carr,0);
    return array;
//int* carr =array;
}

extern "C"
JNIEXPORT jintArray
JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_arrayOtherJNI(JNIEnv *env, jobject /* this */, jint a, jint b) {
    int c = a > b ? a : b;
    jintArray array = env->NewIntArray(4);
    int d =Java_com_muz_ndkdemo_util_NDKUtils_maxMainJNI(env);

    int ss[] = {a, b, c,d};
    env->SetIntArrayRegion(array, 0, 4, ss);
    return array;
//int* carr =array;
}