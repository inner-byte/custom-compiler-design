#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"
#include "type_system.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <set>

// Forward declarations
class BasicBlock;
class Function;
class Module;
class Value;
class Instruction;

// Target platform specification
enum class Platform {
    X86_64,
    ARM64,
    WASM
};

enum class OptimizationLevel {
    O0,  // No optimization
    O1,  // Basic optimizations
    O2,  // Moderate optimizations
    O3   // Aggressive optimizations
};

// Instruction types for IR
enum class IRInstructionType {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    AND,
    OR,
    XOR,
    NOT,
    NEG,
    LOAD,
    STORE,
    CALL,
    RET,
    BR,
    BR_COND,
    PHI,
    ALLOCA,
    GETELEMENTPTR,
    BITCAST
};

// Register class for different types of registers
enum class RegisterClass {
    GENERAL_PURPOSE,
    FLOATING_POINT,
    VECTOR
};

// Register descriptor
class Register {
public:
    Register(int regId) : 
        name("r" + std::to_string(regId)),
        regClass(RegisterClass::GENERAL_PURPOSE),
        isAllocated(false),
        currentValue(nullptr),
        startPos(-1),
        endPos(-1) {}
    
    void setLiveInterval(int start, int end) {
        startPos = start;
        endPos = end;
    }
    
    bool isExpired(int currentPos) const {
        return endPos < currentPos;
    }
    
    int getEndPos() const { return endPos; }
    
    std::string name;
    RegisterClass regClass;
    bool isAllocated;
    Value* currentValue;
    
private:
    int startPos;
    int endPos;
};

// Memory location descriptor
struct MemoryLocation {
    size_t offset;
    size_t size;
    bool isStack;
    bool isGlobal;
    std::string name;
};

// Intermediate representation instruction
class IRInstruction {
public:
    IRInstructionType type;
    std::string result;
    std::string operand1;
    std::string operand2;
    std::vector<std::string> callArgs; // For CALL instructions

    IRInstruction(IRInstructionType type = IRInstructionType::ADD,
                 const std::string& result = "",
                 const std::string& op1 = "",
                 const std::string& op2 = "")
        : type(type), result(result), operand1(op1), operand2(op2) {}

    virtual ~IRInstruction() = default;
    
    virtual std::string toString() const {
        std::string opcode;
        switch (type) {
            case IRInstructionType::ADD: opcode = "add"; break;
            case IRInstructionType::SUB: opcode = "sub"; break;
            case IRInstructionType::MUL: opcode = "mul"; break;
            case IRInstructionType::DIV: opcode = "div"; break;
            case IRInstructionType::MOD: opcode = "mod"; break;
            case IRInstructionType::AND: opcode = "and"; break;
            case IRInstructionType::OR: opcode = "or"; break;
            case IRInstructionType::XOR: opcode = "xor"; break;
            case IRInstructionType::NOT: opcode = "not"; break;
            case IRInstructionType::NEG: opcode = "neg"; break;
            case IRInstructionType::LOAD: opcode = "load"; break;
            case IRInstructionType::STORE: opcode = "store"; break;
            case IRInstructionType::CALL: opcode = "call"; break;
            case IRInstructionType::RET: opcode = "ret"; break;
            case IRInstructionType::BR: opcode = "br"; break;
            case IRInstructionType::BR_COND: opcode = "br_cond"; break;
            case IRInstructionType::PHI: opcode = "phi"; break;
            case IRInstructionType::ALLOCA: opcode = "alloca"; break;
            case IRInstructionType::GETELEMENTPTR: opcode = "getelementptr"; break;
            case IRInstructionType::BITCAST: opcode = "bitcast"; break;
        }

        if (type == IRInstructionType::CALL) {
            std::string args;
            for (const auto& arg : callArgs) {
                if (!args.empty()) args += ", ";
                args += arg;
            }
            return result + " = " + opcode + " " + operand1 + "(" + args + ")";
        } else {
            return result + " = " + opcode + " " + operand1 + " " + operand2;
        }
    }

    virtual std::vector<Value*> getOperands() const { return {}; }
    virtual std::vector<Value*> getResults() const { return {}; }
    virtual bool isTerminator() const { 
        return type == IRInstructionType::RET || 
               type == IRInstructionType::BR || 
               type == IRInstructionType::BR_COND; 
    }
};

// Basic block in control flow graph
class BasicBlock {
public:
    std::string name;
    std::vector<std::unique_ptr<IRInstruction>> instructions;
    std::vector<BasicBlock*> predecessors;
    std::vector<BasicBlock*> successors;

    void addInstruction(std::unique_ptr<IRInstruction> inst);
    void addPredecessor(BasicBlock* pred);
    void addSuccessor(BasicBlock* succ);
};

// Function representation
class Function {
public:
    std::string name;
    Type* returnType;
    std::vector<std::pair<std::string, Type*>> parameters;
    std::vector<std::unique_ptr<BasicBlock>> blocks;
    std::unordered_map<std::string, MemoryLocation> localVariables;
    size_t stackSize;
};

// Module containing all functions and global variables
class Module {
public:
    std::vector<std::unique_ptr<Function>> functions;
    std::unordered_map<std::string, MemoryLocation> globalVariables;
    
    Function* getCurrentFunction() { 
        return functions.empty() ? nullptr : functions.back().get(); 
    }
};

// Register allocator interface
class RegisterAllocator {
public:
    virtual ~RegisterAllocator() = default;
    virtual void allocateRegisters(Function& func) = 0;
    virtual Register* getRegister(Value* value) = 0;
    virtual void freeRegister(Register* reg) = 0;
};

// Code generator main class
class CodeGenerator {
public:
    CodeGenerator();
    
    void initialize();
    void generateDeclarations(const std::vector<std::unique_ptr<ASTNode>>& declarations);
    void generateStatement(ASTNode* node);
    void generateBinaryOperation(BinaryOpNode* binOp);
    void generateUnaryOperation(UnaryOpNode* unaryOp);
    void generateFunctionCall(FunctionCallNode* funcCall);
    std::string generateExpression(ASTNode* node);
    
    Module* generateModule(ProgramNode* program);
    std::string generateARM64Code(Module* module);
    std::string generateWASMCode(Module* module);
    void optimize(Module* module);
    void dumpIR() const;
    void enableOptimization(const std::string& passName, bool enable = true);

private:
    std::vector<std::unique_ptr<BasicBlock>> basicBlocks;
    std::vector<std::unique_ptr<IRInstruction>> instructions;
    Function* currentFunction;
    BasicBlock* currentBlock;
    int tempVarCounter = 0;

    BasicBlock* createBasicBlock(const std::string& name = "");
    IRInstruction* createInstruction(IRInstructionType type,
                                   const std::string& result = "",
                                   const std::string& op1 = "",
                                   const std::string& op2 = "");
    void generateVariableDeclaration(VariableDeclNode* varDecl);
    void generateFunctionDefinition(FunctionDeclNode* funcDef);
};

#endif
