#ifndef PERFECT_BINARY_TREE_TPP
#define PERFECT_BINARY_TREE_TPP

#include "perfect_binary_tree.h"  // Include the header file for PerfectBinaryTree
#include <stack> // Include stack for iterative traversal
#include <queue>

// Constructor implementation
PerfectBinaryTree::PerfectBinaryTree(const std::vector<int>& data, const int depth) {
    root = buildPerfectTree(data, depth);  // Build the perfect tree upon initialization
}

// Destructor implementation
PerfectBinaryTree::~PerfectBinaryTree() {
    delete root;  // Delete the root node to free up memory
}

Node* PerfectBinaryTree::buildPerfectTree(std::vector<int> data, const int depth) {
    if (depth == 0 || data.empty()) {
        return nullptr;  // Return null if depth is 0 or data is empty
    }

    std::queue<std::pair<Node*, int>> q; // Pair of node pointer and depth level
    const auto root = new Node(data[0]); // Create root node
    q.emplace(root, 0); // Push the root node and its level into the queue
    data.erase(data.begin()); // Remove the first element

    while (!q.empty()) {
        auto [currentNode, currentDepth] = q.front(); // Get the current node and its depth
        q.pop(); // Remove it from the queue

        if (currentDepth + 1 < depth) { // Check if we can add more depth
            if (!data.empty()) {
                currentNode->left = new Node(data[0]); // Create left child
                data.erase(data.begin()); // Remove the first element
                q.emplace(currentNode->left, currentDepth + 1); // Push the left child to the queue
            }
            if (!data.empty()) {
                currentNode->right = new Node(data[0]); // Create right child
                data.erase(data.begin()); // Remove the first element
                q.emplace(currentNode->right, currentDepth + 1); // Push the right child to the queue
            }
        }
    }

    return root; // Return the newly created tree root
}

bool PerfectBinaryTree::search(const Node* node, const int target) {
    if (node == nullptr) return false; // Return false if node is null

    std::stack<const Node*> stack; // Create a stack for iterative traversal
    stack.push(node); // Start with the root node

    while (!stack.empty()) {
        const Node* current = stack.top(); // Get the top node
        stack.pop(); // Remove it from the stack

        if (current->data == target) {
            return true; // Return true if target found
        }
        // Push children onto the stack
        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }
    return false; // Return false if target not found
}

// Print the tree using in-order traversal iteratively
void PerfectBinaryTree::printTree(const Node* node) {
    std::stack<const Node*> stack; // Create a stack to hold nodes
    const Node* current = node; // Start with the root node

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
