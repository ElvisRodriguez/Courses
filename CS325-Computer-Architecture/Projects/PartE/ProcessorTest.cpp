#include <string>

#include "../PartA/Log.h"
#include "../PartB/Bus.h"
#include "../PartC/Memory.h"
#include "../PartD/Helper.h"
#include "Processor.h"

using namespace std;

int main() {
    Log log("processor_test_logs.txt");
    Bus bus;
    Memory memory;
    Processor processor;
    memory.setLogger(log);
    memory.setBus(bus);
    memory.setMemoryFile("memory.txt");
    processor.setExternalBus(bus);
    processor.setLogger(log);
    bus[32] = 0;
    bus[33] = bus[34] = 1;
    int count = 0;
    if (ProgramConverter("hex_memory.txt", "memory.txt")) {
        while (memory.Valid() && !(bus[32] == 0 && bus[33] == 0 && bus[34] == 0)) {
            memory.Process();
            processor.Process();
            memory.Process();
            if (count > 10) break;
            count++;
        }
    }
    return 0;
}