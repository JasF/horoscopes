#include <jni.h>
#include <string>
#include "base/horobase.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_horoscopes_jasf_horoscopes_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    int time = horo::localtime();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
