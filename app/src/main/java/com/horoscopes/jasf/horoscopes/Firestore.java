package com.horoscopes.jasf.horoscopes;
import com.google.firebase.firestore.CollectionReference;
import com.google.firebase.firestore.FirebaseFirestore;
import com.orhanobut.logger.*;

/**
 * Created by jasf on 27.01.2018.
 */

public class Firestore {
    static {
        System.loadLibrary("native-lib");
    }
    public native void setPrivateInstance();
    Firestore() {
        setPrivateInstance();
    }
    static Firestore sharedInstance = null;
    FirebaseFirestore db = FirebaseFirestore.getInstance();

    static Firestore shared() {
        if (sharedInstance == null) {
            sharedInstance = new Firestore();
        }
        return sharedInstance;
    }

    public void simpleMethod() {
        Logger.d("simpleoy");
    }
    public CollectionReferenceJava collectionWithPath(String path) {
        Logger.d("path is: " + path);
        CollectionReference colref = db.collection(path);

        /*
        db.collection("users")
                .get()
                .addOnCompleteListener(new OnCompleteListener<QuerySnapshot>() {
                    @Override
                    public void onComplete(@NonNull Task<QuerySnapshot> task) {
                        if (task.isSuccessful()) {
                            for (DocumentSnapshot document : task.getResult()) {
                                Log.d(TAG, document.getId() + " => " + document.getData());
                            }
                        } else {
                            Log.w(TAG, "Error getting documents.", task.getException());
                        }
                    }
                });
        */

        CollectionReferenceJava ref = new CollectionReferenceJava(colref);
        return ref;
    }
}
