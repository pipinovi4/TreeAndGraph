#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#pragma once

class BinarySearchTree {
public:
    // Root node for storing all nodes instead of the vector or something
    Node* root;

    // Basic methods of the class
    inline BinarySearchTree(); // Constructor method
    inline ~BinarySearchTree(); // Destructor method for deletion root

    // Default method of manipulation on the tree
    inline void insert(int data);
    inline bool search(int target) const;
    inline void remove(int data);

    // Static methods
    inline void print_tree() const;
};

#include "binary_search_tree.tpp"

#endif //BINARY_SEARCH_TREE_H
