#include <iostream>
#include "../include/treap.h"  // Include the Treap class header file

int main() {
    // Initialize a new Treap
    Treap treap;

    // Insert elements into the Treap
    std::cout << "Inserting elements into the Treap..." << std::endl;
    treap.insert(10);
    treap.insert(20);
    treap.insert(5);
    treap.insert(15);

    // Perform an in-order traversal and print the result
    std::cout << "In-order traversal after insertions:" << std::endl;
    for (const auto& node : treap.inorder()) {
        std::cout << "(" << node.first << ", " << node.second << ") ";
    }
    std::cout << std::endl;

    // Search for a value in the Treap
    int search_value = 15;
    bool found = treap.search(search_value);
    std::cout << "Search for " << search_value << ": " << (found ? "Found" : "Not Found") << std::endl;

    // Search for a non-existing value
    int non_existing_value = 25;
    bool not_found = treap.search(non_existing_value);
    std::cout << "Search for " << non_existing_value << ": " << (not_found ? "Found" : "Not Found") << std::endl;

    // Delete a value from the Treap
    int delete_value = 20;
    std::cout << "Deleting " << delete_value << "..." << std::endl;
    treap.remove(delete_value);

    // Perform an in-order traversal after deletion and print the result
    std::cout << "In-order traversal after deletion:" << std::endl;
    for (const auto& node : treap.inorder()) {
        std::cout << "(" << node.first << ", " << node.second << ") ";
    }
    std::cout << std::endl;

    // Insert more elements into the Treap
    treap.insert(25);
    treap.insert(30);

    // Perform an in-order traversal after more insertions and print the result
    std::cout << "In-order traversal after more insertions:" << std::endl;
    for (const auto& node : treap.inorder()) {
        std::cout << "(" << node.first << ", " << node.second << ") ";
    }
    std::cout << std::endl;

    // Print the Treap structure for debugging
    std::cout << "\nTreap structure:" << std::endl;
    treap.printTree();

    return 0;
}
