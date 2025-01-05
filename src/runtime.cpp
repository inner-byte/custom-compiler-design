#include "../include/runtime.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

// Runtime implementation
Runtime::Runtime() : gc(std::make_unique<MarkAndSweepGC>()) {
    registerStdLib();
}

void Runtime::registerStdLib() {
    // Register primitive types
    auto intType = std::make_unique<RuntimeType>(
        nullptr, sizeof(int), "int",
        nullptr,  // No destructor needed
        [](void* dst, const void* src) { *(int*)dst = *(const int*)src; },
        [](void* dst, void* src) { *(int*)dst = *(int*)src; }
    );
    
    auto floatType = std::make_unique<RuntimeType>(
        nullptr, sizeof(double), "float",
        nullptr,  // No destructor needed
        [](void* dst, const void* src) { *(double*)dst = *(const double*)src; },
        [](void* dst, void* src) { *(double*)dst = *(double*)src; }
    );
    
    auto boolType = std::make_unique<RuntimeType>(
        nullptr, sizeof(bool), "bool",
        nullptr,  // No destructor needed
        [](void* dst, const void* src) { *(bool*)dst = *(const bool*)src; },
        [](void* dst, void* src) { *(bool*)dst = *(bool*)src; }
    );
    
    auto stringType = std::make_unique<RuntimeType>(
        nullptr, sizeof(std::string), "string",
        [](void* ptr) { ((std::string*)ptr)->~basic_string(); },
        [](void* dst, const void* src) { new(dst) std::string(*(const std::string*)src); },
        [](void* dst, void* src) { new(dst) std::string(std::move(*(std::string*)src)); }
    );
    
    runtimeTypes[nullptr] = std::move(intType);
    runtimeTypes[nullptr] = std::move(floatType);
    runtimeTypes[nullptr] = std::move(boolType);
    runtimeTypes[nullptr] = std::move(stringType);
}

void* Runtime::allocateMemory(size_t size) {
    return gc->allocate(size);
}

void Runtime::freeMemory(void* ptr) {
    // Memory is managed by GC, no explicit free needed
}

RuntimeValue* Runtime::createString(const std::string& str) {
    void* memory = allocateMemory(sizeof(std::string));
    new (memory) std::string(str);
    return new RuntimeValue(memory, getRuntimeType(nullptr));  // TODO: Get proper string type
}

RuntimeValue* Runtime::createArray(const Type* elementType, size_t size) {
    size_t elementSize = getRuntimeType(elementType)->size;
    void* memory = allocateMemory(size * elementSize);
    // Initialize array elements
    for (size_t i = 0; i < size; ++i) {
        void* element = (char*)memory + i * elementSize;
        if (getRuntimeType(elementType)->copyConstructor) {
            getRuntimeType(elementType)->copyConstructor(element, nullptr);
        }
    }
    return new RuntimeValue(memory, getRuntimeType(elementType));
}

void Runtime::throwException(const std::string& message) {
    if (tryBlocks.empty()) {
        std::cerr << "Unhandled exception: " << message << std::endl;
        std::abort();
    }
    
    // Jump to the nearest catch handler
    auto [tryBlock, catchHandler] = tryBlocks.back();
    tryBlocks.pop_back();
    // TODO: Implement actual exception handling
}

void Runtime::pushTryBlock(void* catchHandler) {
    tryBlocks.push_back({nullptr, catchHandler});
}

void Runtime::popTryBlock() {
    if (!tryBlocks.empty()) {
        tryBlocks.pop_back();
    }
}

void Runtime::enterFunction(const std::string& name, const std::vector<RuntimeValue*>& args) {
    StackFrame frame;
    frame.function = name;
    frame.arguments = args;
    callStack.push_back(frame);
    debugBuilder.enterScope(name);
}

void Runtime::exitFunction(RuntimeValue* result) {
    if (!callStack.empty()) {
        callStack.pop_back();
        debugBuilder.exitScope();
    }
}

void Runtime::setSourceLocation(const std::string& file, int line, int column) {
    if (!callStack.empty()) {
        callStack.back().file = file;
        callStack.back().line = line;
        callStack.back().column = column;
    }
    debugBuilder.setSourceLocation(file, line, column);
}

const RuntimeType* Runtime::getRuntimeType(const Type* type) {
    auto it = runtimeTypes.find(type);
    return it != runtimeTypes.end() ? it->second.get() : nullptr;
}

void Runtime::registerRuntimeType(std::unique_ptr<RuntimeType> type) {
    runtimeTypes[type->staticType] = std::move(type);
}

// Standard library implementation
RuntimeValue* Runtime::print(const std::vector<RuntimeValue*>& args) {
    for (auto arg : args) {
        if (arg->type->name == "string") {
            std::cout << *(std::string*)arg->data;
        } else if (arg->type->name == "int") {
            std::cout << *(int*)arg->data;
        } else if (arg->type->name == "float") {
            std::cout << *(double*)arg->data;
        }
    }
    std::cout << std::endl;
    return nullptr;
}

RuntimeValue* Runtime::readLine() {
    std::string line;
    std::getline(std::cin, line);
    return createString(line);
}

RuntimeValue* Runtime::parseInt(RuntimeValue* str) {
    if (str->type->name != "string") {
        throwException("parseInt expects a string argument");
        return nullptr;
    }
    
    try {
        int value = std::stoi(*(std::string*)str->data);
        void* memory = allocateMemory(sizeof(int));
        *(int*)memory = value;
        return new RuntimeValue(memory, getRuntimeType(nullptr));  // TODO: Get proper int type
    } catch (...) {
        throwException("Invalid integer format");
        return nullptr;
    }
}

RuntimeValue* Runtime::parseFloat(RuntimeValue* str) {
    if (str->type->name != "string") {
        throwException("parseFloat expects a string argument");
        return nullptr;
    }
    
    try {
        double value = std::stod(*(std::string*)str->data);
        void* memory = allocateMemory(sizeof(double));
        *(double*)memory = value;
        return new RuntimeValue(memory, getRuntimeType(nullptr));  // TODO: Get proper float type
    } catch (...) {
        throwException("Invalid float format");
        return nullptr;
    }
}

RuntimeValue* Runtime::toString(RuntimeValue* value) {
    std::stringstream ss;
    if (value->type->name == "int") {
        ss << *(int*)value->data;
    } else if (value->type->name == "float") {
        ss << *(double*)value->data;
    } else if (value->type->name == "string") {
        return value;  // Already a string
    } else {
        ss << "<" << value->type->name << ">";
    }
    return createString(ss.str());
}

// Mark-and-sweep garbage collector implementation
void* MarkAndSweepGC::allocate(size_t size) {
    void* memory = std::malloc(size);
    blocks.push_back({memory, size, false});
    return memory;
}

void MarkAndSweepGC::collect() {
    mark();
    sweep();
}

void MarkAndSweepGC::addRoot(void* ptr) {
    roots.push_back(ptr);
}

void MarkAndSweepGC::removeRoot(void* ptr) {
    auto it = std::find(roots.begin(), roots.end(), ptr);
    if (it != roots.end()) {
        roots.erase(it);
    }
}

void MarkAndSweepGC::mark() {
    // Reset marks
    for (auto& block : blocks) {
        block.marked = false;
    }
    
    // Mark from roots
    for (void* root : roots) {
        for (auto& block : blocks) {
            if (block.data == root) {
                block.marked = true;
                break;
            }
        }
    }
}

void MarkAndSweepGC::sweep() {
    auto it = blocks.begin();
    while (it != blocks.end()) {
        if (!it->marked) {
            std::free(it->data);
            it = blocks.erase(it);
        } else {
            ++it;
        }
    }
}

// Debug information builder implementation
void DebugInfoBuilder::setSourceLocation(const std::string& file, int line, int column) {
    auto info = std::make_unique<DebugInfo>();
    info->file = file;
    info->line = line;
    info->column = column;
    info->scope = scopeStack.empty() ? "global" : scopeStack.back();
    debugInfos.push_back(std::move(info));
}

void DebugInfoBuilder::enterScope(const std::string& name) {
    scopeStack.push_back(name);
}

void DebugInfoBuilder::exitScope() {
    if (!scopeStack.empty()) {
        scopeStack.pop_back();
    }
}

void DebugInfoBuilder::addVariable(const std::string& name, const Type* type) {
    if (!debugInfos.empty()) {
        debugInfos.back()->variables.push_back(name);
    }
}

void DebugInfoBuilder::addFunction(const std::string& name, const Function* func) {
    enterScope(name);
}

DebugInfo* DebugInfoBuilder::getCurrentDebugInfo() const {
    return debugInfos.empty() ? nullptr : debugInfos.back().get();
}
