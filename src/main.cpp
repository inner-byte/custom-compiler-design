#include <iostream>
    #include <fstream>
    #include <sstream>
    #include "include/parser.h"
    #include "include/codegen.h"

    int main() {
        std::ifstream file("test.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return 1;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string sourceCode = buffer.str();
        file.close();

        ProgramNode* program = parse(sourceCode);
        if (program) {
            CodeGenerator generator;
            std::string generatedCode = generator.generateCode(program);
            std::cout << generatedCode << std::endl;
        }
        return 0;
    }
