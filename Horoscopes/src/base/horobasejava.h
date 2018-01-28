//
// Created by Jasf on 28.01.2018.
//

#ifndef HORO_HOROBASEJAVA_H
#define HORO_HOROBASEJAVA_H

#ifdef ANDROID

#include <jni.h>

namespace horo {

    JavaVM *getVM();
    void setVM(JavaVM *jvm);
    JNIEnv *getEnv();

#define setEnv(a) strong<JNIEnvStorage> storage = new JNIEnvStorage(a);

    class _JNIEnvStorage {
    public:
        _JNIEnvStorage(JNIEnv *env);
        ~_JNIEnvStorage();
        JNIEnv *getEnv() {return env_; }
        static JNIEnv *env();

    private:
        JNIEnv *env_;
    };

    typedef reff<_JNIEnvStorage> JNIEnvStorage;

    class _LocalRef {
    public:
        _LocalRef(jobject obj) : object_(nullptr) {
            SCParameterAssert(obj);
            if (obj) {
                object_ = getEnv()->NewLocalRef(obj);
            }
        }

        ~_LocalRef() {
            if (object_) {
                getEnv()->DeleteLocalRef(object_);
            }
        }


    private:
        jobject  object_;
    };

    typedef reff<_LocalRef> LocalRef;


    class _GlobalRef {
    public:
        _GlobalRef(jobject obj) : object_(nullptr) {
            SCParameterAssert(obj);
            if (obj) {
                object_ = getEnv()->NewGlobalRef(obj);
            }
        }

        ~_GlobalRef() {
            if (object_) {
                getEnv()->DeleteGlobalRef(object_);
            }
        }


    private:
        jobject  object_;
    };

    typedef reff<_LocalRef> LocalRef;

};

#endif

#endif //HORO_HOROBASEJAVA_H
