#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "../PartA/Log.h"
#include "../PartB/Bus.h"

#define ADDRESS_LINE 0
#define CONTROL_LINE 32
#define DATA_LINE 64
#define OP_SIZE 8
#define SIZE 32

using namespace std;

class Processor {
    private:
        Processor(const Processor&);
        void operator = (const Processor&);
        void ALU();
        void Control();
        void Valid();
        void incrementPC();

        Bus internalBus;
        Bus *externalBus;
        Log *Logger;
        bool accumulator[SIZE];
        bool instructionRegister[OP_SIZE];
        bool memoryAddressRegister[SIZE];
        bool multiplierQuotient[SIZE];
        bool programCounter[SIZE];
    public:
        Processor();
        void setExternalBus(Bus&);
        void setLogger(Log&);
        void Process();
};

Processor::Processor() {
    this->externalBus = NULL;
    for (int i = 0; i < SIZE; i++) {
        if (i < OP_SIZE) this->instructionRegister[i] = 0;
        this->accumulator[i] = 0;
        this->memoryAddressRegister[i] = 0;
        this->multiplierQuotient[i] = 0;
        this->programCounter[i] = 0;
    }
}

void Processor::setExternalBus(Bus& bus) {
    this->externalBus = &bus;
}

void Processor::setLogger(Log& log) {
    this->Logger = &log;
}

void Processor::Process() {
    this->Valid();
    for (int i = 0; i < SIZE; i++) {
        if (this->internalBus[i]) return;
    }
    this->Control();
}

void Processor::Valid() {
    /*
        Assigns a success or failure signal to internal bus depending on the
            state of the external bus
        NULL external bus = Failure = 11111111111111111111111111111111
        !NULL external bus = Success = 00000000000000000000000000000000
    */
    bool signal = this->externalBus == NULL ? 1: 0;
    for (int i = 0; i < SIZE; i++) {
        this->internalBus[CONTROL_LINE + i] = signal;
    }
}

void Processor::incrementPC() {
    for (int i = SIZE - 1; i > 0; i--) {
        if (this->programCounter[i]) {
            programCounter[i] = 0;
        } else {
            this->programCounter[i] = 1;
            break;
        }
    }
}

void Processor::Control() {
    // Flag for stopping external bus address rewrite if memory is being overwritten
    bool writeMode = false;
    if (!(*externalBus)[32] && (*externalBus)[33] && !(*externalBus)[34]) {
        // If memory was just written to, change bus so that it points to next
        // instruction in memory
        for (int i = 0; i < SIZE; i++) {
            (*externalBus)[ADDRESS_LINE + i] = this->programCounter[i];
        }
        // Change control line to read mode
        (*externalBus)[32] = 0;
        (*externalBus)[33] = (*externalBus)[34] = 1;
        return;
    }
    //Extract data from external bus lines:
    //0-31 = address line, 32-63 = control line, 64-95 = data line
    for (int i = 0; i < SIZE; i++) {
        if (i < OP_SIZE) {
            this->instructionRegister[i] = (*externalBus)[DATA_LINE + i];
        }
        else {
            this->internalBus[DATA_LINE + i] = (*externalBus)[DATA_LINE + i];
        }
        this->memoryAddressRegister[i] = (*externalBus)[i];
        //(*Logger).write("external bus address: ", this->memoryAddressRegister, SIZE);
        //(*Logger).write("external bus OP CODE: ", this->instructionRegister, OP_SIZE);
    }
    //Decode op code from IR, op code capacity is 8 bits, but we only have
    //16 instructions and therefore need only look at the last 4 bits
    bool opcode[4];
    for (int i = 0; i < 4; i++) {
        opcode[i] = this->instructionRegister[i+4];
    }
    //Opcode 00000000: HALT
    if (!opcode[0] && !opcode[1] && !opcode[2] && !opcode[3]) {
        (*externalBus)[32] = (*externalBus)[33] = 0;
        return;
    }
    //Opcode 00000001: STORE A
    else if (!opcode[0] && !opcode[1] && !opcode[2] && opcode[3]) {
        writeMode = true;
        for (int i = 0; i < SIZE; i++) {
            (*externalBus)[ADDRESS_LINE + i] = this->internalBus[DATA_LINE + i];
            (*externalBus)[DATA_LINE + i] = this->accumulator[i];
        }
    }
    //Opcode 00000010: STORE MQ,A
    else if (!opcode[0] && !opcode[1] && opcode[2] && !opcode[3]) {
        writeMode = true;
        for (int i = 0; i < SIZE; i++) {
            (*externalBus)[ADDRESS_LINE + i] = this->internalBus[DATA_LINE + i];
            (*externalBus)[DATA_LINE + i] = this->multiplierQuotient[i];
        }
    }
    //Opcode 00000011: LOAD A
    else if (!opcode[0] && !opcode[1] && opcode[2] && opcode[3]) {
        for (int i = 0; i < SIZE; i++) {
            this->accumulator[i] = this->internalBus[DATA_LINE + i];
        }
    }
    //Opcode 00000100: LOAD MQ,A
    else if (!opcode[0] && opcode[1] && !opcode[2] && !opcode[3]) {
        for (int i = 0; i < SIZE; i++) {
            this->multiplierQuotient[i] = this->internalBus[DATA_LINE + i];
        }
    }
    //Opcode 00000101: MOVE A,B
    else if (!opcode[0] && opcode[1] && !opcode[2] && opcode[3]) {
        writeMode = true;
        for (int i = 0; i < SIZE; i++) {
            (*externalBus)[ADDRESS_LINE + i] = this->internalBus[DATA_LINE + i];
        }
    }
    //Opcode 00000110: LOAD MQ
    else if (!opcode[0] && opcode[1] && opcode[2] && !opcode[3]) {
        for (int i = 0; i < SIZE; i++) {
            this->accumulator[i] = this->multiplierQuotient[i];
        }
    }
    //All other opcodes belong to the ALU
    else {
        this->ALU();
    }
    
    this->incrementPC();
    if (!writeMode) {
        //Give bus next address in memory
        for (int i = 0; i < SIZE; i++) {
            (*externalBus)[ADDRESS_LINE + i] = this->programCounter[i];
        }
        // Set bus control line to read mode
        (*externalBus)[32] = 0;
        (*externalBus)[33] = (*externalBus)[34] = 1;
    } else {
        // Set bus control line to write mode
        (*externalBus)[32] = (*externalBus)[33] = 1;
        (*externalBus)[34] = 0;
    }
    return;
}

void Processor::ALU() {
    bool opcode[4];
    for (int i = 0; i < 4; i++) {
        opcode[i] = this->instructionRegister[i+4];
    }
    //Opcode 00000111: ADD A
    if (!opcode[0] && opcode[1] && opcode[2] && opcode[3]) {
        bool carry = 0;
        for (int i = SIZE - 1; i >= 0; i--) {
            if (this->accumulator[i] && this->internalBus[DATA_LINE + i]) {
                carry = 1;
                this->accumulator[i] = 0;
            }
            else if (this->accumulator[i] ^ this->internalBus[DATA_LINE + i]) {
                this->accumulator[i] = 1;
                if (carry) {
                    this->accumulator[i] = 0;
                }
            }
            else if (!this->accumulator[i] && !this->internalBus[DATA_LINE + i]) {
                if (carry) {
                    this->accumulator[i] = 1;
                    carry = 0;
                }
            }
        }
    }
    //Opcode 00001000: SUB A
    if (opcode[0] && !opcode[1] && !opcode[2] && !opcode[3]) {
        bool borrow = 0;
        for (int i = SIZE - 1; i >= 0; i--) {
            if (this->accumulator[i] && this->internalBus[DATA_LINE + i]) {
                this->accumulator[i] = 0;
            }
            else if (this->accumulator[i] && !this->internalBus[DATA_LINE + i] && borrow) {
                this->accumulator[i] = 0;
            }
            else if (!this->accumulator[i] && this->internalBus[DATA_LINE + i]) {
                if (borrow) {
                    this->accumulator[i] = 1;
                    borrow = 0;
                }
                else {
                    borrow = 1;
                }
            }
        }
    }
    //Opcode 00001100: MULT A
    if (opcode[0] && opcode[1] && !opcode[2] && !opcode[3]) {
        //TODO
    }
    //Opcode 00001101: DIV A
    if (opcode[0] && opcode[1] && !opcode[2] && opcode[3]) {
        //TODO
    }
    //Opcode 00001110: LEFT_SHIFT
    if (opcode[0] && opcode[1] && opcode[2] && !opcode[3]) {
        for (int i = 0; i < SIZE - 1; i++) {
            this->accumulator[i] = this->accumulator[i+1];
        }
        this->accumulator[SIZE - 1] = 0;
    }
    //Opcode 00001111: RIGHT_SHIFT
    if (opcode[0] && opcode[1] && opcode[2] && opcode[3]) {
        for (int i = SIZE - 2; i > 0; i--) {
            this->accumulator[i] = this->accumulator[i-1];
        }
        this->accumulator[0] = 0;
    }
}

#endif //PROCESSOR_H