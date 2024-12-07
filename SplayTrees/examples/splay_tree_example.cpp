#include <iostream>
#include "../include/splay_tree.h"

int main() {
    // Create a SplayTree instance
    SplayTree tree;

    // Insert elements into the Splay Tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    // Display the tree's in-order traversal
    std::cout << "In-order Traversal after Insertions: ";
    for (const auto& value : tree.inorder()) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Search for an element in the Splay Tree
    int searchValue = 30;
    Node* foundNode = tree.search(searchValue);
    if (foundNode) {
        std::cout << "Found node with value: " << foundNode->data << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    // Remove an element from the Splay Tree
    int removeValue = 20;
    std::cout << "Removing value: " << removeValue << std::endl;
    tree.remove(removeValue);

    // Display the tree's in-order traversal after removal
    std::cout << "In-order Traversal after Removal: ";
    for (const auto& value : tree.inorder()) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
