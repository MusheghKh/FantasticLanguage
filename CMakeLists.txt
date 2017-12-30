cmake_minimum_required(VERSION 3.10)
project(OwnCpp)

set(CMAKE_CXX_STANDARD 11)

file(GLOB PINECONE_SRC "src/*.h" "src/ast/*.h" "src/*.cpp" "src/ast/*.cpp")

add_executable(OwnCpp main.cpp ${PINECONE_SRC})