package com.horoscopes.jasf.horoscopes;

import com.google.firebase.firestore.CollectionReference;
import com.google.firebase.firestore.DocumentReference;

/**
 * Created by jasf on 28.01.2018.
 */

public class CollectionReferenceJava {
    private CollectionReference ref_ = null;
    CollectionReferenceJava(CollectionReference colref) {
        ref_ = colref;
    }
    DocumentReferenceJava document(String path) {
        DocumentReference doc = ref_.document(path);
        DocumentReferenceJava result = new DocumentReferenceJava(doc);
        return result;
    }
}
