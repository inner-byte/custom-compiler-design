#ifndef RUNTIME_H
#define RUNTIME_H

#include "type_system.h"
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

// Forward declarations
class Value;
class Function;
class Module;

// Runtime type information
struct RuntimeType {
    const Type* staticType;
    size_t size;
    std::string name;
    void (*destructor)(void*);
    void (*copyConstructor)(void*, const void*);
    void (*moveConstructor)(void*, void*);
    
    RuntimeType(const Type* type, size_t s, std::string n,
                void (*dtor)(void*) = nullptr,
                void (*copy)(void*, const void*) = nullptr,
                void (*move)(void*, void*) = nullptr)
        : staticType(type), size(s), name(std::move(n)),
          destructor(dtor), copyConstructor(copy), moveConstructor(move) {}
};

// Runtime value representation
class RuntimeValue {
public:
    void* data;
    const RuntimeType* type;
    bool isLValue;
    
    RuntimeValue(void* d, const RuntimeType* t, bool lvalue = false)
        : data(d), type(t), isLValue(lvalue) {}
    
    ~RuntimeValue() {
        if (type && type->destructor) {
            type->destructor(data);
        }
    }
};

// Garbage collector interface
class GarbageCollector {
public:
    virtual ~GarbageCollector() = default;
    virtual void* allocate(size_t size) = 0;
    virtual void collect() = 0;
    virtual void addRoot(void* ptr) = 0;
    virtual void removeRoot(void* ptr) = 0;
};

// Mark-and-sweep garbage collector
class MarkAndSweepGC : public GarbageCollector {
public:
    void* allocate(size_t size) override;
    void collect() override;
    void addRoot(void* ptr) override;
    void removeRoot(void* ptr) override;

private:
    struct Block {
        void* data;
        size_t size;
        bool marked;
    };
    
    std::vector<Block> blocks;
    std::vector<void*> roots;
    
    void mark();
    void sweep();
};

// Debug information
struct DebugInfo {
    std::string file;
    int line;
    int column;
    std::string scope;
    std::vector<std::string> variables;
};

// Debug information builder
class DebugInfoBuilder {
public:
    void setSourceLocation(const std::string& file, int line, int column);
    void enterScope(const std::string& name);
    void exitScope();
    void addVariable(const std::string& name, const Type* type);
    void addFunction(const std::string& name, const Function* func);
    DebugInfo* getCurrentDebugInfo() const;
    
private:
    std::vector<std::unique_ptr<DebugInfo>> debugInfos;
    std::vector<std::string> scopeStack;
};

// Runtime environment
class Runtime {
public:
    Runtime();
    
    // Standard library functions
    void registerStdLib();
    void* allocateMemory(size_t size);
    void freeMemory(void* ptr);
    RuntimeValue* createString(const std::string& str);
    RuntimeValue* createArray(const Type* elementType, size_t size);
    
    // Exception handling
    void throwException(const std::string& message);
    void pushTryBlock(void* catchHandler);
    void popTryBlock();
    
    // Debug support
    void enterFunction(const std::string& name, const std::vector<RuntimeValue*>& args);
    void exitFunction(RuntimeValue* result);
    void setSourceLocation(const std::string& file, int line, int column);
    
    // Memory management
    GarbageCollector* getGC() { return gc.get(); }
    
    // Runtime type information
    const RuntimeType* getRuntimeType(const Type* type);
    void registerRuntimeType(std::unique_ptr<RuntimeType> type);
    
    // Standard library functions
    RuntimeValue* print(const std::vector<RuntimeValue*>& args);
    RuntimeValue* readLine();
    RuntimeValue* parseInt(RuntimeValue* str);
    RuntimeValue* parseFloat(RuntimeValue* str);
    RuntimeValue* toString(RuntimeValue* value);
    
private:
    std::unique_ptr<GarbageCollector> gc;
    std::unordered_map<const Type*, std::unique_ptr<RuntimeType>> runtimeTypes;
    std::vector<std::pair<void*, void*>> tryBlocks;  // (try block, catch handler)
    
    // Call stack for debugging
    struct StackFrame {
        std::string function;
        std::string file;
        int line;
        int column;
        std::vector<RuntimeValue*> arguments;
    };
    std::vector<StackFrame> callStack;
    
    DebugInfoBuilder debugBuilder;
};

#endif
