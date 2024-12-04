#include "../source/b_tree.h"
#include <iostream>

int main() {
    // Initialize a B-Tree with a minimum degree of 3
    BTree bTree(3);

    // Insert keys into the B-Tree
    std::cout << "Inserting keys: 10, 20, 5, 6, 12, 30, 7, 17" << std::endl;
    bTree.insert(10);
    bTree.insert(20);
    bTree.insert(5);
    bTree.insert(6);
    bTree.insert(12);
    bTree.insert(30);
    bTree.insert(7);
    bTree.insert(17);

    // Print the B-Tree structure after insertion
    std::cout << "\nB-Tree structure after insertions:" << std::endl;
    bTree.printTree();

    // Search for a specific key in the B-Tree
    int searchKey = 12;
    std::cout << "\nSearching for key " << searchKey << "..." << std::endl;
    if (bTree.search(searchKey)) {
        std::cout << "Key " << searchKey << " found in the B-Tree." << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found in the B-Tree." << std::endl;
    }

    // Delete a key from the B-Tree
    int deleteKey = 6;
    std::cout << "\nDeleting key " << deleteKey << " from the B-Tree..." << std::endl;
    bTree.remove(deleteKey);

    // Print the B-Tree structure after deletion
    std::cout << "\nB-Tree structure after deletion:" << std::endl;
    bTree.printTree();

    return 0;
}
