#include "../source/avl_tree.h"
#include <iostream>

int main() {
    AVLTree tree;

    // Insert values into the AVL tree
    std::cout << "Inserting values into the AVL Tree: 10, 20, 5, 15, 30, 25, 35, 16\n";
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);
    tree.insert(25);
    tree.insert(35);
    tree.insert(16);

    // Print the tree in-order
    std::cout << "In-order traversal after insertions:\n";
    tree.printInOrder();

    // Search for a value in the tree
    int searchValue = 15;
    std::cout << "Searching for value " << searchValue << " in the AVL Tree...\n";
    if (tree.search(searchValue)) {
        std::cout << "Value " << searchValue << " found in the AVL Tree.\n";
    } else {
        std::cout << "Value " << searchValue << " not found in the AVL Tree.\n";
    }

    // Delete a value from the AVL tree
    int deleteValue = 20;
    std::cout << "Deleting value " << deleteValue << " from the AVL Tree...\n";
    tree.remove(deleteValue);

    // Print the tree in-order after deletion
    std::cout << "In-order traversal after deletion:\n";
    tree.printInOrder();

    // Insert additional values to test rebalancing
    std::cout << "Inserting additional values into the AVL Tree: 18, 3, 40\n";
    tree.insert(18);
    tree.insert(3);
    tree.insert(40);

    // Print the tree in-order after additional insertions
    std::cout << "In-order traversal after additional insertions:\n";
    tree.printInOrder();

    return 0;
}