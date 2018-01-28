package com.horoscopes.jasf.horoscopes;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

import com.orhanobut.logger.Logger;

/**
 * Created by jasf on 27.01.2018.
 */

public class PredictionScreen extends Activity {
    static {
        System.loadLibrary("native-lib");
    }
    public native void setPrivateInstance();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setPrivateInstance();
        setContentView(R.layout.prediction_screen);


        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText("Prediction View Controller");

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void setTodayText(String text) {
        TextView textView = findViewById(R.id.sample_text);
        textView.setText(text);
    }

}
