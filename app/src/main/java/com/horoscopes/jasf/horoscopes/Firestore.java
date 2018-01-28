package com.horoscopes.jasf.horoscopes;

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
    static Firestore shared() {
        if (sharedInstance == null) {
            sharedInstance = new Firestore();
        }
        return sharedInstance;
    }
}
