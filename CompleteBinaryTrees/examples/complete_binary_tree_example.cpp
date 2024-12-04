#include "../source/complete_binary_tree.h" // Include the CompleteBinaryTree class
#include <iostream> // Include iostream for printing

int main() {
    // Create an instance of the Complete Binary Tree
    CompleteBinaryTree tree;

    // Insert values into the tree
    std::cout << "Inserting values into the Complete Binary Tree..." << std::endl;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    // Print the tree's values in level order
    std::cout << "\nComplete Binary Tree values (Level Order):" << std::endl;
    tree.printTree();

    // Search for values in the tree
    std::cout << "\n\nSearching for values in the tree..." << std::endl;
    int search_values[] = {30, 100, 50};
    for (int value : search_values) {
        if (tree.search(value)) {
            std::cout << "Value " << value << " found in the tree." << std::endl;
        } else {
            std::cout << "Value " << value << " not found in the tree." << std::endl;
        }
    }

    return 0;
}
