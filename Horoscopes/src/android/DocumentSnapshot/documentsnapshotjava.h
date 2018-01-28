//
// Created by Jasf on 28.01.2018.
//

#ifndef HORO_DOCUMENTSNAPSHOTJAVA_H
#define HORO_DOCUMENTSNAPSHOTJAVA_H

#include <managers/firestore/documentsnapshot.h>
#include "base/horobase.h"

namespace horo {
    class DocumentSnapshotJava : public DocumentSnapshot {
    public:
        DocumentSnapshotJava(jobject snapshot)
                : snapshot_(new GlobalObjectRef(snapshot)) {}
        ~DocumentSnapshotJava() override {}
    public:
        Json::Value data() const override;
    private:
        strong<GlobalObjectRef> snapshot_;
    };

};

#endif //HORO_DOCUMENTSNAPSHOTJAVA_H
