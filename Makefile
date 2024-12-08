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
$(BUILD_DIR)/%: %/source/%.cpp Nodes/defaultNodes/node.tpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

# Run C++ Example for a Specific Tree
run-cpp-%: $(BUILD_DIR)/%
	@echo "Running C++ example for $<..."
	@$<

# Python Script for Each Tree (Individual Rules)
run-py-AVLTrees: AVLTrees/examples/avl_tree_example.py
	@echo "Running Python example for AVL Tree..."
	@python $<

run-py-BTrees: BTrees/examples/b_tree_example.py
	@echo "Running Python example for BTree..."
	@python $<

run-py-BPTrees: BPTrees/examples/b_plus_tree_example.py
	@echo "Running Python example for BPlusTree..."
	@python $<

run-py-BinarySearchTrees: BinarySearchTrees/examples/binary_search_tree_example.py
	@echo "Running Python example for BinarySearchTree..."
	@python $<

run-py-CompleteBinaryTrees: CompleteBinaryTrees/examples/complete_binary_tree_example.py
	@echo "Running Python example for CompleteBinaryTree..."
	@python $<

run-py-FenwickTrees: FenwickTrees/examples/fenwick_tree_example.py
	@echo "Running Python example for FenwickTree..."
	@python $<

run-py-FullBinaryTrees: FullBinaryTrees/examples/full_binary_tree_example.py
	@echo "Running Python example for FullBinaryTree..."
	@python $<

run-py-PerfectBinaryTrees: PerfectBinaryTrees/examples/perfect_binary_tree_example.py
	@echo "Running Python example for PerfectBinaryTree..."
	@python $<

run-py-SegmentTrees: SegmentTrees/examples/segment_tree_example.py
	@echo "Running Python example for SegmentTree..."
	@python $<

run-py-SplayTrees: SplayTrees/examples/splay_tree_example.py
	@echo "Running Python example for SplayTree..."
	@python $<

run-py-Treaps: Treaps/examples/treap_example.py
	@echo "Running Python example for Treap..."
	@python $<

# JavaScript Script for Each Tree (Individual Rules)
run-js-AVLTrees: AVLTrees/examples/avl_tree_example.js
	@echo "Running JavaScript example for AVL Tree..."
	@node $<

run-js-BTrees: BTrees/examples/b_tree_example.js
	@echo "Running JavaScript example for BTree..."
	@node $<

run-js-BPTrees: BPTrees/examples/b_plus_tree_example.js
	@echo "Running JavaScript example for BPlusTree..."
	@node $<

run-js-BinarySearchTrees: BinarySearchTrees/examples/binary_search_tree_example.js
	@echo "Running JavaScript example for BinarySearchTree..."
	@node $<

run-js-CompleteBinaryTrees: CompleteBinaryTrees/examples/complete_binary_tree_example.js
	@echo "Running JavaScript example for CompleteBinaryTree..."
	@node $<

run-js-FenwickTrees: FenwickTrees/examples/fenwick_tree_example.js
	@echo "Running JavaScript example for FenwickTree..."
	@node $<

run-js-FullBinaryTrees: FullBinaryTrees/examples/full_binary_tree_example.js
	@echo "Running JavaScript example for FullBinaryTree..."
	@node $<

run-js-PerfectBinaryTrees: PerfectBinaryTrees/examples/perfect_binary_tree_example.js
	@echo "Running JavaScript example for PerfectBinaryTree..."
	@node $<

run-js-SegmentTrees: SegmentTrees/examples/segment_tree_example.js
	@echo "Running JavaScript example for SegmentTree..."
	@node $<

run-js-SplayTrees: SplayTrees/examples/splay_tree_example.js
	@echo "Running JavaScript example for SplayTree..."
	@node $<

run-js-Treaps: Treaps/examples/treap_example.js
	@echo "Running JavaScript example for Treap..."
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