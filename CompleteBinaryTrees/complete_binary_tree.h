#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

#pragma once
#include <vector>

#include "../Nodes/node.h"

class CompleteBinaryTree {
public:
    std::vector<Node*> nodes;

    inline CompleteBinaryTree();
    inline ~CompleteBinaryTree();

    inline void insert(int data);
    inline bool search(int target) const;
    inline void printTree() const;
};

#include "complete_binary_tree.tpp"

#endif //COMPLETE_BINARY_TREE_H
