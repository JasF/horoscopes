package com.horoscopes.jasf.horoscopes;

import android.app.Application;

import com.facebook.FacebookSdk;
import com.orhanobut.logger.*;

/**
 * Created by jasf on 27.01.2018.
 */

public class HoroscopesApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        Logger.addLogAdapter(new AndroidLogAdapter());
        ScreensManager.shared();
    }
}
