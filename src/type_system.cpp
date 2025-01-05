#include "../include/type_system.h"
#include <sstream>

// PrimitiveType implementation
std::string PrimitiveType::toString() const {
    switch (kind) {
        case Kind::VOID: return "void";
        case Kind::BOOL: return "bool";
        case Kind::CHAR: return "char";
        case Kind::INT: return "int";
        case Kind::LONG: return "long";
        case Kind::FLOAT: return "float";
        case Kind::DOUBLE: return "double";
        case Kind::STR: return "str";
        default: return "unknown";
    }
}

bool PrimitiveType::isCompatibleWith(const Type* other) const {
    if (auto otherPrim = dynamic_cast<const PrimitiveType*>(other)) {
        return kind == otherPrim->kind;
    }
    return false;
}

size_t PrimitiveType::getSize() const {
    switch (kind) {
        case Kind::VOID: return 0;
        case Kind::BOOL: return 1;
        case Kind::CHAR: return 1;
        case Kind::INT: return 4;
        case Kind::LONG: return 8;
        case Kind::FLOAT: return 4;
        case Kind::DOUBLE: return 8;
        case Kind::STR: return 8; // pointer size
        default: return 0;
    }
}

std::unique_ptr<Type> PrimitiveType::clone() const {
    return std::make_unique<PrimitiveType>(kind);
}

// ArrayType implementation
std::string ArrayType::toString() const {
    std::stringstream ss;
    ss << elementType->toString() << "[]";
    return ss.str();
}

bool ArrayType::isCompatibleWith(const Type* other) const {
    if (auto otherArray = dynamic_cast<const ArrayType*>(other)) {
        return elementType->isCompatibleWith(otherArray->elementType.get());
    }
    return false;
}

size_t ArrayType::getSize() const {
    if (size.has_value()) {
        return size.value() * elementType->getSize();
    }
    return 8; // pointer size for dynamic arrays
}

std::unique_ptr<Type> ArrayType::clone() const {
    return std::make_unique<ArrayType>(elementType->clone(), size);
}

// PointerType implementation
std::string PointerType::toString() const {
    std::stringstream ss;
    ss << pointeeType->toString() << "*";
    return ss.str();
}

bool PointerType::isCompatibleWith(const Type* other) const {
    if (auto otherPtr = dynamic_cast<const PointerType*>(other)) {
        return pointeeType->isCompatibleWith(otherPtr->pointeeType.get());
    }
    return false;
}

size_t PointerType::getSize() const {
    return 8; // pointer size
}

std::unique_ptr<Type> PointerType::clone() const {
    return std::make_unique<PointerType>(pointeeType->clone());
}

// FunctionType implementation
std::string FunctionType::toString() const {
    std::stringstream ss;
    ss << returnType->toString() << "(";
    for (size_t i = 0; i < parameterTypes.size(); ++i) {
        if (i > 0) ss << ", ";
        ss << parameterTypes[i]->toString();
    }
    ss << ")";
    return ss.str();
}

bool FunctionType::isCompatibleWith(const Type* other) const {
    if (auto otherFunc = dynamic_cast<const FunctionType*>(other)) {
        if (!returnType->isCompatibleWith(otherFunc->returnType.get())) {
            return false;
        }
        if (parameterTypes.size() != otherFunc->parameterTypes.size()) {
            return false;
        }
        for (size_t i = 0; i < parameterTypes.size(); ++i) {
            if (!parameterTypes[i]->isCompatibleWith(otherFunc->parameterTypes[i].get())) {
                return false;
            }
        }
        return true;
    }
    return false;
}

size_t FunctionType::getSize() const {
    return 8; // function pointer size
}

std::unique_ptr<Type> FunctionType::clone() const {
    std::vector<std::unique_ptr<Type>> clonedParams;
    for (const auto& param : parameterTypes) {
        clonedParams.push_back(param->clone());
    }
    return std::make_unique<FunctionType>(returnType->clone(), std::move(clonedParams));
}

// StructType implementation
void StructType::addField(std::string fieldName, std::unique_ptr<Type> fieldType) {
    size_t fieldOffset = size;
    size = fieldOffset + fieldType->getSize();
    fields.push_back({std::move(fieldName), std::move(fieldType), fieldOffset});
}

const StructField* StructType::getField(const std::string& fieldName) const {
    for (const auto& field : fields) {
        if (field.name == fieldName) {
            return &field;
        }
    }
    return nullptr;
}

std::string StructType::toString() const {
    std::stringstream ss;
    ss << "struct " << name << " {";
    for (const auto& field : fields) {
        ss << field.type->toString() << " " << field.name << "; ";
    }
    ss << "}";
    return ss.str();
}

bool StructType::isCompatibleWith(const Type* other) const {
    if (auto otherStruct = dynamic_cast<const StructType*>(other)) {
        return name == otherStruct->name;
    }
    return false;
}

size_t StructType::getSize() const {
    return size;
}

std::unique_ptr<Type> StructType::clone() const {
    auto cloned = std::make_unique<StructType>(name);
    for (const auto& field : fields) {
        cloned->addField(field.name, field.type->clone());
    }
    return cloned;
}

// TypeSystem implementation
TypeSystem::TypeSystem() {
    // Initialize primitive types
    primitiveTypes[PrimitiveType::Kind::VOID] = createPrimitiveType(PrimitiveType::Kind::VOID);
    primitiveTypes[PrimitiveType::Kind::BOOL] = createPrimitiveType(PrimitiveType::Kind::BOOL);
    primitiveTypes[PrimitiveType::Kind::CHAR] = createPrimitiveType(PrimitiveType::Kind::CHAR);
    primitiveTypes[PrimitiveType::Kind::INT] = createPrimitiveType(PrimitiveType::Kind::INT);
    primitiveTypes[PrimitiveType::Kind::LONG] = createPrimitiveType(PrimitiveType::Kind::LONG);
    primitiveTypes[PrimitiveType::Kind::FLOAT] = createPrimitiveType(PrimitiveType::Kind::FLOAT);
    primitiveTypes[PrimitiveType::Kind::DOUBLE] = createPrimitiveType(PrimitiveType::Kind::DOUBLE);
    primitiveTypes[PrimitiveType::Kind::STR] = createPrimitiveType(PrimitiveType::Kind::STR);
}

std::unique_ptr<Type> TypeSystem::createPrimitiveType(PrimitiveType::Kind kind) const {
    return std::make_unique<PrimitiveType>(kind);
}

std::unique_ptr<Type> TypeSystem::createArrayType(std::unique_ptr<Type> elementType,
                                                std::optional<size_t> size) const {
    return std::make_unique<ArrayType>(std::move(elementType), size);
}

std::unique_ptr<Type> TypeSystem::createPointerType(std::unique_ptr<Type> pointeeType) const {
    return std::make_unique<PointerType>(std::move(pointeeType));
}

std::unique_ptr<Type> TypeSystem::createFunctionType(std::unique_ptr<Type> returnType,
                                                   std::vector<std::unique_ptr<Type>> parameterTypes) const {
    return std::make_unique<FunctionType>(std::move(returnType), std::move(parameterTypes));
}

std::unique_ptr<Type> TypeSystem::createStructType(const std::string& name) const {
    return std::make_unique<StructType>(name);
}

bool TypeSystem::isCompatible(const Type* source, const Type* target) const {
    if (!source || !target) return false;
    return source->isCompatibleWith(target);
}

std::unique_ptr<Type> TypeSystem::inferBinaryOpType(const Type* left, const Type* right,
                                                   const std::string& op) const {
    if (!left || !right) return nullptr;

    auto leftPrim = dynamic_cast<const PrimitiveType*>(left);
    auto rightPrim = dynamic_cast<const PrimitiveType*>(right);

    if (leftPrim && rightPrim) {
        // String concatenation
        if (op == "+" &&
            (leftPrim->getPrimitiveKind() == PrimitiveType::Kind::STR ||
             rightPrim->getPrimitiveKind() == PrimitiveType::Kind::STR)) {
            return createPrimitiveType(PrimitiveType::Kind::STR);
        }

        // Arithmetic operations
        if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
            if (leftPrim->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE ||
                rightPrim->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE) {
                return createPrimitiveType(PrimitiveType::Kind::DOUBLE);
            }
            if (leftPrim->getPrimitiveKind() == PrimitiveType::Kind::FLOAT ||
                rightPrim->getPrimitiveKind() == PrimitiveType::Kind::FLOAT) {
                return createPrimitiveType(PrimitiveType::Kind::FLOAT);
            }
            if (leftPrim->getPrimitiveKind() == PrimitiveType::Kind::LONG ||
                rightPrim->getPrimitiveKind() == PrimitiveType::Kind::LONG) {
                return createPrimitiveType(PrimitiveType::Kind::LONG);
            }
            return createPrimitiveType(PrimitiveType::Kind::INT);
        }

        // Comparison operations
        if (op == "==" || op == "!=" || op == "<" || op == "<=" || op == ">" || op == ">=") {
            return createPrimitiveType(PrimitiveType::Kind::BOOL);
        }

        // Logical operations
        if (op == "&&" || op == "||") {
            if (leftPrim->getPrimitiveKind() == PrimitiveType::Kind::BOOL &&
                rightPrim->getPrimitiveKind() == PrimitiveType::Kind::BOOL) {
                return createPrimitiveType(PrimitiveType::Kind::BOOL);
            }
        }

        // Bitwise operations
        if (op == "&" || op == "|" || op == "^") {
            if (leftPrim->getPrimitiveKind() == PrimitiveType::Kind::INT &&
                rightPrim->getPrimitiveKind() == PrimitiveType::Kind::INT) {
                return createPrimitiveType(PrimitiveType::Kind::INT);
            }
        }
    }

    return nullptr;
}

std::unique_ptr<Type> TypeSystem::inferUnaryOpType(const Type* operand,
                                                  const std::string& op) const {
    if (!operand) return nullptr;

    auto primType = dynamic_cast<const PrimitiveType*>(operand);
    if (!primType) return nullptr;

    if (op == "!" && primType->getPrimitiveKind() == PrimitiveType::Kind::BOOL) {
        return createPrimitiveType(PrimitiveType::Kind::BOOL);
    }

    if (op == "-" || op == "+" || op == "~") {
        switch (primType->getPrimitiveKind()) {
            case PrimitiveType::Kind::INT:
            case PrimitiveType::Kind::LONG:
            case PrimitiveType::Kind::FLOAT:
            case PrimitiveType::Kind::DOUBLE:
                return operand->clone();
            default:
                break;
        }
    }

    return nullptr;
}

bool TypeSystem::canConvert(const Type* from, const Type* to) const {
    if (!from || !to) return false;

    // Same type
    if (from->isCompatibleWith(to)) return true;

    auto fromPrim = dynamic_cast<const PrimitiveType*>(from);
    auto toPrim = dynamic_cast<const PrimitiveType*>(to);

    if (fromPrim && toPrim) {
        // Numeric conversions
        switch (fromPrim->getPrimitiveKind()) {
            case PrimitiveType::Kind::INT:
                return toPrim->getPrimitiveKind() == PrimitiveType::Kind::LONG ||
                       toPrim->getPrimitiveKind() == PrimitiveType::Kind::FLOAT ||
                       toPrim->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE;
            case PrimitiveType::Kind::LONG:
                return toPrim->getPrimitiveKind() == PrimitiveType::Kind::FLOAT ||
                       toPrim->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE;
            case PrimitiveType::Kind::FLOAT:
                return toPrim->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE;
            default:
                break;
        }
    }

    // Pointer conversions
    auto fromPtr = dynamic_cast<const PointerType*>(from);
    if (auto toPtr = dynamic_cast<const PointerType*>(to)) {
        return true; // Allow any pointer conversion (unsafe)
    }

    return false;
}

std::unique_ptr<Type> TypeSystem::getCommonType(const Type* t1, const Type* t2) const {
    if (!t1 || !t2) return nullptr;

    // Same type
    if (t1->isCompatibleWith(t2)) return t1->clone();

    auto prim1 = dynamic_cast<const PrimitiveType*>(t1);
    auto prim2 = dynamic_cast<const PrimitiveType*>(t2);

    if (prim1 && prim2) {
        // Get the "wider" type
        if (prim1->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE ||
            prim2->getPrimitiveKind() == PrimitiveType::Kind::DOUBLE) {
            return createPrimitiveType(PrimitiveType::Kind::DOUBLE);
        }
        if (prim1->getPrimitiveKind() == PrimitiveType::Kind::FLOAT ||
            prim2->getPrimitiveKind() == PrimitiveType::Kind::FLOAT) {
            return createPrimitiveType(PrimitiveType::Kind::FLOAT);
        }
        if (prim1->getPrimitiveKind() == PrimitiveType::Kind::LONG ||
            prim2->getPrimitiveKind() == PrimitiveType::Kind::LONG) {
            return createPrimitiveType(PrimitiveType::Kind::LONG);
        }
        return createPrimitiveType(PrimitiveType::Kind::INT);
    }

    return nullptr;
}

void TypeSystem::registerUserType(const std::string& name, std::unique_ptr<Type> type) {
    userDefinedTypes[name] = std::move(type);
}

const Type* TypeSystem::lookupType(const std::string& name) const {
    auto it = userDefinedTypes.find(name);
    return it != userDefinedTypes.end() ? it->second.get() : nullptr;
}
