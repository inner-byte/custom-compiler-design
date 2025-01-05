#include "codegen.h"
#include <sstream>
#include <iostream>

CodeGenerator::CodeGenerator() {
    initialize();
}

void CodeGenerator::initialize() {
    // Clear any existing state
    instructions.clear();
    basicBlocks.clear();
    currentFunction = nullptr;
    currentBlock = nullptr;
    tempVarCounter = 0;
}

BasicBlock* CodeGenerator::createBasicBlock(const std::string& name) {
    auto block = new BasicBlock();
    block->name = name;
    basicBlocks.push_back(std::unique_ptr<BasicBlock>(block));
    return block;
}

IRInstruction* CodeGenerator::createInstruction(IRInstructionType type,
                                              const std::string& result,
                                              const std::string& op1,
                                              const std::string& op2) {
    auto inst = new IRInstruction(type, result, op1, op2);
    instructions.push_back(std::unique_ptr<IRInstruction>(inst));
    return inst;
}

void CodeGenerator::generateDeclarations(const std::vector<std::unique_ptr<ASTNode>>& declarations) {
    for (const auto& decl : declarations) {
        if (auto* varDecl = dynamic_cast<VariableDeclNode*>(decl.get())) {
            generateVariableDeclaration(varDecl);
        }
    }

    for (const auto& def : declarations) {
        if (auto* funcDef = dynamic_cast<FunctionDeclNode*>(def.get())) {
            generateFunctionDefinition(funcDef);
        }
    }
}

void CodeGenerator::generateVariableDeclaration(VariableDeclNode* varDecl) {
    // Handle global variable declaration
    std::string varName = varDecl->name;
    // Add to symbol table or generate appropriate IR
}

void CodeGenerator::generateFunctionDefinition(FunctionDeclNode* funcDef) {
    currentFunction = new Function();
    currentFunction->name = funcDef->name;

    currentBlock = createBasicBlock("entry");
    currentFunction->blocks.push_back(std::unique_ptr<BasicBlock>(currentBlock));

    // Try to get the function body from either FunctionDeclNode or FunctionDefNode
    ASTNode* funcBody = nullptr;
    if (auto* funcDefNode = dynamic_cast<FunctionDefNode*>(funcDef)) {
        funcBody = funcDefNode->block;
    }

    if (auto* blockNode = dynamic_cast<BlockNode*>(funcBody)) {
        for (const auto& stmt : blockNode->statements) {
            generateStatement(stmt);
        }
    }
}

Module* CodeGenerator::generateModule(ProgramNode* program) {
    auto module = new Module();

    // Convert program->declarations to vector of unique_ptrs
    std::vector<std::unique_ptr<ASTNode>> declarations;
    for (auto* decl : program->declarations) {
        declarations.push_back(std::unique_ptr<ASTNode>(decl));
    }

    // Generate IR for all declarations
    generateDeclarations(declarations);

    return module;
}

void CodeGenerator::generateStatement(ASTNode* node) {
    if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
        generateBinaryOperation(binOp);
    } else if (auto* unaryOp = dynamic_cast<UnaryOpNode*>(node)) {
        generateUnaryOperation(unaryOp);
    } else if (auto* varDecl = dynamic_cast<VariableDeclNode*>(node)) {
        generateVariableDeclaration(varDecl);
    } else if (auto* funcCall = dynamic_cast<FunctionCallNode*>(node)) {
        generateFunctionCall(funcCall);
    }
}

void CodeGenerator::generateBinaryOperation(BinaryOpNode* binOp) {
    auto op1 = generateExpression(binOp->left);
    auto op2 = generateExpression(binOp->right);

    IRInstructionType instType;
    if (binOp->op == "+") instType = IRInstructionType::ADD;
    else if (binOp->op == "-") instType = IRInstructionType::SUB;
    else if (binOp->op == "*") instType = IRInstructionType::MUL;
    else if (binOp->op == "/") instType = IRInstructionType::DIV;
    else return; // Unsupported operation

    std::string resultVar = "%" + std::to_string(tempVarCounter++);
    createInstruction(instType, resultVar, op1, op2);
}

void CodeGenerator::generateUnaryOperation(UnaryOpNode* unaryOp) {
    auto operand = generateExpression(unaryOp->operand);

    IRInstructionType instType;
    if (unaryOp->op == "-") instType = IRInstructionType::NEG;
    else if (unaryOp->op == "!") instType = IRInstructionType::NOT;
    else return; // Unsupported operation

    std::string resultVar = "%" + std::to_string(tempVarCounter++);
    createInstruction(instType, resultVar, operand, "");
}

void CodeGenerator::generateFunctionCall(FunctionCallNode* funcCall) {
    std::vector<std::string> args;
    for (auto* arg : *funcCall->arguments) {
        args.push_back(generateExpression(arg));
    }

    std::string resultVar = "%" + std::to_string(tempVarCounter++);
    // Create CALL instruction with function name and arguments
    auto inst = createInstruction(IRInstructionType::CALL, resultVar, funcCall->name, "");
    inst->callArgs = args;
}

std::string CodeGenerator::generateExpression(ASTNode* node) {
    if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
        auto op1 = generateExpression(binOp->left);
        auto op2 = generateExpression(binOp->right);

        IRInstructionType instType;
        if (binOp->op == "+") instType = IRInstructionType::ADD;
        else if (binOp->op == "-") instType = IRInstructionType::SUB;
        else if (binOp->op == "*") instType = IRInstructionType::MUL;
        else if (binOp->op == "/") instType = IRInstructionType::DIV;
        else return ""; // Unsupported operation

        std::string resultVar = "%" + std::to_string(tempVarCounter++);
        createInstruction(instType, resultVar, op1, op2);
        return resultVar;
    } else if (auto* unaryOp = dynamic_cast<UnaryOpNode*>(node)) {
        auto operand = generateExpression(unaryOp->operand);

        IRInstructionType instType;
        if (unaryOp->op == "-") instType = IRInstructionType::NEG;
        else if (unaryOp->op == "!") instType = IRInstructionType::NOT;
        else return ""; // Unsupported operation

        std::string resultVar = "%" + std::to_string(tempVarCounter++);
        createInstruction(instType, resultVar, operand, "");
        return resultVar;
    } else if (auto* id = dynamic_cast<IDNode*>(node)) {
        return id->name;
    } else if (auto* intLit = dynamic_cast<IntegerLiteralNode*>(node)) {
        return std::to_string(intLit->value);
    } else if (auto* realLit = dynamic_cast<RealLiteralNode*>(node)) {
        return std::to_string(realLit->value);
    } else if (auto* strLit = dynamic_cast<StringLiteralNode*>(node)) {
        return "\"" + strLit->value + "\"";
    } else if (auto* boolLit = dynamic_cast<BooleanLiteralNode*>(node)) {
        return boolLit->value ? "true" : "false";
    }
    return "";
}

std::string CodeGenerator::generateARM64Code(Module* module) {
    std::stringstream output;
    // TODO: Implement ARM64 code generation
    return output.str();
}

std::string CodeGenerator::generateWASMCode(Module* module) {
    std::stringstream output;
    // TODO: Implement WebAssembly code generation
    return output.str();
}

void CodeGenerator::optimize(Module* module) {
    // TODO: Implement optimization passes
}

void CodeGenerator::dumpIR() const {
    for (const auto& inst : instructions) {
        // Print instruction in text format
        std::cout << inst->toString() << std::endl;
    }
}

void CodeGenerator::enableOptimization(const std::string& passName, bool enable) {
    // TODO: Enable/disable specific optimization passes
}
