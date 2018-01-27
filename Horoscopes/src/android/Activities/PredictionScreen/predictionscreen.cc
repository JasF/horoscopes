//
// Created by Jasf on 27.01.2018.
//

#include "base/horobase.h"

using namespace std;
using namespace horo;

extern "C"
JNIEXPORT void
        JNICALL
Java_com_horoscopes_jasf_horoscopes_PredictionScreen_setPrivateInstance(
        JNIEnv *env, jobject aThis) {
    JavaVM *jvm = nullptr;
    env->GetJavaVM(&jvm);
    setVM(jvm);
}
