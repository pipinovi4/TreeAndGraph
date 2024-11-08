#include "FullBinaryTrees/full_binary_tree.h"
#include "CompleteBinaryTrees/complete_binary_tree.h"
#include "PerfectBinaryTrees/perfect_binary_tree.h"
#include "BinarySearchTrees/binary_search_tree.h"
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

    // Insert nodes in level-order to maintain complete binary tree properties
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

    // ---------------- Perfect Binary Tree Example ---------------- //
    std::cout << "\nPerfect Binary Tree:\n";

    // Initialize PerfectBinaryTree with sample data and depth
    const std::vector<int> perfectData = {1, 2, 3, 4, 5, 6, 7};  // Sample data for the perfect binary tree
    constexpr int perfectDepth = 3;  // Depth of the perfect binary tree

    const PerfectBinaryTree perfectBinaryTree(perfectData, perfectDepth);  // Create PerfectBinaryTree instance

    // Print the populated Perfect Binary Tree
    std::cout << "Fully populated Perfect Binary Tree: ";
    PerfectBinaryTree::printTree(perfectBinaryTree.root);  // Expected output: 1 2 3 4 5 6 7

    // Perform search operations on PerfectBinaryTree
    std::cout << "\nDoes number \"5\" exist in the Perfect Binary Tree: "
              << (PerfectBinaryTree::search(perfectBinaryTree.root, 5) ? "True" : "False") << std::endl;  // Expected output: True

    std::cout << "Does number \"8\" exist in the Perfect Binary Tree: "
              << (PerfectBinaryTree::search(perfectBinaryTree.root, 8) ? "True" : "False") << std::endl;  // Expected output: False

    // ---------------- Binary Search Tree Example ---------------- //
    std::cout << "\nBinary Search Tree:\n";

    BinarySearchTree binarySearchTree;

    // Insert elements into the BST
    binarySearchTree.insert(15);
    binarySearchTree.insert(10);
    binarySearchTree.insert(20);
    binarySearchTree.insert(8);
    binarySearchTree.insert(12);
    binarySearchTree.insert(17);
    binarySearchTree.insert(25);

    // Print the Binary Search Tree
    std::cout << "Binary Search Tree after insertions: ";
    binarySearchTree.print_tree(); // Expected in-order output: 8 10 12 15 17 20 25

    // Perform search operations on BinarySearchTree
    std::cout << "\nDoes number \"10\" exist in the Binary Search Tree: "
              << (binarySearchTree.search(10) ? "True" : "False") << std::endl;  // Expected output: True

    std::cout << "Does number \"30\" exist in the Binary Search Tree: "
              << (binarySearchTree.search(30) ? "True" : "False") << std::endl;  // Expected output: False

    // Remove a node from the BST
    binarySearchTree.remove(10);
    std::cout << "Binary Search Tree after removing \"10\": ";
    binarySearchTree.print_tree(); // Expected in-order output: 8 12 15 17 20 25

    // Remove another node
    binarySearchTree.remove(15);
    std::cout << "Binary Search Tree after removing \"15\": ";
    binarySearchTree.print_tree(); // Expected in-order output: 8 12 17 20 25

    return 0;
}
