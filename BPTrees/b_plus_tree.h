#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#pragma once
#include "../Nodes/BPTreeNodes/b_plus_tree_node.h"
#include <cstddef>

class BPTree {
public:
    BPTreeNode* _root;
    size_t _t;

    inline explicit BPTree(size_t t); // Contructor
    inline ~BPTree(); // Destructor

    inline void insert(int key);
    inline BPTreeNode* search(int key) const;
    inline void remove(int key);
    inline std::vector<int> rangeQuery(int start_key, int end_key) const;
    inline void printTree() const;

private:
    inline void _fixChild(BPTreeNode* parent, size_t index);
    static inline void _mergeNodes(BPTreeNode* parent, int index);
};

#include "b_plus_tree.tpp"

#endif //B_PLUS_TREE_H
