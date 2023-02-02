cmake_minimum_required (VERSION 2.8.11)
project(BinaryTree)

set(SOURCES
    src/main.cpp
    src/binarytree.cpp
    src/avltree.cpp
)

add_executable(app ${SOURCES})