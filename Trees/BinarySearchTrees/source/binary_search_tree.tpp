#ifndef BINARY_SEARCH_TREE_TPP
#define BINARY_SEARCH_TREE_TPP

#include "../include/binary_search_tree.h"
#include "../../../Nodes/defaultNodes/node.h"
#include <stack>
#include <vector>

// Constructor: Initializes an empty binary search tree with root set to nullptr
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Destructor: Deletes all nodes in the tree to free memory
BinarySearchTree::~BinarySearchTree() {
    if (!root) return; // If the tree is empty, there's nothing to delete

    std::vector<Node*> queue; // Queue to store nodes for breadth-first deletion
    queue.push_back(root);

    // Process each node in the queue
    while (!queue.empty()) {
        const Node* current_node = queue.back();
        queue.pop_back();

        // Add non-null children to the queue to be deleted later
        if (current_node->left) {
            queue.push_back(current_node->left);
        }
        if (current_node->right) {
            queue.push_back(current_node->right);
        }

        // Delete the current node to free its memory
        delete current_node;
    }
}

// Insert function: Adds a new node with the specified data into the BST
void BinarySearchTree::insert(const int data) {
    // If the tree is empty, create the root node
    if (!root) {
        root = new Node(data);
    } else {
        Node* current = root;
        // Traverse the tree to find the correct position for the new node
        while (true) {
            if (data < current->data) { // If data is less than current node's data
                if (current->left == nullptr) { // If no left child, insert here
                    current->left = new Node(data);
                    break; // Node inserted, exit loop
                }
                current = current->left; // Move left in the tree

            } else if (data > current->data) { // If data is greater than current node's data
                if (current->right == nullptr) { // If no right child, insert here
                    current->right = new Node(data);
                    break; // Node inserted, exit loop
                }
                current = current->right; // Move right in the tree

            } else {
                break; // Data is already in the tree, so exit (no duplicates allowed)
            }
        }
    }
}

// Search function: Finds a node with the specified target value in the BST
bool BinarySearchTree::search(const int target) const {
    const Node* current = root;

    // Traverse the tree starting from root
    while (true) {
        if (!current) {
            return false; // Target not found in the tree
        }
        if (current->data == target) {
            return true; // Target found
        }
        if (target < current->data) {
            current = current->left; // Move left if target is smaller than current node
        }
        if (target > current->data) {
            current = current->right; // Move right if target is greater than current node
        }
    }
}

// Remove function: Deletes a node with the specified data from the BST
inline void BinarySearchTree::remove(const int data) {
    Node* parent = nullptr; // Parent of the node to be deleted
    Node* current = root; // Start at the root node

    // Traverse the tree to find the node to delete and its parent
    while (current != nullptr && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left; // Move left if data is less than current node's data
        } else if (data > current->data) {
            current = current->right; // Move right if data is greater than current node's data
        }
    }

    // Node not found in the tree, return
    if (current == nullptr) return;

    // Case 1: Node has one child or no child
    if (current->left == nullptr || current->right == nullptr) {
        Node* newChild = (current->left != nullptr) ? current->left : current->right;

        // If the node to delete is the root
        if (parent == nullptr) {
            root = newChild; // Set root to the only child or nullptr if no child
        } else if (parent->left == current) {
            parent->left = newChild; // Link parent to new child on the left
        } else {
            parent->right = newChild; // Link parent to new child on the right
        }
        delete current; // Free memory of the deleted node
    } else {
        // Case 2: Node has two children
        // Find the inorder successor (smallest node in the right subtree)
        Node* successorParent = current;
        Node* successor = current->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left; // Move to the leftmost node
        }

        // Replace current node's data with successor's data
        current->data = successor->data;

        // Adjust the successor's parent's child pointer
        if (successorParent->left == successor) {
            successorParent->left = successor->right; // Re-link left child
        } else {
            successorParent->right = successor->right; // Re-link right child
        }

        delete successor; // Free memory of the successor node
    }
}

// Print function: Displays the BST nodes in pre-order traversal
inline void BinarySearchTree::print_tree() const {
    if (!root) return;  // If the tree is empty, do nothing

    std::stack<Node*> stackNodes; // Stack to hold nodes for traversal
    stackNodes.push(root);

    // Process nodes in pre-order: root, left, right
    while (!stackNodes.empty()) {
        const Node* currentNode = stackNodes.top();
        stackNodes.pop();

        if (currentNode) {
            std::cout << currentNode->data << " "; // Print current node's data

            // Push the right child first so the left child is processed first
            if (currentNode->right) stackNodes.push(currentNode->right);
            if (currentNode->left) stackNodes.push(currentNode->left);
        }
    }
    std::cout << std::endl; // End line after printing all nodes
}

#endif // BINARY_SEARCH_TREE_TPP
