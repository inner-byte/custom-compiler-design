CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
LDFLAGS = -ly -ll

# Source files
SRCS = src/lexer.cpp \
       src/parser.cpp \
       src/type_system.cpp \
       src/codegen.cpp \
       src/runtime.cpp \
       src/optimization.cpp \
       src/register_allocator.cpp \
       src/basic_block.cpp \
       src/symbol_table.cpp

# Test files
TEST_SRCS = test/test_runner.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Targets
all: compiler test_runner

# Create necessary directories
$(shell mkdir -p include src)

# Parser generation
src/parser.cpp include/parser.hpp: parser.y
	bison -d -o src/parser.cpp parser.y
	mv src/parser.hpp include/parser.hpp

# Lexer generation
src/lexer.cpp: lexer.l include/parser.hpp
	flex -o src/lexer.cpp lexer.l

# Compiler executable
compiler: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Test runner executable
test_runner: $(OBJS) $(TEST_OBJS)
	$(CXX) $(OBJS) $(TEST_OBJS) -o $@ $(LDFLAGS)

# Object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test/%.o: test/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies
src/lexer.o: src/lexer.cpp include/parser.hpp
src/parser.o: src/parser.cpp include/parser.hpp
src/parser.cpp: parser.y
src/lexer.cpp: lexer.l

# Run tests
test: test_runner
	./test_runner

# Clean
clean:
	rm -f src/*.o test/*.o compiler test_runner src/parser.cpp include/parser.hpp src/lexer.cpp

.PHONY: all clean test
