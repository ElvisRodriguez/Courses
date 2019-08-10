package com.example.databasepractice;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void showAuthors(View view) {
        Intent intent = new Intent(this, showResults.class);
        intent.putExtra("query",
                "SELECT Name, Country " +
                        "FROM Authors " +
                        "ORDER BY Name");
        startActivity(intent);
    }

    public void showBooks(View view) {
        Intent intent = new Intent(this, showResults.class);
        intent.putExtra("query",
                "SELECT Title, Genre, PublicationYear " +
                        "FROM Books " +
                        "ORDER BY Title");
        startActivity(intent);
    }

    public void ShowAuthorsAndBooks(View view) {
        Intent intent = new Intent(this, showResults.class);
        intent.putExtra("query",
                        "SELECT Title, Name, Genre, PublicationYear " +
                                "FROM Authors, Books " +
                                "WHERE Authors.AuthorID=Books.AuthorID " +
                                "ORDER BY Title");
        startActivity(intent);
    }
}
