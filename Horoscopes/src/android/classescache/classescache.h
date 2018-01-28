//
// Created by Jasf on 28.01.2018.
//

#ifndef HORO_CLASSESCACHE_H
#define HORO_CLASSESCACHE_H

#ifdef ANDROID

namespace horo {

    class ClassesCache {
    public:
        ClassesCache() {}
        ~ClassesCache() {}
        static ClassesCache *shared() {
            static ClassesCache *sharedInstance = nullptr;
            if (sharedInstance == nullptr) {
                sharedInstance = new ClassesCache();
            }
            return sharedInstance;
        }
        jclass classWithName(string className);

    private:
        map<string, strong<GlobalClassRef>> storage_;
    };

};

#endif

#endif //HORO_CLASSESCACHE_H
