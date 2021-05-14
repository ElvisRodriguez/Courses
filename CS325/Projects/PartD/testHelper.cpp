#include <iostream>
#include <string>

using namespace std;

#include "Helper.h"

int main() {
    string filename = "hex_program.txt";
    if (ProgramConverter((filename))) {
        cout << "Program Converted\n";
    } else {
        cout << "Conversion Error\n";
    }
    return 0;
}