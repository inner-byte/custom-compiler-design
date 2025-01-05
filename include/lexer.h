#ifndef LEXER_H
    #define LEXER_H

    #include <string>
    #include <vector>

    enum class TokenType {
        // Keywords
        FUNCTION,
        VAR,
        TYPE,
        IF,
        ELSE,
        FOR,
        WHILE,
        RETURN,
        TRUE,
        FALSE,
        
        // Identifiers and literals
        IDENTIFIER,
        INTEGER,
        REAL,
        STRING,
        CHAR,
        
        // Operators
        PLUS,
        MINUS,
        STAR,
        SLASH,
        EQUAL,
        EQUAL_EQUAL,
        BANG,
        BANG_EQUAL,
        LESS,
        LESS_EQUAL,
        GREATER,
        GREATER_EQUAL,
        AND,
        OR,
        
        // Punctuation
        LEFT_PAREN,
        RIGHT_PAREN,
        LEFT_BRACE,
        RIGHT_BRACE,
        LEFT_BRACKET,
        RIGHT_BRACKET,
        COMMA,
        DOT,
        SEMICOLON,
        COLON,
        
        // Special tokens
        END_OF_FILE,
        ERROR,
        UNKNOWN
    };

    struct Token {
        TokenType type;
        std::string value;
        int line;
        int column;
        std::string errorMessage;  // For error reporting
    };

    class Lexer {
    public:
        Lexer(const std::string& sourceCode);
        std::vector<Token> tokenize();
        Token getNextToken();
        std::string getErrorContext(int line, int column) const;

    private:
        std::string sourceCode;
        int currentLine = 1;
        int currentColumn = 1;
        int position = 0;
        std::vector<std::string> sourceLines;  // Store lines for error context

        char currentChar();
        char peekChar(int offset = 1);
        void advance();
        void skipWhitespace();
        Token makeToken(TokenType type, const std::string& value);
        Token makeErrorToken(const std::string& message);
        Token makeKeywordToken();
        Token makeIdentifierToken();
        Token makeNumberToken();
        Token makeStringToken();
        Token makeCharacterToken();
        Token makeOperatorToken();
        Token makePunctuationToken();
        std::string processEscapeSequence();
        
        bool isDigit(char c);
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);
        bool isOperator(char c);
        bool isPunctuation(char c);
        bool isHexDigit(char c);
        bool isOctalDigit(char c);
        void initializeSourceLines();
    };

    #endif
