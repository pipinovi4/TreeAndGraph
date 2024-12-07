#include <iostream>
#include "../include/binary_search_tree.h"

int main() {
    BinarySearchTree bst;

    // Insert values into the Binary Search Tree
    std::cout << "Inserting values into the BST: 50, 30, 70, 20, 40, 60, 80\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Print the BST in pre-order traversal
    std::cout << "Pre-order traversal after insertions:\n";
    bst.print_tree();

    // Search for a value in the BST
    int searchValue = 40;
    std::cout << "Searching for value " << searchValue << " in the BST...\n";
    if (bst.search(searchValue)) {
        std::cout << "Value " << searchValue << " found in the BST.\n";
    } else {
        std::cout << "Value " << searchValue << " not found in the BST.\n";
    }

    // Delete a value from the BST
    int deleteValue = 30;
    std::cout << "Deleting value " << deleteValue << " from the BST...\n";
    bst.remove(deleteValue);

    // Print the BST in pre-order traversal after deletion
    std::cout << "Pre-order traversal after deletion:\n";
    bst.print_tree();

    // Insert additional values to test further operations
    std::cout << "Inserting additional values: 25, 35\n";
    bst.insert(25);
    bst.insert(35);

    // Print the BST in pre-order traversal after additional insertions
    std::cout << "Pre-order traversal after additional insertions:\n";
    bst.print_tree();

    return 0;
}
