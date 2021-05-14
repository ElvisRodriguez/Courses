#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toBinaryString(vector<bool>& word) {
    /*
        Converts a vector list of boolean values to a corresponding binary
        string, where true = 1 and false = 0.
    */
    string binaryString;
    for (bool flag: word) {
        if (flag) {
            binaryString += "1";
        } else {
            binaryString += "0";
        }
    }
    return binaryString;
}

int main() {
    vector<bool> word = {false, true, true, false, false, true};
    cout << toBinaryString(word) << endl;
    return 0;
}