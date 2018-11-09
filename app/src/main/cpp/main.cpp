//
// Created by Administrator on 2018/11/8.
//

#include <string.h>
#include "main.h"
#include "Md5Utils.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_muz_ndkdemo_util_NDKUtils_stringFromMainJNI(
        JNIEnv *env) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL Java_com_muz_ndkdemo_util_NDKUtils_maxMainJNI(JNIEnv *env) {
    int a = 4;
    int b = 3;
    int c = a > b ? a : b;
    return c;
};

extern "C"
JNIEXPORT jstring JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_spliceStaticJNI(JNIEnv *env, jobject /* this */, jstring str) {
    jclass jclass1 = env->FindClass("com/muz/ndkdemo/util/NDKUtils");
    jmethodID id = env->GetStaticMethodID(jclass1, "javaStaticString", "()Ljava/lang/String;");
    jstring jstring1 = (jstring) env->CallStaticObjectMethod(jclass1, id);
    string cjs = "c++里的字符串。";
    string sf = env->GetStringUTFChars(jstring1, false);
    cjs += sf;
    env->ReleaseStringUTFChars(jstring1, sf.c_str());
    return env->NewStringUTF(cjs.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_spliceJNI(JNIEnv *env, jobject /* this */, jstring str) {
    jclass jclass1 = env->FindClass("com/muz/ndkdemo/util/NDKUtils");
    jmethodID mainId = env->GetMethodID(jclass1, "<init>", "()V");
    jobject jobject1 = env->NewObject(jclass1, mainId);
    jmethodID id = env->GetMethodID(jclass1, "javaString", "()Ljava/lang/String;");
    jstring jstring1 = (jstring) env->CallObjectMethod(jobject1, id);
    string cjs = "c++里的字符串。";
    string sf = env->GetStringUTFChars(jstring1, false);
    cjs += sf;
    env->ReleaseStringUTFChars(jstring1, sf.c_str());
    return env->NewStringUTF(cjs.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_muz_ndkdemo_util_NDKUtils_md5JNI(JNIEnv *env, jobject /* this */, jstring str) {
    string encrypt = env->GetStringUTFChars(str, false);
    Md5Utils *md5Utils = new Md5Utils();
    encrypt = md5Utils->Md5Utils::encryption16((char *) encrypt.c_str());
    LOGE("加密结果： %s \n", encrypt.c_str());
    env->ReleaseStringUTFChars(str, encrypt.c_str());
    return env->NewStringUTF(encrypt.c_str());
}

int main::add(int a, int b) {

}

int main::max(int a, int b) {
    return 0;
}

main::main() {

}

main::~main() {

}


