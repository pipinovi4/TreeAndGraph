#include "../include/perfect_binary_tree.h"
#include <iostream>
#include <vector>

int main() {
    // Example data to populate the tree
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7};

    // Define the depth of the tree
    int depth = 3; // A depth-3 tree will have 7 nodes (if fully filled)

    // Create a PerfectBinaryTree object
    PerfectBinaryTree tree(data, depth);

    // Print the tree using in-order traversal
    std::cout << "In-order Traversal of Perfect Binary Tree: ";
    tree.printTree(tree.root);
    std::cout << std::endl;

    // Search for a value in the tree
    int target = 5;
    if (tree.search(tree.root, target)) {
        std::cout << "Value " << target << " found in the tree!" << std::endl;
    } else {
        std::cout << "Value " << target << " not found in the tree!" << std::endl;
    }

    // Try searching for a value that doesn't exist
    target = 10;
    if (tree.search(tree.root, target)) {
        std::cout << "Value " << target << " found in the tree!" << std::endl;
    } else {
        std::cout << "Value " << target << " not found in the tree!" << std::endl;
    }

    return 0;
}
