#ifndef TYPE_SYSTEM_H
#define TYPE_SYSTEM_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <optional>

class Type;
class ArrayType;
class PointerType;
class FunctionType;
class StructType;

enum class TypeKind {
    PRIMITIVE,
    ARRAY,
    POINTER,
    FUNCTION,
    STRUCT,
    UNION,
    ENUM
};

// Base class for all types
class Type {
public:
    virtual ~Type() = default;
    virtual TypeKind getKind() const = 0;
    virtual std::string toString() const = 0;
    virtual bool isCompatibleWith(const Type* other) const = 0;
    virtual size_t getSize() const = 0;
    virtual std::unique_ptr<Type> clone() const = 0;
};

// Primitive types (int, float, char, etc.)
class PrimitiveType : public Type {
public:
    enum class Kind {
        VOID,
        BOOL,
        CHAR,
        INT,
        LONG,
        FLOAT,
        DOUBLE,
        STR
    };

    explicit PrimitiveType(Kind kind) : kind(kind) {}
    TypeKind getKind() const override { return TypeKind::PRIMITIVE; }
    Kind getPrimitiveKind() const { return kind; }
    std::string toString() const override;
    bool isCompatibleWith(const Type* other) const override;
    size_t getSize() const override;
    std::unique_ptr<Type> clone() const override;

private:
    Kind kind;
};

// Array type
class ArrayType : public Type {
public:
    ArrayType(std::unique_ptr<Type> elementType, std::optional<size_t> size = std::nullopt)
        : elementType(std::move(elementType)), size(size) {}
    
    TypeKind getKind() const override { return TypeKind::ARRAY; }
    const Type* getElementType() const { return elementType.get(); }
    std::optional<size_t> getArraySize() const { return size; }
    std::string toString() const override;
    bool isCompatibleWith(const Type* other) const override;
    size_t getSize() const override;
    std::unique_ptr<Type> clone() const override;

private:
    std::unique_ptr<Type> elementType;
    std::optional<size_t> size;  // nullopt for dynamic arrays
};

// Pointer type
class PointerType : public Type {
public:
    explicit PointerType(std::unique_ptr<Type> pointeeType)
        : pointeeType(std::move(pointeeType)) {}
    
    TypeKind getKind() const override { return TypeKind::POINTER; }
    const Type* getPointeeType() const { return pointeeType.get(); }
    std::string toString() const override;
    bool isCompatibleWith(const Type* other) const override;
    size_t getSize() const override;
    std::unique_ptr<Type> clone() const override;

private:
    std::unique_ptr<Type> pointeeType;
};

// Function type
class FunctionType : public Type {
public:
    FunctionType(std::unique_ptr<Type> returnType, std::vector<std::unique_ptr<Type>> parameterTypes)
        : returnType(std::move(returnType)), parameterTypes(std::move(parameterTypes)) {}
    
    TypeKind getKind() const override { return TypeKind::FUNCTION; }
    const Type* getReturnType() const { return returnType.get(); }
    const std::vector<std::unique_ptr<Type>>& getParameterTypes() const { return parameterTypes; }
    std::string toString() const override;
    bool isCompatibleWith(const Type* other) const override;
    size_t getSize() const override;
    std::unique_ptr<Type> clone() const override;

private:
    std::unique_ptr<Type> returnType;
    std::vector<std::unique_ptr<Type>> parameterTypes;
};

// Struct field
struct StructField {
    std::string name;
    std::unique_ptr<Type> type;
    size_t offset;
};

// Struct type
class StructType : public Type {
public:
    explicit StructType(std::string name) : name(std::move(name)) {}
    virtual ~StructType() = default;
    TypeKind getKind() const override { return TypeKind::STRUCT; }
    const std::string& getName() const { return name; }
    void addField(std::string fieldName, std::unique_ptr<Type> fieldType);
    const StructField* getField(const std::string& fieldName) const;
    const std::vector<StructField>& getFields() const { return fields; }
    std::string toString() const override;
    bool isCompatibleWith(const Type* other) const override;
    size_t getSize() const override;
    std::unique_ptr<Type> clone() const override;

private:
    std::string name;
    std::vector<StructField> fields;
    size_t size = 0;
};

// Type system manager
class TypeSystem {
public:
    TypeSystem();

    // Type creation
    std::unique_ptr<Type> createPrimitiveType(PrimitiveType::Kind kind) const;
    std::unique_ptr<Type> createArrayType(std::unique_ptr<Type> elementType,
                                        std::optional<size_t> size = std::nullopt) const;
    std::unique_ptr<Type> createPointerType(std::unique_ptr<Type> pointeeType) const;
    std::unique_ptr<Type> createFunctionType(std::unique_ptr<Type> returnType,
                                           std::vector<std::unique_ptr<Type>> parameterTypes) const;
    std::unique_ptr<Type> createStructType(const std::string& name) const;

    // Type checking and inference
    bool isCompatible(const Type* source, const Type* target) const;
    std::unique_ptr<Type> inferBinaryOpType(const Type* left, const Type* right,
                                          const std::string& op) const;
    std::unique_ptr<Type> inferUnaryOpType(const Type* operand,
                                          const std::string& op) const;

    // Type conversion
    bool canConvert(const Type* from, const Type* to) const;
    std::unique_ptr<Type> getCommonType(const Type* t1, const Type* t2) const;

    // User-defined types
    void registerUserType(const std::string& name, std::unique_ptr<Type> type);
    const Type* lookupType(const std::string& name) const;

private:
    mutable std::unordered_map<std::string, std::unique_ptr<Type>> userDefinedTypes;
    mutable std::unordered_map<PrimitiveType::Kind, std::unique_ptr<Type>> primitiveTypes;
};

#endif
