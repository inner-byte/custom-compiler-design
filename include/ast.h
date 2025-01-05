#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include <memory>
#include "type_system.h"

enum class ASTNodeType {
    PROGRAM,
    FT_DECL,
    FUNCTION_DECL,
    VARIABLE_DECL,
    ASSIGNMENT,
    FUNCTION_CALL,
    IF_STATEMENT,
    FOR_STATEMENT,
    RETURN_STATEMENT,
    EXPRESSION,
    ID,
    INTEGER_LITERAL,
    REAL_LITERAL,
    STRING_LITERAL,
    BOOLEAN_LITERAL,
    BINARY_OP,
    UNARY_OP,
    BLOCK,
    FT_DEF,
    TYPE_DECL,
    FIELD,
    ARGS,
    PARAMS,
    TYPE_DEF,
    INOUT,
    INPUT_LIST,
    OUTPUT_LIST,
    VAR_DECL,
    VAR_DECL_CNT,
    STATEMENT,
    COND_STMT,
    LOOP_STMT,
    GOTO_STMT,
    LABEL,
    CONST_VAL,
    VARIABLE,
    FUNCTION_DEF,
    TYPE,
    UNKNOWN
};

class ASTNode {
public:
    ASTNodeType type;
    int line;
    int column;
    ASTNode(ASTNodeType type, int line, int column) : type(type), line(line), column(column) {}
    virtual ~ASTNode() = default;
};

class ProgramNode : public ASTNode {
public:
    std::vector<ASTNode*> declarations;
    std::vector<ASTNode*> definitions;
    ProgramNode(std::vector<ASTNode*>* declarations, std::vector<ASTNode*>* definitions) 
        : ASTNode(ASTNodeType::PROGRAM, 0, 0), 
          declarations(declarations ? *declarations : std::vector<ASTNode*>()),
          definitions(definitions ? *definitions : std::vector<ASTNode*>()) {}
};

class FunctionDeclNode : public ASTNode {
public:
    std::string name;
    ASTNode* args;
    ASTNode* params;
    FunctionDeclNode(const std::string& name, ASTNode* args, ASTNode* params, int line, int column) 
        : ASTNode(ASTNodeType::FUNCTION_DECL, line, column), name(name), args(args), params(params) {}
};

class TypeDeclNode : public ASTNode {
public:
    std::string name;
    std::vector<ASTNode*> fields;
    TypeDeclNode(const std::string& name, std::vector<ASTNode*>* fields, int line, int column)
        : ASTNode(ASTNodeType::TYPE_DECL, line, column), name(name), fields(fields ? *fields : std::vector<ASTNode*>()) {}
};

class TypeDefNode : public ASTNode {
public:
    std::string name;
    std::vector<ASTNode*> fields;
    TypeDefNode(const std::string& name, std::vector<ASTNode*>* fields, int line, int column)
        : ASTNode(ASTNodeType::TYPE_DEF, line, column), name(name), fields(fields ? *fields : std::vector<ASTNode*>()) {}
};

class VariableDeclNode : public ASTNode {
public:
    ASTNode* type;
    std::string name;
    ASTNode* initializer;
    VariableDeclNode(ASTNode* type, const std::string& name, int line, int column) 
        : ASTNode(ASTNodeType::VARIABLE_DECL, line, column), type(type), name(name), initializer(nullptr) {}
};

class AssignmentNode : public ASTNode {
public:
    ASTNode* variable;
    ASTNode* expression;
    AssignmentNode(ASTNode* variable, ASTNode* expression, int line, int column) 
        : ASTNode(ASTNodeType::ASSIGNMENT, line, column), variable(variable), expression(expression) {}
};

class FunctionCallNode : public ASTNode {
public:
    std::string name;
    std::vector<ASTNode*>* arguments;
    FunctionCallNode(const std::string& name, std::vector<ASTNode*>* arguments, int line, int column) 
        : ASTNode(ASTNodeType::FUNCTION_CALL, line, column), name(name), arguments(arguments) {}
};

class IfNode : public ASTNode {
public:
    ASTNode* condition;
    ASTNode* thenBlock;
    ASTNode* elseBlock;
    IfNode(ASTNode* condition, ASTNode* thenBlock, ASTNode* elseBlock, int line, int column) 
        : ASTNode(ASTNodeType::IF_STATEMENT, line, column), condition(condition), thenBlock(thenBlock), elseBlock(elseBlock) {}
};

class ForNode : public ASTNode {
public:
    ASTNode* initializer;
    ASTNode* condition;
    ASTNode* increment;
    ASTNode* body;
    ForNode(ASTNode* initializer, ASTNode* condition, ASTNode* increment, ASTNode* body, int line, int column) 
        : ASTNode(ASTNodeType::FOR_STATEMENT, line, column), initializer(initializer), condition(condition), increment(increment), body(body) {}
};

class ReturnNode : public ASTNode {
public:
    ASTNode* expression;
    ReturnNode(ASTNode* expression, int line, int column) 
        : ASTNode(ASTNodeType::RETURN_STATEMENT, line, column), expression(expression) {}
};

class BlockNode : public ASTNode {
public:
    std::vector<ASTNode*> statements;
    BlockNode(std::vector<ASTNode*>* statements, int line, int column) 
        : ASTNode(ASTNodeType::BLOCK, line, column), statements(statements ? *statements : std::vector<ASTNode*>()) {}
};

class FunctionDefNode : public ASTNode {
public:
    std::string name;
    ASTNode* inout;
    ASTNode* block;
    FunctionDefNode(const std::string& name, ASTNode* inout, ASTNode* block, int line, int column) 
        : ASTNode(ASTNodeType::FUNCTION_DEF, line, column), name(name), inout(inout), block(block) {}
};

class InOutNode : public ASTNode {
public:
    ASTNode* input;
    ASTNode* output;
    InOutNode(ASTNode* input, ASTNode* output, int line, int column)
        : ASTNode(ASTNodeType::INOUT, line, column), input(input), output(output) {}
};

class IDNode : public ASTNode {
public:
    std::string name;
    IDNode(const std::string& name, int line, int column) 
        : ASTNode(ASTNodeType::ID, line, column), name(name) {}
};

class IntegerLiteralNode : public ASTNode {
public:
    int value;
    IntegerLiteralNode(int value, int line, int column) 
        : ASTNode(ASTNodeType::INTEGER_LITERAL, line, column), value(value) {}
};

class RealLiteralNode : public ASTNode {
public:
    double value;
    RealLiteralNode(double value, int line, int column) 
        : ASTNode(ASTNodeType::REAL_LITERAL, line, column), value(value) {}
};

class StringLiteralNode : public ASTNode {
public:
    std::string value;
    StringLiteralNode(const std::string& value, int line, int column) 
        : ASTNode(ASTNodeType::STRING_LITERAL, line, column), value(value) {}
};

class BooleanLiteralNode : public ASTNode {
public:
    bool value;
    BooleanLiteralNode(bool value, int line, int column) 
        : ASTNode(ASTNodeType::BOOLEAN_LITERAL, line, column), value(value) {}
};

class BinaryOpNode : public ASTNode {
public:
    std::string op;
    ASTNode* left;
    ASTNode* right;
    BinaryOpNode(const std::string& op, ASTNode* left, ASTNode* right, int line, int column) 
        : ASTNode(ASTNodeType::BINARY_OP, line, column), op(op), left(left), right(right) {}
};

class UnaryOpNode : public ASTNode {
public:
    std::string op;
    ASTNode* operand;
    UnaryOpNode(const std::string& op, ASTNode* operand, int line, int column) 
        : ASTNode(ASTNodeType::UNARY_OP, line, column), op(op), operand(operand) {}
};

class TypeNode : public ASTNode {
public:
    std::unique_ptr<Type> type;
    TypeNode(std::unique_ptr<Type> type, int line, int column)
        : ASTNode(ASTNodeType::TYPE, line, column), type(std::move(type)) {}
};

class PrimitiveTypeNode : public TypeNode {
public:
    PrimitiveTypeNode(PrimitiveType::Kind kind, int line, int column)
        : TypeNode(std::make_unique<PrimitiveType>(kind), line, column) {}
};

class UserTypeNode : public TypeNode {
public:
    std::string name;
    UserTypeNode(const std::string& name, int line, int column)
        : TypeNode(nullptr, line, column), name(name) {}
};

class ArrayTypeNode : public TypeNode {
public:
    ASTNode* elementType;
    ArrayTypeNode(ASTNode* elementType, int line, int column)
        : TypeNode(nullptr, line, column), elementType(elementType) {}
};

class AllocateNode : public ASTNode {
public:
    ASTNode* variable;
    AllocateNode(ASTNode* variable, int line, int column)
        : ASTNode(ASTNodeType::VARIABLE, line, column), variable(variable) {}
};

class DestructNode : public ASTNode {
public:
    std::string name;
    DestructNode(const std::string& name, int line, int column)
        : ASTNode(ASTNodeType::VARIABLE, line, column), name(name) {}
};

class SizeofNode : public ASTNode {
public:
    ASTNode* type;
    SizeofNode(ASTNode* type, int line, int column)
        : ASTNode(ASTNodeType::EXPRESSION, line, column), type(type) {}
};

class GotoNode : public ASTNode {
public:
    std::string label;
    GotoNode(const std::string& label, int line, int column)
        : ASTNode(ASTNodeType::GOTO_STMT, line, column), label(label) {}
};

class LabelNode : public ASTNode {
public:
    std::string name;
    LabelNode(const std::string& name, int line, int column)
        : ASTNode(ASTNodeType::LABEL, line, column), name(name) {}
};

class BreakNode : public ASTNode {
public:
    BreakNode(int line, int column)
        : ASTNode(ASTNodeType::STATEMENT, line, column) {}
};

class ContinueNode : public ASTNode {
public:
    ContinueNode(int line, int column)
        : ASTNode(ASTNodeType::STATEMENT, line, column) {}
};

class CaseNode : public ASTNode {
public:
    std::string value;
    ASTNode* block;
    CaseNode(const std::string& value, ASTNode* block, int line, int column)
        : ASTNode(ASTNodeType::STATEMENT, line, column), value(value), block(block) {}
};

class DefaultNode : public ASTNode {
public:
    ASTNode* block;
    DefaultNode(ASTNode* block, int line, int column)
        : ASTNode(ASTNodeType::STATEMENT, line, column), block(block) {}
};

class SwitchNode : public ASTNode {
public:
    std::string variable;
    std::vector<ASTNode*>* cases;
    SwitchNode(const std::string& variable, std::vector<ASTNode*>* cases, int line, int column)
        : ASTNode(ASTNodeType::COND_STMT, line, column), variable(variable), cases(cases) {}
};

class VarDeclListNode : public ASTNode {
public:
    std::vector<ASTNode*>* declarations;
    bool isConst;
    VarDeclListNode(std::vector<ASTNode*>* declarations, bool isConst, int line, int column)
        : ASTNode(ASTNodeType::VAR_DECL, line, column), declarations(declarations), isConst(isConst) {}
};

class ArrayAccessNode : public ASTNode {
public:
    ASTNode* array;
    ASTNode* index;
    ArrayAccessNode(ASTNode* array, ASTNode* index, int line, int column)
        : ASTNode(ASTNodeType::VARIABLE, line, column), array(array), index(index) {}
};

#endif
