#include <iostream>
#include <vector>
#include "../include/segment_tree.h"

int main() {
    // Sample data
    std::vector<int> data = {1, 3, 5, 7, 9, 11};

    // Function to calculate the sum
    auto sum_func = [](int a, int b) { return a + b; };

    // Identity value for the sum operation (neutral element)
    int identity = 0;

    // Create a Segment Tree for range sum queries
    SegmentTree<int> seg_tree(data, sum_func, identity);

    // Perform a range query: sum of elements from index 1 to 4 (inclusive)
    std::cout << "Sum of range [1, 4): " << seg_tree.query(1, 4) << std::endl;

    // Update an element: Set index 2 to 10
    seg_tree.update(2, 10);

    // Perform another range query after the update
    std::cout << "Sum of range [1, 4) after update: " << seg_tree.query(1, 4) << std::endl;

    // Range query for the entire array
    std::cout << "Sum of entire range [0, 6): " << seg_tree.query(0, 6) << std::endl;

    return 0;
}
