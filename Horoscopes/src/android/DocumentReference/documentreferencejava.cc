//
// Created by Jasf on 28.01.2018.
//

#include "documentreferencejava.h"
#include "android/DocumentSnapshot/documentsnapshotjava.h"

namespace horo {

    vector<DocumentReferenceJava *> g_documents;

    DocumentReferenceJava::DocumentReferenceJava(jobject reference)
    : ref_(new GlobalObjectRef(reference)) {
    //env->IsSameObject(o, STATUS_ONE);
        g_documents.push_back(this);
    }

    DocumentReferenceJava::~DocumentReferenceJava() {
        g_documents.erase(std::remove(g_documents.begin(), g_documents.end(), this), g_documents.end());
    }

    void DocumentReferenceJava::getDocumentWithCompletion(std::function<void(strong<DocumentSnapshot> snapshot, error err)> completion) {
        callback_ = completion;
        static jmethodID getDocumentMethod = nullptr;
        JNIEnv *env = getEnv();
        jclass cls = ClassesCache::shared()->classWithName("com/horoscopes/jasf/horoscopes/DocumentReferenceJava");
        jthrowable mException = env->ExceptionOccurred();
        if (mException )
        {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
        if (cls) {
            getDocumentMethod = env->GetMethodID(cls, "getDocument", "()V");
        }

        if (getDocumentMethod) {
            getEnv()->CallVoidMethod(ref_->get(), getDocumentMethod);
        }
    }

};
extern "C"
JNIEXPORT void
JNICALL
Java_com_horoscopes_jasf_horoscopes_DocumentReferenceJava_onSuccessCallback(
        JNIEnv *env,
        jobject aObject, jobject aSnapshot) {
    setEnv(env);
    for (auto it : g_documents) {
        DocumentReferenceJava *doc = it;
        if (env->IsSameObject(doc->object(), aObject)) {
            strong<DocumentSnapshot> snapshot = new DocumentSnapshotJava(aSnapshot);
            auto cb = doc->callback();
            if (cb) {
                cb(snapshot, error());
            }
            break;
        }
    }
   // FirestoreJavaImpl::shared()->setJObject(new GlobalObjectRef(aObject));
}
