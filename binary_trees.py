"""
Basic Binary Tree

A binary tree is a hierarchical data structure that consists of nodes, where each node has at most two children. The main components of a binary tree are as follows:

1. **Root Node**:
   - The root node is the topmost node in the binary tree.
   - It serves as the starting point for all operations in the tree, and there are no nodes above it.
   - In a binary tree, there is exactly one root node.

2. **Child Nodes**:
   - Each node in a binary tree can have up to two children: the left child and the right child.
   - The left child is a node that is directly connected to another node when moving left.
   - The right child is similarly connected but moves to the right.
   - Child nodes can themselves be roots of subtrees, leading to a recursive structure.

3. **Node Relationships**:
   - The relationship between nodes in a binary tree is hierarchical. Each node (except for the root) has exactly one parent node, which is the node from which it is descended.
   - A node without children is called a leaf node. Leaf nodes represent the endpoints of the tree.

4. **Types of Binary Trees**:
   - **Full Binary Tree**: Every node other than the leaf nodes has two children.
   - **Complete Binary Tree**: All levels of the tree are fully filled except possibly for the last level, which is filled from left to right.
   - **Perfect Binary Tree**: All internal nodes have two children, and all leaf nodes are at the same level.
   - **Binary Search Tree (BST)**: A binary tree that maintains a specific order, where the left child’s value is less than the parent node’s value, and the right child’s value is greater.

The binary tree is a foundational data structure widely used in various algorithms, such as searching and sorting, as well as in applications like expression parsing and hierarchical data representation.
"""

# Class Node for storing value and children nodes
class Node:
    def __init__(self, data):
        # Initialize a new node with the given data
        self.data = data  # Store the value of the node
        self.left = None  # Initialize left child as None
        self.right = None  # Initialize right child as None


# Class FullBinaryTrees to represent the structure of a full binary tree
class FullBinaryTrees:
    def __init__(self):
        # Create the root of the tree and establish the full binary tree structure
        self.root = Node(1)  # Create the root node with value 1
        # Create left and right children for the root node
        self.root.left = Node(2)  # Left child of root
        self.root.right = Node(3)  # Right child of root

        # Further expand the tree by adding children to the left and right nodes
        self.root.left.left = Node(4)  # Left child of node 2
        self.root.left.right = Node(5)  # Right child of node 2
        self.root.right.left = Node(6)  # Left child of node 3
        self.root.right.right = Node(7)  # Right child of node 3

    def print_tree(self, node):
        # A method to perform a pre-order traversal of the tree and print the node values
        if node is not None:  # Check if the current node is not None
            print(node.data, end=' ')  # Print the value of the current node
            # Recursively print the left subtree
            self.print_tree(node.left)
            # Recursively print the right subtree
            self.print_tree(node.right)


class CompleteBinaryTree:
    def __init__(self):
        self.root = None  # Initialize the root of the tree
        self.size = 0  # Keep track of the number of nodes in the tree

    def insert(self, data):
        # Insert a new node into the complete binary tree
        new_node = Node(data)  # Create a new node with the given data
        if self.root is None:
            self.root = new_node  # If the tree is empty, set the new node as root
        else:
            # Find the position to insert the new node
            queue = [self.root]  # Use a queue for level order traversal
            while queue:
                current = queue.pop(0)  # Dequeue the front node
                # If left child is None, insert here
                if not current.left:
                    current.left = new_node
                    break
                else:
                    queue.append(current.left)
                # If right child is None, insert here
                if not current.right:
                    current.right = new_node
                    break
                else:
                    queue.append(current.right)
        self.size += 1  # Increment the size of the tree

    def print_tree(self, node):
        # A method to perform a level-order traversal of the tree and print the node values
        if node is not None:  # Check if the current node is not None
            print(node.data, end=' ')  # Print the value of the current node
            self.print_tree(node.left)  # Recursively print the left subtree
            self.print_tree(node.right)  # Recursively print the right subtree


# Class PerfectBinaryTree to represent the structure of a perfect binary tree
class PerfectBinaryTree:
    def __init__(self, height):
        # Initialize the tree with a given height
        self.root = None  # Initialize the root of the tree
        self.height = height  # Store the height of the tree

    def _insert_level_order(self, data, level):
        # Insert a new node in level order
        if level > self.height:
            return None

        new_node = Node(data)  # Create a new node with the given data
        new_node.left = self._insert_level_order(data * 2, level + 1)  # Insert left child
        new_node.right = self._insert_level_order(data * 2 + 1, level + 1)  # Insert right child
        return new_node

    def build_tree(self):
        # Start building the perfect binary tree
        self.root = self._insert_level_order(1, 0)

    def print_tree(self, node):
        # A method to perform a pre-order traversal of the tree and print the node values
        if node is not None:  # Check if the current node is not None
            print(node.data, end=' ')  # Print the value of the current node
            self.print_tree(node.left)  # Recursively print the left subtree
            self.print_tree(node.right)  # Recursively print the right subtree


# Class BinarySearchTree to represent the structure of a binary search tree
class BinarySearchTree:
    def __init__(self):
        self.root = None  # Initialize the root of the tree

    def insert(self, data):
        # Insert a new node with the given data into the BST
        if not self.root:
            self.root = Node(data)  # If tree is empty, set new node as root
        else:
            self._insert_recursive(self.root, data)  # Insert recursively

    def _insert_recursive(self, node, data):
        # Helper method to insert data in the BST
        if data < node.data:  # If data is less than node, go to the left
            if node.left is None:
                node.left = Node(data)  # Insert new node here
            else:
                self._insert_recursive(node.left, data)  # Recur on left child
        else:  # If data is greater or equal, go to the right subtree
            if node.right is None:
                node.right = Node(data)  # Insert new node here
            else:
                self._insert_recursive(node.right, data)  # Recur on right child

    def search(self, data):
        # Search for a node with the given data in the BST
        return self._search_recursive(self.root, data)

    def _search_recursive(self, node, data):
        # Helper method to search for data in the BST
        if node is None:  # Base case: node not found
            return False
        if node.data == data:  # Data found
            return True
        elif data < node.data:  # Search in left subtree
            return self._search_recursive(node.left, data)
        else:  # Search in right subtree
            return self._search_recursive(node.right, data)

    def print_in_order(self, node):
        # Perform in-order traversal of the tree and print the node values
        if node is not None:  # Check if the current node is not None
            self.print_in_order(node.left)  # Recursively print left subtree
            print(node.data, end=' ')  # Print the value of the current node
            self.print_in_order(node.right)  # Recursively print right subtree


# Example usage of FullBinaryTrees class
if __name__ == "__main__":
    # Create an instance of FullBinaryTrees
    full_binary_tree = FullBinaryTrees()

    # Print the values of the full binary tree
    print("Full Binary Tree nodes in pre-order traversal:")
    full_binary_tree.print_tree(full_binary_tree.root)  # Output: 1 2 4 5 3 6 7

    # Create an instance of CompleteBinaryTree
    complete_binary_tree = CompleteBinaryTree()

    # Insert nodes into the complete binary tree
    complete_binary_tree.insert(1)
    complete_binary_tree.insert(2)
    complete_binary_tree.insert(3)
    complete_binary_tree.insert(4)
    complete_binary_tree.insert(5)
    complete_binary_tree.insert(6)
    complete_binary_tree.insert(7)

    # Print the values of the complete binary tree
    print("\nComplete Binary Tree nodes in level-order traversal:")
    complete_binary_tree.print_tree(complete_binary_tree.root)  # Output: 1 2 4 5 3

    # Create an instance of PerfectBinaryTree with a specified height
    height = 2  # Example height
    perfect_binary_tree = PerfectBinaryTree(height)

    # Build the perfect binary tree
    perfect_binary_tree.build_tree()

    # Print the values of the perfect binary tree
    print("\nPerfect Binary Tree nodes in pre-order traversal:")
    perfect_binary_tree.print_tree(perfect_binary_tree.root)  # Output: 1 2 4 5 3 6 7

    # Create an instance of BinarySearchTree
    bst = BinarySearchTree()

    # Insert nodes into the binary search tree
    bst.insert(5)
    bst.insert(3)
    bst.insert(7)
    bst.insert(2)
    bst.insert(4)
    bst.insert(6)
    bst.insert(8)

    # Print the values of the binary search tree in in-order traversal
    print("\nBinary Search Tree nodes in in-order traversal:")
    bst.print_in_order(bst.root)  # Output: 2 3 4 5 6 7 8

    # Search for specific values in the binary search tree
    print("\nSearching for values in the BST:")
    print("Search for 4:", bst.search(4))  # Output: True
    print("Search for 9:", bst.search(9))  # Output: False

# Time and Space Complexity Discussion
# 1. Full Binary Tree:
#    - Insertion: O(1) for adding a node, but O(n) for finding the insertion point in worst case (not a priority structure).
#    - Space Complexity: O(n) where n is the number of nodes, as each node requires space.

# 2. Complete Binary Tree:
#    - Insertion: O(log n) on average for balanced insertions.
#    - Space Complexity: O(n) as all nodes are stored.

# 3. Perfect Binary Tree:
#    - Construction: O(n) for building the entire tree.
#    - Space Complexity: O(n) where n is the total number of nodes.

# 4. Binary Search Tree (BST):
#    - Insertion: O(log n) on average for balanced trees, O(n) in the worst case (unbalanced).
#    - Searching: O(log n) on average for balanced trees, O(n) in the worst case.
#    - Space Complexity: O(n) for storing nodes.

# Note: Visual representation tools like Graphviz or online tools can be used to visualize these trees dynamically.
