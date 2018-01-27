package com.horoscopes.jasf.horoscopes;

import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.facebook.AccessToken;
import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.LoginStatusCallback;
import com.facebook.login.LoginManager;
import com.facebook.login.LoginResult;
import com.facebook.login.widget.LoginButton;
import com.facebook.FacebookException;
import com.facebook.FacebookSdk;
import com.orhanobut.logger.*;

/**
 * A placeholder fragment containing a simple view.
 */
public class MainActivityFragment extends Fragment {


    public MainActivityFragment() {
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View result = inflater.inflate(R.layout.fragment_main, container, false);

        Button button = result.findViewById(R.id.test_button);

        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {

                LoginManager.getInstance().retrieveLoginStatus( getActivity(), new LoginStatusCallback()
                {
                    @Override
                    public void onCompleted( AccessToken accessToken )
                    {
                       Logger.d("Access token");
                    }

                    @Override
                    public void onFailure()
                    {
                        Logger.d("Access token");
                    }

                    @Override
                    public void onError( Exception exception )
                    {
                        Logger.d("onError");
                    }
                } );
                // Code here executes on main thread after user presses button
            }
        });

        // If using in a fragment
     //   loginButton.setFragment(this);



        return result;
    }
}
