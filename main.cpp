#include "FullBinaryTrees/full_binary_tree.h"
#include <iostream>

int main() {
    std::cout << "Full Binary Tree:\n";

    // 1. Initialize the FullBinaryTree with the root node set to Node(1)
    const FullBinaryTree fullBinaryTree;  // Root is initialized in the constructor with value 1

    // 2. Print the initial state of the tree (only the root node)
    std::cout << "Initialized Full Binary Tree: ";
    FullBinaryTree::printTree(fullBinaryTree.root); // Expected output: 1

    // 3. Add children to the root node
    FullBinaryTree::addChildren(fullBinaryTree.root, 2, 3); // Adds nodes 2 and 3 as children of root
    std::cout << "\nAdded children for the root node: ";
    FullBinaryTree::printTree(fullBinaryTree.root); // Expected output: 1 2 3

    // 4. Add children to the left and right nodes of the root
    FullBinaryTree::addChildren(fullBinaryTree.root->left, 4, 5); // Adds nodes 4 and 5 as children of node 2
    FullBinaryTree::addChildren(fullBinaryTree.root->right, 6, 7); // Adds nodes 6 and 7 as children of node 3

    // 5. Print the fully populated Full Binary Tree
    std::cout << "\nFully populated Full Binary Tree: ";
    FullBinaryTree::printTree(fullBinaryTree.root); // Expected output: 1 2 4 5 3 6 7

    // 6. Perform search operations to check if specific values exist in the tree
    std::cout << "\nDoes number \"5\" exist in tree: "
              << (FullBinaryTree::search(fullBinaryTree.root, 5) ? "True" : "False") << std::endl;

    std::cout << "Does number \"8\" exist in tree: "
              << (FullBinaryTree::search(fullBinaryTree.root, 8) ? "True" : "False") << std::endl;

    return 0;
}
