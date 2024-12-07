#ifndef B_PLUS_TREE_TPP
#define B_PLUS_TREE_TPP

#include "../include/b_plus_tree.h"
#include <stack>
#include <algorithm>
#include <iostream>
#include <queue>

// Constructor of the BPTree
BPTree::BPTree(const size_t t) {
    _t = t; // Initialize variable t
    _root = new BPTreeNode(t, false); // Initialize root node of the BPTree
}

// Destructor of the BPTree for deliting all pointer data
BPTree::~BPTree() {
    // Check that _root is not nullptr, if _root is nullptr return void
    if (!_root) return;
    std::stack<BPTreeNode*> stackNodes; // Initialize stack of the node for pushing nodes recursively
    stackNodes.push(_root); // Push root node for recursive deletion all nodes in the tree

    while (!stackNodes.empty()) {
        BPTreeNode* currentNode = stackNodes.top(); // Take back node from the stack for deletion
        stackNodes.pop(); // Delete from stack last taked node

        // If currentNode have children then iterate over them
        if (!currentNode->_children.empty()) {
            // Iterate over children of the currentNode and push them into stack
            for (const auto& child : currentNode->_children) {
                if (child) { // If node is not nullptr push him into stack
                    stackNodes.push(child); // Push node into stack
                }
            }
        }

        delete currentNode; // Delete current iterated node and let's move on next node in the stack
    }
}

void BPTree::insert(const int key) {
    // If the root is a leaf and not full, insert directly
    if (_root->_children.empty() && _root->_keys.size() < 2 * _t - 1) {
        // Insert the key in the appropriate position in the root
        const auto it = std::lower_bound(_root->_keys.begin(), _root->_keys.end(), key);
        _root->_keys.insert(it, key);
        return; // Insertion complete
    }

    BPTreeNode* oldRoot = _root;

    // Check if the root is full
    if (oldRoot->_keys.size() == 2 * _t - 1) {
        // Create a new root node
        const auto newRoot = new BPTreeNode(_t, false);

        // Update `_parent` of the old root
        oldRoot->_parent = newRoot;

        // If old root doesn't have children then make him as leaf
        if (oldRoot->_children.empty()) {
            // Make copyRoot as leaf because we descent them into level + 1
            oldRoot->_is_leaf = true;
        }

        // The current root becomes a child of the new root
        newRoot->_children.push_back(oldRoot);

        // Split the full root
        newRoot->splitChildren(0);

        // Update the root
        _root = newRoot;
    }

    // Insert the key into the appropriate node
    _root->insertNonFull(key);
}

BPTreeNode* BPTree::search(const int key) const {
    // Initialize space of the root as default it root
    BPTreeNode* node = _root;

    // Iterate over leaf of the tree
    while (!node->_is_leaf) {
        // Initialize index of the children nodes
        int i = 0;

        // Finding correct inex of the node
        while (i < node->_keys.size() && key >= node->_keys[i]) {
            i += 1;
        }
        // Change node on the child with index i
        node = node->_children[i];
    }
    // If key is in the _keys of the node then return node in another case return nullptr
    return std::find(node->_keys.begin(), node->_keys.end(), key) != node->_keys.end() ? node : nullptr;
}

void BPTree::remove(int key) {
    if (!_root) return;

    std::stack<BPTreeNode*> stack;
    stack.push(_root);

    while (!stack.empty()) {
        BPTreeNode* currentNode = stack.top();
        stack.pop();

        int i = 0;
        while (i < currentNode->_keys.size() && key > currentNode->_keys[i]) {
            i++;
        }

        if (currentNode->_is_leaf) {
            // If it's a leaf, remove the key if it exists
            auto it = std::find(currentNode->_keys.begin(), currentNode->_keys.end(), key);
            if (it != currentNode->_keys.end()) {
                currentNode->_keys.erase(it); // Remove key from leaf
            }
        } else {
            if (i < currentNode->_keys.size() && currentNode->_keys[i] == key) {
                if (currentNode->_children[i]->_is_leaf) {
                    // Replace key with the largest in the left subtree
                    currentNode->_keys[i] = currentNode->_children[i]->_keys.back();
                    key = currentNode->_keys[i];
                    stack.push(currentNode->_children[i]);
                } else {
                    // Replace key with the smallest in the right subtree
                    currentNode->_keys[i] = currentNode->_children[i + 1]->_keys.front();
                    key = currentNode->_keys[i];
                    stack.push(currentNode->_children[i + 1]);
                }
            } else {
                // Check if we need to fix the child before descending
                if (currentNode->_children[i]->_keys.size() < _t) {
                    _fixChild(currentNode, i);
                }
                stack.push(currentNode->_children[i]);
            }
        }
    }

    // Update root if it becomes empty and is not a leaf
    if (_root->_keys.empty() && !_root->_is_leaf) {
        const BPTreeNode* oldRoot = _root;
        _root = _root->_children[0];
        delete oldRoot;
    }
}

std::vector<int> BPTree::rangeQuery(const int start_key, const int end_key) const {
    std::vector<int> result = {};
    BPTreeNode* node = _root;
    while (!node->_is_leaf) {
        // Initialize index for finding correct inex of the right child of the node
        int i = 0;
        // Increment index by one each iteration while it smaller than size of the node keys and start_key bigger than i key in the node keys
        while (i < node->_keys.size() && start_key > node->_keys[i]) {
            i += 1; // Increment index by one
        }
        // Change old node on the i-n child in the children parameter
        node = node->_children[i];
    }

    // Iterate until node
    while (node) {
        // Iterate over keys in the node
        for (const auto& key : node->_keys) {
            if (key > end_key) break;

            // If key less than start_key and bigger than end_key push current key into result
            if (start_key <= key <= end_key) result.push_back(key);
            // If key bigger than end_key retun result
            else if (key > end_key) return result;
        }
        // Iterate over the nodes in the leaf tree
        node = node->_next;
    }

    // Return result after processing
    return result;
}

void BPTree::_fixChild(BPTreeNode* parent, const size_t index) {
    if (!parent) {
        throw std::invalid_argument("Parent node is null.");
    }

    if (index >= parent->_children.size()) {
        throw std::out_of_range("Index is out of range for parent->_children.");
    }

    BPTreeNode* current_child = parent->_children[index];

    // Case 1: Check left sibling for redistribution
    if (index > 0 && parent->_children[index - 1]->_keys.size() >= _t) {
        BPTreeNode* left_sibling = parent->_children[index - 1];

        // Move the parent's key down to the current child
        current_child->_keys.insert(current_child->_keys.begin(), parent->_keys[index - 1]);

        // Update the parent's key to the last key of the left sibling
        parent->_keys[index - 1] = left_sibling->_keys.back();
        left_sibling->_keys.pop_back();

        // Move the child pointer if the node is not a leaf
        if (!left_sibling->_is_leaf) {
            current_child->_children.insert(current_child->_children.begin(), left_sibling->_children.back());
            left_sibling->_children.pop_back();
        }
    }
    // Case 2: Check right sibling for redistribution
    else if (index < parent->_children.size() - 1 && parent->_children[index + 1]->_keys.size() >= _t) {
        BPTreeNode* right_sibling = parent->_children[index + 1];

        // Move the parent's key down to the current child
        current_child->_keys.push_back(parent->_keys[index]);

        // Update the parent's key to the first key of the right sibling
        parent->_keys[index] = right_sibling->_keys.front();
        right_sibling->_keys.erase(right_sibling->_keys.begin());

        // Move the child pointer if the node is not a leaf
        if (!right_sibling->_is_leaf) {
            current_child->_children.push_back(right_sibling->_children.front());
            right_sibling->_children.erase(right_sibling->_children.begin());
        }
    }
    // Case 3: Merge with a sibling
    else {
        if (index > 0) {
            _mergeNodes(parent, static_cast<int>(index) - 1);
        } else {
            _mergeNodes(parent, static_cast<int>(index));
        }

        // Update the root if it becomes empty and is not a leaf
        if (parent == _root && _root->_keys.empty()) {
            _root = _root->_children[0];
            delete parent;
        }
    }
}

void BPTree::_mergeNodes(BPTreeNode* parent, const int index) {
    if (index < 0 || index >= static_cast<int>(parent->_children.size()) - 1) {
        throw std::out_of_range("Index is out of range for merging nodes.");
    }

    BPTreeNode* left_child = parent->_children[index];
    BPTreeNode* right_child = parent->_children[index + 1];

    if (!left_child || !right_child) {
        throw std::logic_error("One or both children are null for merging.");
    }

    // Move the key from parent to the left child
    left_child->_keys.push_back(parent->_keys[index]);

    // Remove the key and right child from parent
    parent->_keys.erase(parent->_keys.begin() + index);
    parent->_children.erase(parent->_children.begin() + index + 1);

    // Merge the keys and children of the right child into the left child
    left_child->_keys.insert(left_child->_keys.end(), right_child->_keys.begin(), right_child->_keys.end());

    if (!left_child->_is_leaf) {
        left_child->_children.insert(left_child->_children.end(), right_child->_children.begin(), right_child->_children.end());

        // Update `_parent` for all moved children
        for (auto* grandchild : right_child->_children) {
            grandchild->_parent = left_child;
        }
    } else {
        left_child->_next = right_child->_next; // Link to the next leaf node if it's a leaf
    }

    // Delete the right child to free memory
    delete right_child;
}

void BPTree::printTree() const {
    if (!_root) {
        std::cout << "[]" << std::endl;
        return;
    }

    std::queue<std::pair<BPTreeNode*, int>> queue;
    queue.emplace(_root, 0);

    int current_level = -1;

    while (!queue.empty()) {
        auto [node, level] = queue.front();
        queue.pop();

        // Start a new line when changing levels
        if (level > current_level) {
            if (current_level != -1) {
                std::cout << "\n";  // Start a new line for the new level
            }
            std::cout << "Level " << level << ": ";
            current_level = level;
        }

        // Print the current node's keys
        std::cout << "[";
        for (size_t i = 0; i < node->_keys.size(); ++i) {
            std::cout << node->_keys[i];
            if (i != node->_keys.size() - 1)
                std::cout << ", ";
        }
        std::cout << "] ";

        // Add children to the queue for next level processing
        if (!node->_is_leaf) {
            for (auto* child : node->_children) {
                if (child) queue.emplace(child, level + 1);
            }
        }
    }
    std::cout << std::endl;
}

#endif //B_PLUS_TREE_TPP