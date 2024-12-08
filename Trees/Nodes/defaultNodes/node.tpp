#ifndef NODE_TPP
#define NODE_TPP

#include "node.h"

// Constructor definition
Node::Node(const int value) {
    data = value;       // Set the node's data to the given value
    left = nullptr;     // Initialize the left child pointer to nullptr (no child yet)
    right = nullptr;    // Initialize the right child pointer to nullptr (no child yet)
    height = 1;         // Initialize height of node
}

#endif // NODE_TPP
