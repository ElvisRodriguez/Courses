#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SIZE 6

int hexToDecimal(char digit) {
    /*
        Converts a single hexadecimal digit into a decimal value.
    */
    char alphaValues[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < SIZE; i++) {
        if (alphaValues[i] == digit) {
            return i + 10;
        }
    }
    return digit - '0';
}

string integerToBinaryNibble(int integer) {
    /*
        Converts an integer into a binary string.
        Pads the result with 0s to the left until the string size is 4.
    */
    string binaryNibble = "";
    while (integer > 0) {
        binaryNibble = std::to_string(integer % 2) + binaryNibble;
        integer /= 2;
    }
    while (binaryNibble.length() < 4) {
        binaryNibble = "0" + binaryNibble;
    }
    return binaryNibble;
}

string toBinaryString(string word) {
    /*
        Converts a hexadecimal string to a binary string.
        Expects whole numbers.
    */
   string binaryString = "";
   int decimalValue;
   string binaryNibble;
   for (char digit: word) {
       decimalValue = hexToDecimal(digit);
       binaryNibble = integerToBinaryNibble(decimalValue);
       binaryString += binaryNibble;
   }
   return binaryString;
}

int main() {
    string word = "34AF";
    cout << toBinaryString(word) << endl;
    return 0;
}