//
// Created by Jasf on 28.01.2018.
//

#include <json/reader.h>
#include "documentsnapshotjava.h"

Json::Value DocumentSnapshotJava::data() const {
    Json::Value value;

    static jmethodID getDataMethod = nullptr;
    JNIEnv *env = getEnv();
    jclass cls = ClassesCache::shared()->classWithName("com/horoscopes/jasf/horoscopes/DocumentSnapshotJava");
    jthrowable mException = env->ExceptionOccurred();
    if (mException )
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (cls) {
        getDataMethod = env->GetMethodID(cls, "dataString", "()Ljava/lang/String;");
    }

    if (getDataMethod) {
        jstring javaString =(jstring)env->CallObjectMethod(snapshot_->get(), getDataMethod);
        const char *nativeString = env->GetStringUTFChars(javaString, 0);
        Json::Reader reader;
        reader.parse(nativeString, value);
        env->ReleaseStringUTFChars(javaString, nativeString);
    }

    return value;
}
