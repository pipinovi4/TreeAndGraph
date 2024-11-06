#ifndef NODE_H
#define NODE_H

#include <iostream> // Corrected from iosteram to iostream

class Node {
public: // Make the constructor public
    int data; // It's good to expose data, if needed
    Node* left;
    Node* right;

    // Constructor declaration
    Node(int data); // Added semicolon
};

#endif // NODE_H