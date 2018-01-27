//
// Created by Jasf on 27.01.2018.
//

#include <jni.h>
#include <string>
#include "base/horobase.h"
#include "managers/managers.h"
#include "managers/firestore/firestoreimpl.h"
#include "managers/firestore/firestorefactory.h"

using namespace std;
using namespace horo;

namespace horo {

    class DocumentSnapshotJava : public DocumentSnapshot {
    public:
        DocumentSnapshotJava(jobject snapshot)
                : snapshot_(snapshot) {}
        ~DocumentSnapshotJava() override {}
    public:
        Json::Value data() const override {
            Json::Value value;
            return value;
            /*
            if (!snapshot_.exists) {
                Json::Value empty;
                return empty;
            }
            NSData *data = [NSJSONSerialization dataWithJSONObject:snapshot_.data options:0 error:nil];
            std::string jsonString((const char *)data.bytes, data.length);
            Json::Reader reader;
            Json::Value root;
            if (!reader.parse(jsonString, root)) {
                Json::Value empty;
                return empty;
            }
            return root;
             */
        }
    private:
        jobject snapshot_;
    };

    class DocumentReferenceJava : public DocumentReference {
    public:
        DocumentReferenceJava(jobject reference)
                : reference_(reference) {}
        ~DocumentReferenceJava() override {}
    public:
        virtual void getDocumentWithCompletion(std::function<void(strong<DocumentSnapshot> snapshot, error err)> completion) override {
           // strong<DocumentSnapshot> documentSnapshot = new DocumentSnapshotJava(nullptr);
            //return documentSnapshot;
            /*
            [reference_ getDocumentWithCompletion:^(FIRDocumentSnapshot * _Nullable snapshot, NSError * _Nullable aError) {
            if (snapshot) {
                strong<DocumentSnapshot> cSnapshot = new DocumentSnapshotObjc(snapshot);
                if (completion) {
                    completion(cSnapshot, horo::error());
                }
                return;
            }
            horo::error err(aError.localizedDescription.UTF8String, (int)aError.code);
            if (completion) {
                completion(nullptr, err);
            }
           }];
             */
        }

    private:
        jobject reference_;
    };

    class CollectionReferenceJava : public CollectionReference {
    public:
        CollectionReferenceJava(jobject reference) : reference_(reference) {}
        ~CollectionReferenceJava() override {}
        strong<DocumentReference> documentWithPath(std::string path) override {
            strong<DocumentReference> documentReference = new DocumentReferenceJava(nullptr);
            /*
            NSString *sPath = [[NSString alloc] initWithUTF8String:path.c_str()];
            FIRDocumentReference *reference = [reference_ documentWithPath:sPath];
            if (!reference) {
                return nullptr;
            }
            strong<DocumentReference> document = new DocumentReferenceObjc(reference);
            return document;
             */
            return documentReference;
        }

    private:
        jobject reference_;
    };

    class FirestoreJavaImpl : public Firestore {
    public:
        static FirestoreJavaImpl *shared() {
            static FirestoreJavaImpl *sharedInstance = nullptr;
            if (sharedInstance == nullptr) {
                sharedInstance = new FirestoreJavaImpl();
                FirestoreImpl::setPrivateInstance(sharedInstance);
            }
            return sharedInstance;
        }
        FirestoreJavaImpl() : jobject_(nullptr) {

        }
        ~FirestoreJavaImpl() override {
            if (jobject_) {
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
            }
        }
    public:
        strong<CollectionReference> collectionWithPath(std::string path) override {

        }

        inline void setJObject(jobject aObject) { jobject_ = aObject; }
    private:
        jobject jobject_;
    };

};
extern "C"
JNIEXPORT void
JNICALL
Java_com_horoscopes_jasf_horoscopes_Firestore_setPrivateInstance(
        JNIEnv *env,
        jobject aObject) {
    FirestoreJavaImpl::shared()->setJObject(env->NewGlobalRef(aObject));
}
