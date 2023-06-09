#include "Memory.h"
#include "CPU.h"

CPU oneCPU;

size_t Memory::address1 = 0;

Memory::Memory(){resize(100);}

template <class T>
void Memory::allocateMemory(T val, size_t &address){
    address1 += sizeof(T);
    address = address1;
    oneCPU.store(val,address1);
}

template <class T>
//Thank you to stackExchange for this clever method.
T& Memory::getVal(size_t address){ //Returns a reference but after casting
    return *(T*)(register1.data()+ address) ;//Points to the first element then indexes. Casts to the correct type.
    // Data points to first element.
}

void Memory::resize(size_t size) {
    register1.resize(size);
}
Memory::~Memory() {}

template int& Memory::getVal(size_t address);
template float& Memory::getVal(size_t address);
template double& Memory::getVal(size_t address);


template void Memory::allocateMemory(int val, size_t &address);
template void Memory::allocateMemory(float val, size_t &address);
template void Memory::allocateMemory(double val, size_t &address);