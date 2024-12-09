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
        Trees/BinarySearchTrees binary_search_tree
        Trees/AVLTrees avl_tree
        Trees/BTrees b_tree
        Trees/BPTrees b_plus_tree
        Trees/CompleteBinaryTrees complete_binary_tree
        Trees/FullBinaryTrees full_binary_tree
        Trees/PerfectBinaryTrees perfect_binary_tree
        Trees/FenwickTrees fenwick_tree
        Trees/SegmentTrees segment_tree
        Trees/SplayTrees splay_tree
        Trees/Treaps treap
)

# List of graph modules and their corresponding file prefixes
set(GRAPH_MODULES_AND_FILES
        Graphs/UndirectedGraphs undirected_graph
        Graphs/DirectedGraphs directed_graph
#        Graphs/AdjacencyListGraphs adjacency_list_graph
#        Graphs/AdjacencyMatrixGraphs adjacency_matrix_graph
#        Graphs/BFSGraphs bfs_graph
#        Graphs/DFSGraphs dfs_graph
#        Graphs/BipartiteGraphs bipartite_graph
#        Graphs/DirectedAcyclicGraphs directed_acyclic_graph
#        Graphs/Hypergraphs hypergraph
#        Graphs/PlanarGraphs planar_graph
#        Graphs/Multigraphs multigraph
#        Graphs/TreeGraphs tree_graph
#        Graphs/WeightedGraphs weighted_graph
)

# Helper function to collect sources and headers for a tree module
macro(add_tree_executable MODULE_NAME FILE_PREFIX)
    # Add debug message
    message(STATUS "Adding executable for tree module: ${MODULE_NAME}, file prefix: ${FILE_PREFIX}")

    # Add executable for the tree module
    add_executable(${FILE_PREFIX}
            ${MODULE_NAME}/examples/${FILE_PREFIX}_example.cpp
            ${MODULE_NAME}/include/${FILE_PREFIX}.h
            ${MODULE_NAME}/source/${FILE_PREFIX}.tpp
    )

    # Include source and common include directories
    target_include_directories(${FILE_PREFIX} PRIVATE
            ${CMAKE_SOURCE_DIR}/${MODULE_NAME}/include
            ${COMMON_INCLUDE_DIR}
    )
endmacro()

# Helper function to collect sources and headers for a graph module
macro(add_graph_executable MODULE_NAME FILE_PREFIX)
    # Add debug message
    message(STATUS "Adding executable for graph module: ${MODULE_NAME}, file prefix: ${FILE_PREFIX}")

    # Add executable for the graph module
    add_executable(${FILE_PREFIX}
            ${MODULE_NAME}/examples/${FILE_PREFIX}_example.cpp
            ${MODULE_NAME}/include/${FILE_PREFIX}.h
            ${MODULE_NAME}/source/${FILE_PREFIX}.tpp
    )

    # Include source and common include directories
    target_include_directories(${FILE_PREFIX} PRIVATE
            ${CMAKE_SOURCE_DIR}/${MODULE_NAME}/include
            ${COMMON_INCLUDE_DIR}
    )
endmacro()

# Loop over all tree modules and add their executables
list(LENGTH TREE_MODULES_AND_FILES num_trees)
math(EXPR num_tree_modules "${num_trees} / 2 - 1")

foreach(idx RANGE 0 ${num_tree_modules})
    math(EXPR module_idx "${idx} * 2")
    math(EXPR file_idx "${module_idx} + 1")
    list(GET TREE_MODULES_AND_FILES ${module_idx} MODULE_NAME)
    list(GET TREE_MODULES_AND_FILES ${file_idx} FILE_PREFIX)

    add_tree_executable(${MODULE_NAME} ${FILE_PREFIX})
endforeach()

# Loop over all graph modules and add their executables
list(LENGTH GRAPH_MODULES_AND_FILES num_graphs)
math(EXPR num_graph_modules "${num_graphs} / 2 - 1")

foreach(idx RANGE 0 ${num_graph_modules})
    math(EXPR module_idx "${idx} * 2")
    math(EXPR file_idx "${module_idx} + 1")
    list(GET GRAPH_MODULES_AND_FILES ${module_idx} MODULE_NAME)
    list(GET GRAPH_MODULES_AND_FILES ${file_idx} FILE_PREFIX)

    add_graph_executable(${MODULE_NAME} ${FILE_PREFIX})
endforeach()

# Add include directories for Nodes
include_directories(
        ${CMAKE_SOURCE_DIR}/Nodes/defaultNodes
        ${CMAKE_SOURCE_DIR}/Nodes/BTreeNodes
        ${CMAKE_SOURCE_DIR}/Nodes/BPTreeNodes
        ${CMAKE_SOURCE_DIR}/Nodes/TreapNode
)
