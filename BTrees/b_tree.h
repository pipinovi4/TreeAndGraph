#ifndef B_TREE_H
#define B_TREE_H

#include "../Nodes/b_tree_node.h"

class BTree {
public:
    inline explicit BTree(const int& t);
    inline ~BTree();

    inline void insert(const int& key);
    inline BTreeNode* search(const int& key) const;
    inline void remove(const int& key);
    inline void printTree() const;

private:
    BTreeNode* _root;
    int _t;
};

#include "b_tree.tpp"

#endif //B_TREE_H
