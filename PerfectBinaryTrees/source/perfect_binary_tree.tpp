#ifndef PERFECT_BINARY_TREE_TPP
#define PERFECT_BINARY_TREE_TPP

#include "perfect_binary_tree.h" // Include the header file for PerfectBinaryTree
#include <stack> // Include stack for iterative traversal
#include <queue> // Include queue for level-order construction
#include <iostream> // Include iostream for displaying data in terminal

// Constructor implementation
PerfectBinaryTree::PerfectBinaryTree(const std::vector<int>& data, const int depth) {
    root = buildPerfectTree(data, depth);  // Build the perfect tree upon initialization
}

// Destructor implementation
PerfectBinaryTree::~PerfectBinaryTree() {
    delete root;  // Delete the root node to free up memory
}

// Recursive function to build a perfect binary tree from provided data
Node* PerfectBinaryTree::buildPerfectTree(std::vector<int> data, const int depth) {
    if (depth == 0 || data.empty()) {
        return nullptr;  // Return null if depth is 0 or data is empty
    }

    std::queue<std::pair<Node*, int>> q; // Queue to manage nodes and their corresponding depth
    const auto root = new Node(data[0]); // Create root node using the first element in data
    q.emplace(root, 0); // Push the root node and its level into the queue
    data.erase(data.begin()); // Remove the first element from data

    // Loop until all nodes are processed
    while (!q.empty()) {
        auto [currentNode, currentDepth] = q.front(); // Get the current node and its depth
        q.pop(); // Remove it from the queue

        if (currentDepth + 1 < depth) { // Check if we can add more depth
            // Create left child if there is data available
            if (!data.empty()) {
                currentNode->left = new Node(data[0]); // Create left child
                data.erase(data.begin()); // Remove the first element from data
                q.emplace(currentNode->left, currentDepth + 1); // Push the left child to the queue with incremented depth
            }
            // Create right child if there is data available
            if (!data.empty()) {
                currentNode->right = new Node(data[0]); // Create right child
                data.erase(data.begin()); // Remove the first element from data
                q.emplace(currentNode->right, currentDepth + 1); // Push the right child to the queue with incremented depth
            }
        }
    }

    return root; // Return the newly created tree root
}

// Search function to find a target value in the tree using iterative traversal
bool PerfectBinaryTree::search(const Node* node, const int target) {
    if (node == nullptr) return false; // Return false if the node is null

    std::stack<const Node*> stack; // Create a stack for iterative traversal
    stack.push(node); // Start with the root node

    // Loop until there are no nodes left to process
    while (!stack.empty()) {
        const Node* current = stack.top(); // Get the top node from the stack
        stack.pop(); // Remove it from the stack

        if (current->data == target) {
            return true; // Return true if the target is found
        }
        // Push the right child first so the left child is processed first
        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }
    return false; // Return false if the target is not found
}

// Print the tree using in-order traversal iteratively
void PerfectBinaryTree::printTree(const Node* node) {
    std::stack<const Node*> stack; // Create a stack to hold nodes
    const Node* current = node; // Start with the root node

    // Loop until there are nodes to process or the stack is empty
    while (current != nullptr || !stack.empty()) {
        // Reach the leftmost Node of the current Node
        while (current != nullptr) {
            stack.push(current); // Push current node onto the stack
            current = current->left; // Move to the left child
        }

        // Current must be NULL at this point, so we pop the stack
        current = stack.top(); // Get the top node from the stack
        stack.pop(); // Remove the top node from the stack

        std::cout << current->data << " "; // Print the data of the node

        // Now, we need to visit the right subtree
        current = current->right; // Move to the right child
    }
}

#endif //PERFECT_BINARY_TREE_TPP
