#ifndef MEMORY_H
#define MEMORY_H

#include <fstream>
#include <math.h>
#include <string>
#include <vector>

#include "../PartA/Log.h"
#include "../PartB/Bus.h"
#include "../PartD/Helper.h"

using namespace std;

#define ADDRESS_LINE 0
#define CONTROL_LINE 32
#define DATA_LINE 64
#define DEFAULT_FILENAME "memory.txt"

class Memory {
    private:
        Memory(const Memory&);
        void Read();
        void Write();
        void operator = (const Memory&);
        bool isBinaryString(string);
        int getLineNumber();
        Log *logger;
        Bus *bus;
        string filename;
    public:
        Memory();
        void setLogger(Log&);
        void setBus(Bus&);
        void setMemoryFile(string);
        bool Valid();
        void Process();
};

Memory::Memory() {
    logger = NULL;
    bus = NULL;
    filename = DEFAULT_FILENAME;
}

void Memory::Read() {
    /*
        Reads memory file at line number specified by bus address
        If line number exists in memory, read is successful and data at
            that line is read into the bus data line.
        If the read is successful, the first 3 bits of the bus control line
            are set to 101.
        If the read fails, the first 3 bits are set to 000.
    */
    int line_number = getLineNumber();
    int line_count = 0;
    bool success = false;
    string line;
    fstream memoryFile(filename);
    while (getline(memoryFile, line)) {
        if (line_count == line_number) {
            for (int i = 0; i < BUS_WIDTH; i++) {
                (*bus)[DATA_LINE + i] = line[i] == '1' ? true : false;
            }
            success = true;
            break;
        }
        line_count++;
    }
    if (success) {
        (*bus)[CONTROL_LINE] = (*bus)[CONTROL_LINE + 2] = true;
        (*bus)[CONTROL_LINE + 1] = false;
    }
    else {
        (*bus)[CONTROL_LINE] = (*bus)[CONTROL_LINE + 1] = (*bus)[CONTROL_LINE + 2] = false;
    }
}

void Memory::Write() {
    /*
        Writes data from bus data line to memory file at specified
            address from bus address line.
        If the write is successful, the first 3 bits of the bus control line
            are set to 010.
        If the write fails, the first 3 bits are set to 000.
    */
    string data = "";
    for (int i = 0; i < BUS_WIDTH; i++) {
        data += (*bus)[DATA_LINE + i] ? "1" : "0";
    }
    vector<string> tempFile;
    string line;
    fstream memoryFile(filename);
    while (getline(memoryFile, line)) {
        tempFile.push_back(line);
    }
    memoryFile.close();
    int lineNumber = getLineNumber();
    bool success = false;
    memoryFile.open(filename);
    for (int lineCount = 0; lineCount < tempFile.size(); lineCount++) {
        if (lineCount == lineNumber) {
            memoryFile << data << endl;
            success = true;
        }
        else {
            memoryFile << tempFile[lineCount] << endl;
        }
    }
    memoryFile.close();
    if (success) {
        (*bus)[CONTROL_LINE] = (*bus)[CONTROL_LINE + 2] = false;
        (*bus)[CONTROL_LINE + 1] = true;
    }
    else {
        (*bus)[CONTROL_LINE] = (*bus)[CONTROL_LINE + 1] = (*bus)[CONTROL_LINE + 2] = false;
    }
}

void Memory::setLogger(Log& logger) {
    this->logger = &logger;
}

void Memory::setBus(Bus& bus) {
    this->bus = &bus;
}

void Memory::setMemoryFile(string filename) {
    this->filename = filename; 
}

bool Memory::isBinaryString(string line) {
    for (char bit: line) {
        if (!(bit == '0' or bit == '1')) {
            if (bit != '\n') {
                return false;
            }
        }
    }
    return true;
}

int Memory::getLineNumber() {
    /*
        Converts bus address line into an integer based off the bits of
            the line, max line number is 2^32 % 256 for testing purposes.
    */
    int lineNumber = 0;
    for (int i = BUS_WIDTH - i; i >= 0; i--) {
        if ((*bus)[ADDRESS_LINE + i]) {
            int value = pow(2, i);
            lineNumber += value;
        }
    }
    return lineNumber;
}

bool Memory::Valid() {
    if (logger == NULL) return false;
    if (bus == NULL) return false;
    fstream memoryFile(filename);
    if (!memoryFile) {
        return false;
    }
    string line;
    while (getline(memoryFile, line)) {
        if (!(isBinaryString(line))) {
            return false;
        }
    }
    memoryFile.close();
    return true;
}

void Memory::Process() {
    /*
        If Valid() is true, Process calls Read() or Write() depending on the
        first 2 bits of the control line in the system bus:
        - 011: call Read(), change to 101 if successful, 000 otherwise.
        - 110: call Write(), change to 010 if successful, 000 otherwise.
    */
   if (Valid()) {
       if (!(*bus)[CONTROL_LINE] && (*bus)[CONTROL_LINE + 1] && (*bus)[CONTROL_LINE + 2]) {
           Read();
       }
       else if ((*bus)[CONTROL_LINE] && (*bus)[CONTROL_LINE + 1] && !(*bus)[CONTROL_LINE + 2]) {
           Write();
       }
   }
}

#endif //MEMORY_H