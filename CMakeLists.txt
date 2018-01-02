cmake_minimum_required(VERSION 3.10)
project(OwnCpp)

set(CMAKE_CXX_STANDARD 11)

file(GLOB PINECONE_SRC
        "include/*.h"
        "include/ast/*.h"
        "include/lib/*.h"
        "include/utils/*.h"

        "src/*.cpp"
        "src/ast/*.cpp"
        "src/lib/*.cpp"
        "src/utils/*.cpp"
        )

add_executable(OwnCpp main.cpp ${PINECONE_SRC})