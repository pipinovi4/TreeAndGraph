#include <iostream>
#include "../source/fenwick_tree.h"

int main() {
    // Example data to initialize the Fenwick Tree
    std::vector<int> data = {0, 3, 2, -1, 6, 5, 4, -3};  // Index 0 is dummy for 1-indexed Fenwick Tree

    // Build a Fenwick Tree from the data
    std::cout << "Building Fenwick Tree from data...\n";
    FenwickTree fenwick = FenwickTree::build(data);

    // Query the prefix sum up to specific indices
    std::cout << "Querying prefix sums:\n";
    for (size_t i = 1; i < data.size(); i++) {
        std::cout << "Sum of first " << i << " elements: " << fenwick.query(i) << '\n';
    }

    // Update an element in the tree
    std::cout << "\nUpdating index 3 with +4...\n";
    fenwick.update(3, 4);

    // Query again after the update
    std::cout << "Querying prefix sums after update:\n";
    for (size_t i = 1; i < data.size(); i++) {
        std::cout << "Sum of first " << i << " elements: " << fenwick.query(i) << '\n';
    }

    // Perform a range query
    int left = 2, right = 5;
    std::cout << "\nRange query for indices " << left << " to " << right << ": "
              << fenwick.range_query(left, right) << '\n';

    return 0;
}
