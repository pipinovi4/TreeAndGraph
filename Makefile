# Build Directory
BUILD_DIR = build

# C++ Executables
CPP_EXECUTABLES = \
	$(BUILD_DIR)/avl_tree \
	$(BUILD_DIR)/b_tree \
	$(BUILD_DIR)/bplus_tree \
	$(BUILD_DIR)/binary_search_tree \
	$(BUILD_DIR)/complete_binary_tree \
	$(BUILD_DIR)/fenwick_tree \
	$(BUILD_DIR)/full_binary_tree \
	$(BUILD_DIR)/perfect_binary_tree \
	$(BUILD_DIR)/segment_tree \
	$(BUILD_DIR)/splay_tree \
	$(BUILD_DIR)/treap

# Python Scripts
PYTHON_SCRIPTS = \
	AVLTree/avl_tree.py \
	BTrees/b_tree.py \
	BPTrees/bplus_tree.py \
	BinarySearchTrees/binary_search_tree.py \
	CompleteBinaryTrees/complete_binary_tree.py \
	FenwickTrees/fenwick_tree.py \
	FullBinaryTrees/full_binary_tree.py \
	PerfectBinaryTrees/perfect_binary_tree.py \
	SegmentTrees/segment_tree.py \
	SplayTrees/splay_tree.py \
	Treaps/treap.py

# JavaScript Scripts
JS_SCRIPTS = \
	AVLTree/avl_tree.js \
	BTrees/b_tree.js \
	BPTrees/bplus_tree.js \
	BinarySearchTrees/binary_search_tree.js \
	CompleteBinaryTrees/complete_binary_tree.js \
	FenwickTrees/fenwick_tree.js \
	FullBinaryTrees/full_binary_tree.js \
	PerfectBinaryTrees/perfect_binary_tree.js \
	SegmentTrees/segment_tree.js \
	SplayTrees/splay_tree.js \
	Treaps/treap.js

# Default target: Build and prepare everything
all: $(CPP_EXECUTABLES)

# Build Rules for C++ Executables
$(BUILD_DIR)/avl_tree: AVLTree/cpp/main.cpp AVLTree/cpp/avl_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/b_tree: BTrees/cpp/main.cpp BTrees/cpp/b_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/bplus_tree: BPTrees/cpp/main.cpp BPTrees/cpp/bplus_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/binary_search_tree: BinarySearchTrees/cpp/main.cpp BinarySearchTrees/cpp/binary_search_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/complete_binary_tree: CompleteBinaryTrees/cpp/main.cpp CompleteBinaryTrees/cpp/complete_binary_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/fenwick_tree: FenwickTrees/cpp/main.cpp FenwickTrees/cpp/fenwick_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/full_binary_tree: FullBinaryTrees/cpp/main.cpp FullBinaryTrees/cpp/full_binary_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/perfect_binary_tree: PerfectBinaryTrees/cpp/main.cpp PerfectBinaryTrees/cpp/perfect_binary_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/segment_tree: SegmentTrees/cpp/main.cpp SegmentTrees/cpp/segment_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/splay_tree: SplayTrees/cpp/main.cpp SplayTrees/cpp/splay_tree.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

$(BUILD_DIR)/treap: Treaps/cpp/main.cpp Treaps/cpp/treap.cpp Nodes/defaultNodes/node.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ $^

# Run Rules for Python
run-python:
	@echo "Running Python Scripts..."
	@for script in $(PYTHON_SCRIPTS); do \
		echo "Running $$script"; \
		python $$script; \
	done

# Run Rules for JavaScript
run-js:
	@echo "Running JavaScript Scripts..."
	@for script in $(JS_SCRIPTS); do \
		echo "Running $$script"; \
		node $$script; \
	done

# Run Rules for C++
run-cpp:
	@echo "Running C++ Executables..."
	@for exe in $(CPP_EXECUTABLES); do \
		echo "Running $$exe"; \
		$$exe; \
	done

# Clean Build Artifacts
clean:
	@echo "Cleaning up build directory..."
	rm -rf $(BUILD_DIR)
