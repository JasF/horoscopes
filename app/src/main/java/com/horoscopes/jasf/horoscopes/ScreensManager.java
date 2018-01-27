package com.horoscopes.jasf.horoscopes;

/**
 * Created by jasf on 27.01.2018.
 */

public class ScreensManager {
    static {
        System.loadLibrary("native-lib");
    }
    public native void setPrivateInstance();
    static ScreensManager sharedInstance = null;
    ScreensManager() {
        setPrivateInstance();
    }
    static ScreensManager shared() {
        if (sharedInstance == null) {
            sharedInstance = new ScreensManager();
        }
        return sharedInstance;
    }
}
