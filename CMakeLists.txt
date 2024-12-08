# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name of the main project
project(TreesAndGraphs)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Common include directory
set(COMMON_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")
include_directories(${COMMON_INCLUDE_DIR})

# List of tree modules and their corresponding file prefixes
set(TREE_MODULES_AND_FILES
        BinarySearchTrees binary_search_tree
        AVLTrees avl_tree
        BTrees b_tree
        BPTrees b_plus_tree
        CompleteBinaryTrees complete_binary_tree
        FullBinaryTrees full_binary_tree
        PerfectBinaryTrees perfect_binary_tree
        FenwickTrees fenwick_tree
        SegmentTrees segment_tree
        SplayTrees splay_tree
        Treaps treap
)

# Helper function to collect sources and headers for a tree module
macro(add_tree_executable MODULE_NAME FILE_PREFIX)
    # Add debug message
    message(STATUS "Adding executable for module: ${MODULE_NAME}, file prefix: ${FILE_PREFIX}")

    # Add executable for the tree module
    add_executable(${MODULE_NAME}
            ${MODULE_NAME}/examples/${FILE_PREFIX}_example.cpp
            ${MODULE_NAME}/include/${FILE_PREFIX}.h
            ${MODULE_NAME}/source/${FILE_PREFIX}.tpp
    )

    # Include source and common include directories
    target_include_directories(${MODULE_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}/${MODULE_NAME}/include
            ${COMMON_INCLUDE_DIR}
    )
endmacro()

# Loop over all tree modules and add their executables
list(LENGTH TREE_MODULES_AND_FILES num_items)
math(EXPR num_modules "${num_items} / 2 - 1")

foreach(idx RANGE 0 ${num_modules})
    math(EXPR module_idx "${idx} * 2")
    math(EXPR file_idx "${module_idx} + 1")
    list(GET TREE_MODULES_AND_FILES ${module_idx} MODULE_NAME)
    list(GET TREE_MODULES_AND_FILES ${file_idx} FILE_PREFIX)

    add_tree_executable(${MODULE_NAME} ${FILE_PREFIX})
endforeach()

# Add include directories for Nodes
include_directories(
        ${CMAKE_SOURCE_DIR}/Nodes/defaultNodes
        ${CMAKE_SOURCE_DIR}/Nodes/BTreeNodes
        ${CMAKE_SOURCE_DIR}/Nodes/BPTreeNodes
        ${CMAKE_SOURCE_DIR}/Nodes/TreapNode
)
