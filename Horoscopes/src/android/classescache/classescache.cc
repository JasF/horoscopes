//
// Created by Jasf on 28.01.2018.
//

#include "base/horobase.h"

#ifdef ANDROID

namespace horo {

    jclass ClassesCache::classWithName(string className) {
        strong<GlobalClassRef> ref = storage_[className];
        jclass cls = nullptr;
        if (ref.get()) {
            cls = ref->get();
        }
        if (!cls) {
            cls = getEnv()->FindClass( className.c_str() );
            if (cls) {
                storage_[className] = new GlobalClassRef(cls);
            }
        }
        SCAssert(cls, "class with name %s not found", className.c_str());
        return cls;
    }

};

#endif
