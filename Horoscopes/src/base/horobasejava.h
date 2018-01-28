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

        jobject object() { return object_; }

    private:
        jobject  object_;
    };

    typedef reff<_LocalRef> LocalRef;

    template <class T> class GlobalRef {
    public:
        GlobalRef(T obj) : object_(nullptr) {
            SCParameterAssert(obj);
            if (obj) {
                object_ = static_cast<T>( getEnv()->NewGlobalRef((jobject)obj) );
                //getEnv()->DeleteLocalRef( obj );
            }
        }

        ~GlobalRef() {
            if (object_) {
                getEnv()->DeleteGlobalRef(object_);
            }
        }


        void AddRef() const { ref_count_.IncRef(); }
        rtc::RefCountReleaseStatus Release() const {
            const auto status = ref_count_.DecRef();
            if (status == rtc::RefCountReleaseStatus::kDroppedLastRef) {
                delete this;
            }
            return status;
        }
        bool HasOneRef() const { return ref_count_.HasOneRef(); }
        T get() { return object_; }
    private:
        T  object_;
        mutable webrtc::webrtc_impl::RefCounter ref_count_{0};
    };


    typedef GlobalRef<jclass> GlobalClassRef;
    typedef GlobalRef<jobject> GlobalObjectRef;


    //typedef reff<_GlobalRef> GlobalRef;

};

#include "android/classescache/classescache.h"

#endif

#endif //HORO_HOROBASEJAVA_H
