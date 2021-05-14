#include <iostream>
#include <string>

using namespace std;

string ToBinaryMantissa(double radix) {
    /*
        Convert the portion of a number after it's decimal point to binary.
    */
    if (radix >= 1) {
        return "";
    }
    string binaryMantissa = "0.";
    while (radix > 0 and binaryMantissa.length() < 12) {
        radix *= 2;
        if (radix >= 1) {
            binaryMantissa += "1";
            radix -= 1;
        } else {
            binaryMantissa += "0";
        }
    }
    return binaryMantissa;
}

int main() {
    cout << ToBinaryMantissa(0.8) << endl;
    return 0;
}