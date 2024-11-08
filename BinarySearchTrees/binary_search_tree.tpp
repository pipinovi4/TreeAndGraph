#ifndef BINARY_SEARCH_TREE_TPP
#define BINARY_SEARCH_TREE_TPP

#include "binary_search_tree.h"
#include "../Nodes/node.h"
#include <stack>
#include <vector>

BinarySearchTree::BinarySearchTree() : root(nullptr) {};

BinarySearchTree::~BinarySearchTree() {
    if (!root) return; // If the tree is empty, there's nothing to delete

    std::vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        const Node* current_node = queue.back();
        queue.pop_back();

        // Add non-null children to the queue
        if (current_node->left) {
            queue.push_back(current_node->left);
        }
        if (current_node->right) {
            queue.push_back(current_node->right);
        }

        // Delete the current node
        delete current_node;
    }
}

void BinarySearchTree::insert(const int data) {
    if (!root) {
        root = new Node(data);
    } else {
        Node* current = root;
        while (true) {
            if (data < current->data) { // If data is less than current node's data
                if (current->left == nullptr) { // If no left child, insert here
                    current->left = new Node(data);
                    break;
                }
                current = current->left;

            } else if (data > current->data) { // If data is greater than current node's data
                if (current->right == nullptr) { // If no right child, insert here
                    current->right = new Node(data);
                    break;
                }
                current = current->right;

            } else {
                break; // Data is already in the tree, no duplicates if BST doesn't allow them
            }
        }
    }
};

bool BinarySearchTree::search(const int target) const {
    const Node* current = root;

    while (true) {
        if (!current) {
            return false;
        }
        if (current->data == target) {
            return true;
        }
        if (target < current->data) {
            current = current->left;
        }
        if (target > current->data) {
            current = current->right;
        }
    }
}

inline void BinarySearchTree::remove(const int data) {
    Node* parent = nullptr;
    Node* current = root;

    // Find the node to delete and its parent
    while (current != nullptr && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        }
    }

    // Node not found
    if (current == nullptr) return;

    // Case 1: Node with only one child or no child
    if (current->left == nullptr || current->right == nullptr) {
        Node* newChild = (current->left != nullptr) ? current->left : current->right;

        // If deleting the root node
        if (parent == nullptr) {
            root = newChild;
        } else if (parent->left == current) {
            parent->left = newChild;
        } else {
            parent->right = newChild;
        }
        delete current;
    } else {
        // Case 2: Node with two children
        // Find the inorder successor (smallest node in the right subtree)
        Node* successorParent = current;
        Node* successor = current->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace current node's data with the successor's data
        current->data = successor->data;

        // Adjust the successor's parent's child pointer
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        delete successor;
    }
}

inline void BinarySearchTree::print_tree() const {
    if (!root) return;  // Check if the tree is empty

    std::stack<Node*> stackNodes;
    stackNodes.push(root);

    while (!stackNodes.empty()) {
        const Node* currentNode = stackNodes.top();
        stackNodes.pop();

        if (currentNode) {
            std::cout << currentNode->data << " ";
            
            // Push the right child first so that the left child is processed first
            if (currentNode->right) stackNodes.push(currentNode->right);
            if (currentNode->left) stackNodes.push(currentNode->left);
        }
    }
    std::cout << std::endl;
}

#endif //BINARY_SEARCH_TREE_TPP
