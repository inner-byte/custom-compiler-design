#include "../include/symbol_table.h"

SymbolTable::SymbolTable() : currentOffset(0) {
    // Create global scope
    scopes.push_back(std::make_unique<Scope>(0));
    registerBuiltinTypes();
}

void SymbolTable::registerBuiltinTypes() {
    // Register primitive types
    auto voidType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::VOID);
    auto boolType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::BOOL);
    auto charType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::CHAR);
    auto intType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::INT);
    auto longType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::LONG);
    auto floatType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::FLOAT);
    auto doubleType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::DOUBLE);
    auto stringType = std::make_unique<PrimitiveType>(PrimitiveType::Kind::STRING);
    
    declareType("void", std::move(voidType));
    declareType("bool", std::move(boolType));
    declareType("char", std::move(charType));
    declareType("int", std::move(intType));
    declareType("long", std::move(longType));
    declareType("float", std::move(floatType));
    declareType("double", std::move(doubleType));
    declareType("string", std::move(stringType));
}

void SymbolTable::enterScope() {
    scopes.push_back(std::make_unique<Scope>(getCurrentScopeLevel() + 1));
}

void SymbolTable::exitScope() {
    if (scopes.size() > 1) { // Don't remove global scope
        currentOffset -= scopes.back()->size;
        scopes.pop_back();
    }
}

size_t SymbolTable::getCurrentScopeLevel() const {
    return scopes.size() - 1;
}

bool SymbolTable::declareSymbol(const std::string& name, std::unique_ptr<Type> type,
                               bool isConstant) {
    if (scopes.empty()) {
        setError("No active scope");
        return false;
    }
    
    auto& currentScope = scopes.back()->symbols;
    if (currentScope.find(name) != currentScope.end()) {
        setError("Symbol '" + name + "' already declared in current scope");
        return false;
    }
    
    auto symbol = std::make_unique<Symbol>(name, std::move(type), isConstant);
    symbol->scopeLevel = getCurrentScopeLevel();
    symbol->offset = currentOffset;
    currentOffset += symbol->type->getSize();
    scopes.back()->size += symbol->type->getSize();
    
    currentScope[name] = std::move(symbol);
    return true;
}

Symbol* SymbolTable::findSymbol(const std::string& name) {
    // Search from innermost scope to outermost
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto found = (*it)->symbols.find(name);
        if (found != (*it)->symbols.end()) {
            return found->second.get();
        }
    }
    return nullptr;
}

bool SymbolTable::declareType(const std::string& name, std::unique_ptr<Type> type) {
    if (types.find(name) != types.end()) {
        setError("Type '" + name + "' already declared");
        return false;
    }
    types[name] = std::move(type);
    return true;
}

Type* SymbolTable::findType(const std::string& name) {
    auto it = types.find(name);
    return it != types.end() ? it->second.get() : nullptr;
}

Type* SymbolTable::getType(const std::string& name) const {
    auto it = types.find(name);
    if (it == types.end()) {
        // Try to find in current scope
        for (auto scopeIt = scopes.rbegin(); scopeIt != scopes.rend(); ++scopeIt) {
            auto found = (*scopeIt)->symbols.find(name);
            if (found != (*scopeIt)->symbols.end()) {
                return found->second->type.get();
            }
        }
        return nullptr;
    }
    return it->second.get();
}

bool SymbolTable::isTypeCompatible(const Type* source, const Type* target) {
    if (!source || !target) {
        return false;
    }
    return source->isCompatibleWith(target);
}

std::string SymbolTable::getCommonType(const std::string& type1, const std::string& type2) {
    Type* t1 = findType(type1);
    Type* t2 = findType(type2);
    
    if (!t1 || !t2) {
        return "";
    }
    
    // Same type
    if (t1->isCompatibleWith(t2)) {
        return type1;
    }
    
    // Handle numeric types
    if (t1->getKind() == TypeKind::PRIMITIVE && t2->getKind() == TypeKind::PRIMITIVE) {
        auto p1 = static_cast<const PrimitiveType*>(t1);
        auto p2 = static_cast<const PrimitiveType*>(t2);
        
        switch (p1->getPrimitiveKind()) {
            case PrimitiveType::Kind::DOUBLE:
                return "double";
            case PrimitiveType::Kind::FLOAT:
                if (p2->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE) {
                    return "double";
                }
                return "float";
            case PrimitiveType::Kind::LONG:
                switch (p2->getPrimitiveKind()) {
                    case PrimitiveType::Kind::DOUBLE:
                    case PrimitiveType::Kind::FLOAT:
                        return type2;
                    default:
                        return "long";
                }
            case PrimitiveType::Kind::INT:
                switch (p2->getPrimitiveKind()) {
                    case PrimitiveType::Kind::DOUBLE:
                    case PrimitiveType::Kind::FLOAT:
                    case PrimitiveType::Kind::LONG:
                        return type2;
                    default:
                        return "int";
                }
            default:
                break;
        }
    }
    
    return "";
}

void SymbolTable::setError(const std::string& error) {
    lastError = error;
}

const std::string& SymbolTable::getLastError() const {
    return lastError;
}
