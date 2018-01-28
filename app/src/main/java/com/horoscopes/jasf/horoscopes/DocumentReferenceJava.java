package com.horoscopes.jasf.horoscopes;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.QuerySnapshot;
import com.orhanobut.logger.Logger;

import bolts.Task;

/**
 * Created by jasf on 28.01.2018.
 */

public class DocumentReferenceJava {
    DocumentReference ref_;
    DocumentReferenceJava(DocumentReference ref) {
        ref_ = ref;
    }
    public native void onSuccessCallback(DocumentSnapshotJava doc);
    void getDocument() {
        ref_.get().addOnSuccessListener(new OnSuccessListener<DocumentSnapshot>() {
            @Override
            public void onSuccess(DocumentSnapshot documentSnapshot) {
                Logger.d("on success");
                DocumentSnapshotJava doc = new DocumentSnapshotJava(documentSnapshot);
                onSuccessCallback(doc);
            }
        });

    }

}
