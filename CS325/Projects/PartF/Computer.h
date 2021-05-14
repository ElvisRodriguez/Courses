#ifndef COMPUTER_H
#define COMPUTER_H

#include "../PartA/Log.h"
#include "../PartB/Bus.h"
#include "../PartC/Memory.h"
#include "../PartE/Processor.h"

using namespace std;

class Computer {
    private:
        Computer(const Computer&);
        void operator = (const Computer&);
        Bus systemBus;
        Memory* memory;
        Processor* processor;
        Log* logger;
    public:
        Computer();
        Computer(Memory&, Processor&, Log&);
        void setMemory(Memory&);
        void setProcessor(Processor&);
        void setLogger(Log&);
        void Power();
};

Computer::Computer() {
    this->memory = NULL;
    this->processor = NULL;
    this->logger = NULL;
}

Computer::Computer(Memory& memory, Processor& processor, Log& logger) {
    this->memory = &memory;
    this->processor = &processor;
    this->logger = &logger;
}

void Computer::setMemory(Memory& memory) {
    this->memory = &memory;
}

void Computer::setProcessor(Processor& processor) {
    this->processor = &processor;
}

void Computer::setLogger(Log& logger) {
    this->logger = &logger;
}

void Computer::Power() {
    if (this->memory == NULL) return;
    if (this->processor == NULL) return;
    if (this->logger == NULL) return;
}

#endif //COMPUTER_H