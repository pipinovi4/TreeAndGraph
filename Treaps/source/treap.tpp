#ifndef TREAP_TPP
#define TREAP_TPP

#include "../include/treap.h"
#include <stack>
#include <iostream>

// Constructor initializes an empty Treap
Treap::Treap() {
    _root = nullptr;
    _priority_counter = 0;  // Unique priority counter
}

// Destructor to deallocate all nodes in the Treap
Treap::~Treap() {
    if (!_root) return;
    std::stack<TreapNode*> stackNodes = {};
    stackNodes.push(_root);

    while (!stackNodes.empty()) {
        const TreapNode* currentNode = stackNodes.top();
        stackNodes.pop();

        // Push children to the stack to delete them later
        if (currentNode->right) stackNodes.push(currentNode->right);
        if (currentNode->left) stackNodes.push(currentNode->left);

        delete currentNode;  // Delete the current node
    }
}

// Perform a right rotation at the given node
TreapNode* Treap::_rightRotation(TreapNode *node) {
    TreapNode* left_child = node->left;  // Left child becomes the new root
    node->left = left_child->right;      // Move the left child's right subtree
    left_child->right = node;            // Update right child of the new root
    return left_child;                   // Return the new root
}

// Perform a left rotation at the given node
TreapNode* Treap::_leftRotation(TreapNode *node) {
    TreapNode* right_child = node->right;  // Right child becomes the new root
    node->right = right_child->left;       // Move the right child's left subtree
    right_child->left = node;              // Update left child of the new root
    return right_child;                    // Return the new root
}

// Generate a unique priority by adding an incrementing counter
int Treap::_generateUniquePriority() {
    // Generate a random base priority using a static random number generator
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 1000000);
    int basePriority = dist(rng);

    // Ensure uniqueness by adding the counter
    int unique_priority = basePriority + _priority_counter;
    ++_priority_counter;

    // Debug output to verify the generated priority
    std::cout << "Generated Priority: " << basePriority << ", Counter: " << _priority_counter - 1 << ", Unique Priority: " << unique_priority << std::endl;

    return unique_priority;
}

// Insert a new node with the given key and priority
void Treap::insert(const int &key, int priority) {
    if (priority == -1) {
        priority = _generateUniquePriority();  // Generate priority if not provided
    }

    // Create the new node
    TreapNode* new_node = new TreapNode(key, priority);

    if (_root == nullptr) {
        _root = new_node;  // If the tree is empty, set the new node as the root
        return;
    }

    TreapNode* parent = nullptr;
    TreapNode* current = _root;
    std::stack<TreapNode*> path;  // Stack to track the path for potential rotations

    // Traverse the tree to find the correct position
    while (current) {
        parent = current;
        path.push(current);

        if (key < current->key) {
            if (current->left == nullptr) {
                current->left = new_node;
                current = current->left;  // Fix: Update current to the newly inserted node
                break;
            }
            current = current->left;
        } else if (key > current->key) {
            if (current->right == nullptr) {
                current->right = new_node;
                current = current->right;  // Fix: Update current to the newly inserted node
                break;
            }
            current = current->right;
        } else {
            // Key already exists, no insertion needed
            delete new_node;
            return;
        }
    }

    // Rebalance the tree to maintain heap property
    while (!path.empty()) {
        parent = path.top();
        path.pop();

        // Check if heap property is violated (parent's priority is less than child's)
        if (parent && current && parent->priority < current->priority) {
            TreapNode* rotated;
            if (parent->left == current) {  // This will now evaluate correctly
                rotated = _rightRotation(parent);
            } else {
                rotated = _leftRotation(parent);
            }

            // Update parent's reference in the grandparent
            if (!path.empty()) {
                TreapNode* grandparent = path.top();
                if (grandparent->left == parent) {
                    grandparent->left = rotated;
                } else {
                    grandparent->right = rotated;
                }
            } else {
                _root = rotated;  // If parent was the root, update the root
            }

            // Update current to reflect the rotated subtree
            current = rotated;
        } else {
            break;
        }
    }
}

// Remove a node with the given key from the Treap
void Treap::remove(const int &key) {
    TreapNode* parent = nullptr;
    TreapNode* current = _root;

    // Find the node to be removed
    while (current && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (!current) {
        return;  // Node not found
    }

    // Repeatedly rotate the node down until it has at most one child
    while (current->left && current->right) {
        TreapNode* rotated;

        if (current->left->priority > current->right->priority) {
            rotated = _rightRotation(current);
        } else {
            rotated = _leftRotation(current);
        }

        if (!parent) {
            _root = rotated;
        } else if (parent->left == current) {
            parent->left = rotated;
        } else {
            parent->right = rotated;
        }

        parent = rotated;
    }

    // Remove the node by connecting its parent to its remaining child
    if (!parent) {
        _root = current->left ? current->left : current->right;
    } else if (parent->left == current) {
        parent->left = current->left ? current->left : current->right;
    } else {
        parent->right = current->left ? current->left : current->right;
    }

    delete current;
}

// Search for a node with the given key
bool Treap::search(const int &key) {
    TreapNode* current = _root;

    while (current) {
        if (key == current->key) {
            return true;  // Key found
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;  // Key not found
}

// Perform an in-order traversal and return key-priority pairs
std::vector<std::pair<int, int>> Treap::inorder() {
    std::vector<std::pair<int, int>> result = {};
    std::stack<TreapNode*> stack = {};
    TreapNode* current = _root;

    while (!stack.empty() || current) {
        while (current) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        result.push_back({current->key, current->priority});

        current = current->right;
    }

    return result;
}

// Print the tree structure with indentation
void Treap::printTree() {
    if (_root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::stack<StackNode> stack;
    stack.push(StackNode(_root, 0, "Root: "));

    while (!stack.empty()) {
        StackNode current = stack.top();
        stack.pop();

        // Print the current node with indentation
        std::cout << std::string(current.level * 4, ' ')
                  << current.prefix << "(" << current.node->key << ", " << current.node->priority << ")" << std::endl;

        // Push right child first so left child is processed first
        if (current.node->right) {
            stack.push(StackNode(current.node->right, current.level + 1, "R--- "));
        }
        if (current.node->left) {
            stack.push(StackNode(current.node->left, current.level + 1, "L--- "));
        }
    }
}

#endif // TREAP_TPP
