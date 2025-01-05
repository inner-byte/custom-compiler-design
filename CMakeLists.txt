cmake_minimum_required(VERSION 3.10)
    project(compiler)

    set(CMAKE_CXX_STANDARD 17)

    find_package(BISON REQUIRED)
    find_package(FLEX REQUIRED)

    BISON_TARGET(parser parser.y parser.cpp)
    FLEX_TARGET(lexer lexer.l lexer.cpp)

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

    add_executable(compiler
        src/main.cpp
        src/lexer.cpp
        src/parser.cpp
        src/codegen.cpp
        ${parser_OUTPUTS}
        ${lexer_OUTPUTS}
    )
