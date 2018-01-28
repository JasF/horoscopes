package com.horoscopes.jasf.horoscopes;

/**
 * Created by jasf on 28.01.2018.
 */

public class Notifications {
    static {
        System.loadLibrary("native-lib");
    }
    public native void setPrivateInstance();
    Notifications() {
        setPrivateInstance();
    }

    public static Notifications sharedInstance = null;
    static Notifications shared() {
        if (sharedInstance == null) {
            sharedInstance = new Notifications();
        }
        return sharedInstance;
    }
}
