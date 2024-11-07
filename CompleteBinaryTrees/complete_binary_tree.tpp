#ifndef COMPLETE_BINARY_TREE_TPP
#define COMPLETE_BINARY_TREE_TPP

#include "complete_binary_tree.h"
#include <cmath>
#include <algorithm>

inline CompleteBinaryTree::CompleteBinaryTree() {
    nodes = {};
}

inline CompleteBinaryTree::~CompleteBinaryTree() {
    for (const Node* node : nodes) {
        delete node;
    }
}

inline void CompleteBinaryTree::insert(const int data) {
    const auto new_data = new Node(data);
    nodes.push_back(new_data);
    const size_t index = nodes.size() - 1;
    if (index > 0) {
        const int parent_idx = std::floor((index - 1) / 2);
        if (!nodes[parent_idx]->left) {
            nodes[parent_idx]->left = new_data;
        } else {
            nodes[parent_idx]->right = new_data;
        }
    }
}

inline bool CompleteBinaryTree::search(const int target) const {
    return std::any_of(nodes.begin(), nodes.end(), [target](const Node* node) {
        return node->data == target;
    });
}

void CompleteBinaryTree::printTree() const {
    for (const Node* node : nodes) {
        std::cout << node << " ";
    }
}

#endif //COMPLETE_BINARY_TREE_TPP
