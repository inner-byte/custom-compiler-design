#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "lexer.h"
#include "ast.h"
#include "symbol_table.h"

class ParseError : public std::runtime_error {
public:
    Token token;
    explicit ParseError(const std::string& message, const Token& t)
        : std::runtime_error(message), token(t) {}
};

class Parser {
public:
    explicit Parser(const std::string& sourceCode);
    std::unique_ptr<ProgramNode> parse();

private:
    Lexer lexer;
    std::vector<Token> tokens;
    size_t currentToken;
    SymbolTable symbolTable;
    
    // Error recovery
    void synchronize();
    void reportError(const std::string& message);
    bool isAtSynchronizationPoint();
    
    // Utility methods
    Token peek(size_t offset = 0);
    Token consume();
    bool match(TokenType type);
    bool check(TokenType type);
    Token expect(TokenType type, const std::string& message);
    
    // Grammar rules
    std::unique_ptr<ProgramNode> parseProgram();
    std::unique_ptr<FunctionDefNode> parseFunction();
    std::unique_ptr<ASTNode> parseStatement();
    std::unique_ptr<ASTNode> parseExpression();
    std::unique_ptr<ASTNode> parseTerm();
    std::unique_ptr<ASTNode> parseFactor();
    
    // Declaration parsing
    std::unique_ptr<ASTNode> parseDeclaration();
    std::unique_ptr<VariableDeclNode> parseVariableDeclaration();
    std::unique_ptr<FunctionDeclNode> parseFunctionDeclaration();
    std::unique_ptr<ASTNode> parseTypeDeclaration();
    
    // Statement parsing
    std::unique_ptr<IfNode> parseIfStatement();
    std::unique_ptr<ForNode> parseForStatement();
    std::unique_ptr<ReturnNode> parseReturnStatement();
    std::unique_ptr<BlockNode> parseBlock();
    
    // Expression parsing
    std::unique_ptr<ASTNode> parseAssignment();
    std::unique_ptr<ASTNode> parseLogicalOr();
    std::unique_ptr<ASTNode> parseLogicalAnd();
    std::unique_ptr<ASTNode> parseEquality();
    std::unique_ptr<ASTNode> parseComparison();
    std::unique_ptr<ASTNode> parseAdditive();
    std::unique_ptr<ASTNode> parseMultiplicative();
    std::unique_ptr<ASTNode> parseUnary();
    std::unique_ptr<ASTNode> parsePrimary();
    
    // Type checking
    std::string getExpressionType(const ASTNode* expr);
    void checkTypesCompatible(const std::string& expected, const std::string& actual,
                            const Token& token);
};

// Helper function for the bison parser
ProgramNode* parse(const std::string& sourceCode);

#endif
