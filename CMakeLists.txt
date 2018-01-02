cmake_minimum_required(VERSION 3.10)
project(Diagram)

set(CMAKE_CXX_STANDARD 11)

file(GLOB DIAGRAM_SRC
        "include/*.h"
        "include/ast/*.h"
        "include/lib/*.h"
        "include/utils/*.h"

        "src/*.cpp"
        "src/ast/*.cpp"
        "src/lib/*.cpp"
        "src/utils/*.cpp"
        )

add_executable(diagram main.cpp ${DIAGRAM_SRC})