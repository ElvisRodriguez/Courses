#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define FILENAME "results.txt"
#define SIZE 5

bool BinaryStringWrite(string word, ofstream& out) {
    /*
        Checks if word is a binary string, if so, writes it to the file
        referenced by out and returns true. Returns false and writes
        nothing otherwise.
    */
   if (word == "") {
       return false;
   }
   for (char c: word) {
       if (c != '0' && c != '1') {
           return false;
       }
   }
   out << word << endl;
   return true;
}

int main() {
    ofstream file;
    file.open(FILENAME);
    string testStrings[SIZE] = {"010101", "Elvis", "1111111", "00000", ""};
    for (int i = 0; i < SIZE; i++) {
        string word = testStrings[i];
        cout << "Testing: " << word << endl;
        if (BinaryStringWrite(word, file)) {
            cout << "\tValid binary string, adding to results...\n";
        } else {
            cout << "\tInvalid binary string, string may only include {0, 1}\n";
        }
    }
    return 0;
}