#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

#include "codegen.h"
#include <unordered_set>
#include <unordered_map>

// Optimization pass interface
class OptimizationPass {
public:
    virtual ~OptimizationPass() = default;
    virtual void runOnFunction(Function& func) = 0;
    virtual void runOnModule(Module& module) = 0;
};

// Dead code elimination pass
class DeadCodeElimination : public OptimizationPass {
public:
    void runOnFunction(Function& func) override;
    void runOnModule(Module& module) override;
};

// Constant folding pass
class ConstantFolding : public OptimizationPass {
public:
    void runOnFunction(Function& func) override;
    void runOnModule(Module& module) override;
};

// Common subexpression elimination pass
class CommonSubexpressionElimination : public OptimizationPass {
public:
    void runOnFunction(Function& func) override;
    void runOnModule(Module& module) override;
};

#endif
