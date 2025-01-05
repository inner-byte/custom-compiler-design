#include "register_allocator.h"
#include <algorithm>

void LinearScanRegisterAllocator::allocateRegisters(Function& func) {
    // Initialize registers
    registers.clear();
    valueToRegister.clear();
    freeRegisters.clear();
    
    // Create physical registers
    for (int i = 0; i < 16; i++) {  // Assuming 16 general purpose registers
        registers.emplace_back(Register{i});
        freeRegisters.insert(&registers.back());
    }
    
    // Collect live intervals
    std::vector<std::pair<Value*, std::pair<int, int>>> liveIntervals;
    int currentPos = 0;
    
    for (auto& block : func.blocks) {
        for (auto& inst : block->instructions) {
            // Record uses
            for (Value* operand : inst->getOperands()) {
                auto it = valueToRegister.find(operand);
                if (it == valueToRegister.end()) {
                    liveIntervals.emplace_back(operand, std::make_pair(currentPos, currentPos));
                }
            }
            
            // Record definitions
            for (Value* result : inst->getResults()) {
                liveIntervals.emplace_back(result, std::make_pair(currentPos, currentPos));
            }
            
            currentPos++;
        }
    }
    
    // Sort intervals by start position
    std::sort(liveIntervals.begin(), liveIntervals.end(),
              [](const auto& a, const auto& b) {
                  return a.second.first < b.second.first;
              });
    
    // Allocate registers using linear scan
    for (auto& interval : liveIntervals) {
        Value* value = interval.first;
        
        // Free expired intervals
        for (auto it = valueToRegister.begin(); it != valueToRegister.end();) {
            if (it->second && it->second->isExpired(interval.second.first)) {
                freeRegister(it->second);
                it = valueToRegister.erase(it);
            } else {
                ++it;
            }
        }
        
        // Allocate register
        Register* reg = getRegister(value);
        if (reg) {
            valueToRegister[value] = reg;
            reg->setLiveInterval(interval.second.first, interval.second.second);
        }
    }
}

Register* LinearScanRegisterAllocator::getRegister(Value* value) {
    // First try to find a free register
    if (!freeRegisters.empty()) {
        Register* reg = *freeRegisters.begin();
        freeRegisters.erase(freeRegisters.begin());
        return reg;
    }
    
    // If no free registers, implement spilling
    // This is a simple implementation - in practice, you'd want more sophisticated spilling heuristics
    Register* spilledReg = nullptr;
    int latestEnd = -1;
    
    for (auto& [val, reg] : valueToRegister) {
        if (reg && reg->getEndPos() > latestEnd) {
            latestEnd = reg->getEndPos();
            spilledReg = reg;
        }
    }
    
    return spilledReg;
}

void LinearScanRegisterAllocator::freeRegister(Register* reg) {
    if (reg) {
        freeRegisters.insert(reg);
    }
}
