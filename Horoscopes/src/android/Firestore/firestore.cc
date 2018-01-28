//
// Created by Jasf on 27.01.2018.
//

#include <jni.h>
#include <string>
#include "base/horobase.h"
#include "managers/managers.h"
#include "managers/firestore/firestoreimpl.h"
#include "managers/firestore/firestorefactory.h"
#include "android/DocumentReference/documentreferencejava.h"
#include "android/DocumentSnapshot/documentsnapshotjava.h"
#include "android/CollectionReference/collectionreferencejava.h"

using namespace std;
using namespace horo;

namespace horo {


    class CollectionReferenceJava : public CollectionReference {
    public:
        CollectionReferenceJava(jobject reference) : ref_(new GlobalObjectRef(reference)) {}
        ~CollectionReferenceJava() override {}
        strong<DocumentReference> documentWithPath(std::string path) override {
            strong<DocumentReference> documentReference;


            static jmethodID documentMethod = nullptr;
            JNIEnv *env = getEnv();
            jclass cls = ClassesCache::shared()->classWithName("com/horoscopes/jasf/horoscopes/CollectionReferenceJava");
            jthrowable mException = env->ExceptionOccurred();
            if (mException )
            {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
            if (cls) {
                documentMethod = env->GetMethodID(cls, "document", "(Ljava/lang/String;)Lcom/horoscopes/jasf/horoscopes/DocumentReferenceJava;");
            }

            if (documentMethod) {
                jstring parameter = getEnv()->NewStringUTF(path.c_str());
                jobject result = getEnv()->CallObjectMethod(ref_->get(), documentMethod, parameter);
                documentReference = new DocumentReferenceJava(result);
            }
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
        strong<GlobalObjectRef> ref_;
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
        FirestoreJavaImpl() {

        }
        ~FirestoreJavaImpl() override {
        }
    public:
        strong<CollectionReference> collectionWithPath(std::string path) override {

            static jmethodID collectionWithPathMethod = nullptr;
            JNIEnv *env = getEnv();
            jclass cls = ClassesCache::shared()->classWithName("com/horoscopes/jasf/horoscopes/Firestore");
            jthrowable mException = env->ExceptionOccurred();
            if (mException )
            {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
            if (cls) {
                collectionWithPathMethod = env->GetMethodID(cls, "collectionWithPath", "(Ljava/lang/String;)Lcom/horoscopes/jasf/horoscopes/CollectionReferenceJava;");
            }
            strong<CollectionReference> value;

            if (collectionWithPathMethod) {
                jstring parameter = getEnv()->NewStringUTF(path.c_str());
                jobject result = getEnv()->CallObjectMethod(object_->get(), collectionWithPathMethod, parameter);
                value = new CollectionReferenceJava(result);
            }

            return value;
        }

        inline void setJObject(strong<GlobalObjectRef> aObject) { object_ = aObject; }
    private:
        strong<GlobalObjectRef> object_;
    };

};

extern "C"
JNIEXPORT void
JNICALL
Java_com_horoscopes_jasf_horoscopes_Firestore_setPrivateInstance(
        JNIEnv *env,
        jobject aObject) {
    setEnv(env);
    FirestoreJavaImpl::shared()->setJObject(new GlobalObjectRef(aObject));
}
