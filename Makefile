# Build Directory
BUILD_DIR = build

# List of C++ Trees (lowercase to match the pattern)
CPP_TREES = avl_tree b_tree bplus_tree binary_search_tree complete_binary_tree \
             fenwick_tree full_binary_tree perfect_binary_tree segment_tree \
             splay_tree treap

# Default target: Build everything
all: build $(CPP_TREES:%=$(BUILD_DIR)/%)

.PHONY: build clean

# Build Rules for C++ Executables
$(BUILD_DIR)/%: %/source/%.cpp Trees/Nodes
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

# Run C++ Example for a Specific Tree
run-cpp-%: $(BUILD_DIR)/%
	@echo "Running C++ example for $<..."
	@$<

# Python and JavaScript targets for all Tree Types

# Python Script for Each Tree (Individual Rules)
run-py-AVLTrees: Trees/AVLTrees/examples/avl_tree_example.py
	@echo "Running Python example for AVL Tree..."
	@python $<

run-py-BTrees: Trees/BTrees/examples/b_tree_example.py
	@echo "Running Python example for BTree..."
	@python $<

run-py-BPTrees: Trees/BPTrees/examples/b_plus_tree_example.py
	@echo "Running Python example for BPlusTree..."
	@python $<

run-py-BinarySearchTrees: Trees/BinarySearchTrees/examples/binary_search_tree_example.py
	@echo "Running Python example for BinarySearchTree..."
	@python $<

run-py-CompleteBinaryTrees: Trees/CompleteBinaryTrees/examples/complete_binary_tree_example.py
	@echo "Running Python example for CompleteBinaryTree..."
	@python $<

run-py-FenwickTrees: Trees/FenwickTrees/examples/fenwick_tree_example.py
	@echo "Running Python example for FenwickTree..."
	@python $<

run-py-FullBinaryTrees: Trees/FullBinaryTrees/examples/full_binary_tree_example.py
	@echo "Running Python example for FullBinaryTree..."
	@python $<

run-py-PerfectBinaryTrees: Trees/PerfectBinaryTrees/examples/perfect_binary_tree_example.py
	@echo "Running Python example for PerfectBinaryTree..."
	@python $<

run-py-SegmentTrees: Trees/SegmentTrees/examples/segment_tree_example.py
	@echo "Running Python example for SegmentTree..."
	@python $<

run-py-SplayTrees: Trees/SplayTrees/examples/splay_tree_example.py
	@echo "Running Python example for SplayTree..."
	@python $<

run-py-Treaps: Trees/Treaps/examples/treap_example.py
	@echo "Running Python example for Treap..."
	@python $<

# JavaScript Script for Each Tree (Individual Rules)
run-js-AVLTrees: Trees/AVLTrees/examples/avl_tree_example.js
	@echo "Running JavaScript example for AVL Tree..."
	@node $<

run-js-BTrees: Trees/BTrees/examples/b_tree_example.js
	@echo "Running JavaScript example for BTree..."
	@node $<

run-js-BPTrees: Trees/BPTrees/examples/b_plus_tree_example.js
	@echo "Running JavaScript example for BPlusTree..."
	@node $<

run-js-BinarySearchTrees: Trees/BinarySearchTrees/examples/binary_search_tree_example.js
	@echo "Running JavaScript example for BinarySearchTree..."
	@node $<

run-js-CompleteBinaryTrees: Trees/CompleteBinaryTrees/examples/complete_binary_tree_example.js
	@echo "Running JavaScript example for CompleteBinaryTree..."
	@node $<

run-js-FenwickTrees: Trees/FenwickTrees/examples/fenwick_tree_example.js
	@echo "Running JavaScript example for FenwickTree..."
	@node $<

run-js-FullBinaryTrees: Trees/FullBinaryTrees/examples/full_binary_tree_example.js
	@echo "Running JavaScript example for FullBinaryTree..."
	@node $<

run-js-PerfectBinaryTrees: Trees/PerfectBinaryTrees/examples/perfect_binary_tree_example.js
	@echo "Running JavaScript example for PerfectBinaryTree..."
	@node $<

run-js-SegmentTrees: Trees/SegmentTrees/examples/segment_tree_example.js
	@echo "Running JavaScript example for SegmentTree..."
	@node $<

run-js-SplayTrees: Trees/SplayTrees/examples/splay_tree_example.js
	@echo "Running JavaScript example for SplayTree..."
	@node $<

run-js-Treaps: Trees/Treaps/examples/treap_example.js
	@echo "Running JavaScript example for Treap..."
	@node $<

# Python and JavaScript targets for all Graph Types

# Adjacency List Graph
run-py-adjacency_list_graph: Graphs/AdjacencyListGraphs/examples/adjacency_list_graph_example.py
	@echo "Running Python example for AdjacencyListGraph..."
	@python $<

run-js-adjacency_list_graph: Graphs/AdjacencyListGraphs/examples/adjacency_list_graph_example.js
	@echo "Running JavaScript example for AdjacencyListGraph..."
	@node $<

# Adjacency Matrix Graph
run-py-adjacency_matrix_graph: Graphs/AdjacencyMatrixGraphs/examples/adjacency_matrix_graph_example.py
	@echo "Running Python example for AdjacencyMatrixGraph..."
	@python $<

run-js-adjacency_matrix_graph: Graphs/AdjacencyMatrixGraphs/examples/adjacency_matrix_graph_example.js
	@echo "Running JavaScript example for AdjacencyMatrixGraph..."
	@node $<

# BFS Graph
run-py-bfs_graph: Graphs/BFSGraphs/examples/bfs_graph_example.py
	@echo "Running Python example for BFSGraph..."
	@python $<

run-js-bfs_graph: Graphs/BFSGraphs/examples/bfs_graph_example.js
	@echo "Running JavaScript example for BFSGraph..."
	@node $<

# Bipartite Graph
run-py-bipartite_graph: Graphs/BipartiteGraphs/examples/bipartite_graph_example.py
	@echo "Running Python example for BipartiteGraph..."
	@python $<

run-js-bipartite_graph: Graphs/BipartiteGraphs/examples/bipartite_graph_example.js
	@echo "Running JavaScript example for BipartiteGraph..."
	@node $<

# DFS Graph
run-py-dfs_graph: Graphs/DFSGraphs/examples/dfs_graph_example.py
	@echo "Running Python example for DFSGraph..."
	@python $<

run-js-dfs_graph: Graphs/DFSGraphs/examples/dfs_graph_example.js
	@echo "Running JavaScript example for DFSGraph..."
	@node $<

# Directed Acyclic Graph
run-py-directed_acyclic_graph: Graphs/DirectedAcyclicGraphs/examples/directed_acyclic_graph_example.py
	@echo "Running Python example for DirectedAcyclicGraph..."
	@python $<

run-js-directed_acyclic_graph: Graphs/DirectedAcyclicGraphs/examples/directed_acyclic_graph_example.js
	@echo "Running JavaScript example for DirectedAcyclicGraph..."
	@node $<

# Directed Graph
run-py-directed_graph: Graphs/DirectedGraphs/examples/directed_graph_example.py
	@echo "Running Python example for DirectedGraph..."
	@python $<

run-js-directed_graph: Graphs/DirectedGraphs/examples/directed_graph_example.js
	@echo "Running JavaScript example for DirectedGraph..."
	@node $<

# Hypergraph
run-py-hypergraph: Graphs/Hypergraphs/examples/hypergraph_example.py
	@echo "Running Python example for Hypergraph..."
	@python $<

run-js-hypergraph: Graphs/Hypergraphs/examples/hypergraph_example.js
	@echo "Running JavaScript example for Hypergraph..."
	@node $<

# Multigraph
run-py-multigraph: Graphs/Multigraphs/examples/multigraph_example.py
	@echo "Running Python example for Multigraph..."
	@python $<

run-js-multigraph: Graphs/Multigraphs/examples/multigraph_example.js
	@echo "Running JavaScript example for Multigraph..."
	@node $<

# Planar Graph
run-py-planar_graph: Graphs/PlanarGraphs/examples/planar_graph_example.py
	@echo "Running Python example for PlanarGraph..."
	@python $<

run-js-planar_graph: Graphs/PlanarGraphs/examples/planar_graph_example.js
	@echo "Running JavaScript example for PlanarGraph..."
	@node $<

# Tree Graph
run-py-tree_graph: Graphs/TreeGraphs/examples/tree_graph_example.py
	@echo "Running Python example for TreeGraph..."
	@python $<

run-js-tree_graph: Graphs/TreeGraphs/examples/tree_graph_example.js
	@echo "Running JavaScript example for TreeGraph..."
	@node $<

# Undirected Graph
run-py-undirected_graph: Graphs/UndirectedGraphs/examples/undirected_graph_example.py
	@echo "Running Python example for UndirectedGraph..."
	@python $<

run-js-undirected_graph: Graphs/UndirectedGraphs/examples/undirected_graph_example.js
	@echo "Running JavaScript example for UndirectedGraph..."
	@node $<

# Weighted Graph
run-py-weighted_graph: Graphs/WeightedGraph/examples/weighted_graph_example.py
	@echo "Running Python example for WeightedGraph..."
	@python $<

run-js-weighted_graph: Graphs/WeightedGraph/examples/weighted_graph_example.js
	@echo "Running JavaScript example for WeightedGraph..."
	@node $<

# Build the project
build:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)
	@echo "Running CMake build..."
	mkdir build && cd $(BUILD_DIR) && cmake .. && cmake --build .

# Clean Build Artifacts
clean:
	@echo "Cleaning up build directory..."
	rm -rf $(BUILD_DIR)

# Path to your virtual environment
VENV_PATH = .venv

# Target to add dynamic PYTHONPATH export to the venv activate script
add-pythonpath:
	@echo "Adding dynamic PYTHONPATH to $(VENV_PATH)/bin/activate"
	@echo 'export PYTHONPATH=$$(pwd)' >> $(VENV_PATH)/bin/activate
	@echo "Dynamic PYTHONPATH added."

# Target to create a virtual environment and add PYTHONPATH
setup-venv:
	@echo "Creating virtual environment..."
	python3 -m venv $(VENV_PATH)
	$(MAKE) add-pythonpath
	@echo "Virtual environment setup completed."

# Clean the virtual environment (optional)
clean-venv:
	@echo "Removing virtual environment..."
	rm -rf $(VENV_PATH)
	@echo "Virtual environment removed."