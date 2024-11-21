# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(TreesAndGraphs)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR}/Nodes/defaultNodes)

# Add the executable target
add_executable(TreesAndGraphs
        main.cpp
        AVLTree/avl_tree.h
        AVLTree/avl_tree.tpp
        BinarySearchTrees/source/binary_search_tree.h
        BinarySearchTrees/source/binary_search_tree.tpp
        BPTrees/source /b_plus_tree.h
        BPTrees/source /b_plus_tree.tpp
        BTrees/source/b_tree.h
        BTrees/source/b_tree.tpp
        CompleteBinaryTrees/source/complete_binary_tree.h
        CompleteBinaryTrees/source/complete_binary_tree.tpp
        FenwickTrees/source/fenwick_tree.h
        FenwickTrees/source/fenwick_tree.tpp
        FullBinaryTrees/source/full_binary_tree.h
        FullBinaryTrees/source/full_binary_tree.tpp
        Nodes/defaultNodes/node.h
        Nodes/defaultNodes/node.tpp
        Nodes/BPTreeNodes/b_plus_tree_node.h
        Nodes/BPTreeNodes/b_plus_tree_node.tpp
        Nodes/BTreeNodes/b_tree_node.h
        Nodes/BTreeNodes/b_tree_node.tpp
        FullBinaryTrees/source/full_binary_tree.h
        FullBinaryTrees/source/full_binary_tree.tpp
        PerfectBinaryTrees/source/perfect_binary_tree.h
        PerfectBinaryTrees/source/perfect_binary_tree.tpp
        SegmentTrees/source/segment_tree.h
        SegmentTrees/source/segment_tree.tpp
        SplayTrees/source/splay_tree.h
        SplayTrees/source/splay_tree.js
)

add_executable(BinarySearchTree,
        BinarySearchTrees/binary_search_tree.h,
        BinarySearchTrees/source/binary_search_tree.tpp
        BinarySearchTrees/examples/
)
