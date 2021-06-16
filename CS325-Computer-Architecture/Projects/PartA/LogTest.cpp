#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Log.h"

#define TEST_SIZE 5
#define ID_SIZE 8

int main() {
    Log logger("test_logs.txt");
    string identifiers[ID_SIZE];
    for (int i = 0; i < ID_SIZE; i++) {
        identifiers[i] = "0x0" + to_string(i);
    }
    string testStrings[TEST_SIZE] = {
        "0111001011010", "FF00FABCD", "Bad String", "0", "1"
    };
    vector<vector<bool>> testBinaryArrays = {
        {true, false, true, false},
        {true, true, true, true},
        {false, false, false, false}
    };
    for (int i = 0; i < TEST_SIZE; i++) {
        string testString = testStrings[i];
        logger.write(identifiers[i], testString);
    }
    int i = 5;
    for (vector<bool> testBinaryArray: testBinaryArrays) {
        logger.write(identifiers[i], testBinaryArray);
        i++;
    }
    return 0;
}