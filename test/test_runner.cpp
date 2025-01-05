#include <iostream>
#include <cassert>
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/type_system.h"
#include "../include/codegen.h"
#include "../include/runtime.h"
#include "../include/optimization_framework.h"

void testLexer(const std::string& sourceFile) {
    std::cout << "Testing Lexer..." << std::endl;
    
    Lexer lexer(sourceFile);
    Token token;
    while ((token = lexer.getNextToken()).type != TokenType::END_OF_FILE) {
        std::cout << "Token: " << token.toString() << std::endl;
    }
    
    std::cout << "Lexer test completed." << std::endl;
}

void testParser(const std::string& sourceFile) {
    std::cout << "Testing Parser..." << std::endl;
    
    Parser parser(sourceFile);
    std::unique_ptr<AST> ast = parser.parse();
    assert(ast != nullptr && "Parser failed to generate AST");
    
    std::cout << "AST Structure:" << std::endl;
    ast->print();
    
    std::cout << "Parser test completed." << std::endl;
}

void testTypeSystem(const std::string& sourceFile) {
    std::cout << "Testing Type System..." << std::endl;
    
    Parser parser(sourceFile);
    std::unique_ptr<AST> ast = parser.parse();
    
    TypeSystem typeSystem;
    bool typeCheckResult = typeSystem.checkTypes(ast.get());
    assert(typeCheckResult && "Type checking failed");
    
    std::cout << "Type System test completed." << std::endl;
}

void testCodeGeneration(const std::string& sourceFile) {
    std::cout << "Testing Code Generation..." << std::endl;
    
    Parser parser(sourceFile);
    std::unique_ptr<AST> ast = parser.parse();
    
    TypeSystem typeSystem;
    typeSystem.checkTypes(ast.get());
    
    CodeGenerator codegen;
    std::unique_ptr<Module> module = codegen.generateCode(ast.get());
    assert(module != nullptr && "Code generation failed");
    
    // Test optimization passes
    OptimizationManager optManager;
    
    // Add analysis passes
    optManager.addAnalysis(std::make_unique<LivenessAnalysis>());
    optManager.addAnalysis(std::make_unique<ReachingDefinitions>());
    
    // Add optimization passes
    optManager.addOptimization(std::make_unique<DeadCodeElimination>());
    optManager.addOptimization(std::make_unique<ConstantFolding>());
    optManager.addOptimization(std::make_unique<CommonSubexpressionElimination>());
    
    // Run optimizations
    optManager.optimize(*module);
    
    std::cout << "Code Generation test completed." << std::endl;
}

void testRuntime() {
    std::cout << "Testing Runtime..." << std::endl;
    
    Runtime runtime;
    
    // Test memory allocation
    void* memory = runtime.allocateMemory(100);
    assert(memory != nullptr && "Memory allocation failed");
    
    // Test string creation
    RuntimeValue* str = runtime.createString("Hello, World!");
    assert(str != nullptr && "String creation failed");
    
    // Test array creation
    RuntimeValue* arr = runtime.createArray(nullptr, 10);  // nullptr as placeholder for int type
    assert(arr != nullptr && "Array creation failed");
    
    // Test standard library functions
    std::vector<RuntimeValue*> printArgs;
    printArgs.push_back(str);
    runtime.print(printArgs);
    
    RuntimeValue* num = runtime.parseInt(str);
    assert(num == nullptr && "parseInt should fail for invalid input");
    
    std::cout << "Runtime test completed." << std::endl;
}

void runAllTests(const std::string& sourceFile) {
    std::cout << "Starting compiler tests..." << std::endl;
    
    try {
        testLexer(sourceFile);
        testParser(sourceFile);
        testTypeSystem(sourceFile);
        testCodeGeneration(sourceFile);
        testRuntime();
        
        std::cout << "All tests passed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with error: " << e.what() << std::endl;
        throw;
    }
}

int main() {
    const std::string testFile = "../test/test.c";
    runAllTests(testFile);
    return 0;
}
