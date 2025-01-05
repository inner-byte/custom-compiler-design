#ifndef REGISTER_ALLOCATOR_H
#define REGISTER_ALLOCATOR_H

#include "codegen.h"
#include <unordered_set>
#include <unordered_map>

// Linear scan register allocator
class LinearScanRegisterAllocator : public RegisterAllocator {
public:
    void allocateRegisters(Function& func) override;
    Register* getRegister(Value* value) override;
    void freeRegister(Register* reg) override;

private:
    std::vector<Register> registers;
    std::unordered_map<Value*, Register*> valueToRegister;
    std::set<Register*> freeRegisters;
};

#endif
