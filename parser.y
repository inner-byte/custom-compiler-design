%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include "ast.h"
    #include "type_system.h"
    #include "symbol_table.h"
    
    extern int yylex();
    extern void yyerror(const char* s);
    extern ProgramNode* programRoot;
    extern int yylineno;
%}

%union {
    char* str;
    ASTNode* node;
    std::vector<ASTNode*>* node_list;
}

%token <str> IDENTIFIER INTEGER REAL STRING BOOLEAN
%token <str> KEYWORD_ALLOCATE KEYWORD_BOOL KEYWORD_BREAK KEYWORD_CASE KEYWORD_CHAR KEYWORD_CONST KEYWORD_CONTINUE KEYWORD_DECLARE KEYWORD_DEFAULT KEYWORD_DESTRUCT KEYWORD_DOUBLE KEYWORD_ELSE KEYWORD_FALSE KEYWORD_FUNCTION KEYWORD_FLOAT KEYWORD_FOR KEYWORD_GOTO KEYWORD_IF KEYWORD_INPUT KEYWORD_INT KEYWORD_LONG KEYWORD_OUTPUT KEYWORD_RETURN KEYWORD_SIZEOF KEYWORD_STATIC KEYWORD_STR KEYWORD_SWITCH KEYWORD_TRUE KEYWORD_TYPE
%token <str> OPERATOR_EQ OPERATOR_NEQ OPERATOR_LEQ OPERATOR_LT OPERATOR_GT OPERATOR_GEQ OPERATOR_ASSIGN OPERATOR_NOT OPERATOR_BITWISE_NEG OPERATOR_ARITH_AND OPERATOR_LOGIC_AND OPERATOR_ARITH_OR OPERATOR_LOGIC_OR OPERATOR_XOR OPERATOR_MUL OPERATOR_ADD OPERATOR_INC OPERATOR_DEC OPERATOR_SUB OPERATOR_DIV OPERATOR_MOD
%token <str> PUNCTUATION_LBRACE PUNCTUATION_RBRACE PUNCTUATION_LPAREN PUNCTUATION_RPAREN PUNCTUATION_LBRACKET PUNCTUATION_RBRACKET PUNCTUATION_DOT PUNCTUATION_COMMA PUNCTUATION_COLON PUNCTUATION_SEMICOLON
%token END_OF_FILE

%type <node> program ft_decl func_decl type_decl globl_var args params type_def func_def inout input_list output_list block var_decl var_decl_cnt statement assignment func_call cond_stmt loop_stmt goto_stmt label expr const_val variable primary unary_op type field func_prot ft_def
%type <node_list> statement_list field_list param_list type_list var_decl_list case_list func_decl_list type_decl_list globl_var_list ft_decl_list ft_def_list
%type <str> binary_op

%start program

%%

program:
    ft_decl_list ft_def_list   { programRoot = new ProgramNode($1, $2); }
;

ft_decl_list:
    /* empty */                { $$ = new std::vector<ASTNode*>(); }
    | ft_decl_list ft_decl    { $$->push_back($2); }
;

ft_def_list:
    /* empty */               { $$ = new std::vector<ASTNode*>(); }
    | ft_def_list ft_def     { $$->push_back($2); }
;

ft_decl:
    KEYWORD_DECLARE PUNCTUATION_LBRACE func_decl_list type_decl_list globl_var_list PUNCTUATION_RBRACE 
                               { $$ = new ASTNode(ASTNodeType::FT_DECL, @$.first_line, @$.first_column); }
;

func_decl_list:
    func_decl                 { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | func_decl_list func_decl { $$->push_back($2); }
;

type_decl_list:
    type_decl                 { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | type_decl_list type_decl { $$->push_back($2); }
;

globl_var_list:
    globl_var                 { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | globl_var_list globl_var { $$->push_back($2); }
;

func_decl:
    func_prot PUNCTUATION_SEMICOLON { $$ = $1; }
;

func_prot:
    PUNCTUATION_LPAREN args PUNCTUATION_RPAREN IDENTIFIER PUNCTUATION_LPAREN params PUNCTUATION_RPAREN 
                               { $$ = new FunctionDeclNode($4, $2, $6, @$.first_line, @$.first_column); }
;

globl_var:
    PUNCTUATION_LBRACE type IDENTIFIER PUNCTUATION_SEMICOLON PUNCTUATION_RBRACE 
                               { $$ = new VariableDeclNode($2, $3, @$.first_line, @$.first_column); }
;

args:
    type_list                 { $$ = new ASTNode(ASTNodeType::ARGS, @$.first_line, @$.first_column); }
;

type_list:
    type                      { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | type_list PUNCTUATION_COMMA type { $$->push_back($3); }
;

params:
    param_list                { $$ = new ASTNode(ASTNodeType::PARAMS, @$.first_line, @$.first_column); }
;

param_list:
    IDENTIFIER               { $$ = new std::vector<ASTNode*>(); $$->push_back(new IDNode($1, @$.first_line, @$.first_column)); }
    | type IDENTIFIER        { $$ = new std::vector<ASTNode*>(); $$->push_back(new VariableDeclNode($1, $2, @$.first_line, @$.first_column)); }
    | param_list PUNCTUATION_COMMA IDENTIFIER { $$->push_back(new IDNode($3, @$.first_line, @$.first_column)); }
    | param_list PUNCTUATION_COMMA type IDENTIFIER { $$->push_back(new VariableDeclNode($3, $4, @$.first_line, @$.first_column)); }
;

type_decl:
    KEYWORD_TYPE IDENTIFIER PUNCTUATION_LBRACE field_list PUNCTUATION_SEMICOLON PUNCTUATION_RBRACE 
                               { $$ = new TypeDeclNode($2, $4, @$.first_line, @$.first_column); }
;

field_list:
    field                     { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | field_list field       { $$->push_back($2); }
;

field:
    type IDENTIFIER          { $$ = new VariableDeclNode($1, $2, @$.first_line, @$.first_column); }
;

ft_def:
    func_def                 { $$ = $1; }
    | type_def              { $$ = $1; }
;

type_def:
    KEYWORD_TYPE IDENTIFIER PUNCTUATION_LBRACE field_list PUNCTUATION_SEMICOLON PUNCTUATION_RBRACE 
                               { $$ = new TypeDefNode($2, $4, @$.first_line, @$.first_column); }
;

func_def:
    KEYWORD_FUNCTION IDENTIFIER PUNCTUATION_COLON PUNCTUATION_LBRACE inout PUNCTUATION_RBRACE PUNCTUATION_LBRACE block PUNCTUATION_RBRACE 
                               { $$ = new FunctionDefNode($2, $5, $8, @$.first_line, @$.first_column); }
;

inout:
    /* empty */              { $$ = new ASTNode(ASTNodeType::INOUT, @$.first_line, @$.first_column); }
    | input_list            { $$ = $1; }
    | output_list           { $$ = $1; }
    | input_list output_list { $$ = new InOutNode($1, $2, @$.first_line, @$.first_column); }
;

input_list:
    KEYWORD_INPUT params     { $$ = new ASTNode(ASTNodeType::INPUT_LIST, @$.first_line, @$.first_column); }
;

output_list:
    KEYWORD_OUTPUT params    { $$ = new ASTNode(ASTNodeType::OUTPUT_LIST, @$.first_line, @$.first_column); }
;

block:
    PUNCTUATION_LBRACE statement_list PUNCTUATION_RBRACE { $$ = new BlockNode($2, @$.first_line, @$.first_column); }
;

statement_list:
    /* empty */             { $$ = new std::vector<ASTNode*>(); }
    | statement_list var_decl { $$->push_back($2); }
    | statement_list statement { $$->push_back($2); }
;

type:
    KEYWORD_INT             { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::INT, @$.first_line, @$.first_column); }
    | KEYWORD_BOOL         { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::BOOL, @$.first_line, @$.first_column); }
    | KEYWORD_FLOAT        { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::FLOAT, @$.first_line, @$.first_column); }
    | KEYWORD_LONG         { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::LONG, @$.first_line, @$.first_column); }
    | KEYWORD_CHAR         { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::CHAR, @$.first_line, @$.first_column); }
    | KEYWORD_DOUBLE       { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::DOUBLE, @$.first_line, @$.first_column); }
    | KEYWORD_STR          { $$ = new PrimitiveTypeNode(PrimitiveType::Kind::STR, @$.first_line, @$.first_column); }
    | IDENTIFIER          { $$ = new UserTypeNode($1, @$.first_line, @$.first_column); }
    | type PUNCTUATION_LBRACKET PUNCTUATION_RBRACKET { $$ = new ArrayTypeNode($1, @$.first_line, @$.first_column); }
;

var_decl:
    KEYWORD_CONST type var_decl_list PUNCTUATION_SEMICOLON { $$ = new VarDeclListNode($3, true, @$.first_line, @$.first_column); }
    | type var_decl_list PUNCTUATION_SEMICOLON { $$ = new VarDeclListNode($2, false, @$.first_line, @$.first_column); }
;

var_decl_list:
    var_decl_cnt           { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | var_decl_list PUNCTUATION_COMMA var_decl_cnt { $$->push_back($3); }
;

var_decl_cnt:
    variable              { $$ = $1; }
    | variable OPERATOR_ASSIGN expr { $$ = new AssignmentNode($1, $3, @$.first_line, @$.first_column); }
    | variable KEYWORD_ALLOCATE { $$ = new AllocateNode($1, @$.first_line, @$.first_column); }
;

statement:
    assignment           { $$ = $1; }
    | func_call         { $$ = $1; }
    | cond_stmt         { $$ = $1; }
    | loop_stmt         { $$ = $1; }
    | KEYWORD_RETURN expr PUNCTUATION_SEMICOLON { $$ = new ReturnNode($2, @$.first_line, @$.first_column); }
    | goto_stmt         { $$ = $1; }
    | label             { $$ = $1; }
    | KEYWORD_BREAK PUNCTUATION_SEMICOLON { $$ = new BreakNode(@$.first_line, @$.first_column); }
    | KEYWORD_CONTINUE PUNCTUATION_SEMICOLON { $$ = new ContinueNode(@$.first_line, @$.first_column); }
    | KEYWORD_DESTRUCT PUNCTUATION_LBRACKET PUNCTUATION_RBRACKET IDENTIFIER PUNCTUATION_SEMICOLON 
                        { $$ = new DestructNode($4, @$.first_line, @$.first_column); }
    | KEYWORD_SIZEOF PUNCTUATION_LPAREN type PUNCTUATION_RPAREN 
                        { $$ = new SizeofNode($3, @$.first_line, @$.first_column); }
;

assignment:
    variable OPERATOR_ASSIGN expr PUNCTUATION_SEMICOLON { $$ = new AssignmentNode($1, $3, @$.first_line, @$.first_column); }
;

variable:
    IDENTIFIER          { $$ = new IDNode($1, @$.first_line, @$.first_column); }
    | variable PUNCTUATION_LBRACKET expr PUNCTUATION_RBRACKET { $$ = new ArrayAccessNode($1, $3, @$.first_line, @$.first_column); }
    | PUNCTUATION_LPAREN variable PUNCTUATION_RPAREN { $$ = $2; }
    | func_call         { $$ = $1; }
    | OPERATOR_DEC variable { $$ = new UnaryOpNode("--", $2, @$.first_line, @$.first_column); }
    | OPERATOR_INC variable { $$ = new UnaryOpNode("++", $2, @$.first_line, @$.first_column); }
    | variable OPERATOR_DEC { $$ = new UnaryOpNode("--", $1, @$.first_line, @$.first_column); }
    | variable OPERATOR_INC { $$ = new UnaryOpNode("++", $1, @$.first_line, @$.first_column); }
;

func_call:
    IDENTIFIER PUNCTUATION_LPAREN PUNCTUATION_RPAREN { $$ = new FunctionCallNode($1, nullptr, @$.first_line, @$.first_column); }
    | IDENTIFIER PUNCTUATION_LPAREN param_list PUNCTUATION_RPAREN { $$ = new FunctionCallNode($1, $3, @$.first_line, @$.first_column); }
;

cond_stmt:
    KEYWORD_IF PUNCTUATION_LPAREN expr PUNCTUATION_RPAREN block { $$ = new IfNode($3, $5, nullptr, @$.first_line, @$.first_column); }
    | KEYWORD_IF PUNCTUATION_LPAREN expr PUNCTUATION_RPAREN block KEYWORD_ELSE block 
                        { $$ = new IfNode($3, $5, $7, @$.first_line, @$.first_column); }
    | KEYWORD_SWITCH PUNCTUATION_LPAREN IDENTIFIER PUNCTUATION_RPAREN PUNCTUATION_LBRACE case_list PUNCTUATION_RBRACE 
                        { $$ = new SwitchNode($3, $6, @$.first_line, @$.first_column); }
;

case_list:
    /* empty */         { $$ = new std::vector<ASTNode*>(); }
    | case_list KEYWORD_CASE INTEGER PUNCTUATION_COLON block { $$->push_back(new CaseNode($3, $5, @$.first_line, @$.first_column)); }
    | case_list KEYWORD_DEFAULT PUNCTUATION_COLON block { $$->push_back(new DefaultNode($4, @$.first_line, @$.first_column)); }
;

loop_stmt:
    KEYWORD_FOR PUNCTUATION_LPAREN var_decl expr PUNCTUATION_SEMICOLON assignment PUNCTUATION_RPAREN block 
                        { $$ = new ForNode($3, $4, $6, $8, @$.first_line, @$.first_column); }
;

goto_stmt:
    KEYWORD_GOTO IDENTIFIER PUNCTUATION_SEMICOLON { $$ = new GotoNode($2, @$.first_line, @$.first_column); }
;

label:
    IDENTIFIER PUNCTUATION_COLON { $$ = new LabelNode($1, @$.first_line, @$.first_column); }
;

expr:
    expr binary_op expr { $$ = new BinaryOpNode($2, $1, $3, @$.first_line, @$.first_column); }
    | PUNCTUATION_LPAREN expr PUNCTUATION_RPAREN { $$ = $2; }
    | func_call        { $$ = $1; }
    | variable         { $$ = $1; }
    | const_val        { $$ = $1; }
    | unary_op         { $$ = $1; }
;

unary_op:
    OPERATOR_SUB primary { $$ = new UnaryOpNode("-", $2, @$.first_line, @$.first_column); }
    | OPERATOR_NOT primary { $$ = new UnaryOpNode("!", $2, @$.first_line, @$.first_column); }
;

primary:
    IDENTIFIER         { $$ = new IDNode($1, @$.first_line, @$.first_column); }
    | INTEGER         { $$ = new IntegerLiteralNode(std::stoi($1), @$.first_line, @$.first_column); }
    | REAL            { $$ = new RealLiteralNode(std::stod($1), @$.first_line, @$.first_column); }
    | STRING          { $$ = new StringLiteralNode($1, @$.first_line, @$.first_column); }
    | BOOLEAN         { $$ = new BooleanLiteralNode(std::string($1) == "true", @$.first_line, @$.first_column); }
;

binary_op:
    OPERATOR_ADD      { $$ = strdup("+"); }
    | OPERATOR_SUB    { $$ = strdup("-"); }
    | OPERATOR_MUL    { $$ = strdup("*"); }
    | OPERATOR_DIV    { $$ = strdup("/"); }
    | OPERATOR_MOD    { $$ = strdup("%"); }
    | OPERATOR_ARITH_AND { $$ = strdup("&"); }
    | OPERATOR_ARITH_OR { $$ = strdup("|"); }
    | OPERATOR_XOR    { $$ = strdup("^"); }
    | OPERATOR_LOGIC_OR { $$ = strdup("||"); }
    | OPERATOR_LOGIC_AND { $$ = strdup("&&"); }
    | OPERATOR_EQ     { $$ = strdup("=="); }
    | OPERATOR_NEQ    { $$ = strdup("!="); }
    | OPERATOR_LEQ    { $$ = strdup("<="); }
    | OPERATOR_LT     { $$ = strdup("<"); }
    | OPERATOR_GT     { $$ = strdup(">"); }
    | OPERATOR_GEQ    { $$ = strdup(">="); }
;

const_val:
    INTEGER          { $$ = new IntegerLiteralNode(std::stoi($1), @$.first_line, @$.first_column); }
    | REAL           { $$ = new RealLiteralNode(std::stod($1), @$.first_line, @$.first_column); }
    | STRING         { $$ = new StringLiteralNode($1, @$.first_line, @$.first_column); }
    | BOOLEAN        { $$ = new BooleanLiteralNode(std::string($1) == "true", @$.first_line, @$.first_column); }
;

%%

void yyerror(const char* s) {
    std::cerr << "Error: " << s << " at line " << yylineno << std::endl;
}
