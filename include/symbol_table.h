#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "type_system.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

// Forward declarations
class Type;

struct Symbol {
    std::string name;
    std::unique_ptr<Type> type;
    bool isConstant;
    size_t scopeLevel;
    size_t offset;  // Memory offset for code generation
    
    Symbol(std::string name, std::unique_ptr<Type> type, bool isConstant = false)
        : name(std::move(name)), type(std::move(type)), isConstant(isConstant),
          scopeLevel(0), offset(0) {}
};

class Scope {
public:
    std::unordered_map<std::string, std::unique_ptr<Symbol>> symbols;
    size_t level;
    size_t size;  // Total size of all symbols in this scope
    
    explicit Scope(size_t level) : level(level), size(0) {}
};

class SymbolTable {
public:
    SymbolTable();
    
    // Scope management
    void enterScope();
    void exitScope();
    size_t getCurrentScopeLevel() const;
    
    // Symbol management
    bool declareSymbol(const std::string& name, std::unique_ptr<Type> type,
                      bool isConstant = false);
    Symbol* findSymbol(const std::string& name);
    
    // Type management
    bool declareType(const std::string& name, std::unique_ptr<Type> type);
    Type* findType(const std::string& name);
    Type* getType(const std::string& name) const;
    
    // Type checking helpers
    bool isTypeCompatible(const Type* source, const Type* target);
    std::string getCommonType(const std::string& type1, const std::string& type2);
    
    // Memory layout
    size_t getCurrentOffset() const { return currentOffset; }
    
    // Error handling
    const std::string& getLastError() const;
    void setError(const std::string& error);

private:
    std::vector<std::unique_ptr<Scope>> scopes;
    std::unordered_map<std::string, std::unique_ptr<Type>> types;
    size_t currentOffset;
    std::string lastError;
    
    void registerBuiltinTypes();
};

#endif
