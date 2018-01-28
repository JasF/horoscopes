package com.horoscopes.jasf.horoscopes;

import com.google.firebase.firestore.DocumentSnapshot;

import java.util.Map;
import com.google.gson.*;

/**
 * Created by jasf on 28.01.2018.
 */

public class DocumentSnapshotJava {
    DocumentSnapshot snapshot_ = null;
    DocumentSnapshotJava(DocumentSnapshot snapshot) {
        snapshot_  = snapshot;
    }

    public String dataString() {
        Gson gson = new Gson();
        Map<String, Object> result = snapshot_.getData();
        String resultString = gson.toJson(result);
        return resultString;
    }
}
