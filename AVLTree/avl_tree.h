#ifndef AVL_TREE_H
#define AVL_TREE_H

#pragma once
#include "../Nodes/node.h"


class AVLTree {
public:
    inline AVLTree();
    ~AVLTree();

    inline void insert(int data);
    inline bool search(int target) const;
    inline void remove(int data);
    inline void printInOrder() const;

private:
    Node* root;

    static inline size_t _height(const Node* node);
    static inline void _updateHeight(Node* node);
    static inline int _getBalance(const Node* node);
    static inline Node* _rightRotation(Node* y);
    static inline Node* _leftRotation(Node* x);
};

#include "avl_tree.tpp"

#endif //AVL_TREE_H
