# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name of the main project
project(TreesAndGraphs)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# List of all example executables
set(EXAMPLES
        BinarySearchTree
        AVLTree
        BTree
        BPTree
        CompleteBinaryTree
        FullBinaryTree
        PerfectBinaryTree
        FenwickTree
        SegmentTree
        SplayTree
        TreapTree
)

# Include directories for all targets
include_directories(${CMAKE_SOURCE_DIR}/Nodes/defaultNodes)
include_directories(${CMAKE_SOURCE_DIR}/Nodes/BTreeNodes)
include_directories(${CMAKE_SOURCE_DIR}/Nodes/BPTreeNodes)
include_directories(${CMAKE_SOURCE_DIR}/Nodes/TreapNode)

# Add main TreesAndGraphs executable (optional if combining everything)
add_executable(TreesAndGraphs
        main.cpp
        # Add all source/header files needed for the main executable
        AVLTrees/source/avl_tree.h
        AVLTrees/source/avl_tree.tpp
        BinarySearchTrees/source/binary_search_tree.h
        BinarySearchTrees/source/binary_search_tree.tpp
        BPTrees/source/b_plus_tree.h
        BPTrees/source/b_plus_tree.tpp
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
        PerfectBinaryTrees/source/perfect_binary_tree.h
        PerfectBinaryTrees/source/perfect_binary_tree.tpp
        SegmentTrees/source/segment_tree.h
        SegmentTrees/source/segment_tree.tpp
        SplayTrees/source/splay_tree.h
        SplayTrees/source/splay_tree.tpp
        Treaps/source/treap.h
        Treaps/source/treap.tpp
)

# Add executables for all tree structures with proper paths and files
add_executable(BinarySearchTree
        BinarySearchTrees/examples/binary_search_tree_example.cpp
        BinarySearchTrees/source/binary_search_tree.h
        BinarySearchTrees/source/binary_search_tree.tpp
)

add_executable(AVLTree
        AVLTrees/examples/avl_tree_example.cpp
        AVLTrees/source/avl_tree.h
        AVLTrees/source/avl_tree.tpp
        Nodes/defaultNodes/node.h
        Nodes/defaultNodes/node.tpp
)

add_executable(BTree
        BTrees/examples/b_tree_example.cpp
        BTrees/source/b_tree.h
        BTrees/source/b_tree.tpp
        Nodes/BTreeNodes/b_tree_node.h
        Nodes/BTreeNodes/b_tree_node.tpp
)

add_executable(BPTree
        BPTrees/examples/b_plus_tree_example.cpp
        BPTrees/source/b_plus_tree.h
        BPTrees/source/b_plus_tree.tpp
        Nodes/BPTreeNodes/b_plus_tree_node.h
        Nodes/BPTreeNodes/b_plus_tree_node.tpp
)

add_executable(CompleteBinaryTree
        CompleteBinaryTrees/examples/complete_binary_tree_example.cpp
        CompleteBinaryTrees/source/complete_binary_tree.h
        CompleteBinaryTrees/source/complete_binary_tree.tpp
)

add_executable(FullBinaryTree
        FullBinaryTrees/examples/full_binary_tree_example.cpp
        FullBinaryTrees/source/full_binary_tree.h
        FullBinaryTrees/source/full_binary_tree.tpp
)

add_executable(PerfectBinaryTree
        PerfectBinaryTrees/examples/perfect_binary_tree_example.cpp
        PerfectBinaryTrees/source/perfect_binary_tree.h
        PerfectBinaryTrees/source/perfect_binary_tree.tpp
)

add_executable(FenwickTree
        FenwickTrees/examples/fenwick_tree_example.cpp
        FenwickTrees/source/fenwick_tree.h
        FenwickTrees/source/fenwick_tree.tpp
)

add_executable(SegmentTree
        SegmentTrees/examples/segment_tree_example.cpp
        SegmentTrees/source/segment_tree.h
        SegmentTrees/source/segment_tree.tpp
)

add_executable(SplayTree
        SplayTrees/examples/splay_tree_example.cpp
        SplayTrees/source/splay_tree.h
        SplayTrees/source/splay_tree.tpp
)

add_executable(TreapTree
        Treaps/examples/treap_example.cpp
        Treaps/source/treap.h
        Treaps/source/treap.tpp
        Nodes/TreapNode/treap_node.h
        Nodes/TreapNode/treap_node.tpp
)
