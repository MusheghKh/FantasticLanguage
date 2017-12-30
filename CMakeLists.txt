cmake_minimum_required(VERSION 3.10)
project(OwnCpp)

set(CMAKE_CXX_STANDARD 11)

file(GLOB PINECONE_SRC "src/*.h" "src/ast/*.h" "src/lib/*.h" "src/*.cpp" "src/ast/*.cpp" "src/lib/*.cpp")

add_executable(OwnCpp main.cpp ${PINECONE_SRC})