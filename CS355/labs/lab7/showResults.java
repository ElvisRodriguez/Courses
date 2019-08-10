package com.example.databasepractice;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class showResults extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_results);



        Intent intent = getIntent();
        String query = intent.getStringExtra("query");

        ArrayList<String> values = queryDB(query);

        ListView listView = (ListView) findViewById(R.id.listView);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, values);
        listView.setAdapter(adapter);
    }

    private ArrayList<String> queryDB (String query) {
        ArrayList<String> list = new ArrayList<String>();
        try {
            SQLiteDatabase db = openOrCreateDatabase("literatures.db", Context.MODE_PRIVATE, null);
            Cursor cursor = db.rawQuery(query, null);
            while (cursor.moveToNext()) {
                StringBuilder data = new StringBuilder();
                for (int i = 0; i < cursor.getColumnCount(); i++) {
                    if (i > 0) data.append(" || ");
                    String colvalue = cursor.getString(i);
                    data.append(colvalue);
                }
                list.add(data.toString());
            }
            cursor.close();
            db.close();
        } catch (Exception e) {
            Toast.makeText(getApplicationContext(), "Error opening/querying Database", Toast.LENGTH_LONG).show();
        }
        return list;
    }
}
