#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "../PartA/Log.h"
#include "../PartB/Bus.h"
#include "Memory.h"

using namespace std;

void populateMemoryFile(string filename) {
    int lines = rand() % 224 + 32;
    fstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < 32; j++) {
                file << rand() % 2;
            }
            file << endl;
        }
    }
    file.close();
}

string getBusControlState(Bus &bus) {
    string signal;
    if (bus[32] && bus[33]) {
        signal = "success";
    }
    else if (!bus[32] && !bus[33]) {
        signal = "failure";
    }
    else if (bus[32] && !bus[33]) {
        signal = "write";
    }
    else if (!bus[32] && bus[33]) {
        signal = "read";
    }
    return signal;
}

int main() {
    srand(time(0));
    populateMemoryFile("memory.txt");
    Log logger("test_memory_logs.txt");
    Bus testBus;
    Memory memory;
    memory.setLogger(logger);
    memory.setBus(testBus);
    cout << "Giving bus an initial read signal...\n";
    testBus[32] = false;
    testBus[33] = true;
    for (int i = 0; i < 32; i++) {
        memory.Process();
        cout << "Processing result: " << getBusControlState(testBus) << endl;
        if (testBus[32] == testBus[33]) {
            testBus[32] = rand() % 2;
            testBus[33] = !testBus[32];
            cout << "Signal changed to: " << getBusControlState(testBus) << endl;
        }
    }
    return 0;
}