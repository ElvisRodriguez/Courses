#include <iostream>
#include <string>

using namespace std;

int binaryToInt(bool binary[]) {
    int value = 0;
    int multiplier = 1;
    for (int i = 0; i < 3; i++) {
        if (binary[i]) {
            value += multiplier;
        }
        multiplier *= 2;
    }
    return value;
}

string intToBinaryString(int value) {
    string binaryString = "";
    while (value > 0) {
        binaryString = to_string(value % 2) + binaryString;
        value /= 2;
    }
    return binaryString;
}

void MemoryIO(bool bus[], string memory[]) {
    /*
        If the control line of bus reads as 011:
        - Memory at the address of the bus address line is changed to the data
          from the bus data line.
        If the control line of bus reads as 101:
        - The bus data line is changed to the memory data at the address of the
          bus address line.
        The function does nothing for any other control line configuration.
    */
    bool control[] = {bus[0], bus[1], bus[2]};
    bool address[] = {bus[3], bus[4], bus[5]};
    bool data[] = {bus[6], bus[7], bus[8]};
    int lineNumber;
    string binaryString;
    if (binaryToInt(control) == 3) {
        lineNumber = binaryToInt(address);
        memory[lineNumber] = intToBinaryString(binaryToInt(data));
        bus[0] = bus[1] = bus[2] = true;
    }
    else if (binaryToInt(control) == 5) {
        lineNumber = binaryToInt(address);
        binaryString = memory[lineNumber];
        int data_index = 6;
        for (char bit: binaryString) {
            if (bit == '1') {
                bus[data_index] = true;
            } else {
                bus[data_index] = false;
            }
            data_index += 1;
        }
        bus[0] = bus[1] = bus[2] = true;
    }
}

int main() {
    bool bus[] = {true, false, true, false, true, true, true, true, false};
    string memory[] = {"000", "001","010", "011", "100", "101", "110", "111"};
    MemoryIO(bus, memory);
    if (bus[0] && bus[1] && bus[2]) {
        cout << "Successful memory read\n";
    } else {
        cout << "Memory I/O failure\n";
    }
    return 0;
}