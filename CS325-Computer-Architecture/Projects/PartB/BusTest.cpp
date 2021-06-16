#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

#include "Bus.h"

#define BUS_WIDTH 32
#define LINE_COUNT 3

bool randomBit() {
    // Randomly generates a boolean representation of a bit.
    bool bit = rand() % 2;
    return bit;
}

void randomizeBusLines(Bus& bus) {
    // Populates the lines of a bus object with random bits.
    for (int i = 0; i < LINE_COUNT * BUS_WIDTH; i++) {
        bus[i] = randomBit();
    }
}

string buildBinaryString(Bus& bus, int lineType) {
    /*Builds a binary string representation of a line in a bus object.
      Args:
        lineType: integer in {0,1,2}.
                  0 represents the address line.
                  1 represents the control line.
                  2 represents the data line.  
    */
    string binaryString = "";
    for (int i = 0; i < BUS_WIDTH; i++) {
        int bit = bus[i + (lineType * BUS_WIDTH)];
        binaryString += to_string(bit);
    }
    return binaryString;
}

int main() {
    cout << "Testing average usage of Bus:\n";
    srand(time(0));
    Bus bus;
    randomizeBusLines(bus);
    string line_types[] = {"address", "control", "data   "};
    for (int i = 0; i < LINE_COUNT; i++) {
        cout << line_types[i] << " : " << buildBinaryString(bus, i) << endl;
    }

    cout << "\nTesting index bounds:\n";
    try {
        bus[BUS_WIDTH * LINE_COUNT];
        cout << "This string should not print.";
    }
    catch (const char* error) {
        cout << error << endl;
    }

    return 0;
}
