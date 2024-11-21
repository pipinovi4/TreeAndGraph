#ifndef SPLAY_TREE_TPP
#define SPLAY_TREE_TPP

#include "splay_tree.h"
#include <stack>

// Constructor: Initializes the root to nullptr
SplayTree::SplayTree() {
    _root = nullptr;
}

// Destructor: Deallocates all nodes in the tree
SplayTree::~SplayTree() {
    std::stack<Node*> stackNodes;
    if (_root) stackNodes.push(_root);

    while (!stackNodes.empty()) {
        Node* currentNode = stackNodes.top();
        stackNodes.pop();

        // Push left and right children to the stack for later deletion
        if (currentNode->left) stackNodes.push(currentNode->left);
        if (currentNode->right) stackNodes.push(currentNode->right);

        // Delete the current node
        delete currentNode;
    }
}

// Insert a new node with the given data into the splay tree
void SplayTree::insert(int data) {
    // If the tree is empty, create a new root node
    if (!_root) {
        _root = new Node(data);
        return;
    }

    // Splay the tree with the given data
    _root = _splay(_root, data);

    // If the data already exists in the tree, do not insert
    if (_root->data == data) return;

    // Create a new node with the given data
    auto newNode = new Node(data);

    // Insert the new node based on the comparison with the root
    if (data < _root->data) {
        newNode->right = _root;
        newNode->left = _root->left;
        _root->left = nullptr;
    } else {
        newNode->left = _root;
        newNode->right = _root->right;
        _root->right = nullptr;
    }

    // Update the root to the new node
    _root = newNode;
}

// Search for a node with the given data in the splay tree
Node* SplayTree::search(int data) {
    // Splay the tree with the given data
    _root = _splay(_root, data);

    // If the root's data matches the search data, return the root
    if (_root && _root->data == data) {
        return _root; // Node found
    } else {
        return nullptr; // Node not found
    }
}

// Remove a node with the given data from the splay tree
void SplayTree::remove(int data) {
    if (!_root) return; // Tree is empty

    // Splay the tree with the given data
    _root = _splay(_root, data);

    // If the data is not found, do nothing
    if (_root->data != data) return;

    // If the node to be deleted has no left child
    if (!_root->left) {
        _root = _root->right;
    }
        // If the node to be deleted has no right child
    else if (!_root->right) {
        _root = _root->left;
    }
        // If the node to be deleted has both left and right children
    else {
        Node* leftSubtree = _root->left;
        Node* rightSubtree = _root->right;

        // Splay the maximum node in the left subtree
        _root = _splay(leftSubtree, data);

        // Attach the right subtree to the new root
        _root->right = rightSubtree;
    }
}

// Perform an in-order traversal of the splay tree
std::vector<int> SplayTree::inorder() {
    std::vector<int> result;
    std::stack<Node*> stack;
    Node* current = _root;

    // Traverse the tree iteratively
    while (current != nullptr || !stack.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = stack.top();
        stack.pop();

        // Add the node's data to the result
        result.push_back(current->data);

        // Visit the right subtree
        current = current->right;
    }

    return result;
}

// Splay operation: Bring the node with the given data to the root
Node* SplayTree::_splay(Node* node, int data) {
    if (!node || node->data == data) {
        return node; // Tree is empty or data is already at the root
    }

    // Data lies in the left subtree
    if (data < node->data) {
        // If the left child is null, the data is not in the tree
        if (!node->left) return node;

        // Zig-Zig (Left Left)
        if (data < node->left->data) {
            // Recursively splay the left-left grandchild
            node->left->left = _splay(node->left->left, data);
            // Perform right rotation
            node = _rightRotation(node);
        }
            // Zig-Zag (Left Right)
        else if (data > node->left->data) {
            // Recursively splay the left-right grandchild
            node->left->right = _splay(node->left->right, data);
            // Perform left rotation on left child
            if (node->left->right) {
                node->left = _leftRotation(node->left);
            }
        }

        // Perform right rotation
        return (node->left == nullptr) ? node : _rightRotation(node);
    }
        // Data lies in the right subtree
    else {
        // If the right child is null, the data is not in the tree
        if (!node->right) return node;

        // Zig-Zig (Right Right)
        if (data > node->right->data) {
            // Recursively splay the right-right grandchild
            node->right->right = _splay(node->right->right, data);
            // Perform left rotation
            node = _leftRotation(node);
        }
            // Zig-Zag (Right Left)
        else if (data < node->right->data) {
            // Recursively splay the right-left grandchild
            node->right->left = _splay(node->right->left, data);
            // Perform right rotation on right child
            if (node->right->left) {
                node->right = _rightRotation(node->right);
            }
        }

        // Perform left rotation
        return (node->right == nullptr) ? node : _leftRotation(node);
    }
}

// Right rotation: Rotate the subtree to the right
Node* SplayTree::_rightRotation(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

// Left rotation: Rotate the subtree to the left
Node* SplayTree::_leftRotation(Node* node) {
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

#endif // SPLAY_TREE_TPP