//
// Created by Jasf on 28.01.2018.
//

#ifndef HORO_DOCUMENTREFERENCEJAVA_H
#define HORO_DOCUMENTREFERENCEJAVA_H

#include <managers/firestore/documentreference.h>
#include "base/horobase.h"

namespace horo {


    class DocumentReferenceJava : public DocumentReference {
    public:
        DocumentReferenceJava(jobject reference);
        ~DocumentReferenceJava() override;
    public:
        void getDocumentWithCompletion(std::function<void(strong<DocumentSnapshot> snapshot, error err)> completion) override;
        inline jobject object() { return ref_->get(); }
        inline function<void(strong<DocumentSnapshot> snapshot, error err)> callback() { return callback_; }
    private:
        strong<GlobalObjectRef> ref_;
        function<void(strong<DocumentSnapshot> snapshot, error err)> callback_;
    };

};

#endif //HORO_DOCUMENTREFERENCEJAVA_H
