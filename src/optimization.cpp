#include "optimization.h"
#include <unordered_set>
#include <unordered_map>

// Dead Code Elimination Pass
void DeadCodeElimination::runOnFunction(Function& func) {
    bool changed;
    do {
        changed = false;
        std::unordered_set<BasicBlock*> reachable;
        std::vector<BasicBlock*> workList;
        
        // Start from entry block
        if (!func.blocks.empty()) {
            workList.push_back(func.blocks[0].get());
            reachable.insert(func.blocks[0].get());
        }
        
        // Find all reachable blocks
        while (!workList.empty()) {
            BasicBlock* block = workList.back();
            workList.pop_back();
            
            for (BasicBlock* succ : block->successors) {
                if (reachable.insert(succ).second) {
                    workList.push_back(succ);
                }
            }
        }
        
        // Remove unreachable blocks
        auto it = func.blocks.begin();
        while (it != func.blocks.end()) {
            if (reachable.count(it->get()) == 0) {
                it = func.blocks.erase(it);
                changed = true;
            } else {
                ++it;
            }
        }
        
        // Remove dead instructions within blocks
        for (auto& block : func.blocks) {
            auto instIt = block->instructions.begin();
            while (instIt != block->instructions.end()) {
                bool isDead = true;
                
                // Check if instruction results are used
                for (Value* result : (*instIt)->getResults()) {
                    for (auto& otherBlock : func.blocks) {
                        for (auto& otherInst : otherBlock->instructions) {
                            for (Value* operand : otherInst->getOperands()) {
                                if (operand == result) {
                                    isDead = false;
                                    break;
                                }
                            }
                            if (!isDead) break;
                        }
                        if (!isDead) break;
                    }
                    if (!isDead) break;
                }
                
                // Remove dead instruction
                if (isDead && !(*instIt)->isTerminator()) {
                    instIt = block->instructions.erase(instIt);
                    changed = true;
                } else {
                    ++instIt;
                }
            }
        }
    } while (changed);
}

void DeadCodeElimination::runOnModule(Module& module) {
    for (auto& func : module.functions) {
        runOnFunction(*func);
    }
}

// Constant Folding Pass
void ConstantFolding::runOnFunction(Function& func) {
    bool changed;
    do {
        changed = false;
        
        for (auto& block : func.blocks) {
            auto instIt = block->instructions.begin();
            while (instIt != block->instructions.end()) {
                bool folded = false;
                
                // Try to evaluate constant expressions
                // This is a placeholder - actual implementation would handle specific IR instructions
                
                if (folded) {
                    changed = true;
                    instIt = block->instructions.erase(instIt);
                } else {
                    ++instIt;
                }
            }
        }
    } while (changed);
}

void ConstantFolding::runOnModule(Module& module) {
    for (auto& func : module.functions) {
        runOnFunction(*func);
    }
}

// Common Subexpression Elimination Pass
struct ExpressionHash {
    size_t operator()(const IRInstruction* inst) const {
        // Hash based on instruction type and operands
        size_t hash = std::hash<std::string>{}(inst->toString());
        for (Value* operand : inst->getOperands()) {
            hash ^= std::hash<Value*>{}(operand) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct ExpressionEqual {
    bool operator()(const IRInstruction* lhs, const IRInstruction* rhs) const {
        // Compare instruction type and operands
        if (lhs->toString() != rhs->toString()) return false;
        auto lhsOps = lhs->getOperands();
        auto rhsOps = rhs->getOperands();
        if (lhsOps.size() != rhsOps.size()) return false;
        for (size_t i = 0; i < lhsOps.size(); ++i) {
            if (lhsOps[i] != rhsOps[i]) return false;
        }
        return true;
    }
};

void CommonSubexpressionElimination::runOnFunction(Function& func) {
    bool changed;
    do {
        changed = false;
        std::unordered_map<IRInstruction*, Value*, ExpressionHash, ExpressionEqual> availableExpr;
        
        for (auto& block : func.blocks) {
            auto instIt = block->instructions.begin();
            while (instIt != block->instructions.end()) {
                auto* inst = instIt->get();
                
                // Look for available expression
                auto it = availableExpr.find(inst);
                if (it != availableExpr.end()) {
                    // Replace instruction results with available value
                    auto results = inst->getResults();
                    if (!results.empty()) {
                        // This is a placeholder - actual implementation would handle value replacement
                        changed = true;
                    }
                    instIt = block->instructions.erase(instIt);
                } else {
                    // Add to available expressions
                    auto results = inst->getResults();
                    if (!results.empty()) {
                        availableExpr[inst] = results[0];
                    }
                    ++instIt;
                }
            }
        }
    } while (changed);
}

void CommonSubexpressionElimination::runOnModule(Module& module) {
    for (auto& func : module.functions) {
        runOnFunction(*func);
    }
}
