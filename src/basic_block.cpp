#include "../include/codegen.h"
#include <algorithm>

void BasicBlock::addInstruction(std::unique_ptr<IRInstruction> inst) {
    instructions.push_back(std::move(inst));
}

void BasicBlock::addPredecessor(BasicBlock* pred) {
    if (std::find(predecessors.begin(), predecessors.end(), pred) == predecessors.end()) {
        predecessors.push_back(pred);
    }
}

void BasicBlock::addSuccessor(BasicBlock* succ) {
    if (std::find(successors.begin(), successors.end(), succ) == successors.end()) {
        successors.push_back(succ);
    }
}
