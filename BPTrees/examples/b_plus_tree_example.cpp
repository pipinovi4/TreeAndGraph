#include "../source/b_plus_tree.h" // Include the BPTree header
#include <iostream>

int main() {
    // Initialize a B+ Tree with a minimum degree t = 3
    BPTree bpt(3);

    // Insert keys into the B+ Tree
    std::cout << "Inserting keys into the B+ Tree: 10, 20, 5, 6, 12, 30, 7, 17\n";
    bpt.insert(10);
    bpt.insert(20);
    bpt.insert(5);
    bpt.insert(6);
    bpt.insert(12);
    bpt.insert(30);
    bpt.insert(7);
    bpt.insert(17);

    // Print the B+ Tree structure
    std::cout << "\nB+ Tree after insertions:\n";
    bpt.printTree();

    // Search for a key in the B+ Tree
    int searchKey = 12;
    std::cout << "\nSearching for key " << searchKey << " in the B+ Tree...\n";
    auto searchResult = bpt.search(searchKey);
    if (searchResult) {
        std::cout << "Key " << searchKey << " found in the B+ Tree.\n";
    } else {
        std::cout << "Key " << searchKey << " not found in the B+ Tree.\n";
    }

    // Perform a range query
    int startKey = 6, endKey = 17;
    std::cout << "\nPerforming range query for keys between " << startKey << " and " << endKey << "...\n";
    auto rangeResult = bpt.rangeQuery(startKey, endKey);
    std::cout << "Keys in range [" << startKey << ", " << endKey << "]: ";
    for (const auto& key : rangeResult) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    // Delete a key from the B+ Tree
    int deleteKey = 6;
    std::cout << "\nDeleting key " << deleteKey << " from the B+ Tree...\n";
    bpt.remove(deleteKey);

    // Print the B+ Tree after deletion
    std::cout << "\nB+ Tree after deletion of key " << deleteKey << ":\n";
    bpt.printTree();

    return 0;
}
