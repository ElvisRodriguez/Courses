#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <vector>

#define DEFAULT_LOG_FILENAME "logs.txt"

using namespace std;

class Log {
    private:
        string filename;
        ofstream output;
        ifstream input;
        bool checkBinaryString(string);
    public:
        Log();
        Log(string);
        void write(string, string);
        void write(string, vector<bool>&);
        void write(string, bool*, int);

};

Log::Log() {
    /*
        If filename is not provided, DEFAULT_FILENAME will be used instead.
    */
    this->filename = DEFAULT_LOG_FILENAME;
}

Log::Log(string filename) {
    /*
        filename must be a .txt file, will fallback to DEFAULT_FILENAME
        if it is not.
    */
    if (filename.find(".txt") != string::npos) {
        this->filename = filename;
    }
    else {
        this->filename = DEFAULT_LOG_FILENAME;
    }
}

bool Log::checkBinaryString(string binaryString) {
    /*
        Verifies that binaryString is a string consisting of only 0s and 1s.
    */
    if (binaryString == "") {
        return false;
    }
    for (char c: binaryString) {
        if (c != '1' && c != '0') {
            return false;
        }
    }
    return true;
}

void Log::write(string identifier, string binaryString) {
    /*
        Writes binaryString with identifier identifier to this->filename if
        and only if binaryString is a proper binary string.
    */
    if (checkBinaryString(binaryString)) {
        this->output.open(this->filename, ofstream::app);
        this->output << identifier << " " << binaryString << endl;
        this->output.close();
    }
}

void Log::write(string identifier, vector<bool>& binaryArray) {
    /*
        Converts binaryArray to a binary string then passes binaryString to
        Log::write(string).
    */
    string binaryString = "";
    for (bool binaryDigit: binaryArray) {
        if (binaryDigit) {
            binaryString += "1";
        } else {
            binaryString += "0";
        }
    }
    write(identifier, binaryString);
}

void Log::write(string identifier, bool binaryArray[], int size) {
    /*
        Converts binaryArray to a binary string then passes binaryString to
        Log::write(string).
    */
    string binaryString = "";
    for (int i = 0; i < size; i++) {
        if (binaryArray[i]) {
            binaryString += "1";
        } else {
            binaryString += "0";
        }
    }
    write(identifier, binaryString);
}

#endif //LOG_H
