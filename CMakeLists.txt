cmake_minimum_required(VERSION 3.15)

project(loxcpp VERSION 0.1.0 LANGUAGES CXX)

set(SOURCE_FILES
    Lox.cpp
    TokenType.h
    Token.h
    Scanner.h
    Error.h
    )

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})