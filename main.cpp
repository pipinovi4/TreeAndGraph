#include "FullBinaryTrees/full_binary_tree.h"
#include "CompleteBinaryTrees/complete_binary_tree.h"
#include <iostream>

int main() {
    // ---------------- Full Binary Tree Example ---------------- //
    std::cout << "Full Binary Tree:\n";

    // Initialize the FullBinaryTree with the root node set to Node(1)
    const FullBinaryTree fullBinaryTree;  // Root is initialized in the constructor with value 1

    // Print the initial state of the tree (only the root node)
    std::cout << "Initialized Full Binary Tree: ";
    FullBinaryTree::printTree(fullBinaryTree.root);  // Expected output: 1

    // Add children to the root node
    FullBinaryTree::addChildren(fullBinaryTree.root, 2, 3);  // Adds nodes 2 and 3 as children of root
    std::cout << "\nAdded children for the root node: ";
    FullBinaryTree::printTree(fullBinaryTree.root);  // Expected output: 1 2 3

    // Add children to the left and right nodes of the root
    FullBinaryTree::addChildren(fullBinaryTree.root->left, 4, 5);  // Adds nodes 4 and 5 as children of node 2
    FullBinaryTree::addChildren(fullBinaryTree.root->right, 6, 7); // Adds nodes 6 and 7 as children of node 3

    // Print the fully populated Full Binary Tree
    std::cout << "\nFully populated Full Binary Tree: ";
    FullBinaryTree::printTree(fullBinaryTree.root);  // Expected output: 1 2 4 5 3 6 7

    // Perform search operations to check if specific values exist in the tree
    std::cout << "\nDoes number \"5\" exist in the Full Binary Tree: "
              << (FullBinaryTree::search(fullBinaryTree.root, 5) ? "True" : "False") << std::endl;

    std::cout << "Does number \"8\" exist in the Full Binary Tree: "
              << (FullBinaryTree::search(fullBinaryTree.root, 8) ? "True" : "False") << std::endl;

    // ---------------- Complete Binary Tree Example ---------------- //
    std::cout << "\nComplete Binary Tree:\n";

    // Initialize the CompleteBinaryTree
    CompleteBinaryTree completeBinaryTree;

    // 2. Insert nodes in level-order to maintain complete binary tree properties
    completeBinaryTree.insert(1);  // Insert root node
    completeBinaryTree.insert(2);  // Inserts as left child of root
    completeBinaryTree.insert(3);  // Inserts as right child of root
    completeBinaryTree.insert(4);  // Inserts as left child of node 2
    completeBinaryTree.insert(5);  // Inserts as right child of node 2
    completeBinaryTree.insert(6);  // Inserts as left child of node 3

    // Print the fully populated Complete Binary Tree
    std::cout << "Fully populated Complete Binary Tree: ";
    completeBinaryTree.printTree();  // Expected output: 1 2 3 4 5 6

    // Perform search operations on CompleteBinaryTree
    std::cout << "\nDoes number \"5\" exist in the Complete Binary Tree: "
              << (completeBinaryTree.search(5) ? "True" : "False") << std::endl;

    std::cout << "Does number \"7\" exist in the Complete Binary Tree: "
              << (completeBinaryTree.search(7) ? "True" : "False") << std::endl;

    return 0;
}
