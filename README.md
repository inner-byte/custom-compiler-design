# Advanced Compiler Design Project

## Overview

This project implements a full-featured compiler for a custom programming language, demonstrating modern compiler design principles and optimization techniques. The compiler follows the traditional multi-pass compilation process while incorporating advanced features like optimization frameworks and sophisticated register allocation.

## Architecture

The compiler is structured into several major components:

### Frontend
- **Lexical Analysis**: 
  - Implemented using Flex for efficient token generation
  - Handles source code tokenization with support for complex language constructs
  - Located in [lexer.l](lexer.l) and [src/lexer.cpp](src/lexer.cpp)

- **Parsing**:
  - Built with Bison for robust grammar processing
  - Generates Abstract Syntax Tree (AST) representation
  - Implements error recovery mechanisms
  - Core files: [parser.y](parser.y) and [src/parser.cpp](src/parser.cpp)

### Middle-end
- **Semantic Analysis**:
  - Comprehensive type checking system ([src/type_system.cpp](src/type_system.cpp))
  - Symbol table management for variable scoping ([src/symbol_table.cpp](src/symbol_table.cpp))
  - Semantic error detection and reporting

- **Optimization Framework**:
  - Multiple optimization passes:
    - Common subexpression elimination
    - Dead code elimination
    - Constant propagation
    - Loop optimization
  - Configurable optimization levels
  - Implementation in [src/optimization.cpp](src/optimization.cpp)

### Backend
- **Code Generation**:
  - Target-specific code emission
  - Efficient instruction selection
  - Located in [src/codegen.cpp](src/codegen.cpp)

- **Register Allocation**:
  - Graph coloring-based register allocation
  - Register spilling handling
  - Implemented in [src/register_allocator.cpp](src/register_allocator.cpp)

## Building the Project

### Prerequisites
- CMake (3.10 or higher)
- C++ compiler supporting C++17
- Flex and Bison
- Make

### Build Options

#### Using CMake (Recommended)
```bash
mkdir build && cd build
cmake ..
make
```

#### Using Make
```bash
make
```

## Project Structure

```
.
├── include/           # Header files
├── src/              # Source implementations
├── test/             # Test suite
├── lexer.l           # Flex lexer definition
├── parser.y          # Bison parser grammar
├── CMakeLists.txt    # CMake configuration
└── Makefile         # Traditional build support
```

## Current Status

### Implemented Features
- Complete frontend pipeline (lexing, parsing)
- Type system with static type checking
- Basic optimization framework
- Register allocation using graph coloring
- Runtime support system

### Roadmap
1. **Short-term Goals**
   - Enhance optimization passes
   - Improve error reporting
   - Extend type system

2. **Medium-term Goals**
   - Implement advanced optimizations
   - Add cross-platform support
   - Enhance debugging information

3. **Long-term Vision**
   - JIT compilation support
   - Parallel compilation
   - Language server protocol integration

## Contributing

We welcome contributions! Please follow these steps:

1. Fork the repository
2. Create a feature branch
3. Implement your changes
4. Add tests for new functionality
5. Submit a pull request

### Development Guidelines
- Follow the existing code style
- Add documentation for new features
- Ensure all tests pass
- Update relevant documentation

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- The LLVM Project for inspiration
- The GCC community for optimization insights
- Contributors and maintainers

