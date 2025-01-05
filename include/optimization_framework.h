#ifndef OPTIMIZATION_FRAMEWORK_H
#define OPTIMIZATION_FRAMEWORK_H

#include "codegen.h"
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>

// Analysis result interface
class AnalysisResult {
public:
    virtual ~AnalysisResult() = default;
};

// Analysis pass interface
class AnalysisPass {
public:
    virtual ~AnalysisPass() = default;
    virtual std::unique_ptr<AnalysisResult> analyze(const Function& func) = 0;
    virtual std::unique_ptr<AnalysisResult> analyze(const Module& module) = 0;
    virtual std::string getName() const = 0;
};

// Optimization pass with dependencies
class OptimizationPassWithDeps : public OptimizationPass {
public:
    virtual ~OptimizationPassWithDeps() = default;
    virtual std::vector<std::string> getDependencies() const = 0;
    virtual bool shouldRunOnFunction(const Function& func) const = 0;
    virtual bool shouldRunOnModule(const Module& module) const = 0;
};

// Data flow analysis framework
template<typename ValueType>
class DataFlowAnalysis : public AnalysisPass {
public:
    struct DataFlowResult : public AnalysisResult {
        std::unordered_map<BasicBlock*, ValueType> inValues;
        std::unordered_map<BasicBlock*, ValueType> outValues;
    };
    
    virtual ValueType initialValue() = 0;
    virtual ValueType boundary() = 0;
    virtual ValueType meet(const std::vector<ValueType>& values) = 0;
    virtual ValueType transfer(const BasicBlock& block, const ValueType& in) = 0;
    
    std::unique_ptr<AnalysisResult> analyze(const Function& func) override {
        auto result = std::make_unique<DataFlowResult>();
        bool changed;
        
        // Initialize
        for (const auto& block : func.blocks) {
            result->inValues[block.get()] = initialValue();
            result->outValues[block.get()] = initialValue();
        }
        
        // Iterate until fixed point
        do {
            changed = false;
            for (const auto& block : func.blocks) {
                // Meet operator for predecessors
                std::vector<ValueType> predValues;
                for (auto pred : block->predecessors) {
                    predValues.push_back(result->outValues[pred]);
                }
                
                // Compute new in value
                ValueType newIn = predValues.empty() ? boundary() : meet(predValues);
                if (newIn != result->inValues[block.get()]) {
                    result->inValues[block.get()] = newIn;
                    changed = true;
                }
                
                // Transfer function
                ValueType newOut = transfer(*block, newIn);
                if (newOut != result->outValues[block.get()]) {
                    result->outValues[block.get()] = newOut;
                    changed = true;
                }
            }
        } while (changed);
        
        return result;
    }
    
    std::unique_ptr<AnalysisResult> analyze(const Module& module) override {
        // Default implementation analyzes each function separately
        return nullptr;
    }
};

// Liveness analysis
class LivenessAnalysis : public DataFlowAnalysis<std::unordered_set<Value*>> {
public:
    std::string getName() const override { return "LivenessAnalysis"; }
    std::unordered_set<Value*> initialValue() override { return {}; }
    std::unordered_set<Value*> boundary() override { return {}; }
    
    std::unordered_set<Value*> meet(
        const std::vector<std::unordered_set<Value*>>& values) override {
        std::unordered_set<Value*> result;
        for (const auto& set : values) {
            result.insert(set.begin(), set.end());
        }
        return result;
    }
    
    std::unordered_set<Value*> transfer(
        const BasicBlock& block, 
        const std::unordered_set<Value*>& in) override;
};

// Reaching definitions analysis
class ReachingDefinitions : public DataFlowAnalysis<std::unordered_set<IRInstruction*>> {
public:
    std::string getName() const override { return "ReachingDefinitions"; }
    std::unordered_set<IRInstruction*> initialValue() override { return {}; }
    std::unordered_set<IRInstruction*> boundary() override { return {}; }
    
    std::unordered_set<IRInstruction*> meet(
        const std::vector<std::unordered_set<IRInstruction*>>& values) override {
        std::unordered_set<IRInstruction*> result;
        for (const auto& set : values) {
            result.insert(set.begin(), set.end());
        }
        return result;
    }
    
    std::unordered_set<IRInstruction*> transfer(
        const BasicBlock& block,
        const std::unordered_set<IRInstruction*>& in) override;
};

// Optimization manager
class OptimizationManager {
public:
    void addAnalysis(std::unique_ptr<AnalysisPass> analysis);
    void addOptimization(std::unique_ptr<OptimizationPassWithDeps> optimization);
    void optimize(Module& module);
    
    template<typename T>
    const T* getAnalysisResult(const Function& func) const {
        std::string name = T().getName();
        auto it = functionResults.find(&func);
        if (it != functionResults.end()) {
            auto resultIt = it->second.find(name);
            if (resultIt != it->second.end()) {
                return dynamic_cast<const T*>(resultIt->second.get());
            }
        }
        return nullptr;
    }

private:
    std::vector<std::unique_ptr<AnalysisPass>> analyses;
    std::vector<std::unique_ptr<OptimizationPassWithDeps>> optimizations;
    std::unordered_map<
        const Function*,
        std::unordered_map<std::string, std::unique_ptr<AnalysisResult>>
    > functionResults;
    
    void runAnalysis(AnalysisPass* analysis, const Function& func);
    void runOptimization(OptimizationPassWithDeps* opt, Module& module);
    bool checkDependencies(const OptimizationPassWithDeps* opt) const;
};

#endif
