//
// Created by Jasf on 28.01.2018.
//

#include "base/horobase.h"

#ifdef ANDROID

namespace horo {

    static JavaVM *g_jvm = nullptr;
    static JNIEnv *g_env = nullptr;
    JavaVM *getVM() {
        return g_jvm;
    }

    void setVM(JavaVM *jvm) {
        g_jvm = jvm;
    }

    JNIEnv *getEnv() {
        return _JNIEnvStorage::env();
    }

    static vector<_JNIEnvStorage *> envsStorage;

    _JNIEnvStorage::_JNIEnvStorage(JNIEnv *env) : env_(env) {
        envsStorage.push_back(this);
    }

    _JNIEnvStorage::~_JNIEnvStorage() {
        envsStorage.erase(std::remove(envsStorage.begin(), envsStorage.end(), this), envsStorage.end());
    }

    JNIEnv *_JNIEnvStorage::env() {
        if (envsStorage.size()) {
            _JNIEnvStorage *storage = *envsStorage.begin();
            return storage->getEnv();
        }
        return nullptr;
    }

/*
    JavaVM *g_vm = getVM();
    JNIEnv * g_env;
    // double check it's all ok
    int getEnvStat = g_vm->GetEnv((void **)&g_env, JNI_VERSION_1_6);
    bool atached = false;
    if (getEnvStat == JNI_EDETACHED) {
    atached = true;
    std::cout << "GetEnv: not attached" << std::endl;
    if (g_vm->AttachCurrentThread((JNIEnv **) &g_env, NULL) != 0) {
    std::cout << "Failed to attach" << std::endl;
}
} else if (getEnvStat == JNI_OK) {
//
} else if (getEnvStat == JNI_EVERSION) {
std::cout << "GetEnv: version not supported" << std::endl;
}

g_env->DeleteGlobalRef(jobject_);
jobject_ = nullptr;

if (g_env->ExceptionCheck()) {
g_env->ExceptionDescribe();
}

if (atached) {
g_vm->DetachCurrentThread();
}
*/

}

#endif
