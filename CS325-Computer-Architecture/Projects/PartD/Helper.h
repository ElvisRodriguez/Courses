#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define OUTPUT_FILE "binary_program.txt"

string decimalToBinary(int decimal) {
    string binaryString = "";
    while (decimal > 0) {
        binaryString = to_string(decimal % 2) + binaryString;
        decimal /= 2;
    }
    while (binaryString.length() < 4) {
        binaryString = '0' + binaryString;
    }
    return binaryString;
}

string hexToBinary(char hexBit) {
    int decimal = -1;
    string hexLetters = "ABCDEF";
    for (int i = 0; i < hexLetters.length(); i++) {
        if (hexBit == hexLetters[i]) {
            decimal = i + 10;
            break;
        }
    }
    if (decimal < 0) {
        decimal = hexBit - '0';
    }
    return decimalToBinary(decimal);
}

bool ProgramConverter(string filename, string output=OUTPUT_FILE) {
    fstream inputFile(filename, ios::in);
    string line;
    vector<string> outputLines;
    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            string outputLine = "";
            for (char hexBit: line) {
                if (hexBit != '\n') {
                    outputLine += hexToBinary(hexBit);
                }
            }
            outputLines.push_back(outputLine);
        }
    } else {
        return false;
    }
    fstream outputFile(output, ios::out);
    if (outputFile.is_open()) {
        for (string line: outputLines) {
            outputFile << line << endl;
        }
    } else {
        return false;
    }
    return true;
}

void debug(string output) {
    cout << output << endl;
}

#endif //HELPER_H