#include "../source/full_binary_tree.h"
#include <iostream>

int main() {
    // Create a FullBinaryTree instance
    FullBinaryTree tree;

    // Add children to the root node
    tree.addChildren(tree.root, 2, 3); // Adds left child (2) and right child (3)

    // Add children to the left child of the root
    tree.addChildren(tree.root->left, 4, 5); // Adds children 4 and 5 to node 2

    // Add children to the right child of the root
    tree.addChildren(tree.root->right, 6, 7); // Adds children 6 and 7 to node 3

    // Print the tree in pre-order traversal
    std::cout << "Tree in pre-order traversal: ";
    tree.printTree(tree.root);
    std::cout << std::endl;

    // Search for a value in the tree
    int target = 5;
    bool found = tree.search(tree.root, target);
    std::cout << "Value " << target << (found ? " is found" : " is not found") << " in the tree." << std::endl;

    // Try searching for a non-existent value
    target = 10;
    found = tree.search(tree.root, target);
    std::cout << "Value " << target << (found ? " is found" : " is not found") << " in the tree." << std::endl;

    return 0;
}
