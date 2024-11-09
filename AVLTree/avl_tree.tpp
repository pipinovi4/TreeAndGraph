#ifndef AVL_TREE_TPP
#define AVL_TREE_TPP

#include "avl_tree.h"
#include <stack>
#include <cmath>

// Constructor initializes the AVL Tree with a nullptr root
AVLTree::AVLTree() {
    root = nullptr;
}

// Destructor to delete all nodes in the AVL tree using an iterative approach
inline AVLTree::~AVLTree() {
    std::stack<Node> stackNodes;
    if (root) {
        stackNodes.push(*root);
    }

    // Use a stack to iteratively delete all nodes
    while (!stackNodes.empty()) {
        const auto current = &stackNodes.top();
        stackNodes.pop();

        // Push left and right children onto the stack for deletion if they exist
        if (current->left) stackNodes.push(*current->left);
        if (current->right) stackNodes.push(*current->right);

        delete current;  // Free the memory of the current node
    }
}

// Helper function to calculate the height of a given node
size_t AVLTree::_height(const Node* node) {
    if (!node) {
        return 0;  // Null nodes have height 0
    }
    return node->height;  // Otherwise, return the height of the node
}

// Helper function to update the height of a node based on its children’s heights
void AVLTree::_updateHeight(Node* node) {
    if (node) {
        node->height = 1 + std::max(_height(node->left), _height(node->right));
    }
}

// Calculates the balance factor of a node to check if the tree needs balancing
int AVLTree::_getBalance(const Node* node) {
    if (!node) {
        return 0;  // Null nodes are perfectly balanced
    }
    // Balance factor is height difference between left and right subtrees
    return static_cast<int>(_height(node->left) - _height(node->right));
}

// Performs a right rotation on a left-heavy subtree rooted at `y`
// Adjusts the heights and returns the new root of the rotated subtree
Node* AVLTree::_rightRotation(Node* y) {
    Node* x = y->left;      // x becomes the new root of the rotated subtree
    Node* t2 = x->right;    // t2 is the right child of x, will become left child of y

    // Perform rotation by adjusting pointers
    x->right = y;
    y->left = t2;

    // Update heights of y and x after rotation
    _updateHeight(y);
    _updateHeight(x);

    return x;  // Return the new root of the rotated subtree
}

// Performs a left rotation on a right-heavy subtree rooted at `x`
// Adjusts the heights and returns the new root of the rotated subtree
Node* AVLTree::_leftRotation(Node* x) {
    Node* y = x->right;     // y becomes the new root of the rotated subtree
    Node* t2 = y->left;     // t2 is the left child of y, will become right child of x

    // Perform rotation by adjusting pointers
    y->left = x;
    x->right = t2;

    // Update heights of x and y after rotation
    _updateHeight(x);
    _updateHeight(y);

    return y;  // Return the new root of the rotated subtree
}

// Public method to insert a new value and maintain AVL balance
void AVLTree::insert(const int data) {
    std::stack<Node*> pathStack;
    Node* current = root;
    Node* parent = nullptr;

    // Traverse the tree to find insertion point while storing the path
    while (current != nullptr) {
        pathStack.push(current);
        parent = current;
        if (data < current->data) {
            current = current->left;  // Move to left subtree
        } else if (data > current->data) {
            current = current->right; // Move to right subtree
        } else {
            return;  // Duplicate data is not allowed, so return without insertion
        }
    }

    // Create the new node and insert it at the correct location
    const auto newNode = new Node(data);
    if (parent == nullptr) {
        root = newNode;  // Tree was empty, new node becomes the root
    } else if (data < parent->data) {
        parent->left = newNode;  // Insert as the left child of parent
    } else {
        parent->right = newNode; // Insert as the right child of parent
    }

    // Backtrack using pathStack to maintain AVL property by checking balance factors
    while (!pathStack.empty()) {
        Node* node = pathStack.top();
        pathStack.pop();

        // Update the height of the current node
        _updateHeight(node);

        // Calculate the balance factor to detect imbalance
        const int balance = _getBalance(node);

        // Rotate the tree to restore AVL balance
        if (balance > 1 && data < node->left->data) {
            // Left Left Case (single right rotation required)
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _rightRotation(node);
                } else {
                    pathStack.top()->right = _rightRotation(node);
                }
            } else {
                root = _rightRotation(node);
            }
        } else if (balance < -1 && data > node->right->data) {
            // Right Right Case (single left rotation required)
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _leftRotation(node);
                } else {
                    pathStack.top()->right = _leftRotation(node);
                }
            } else {
                root = _leftRotation(node);
            }
        } else if (balance > 1 && data > node->left->data) {
            // Left Right Case (double rotation: left on left child, then right on node)
            node->left = _leftRotation(node->left);
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _rightRotation(node);
                } else {
                    pathStack.top()->right = _rightRotation(node);
                }
            } else {
                root = _rightRotation(node);
            }
        } else if (balance < -1 && data < node->right->data) {
            // Right Left Case (double rotation: right on right child, then left on node)
            node->right = _rightRotation(node->right);
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _leftRotation(node);
                } else {
                    pathStack.top()->right = _leftRotation(node);
                }
            } else {
                root = _leftRotation(node);
            }
        }
    }
}

// Public method to search for a target value in the AVL tree iteratively
bool AVLTree::search(const int target) const {
    std::stack<Node> stackNodes;
    if (root) {
        stackNodes.push(*root);
    }

    // Iteratively search by traversing left or right based on the target
    while (!stackNodes.empty()) {
        const Node* currentNode = &stackNodes.top();
        stackNodes.pop();

        if (currentNode->data == target) {
            return true;  // Target found
        } else if (target < currentNode->data && currentNode->left) {
            stackNodes.push(*currentNode->left);  // Move to left subtree
        } else if (target > currentNode->data && currentNode->right) {
            stackNodes.push(*currentNode->right); // Move to right subtree
        }
    }
    return false;  // Target not found
}

// Removes a value from the AVL tree and maintains balance iteratively
void AVLTree::remove(const int data) {
    std::stack<Node*> pathStack;
    Node* current = root;
    Node* parent = nullptr;

    // Find the node to be deleted and store the path
    while (current != nullptr && current->data != data) {
        pathStack.push(current);
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (!current) return;  // Node not found

    // Node with only one child or no child
    if (!current->left || !current->right) {
        Node* child = current->left ? current->left : current->right;

        if (!parent) {
            root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;

    } else {  // Node with two children
        Node* successor = current->right;
        Node* successorParent = current;

        // Find successor (smallest in the right subtree)
        while (successor->left) {
            pathStack.push(successorParent);
            successorParent = successor;
            successor = successor->left;
        }

        // Replace `current` with `successor`'s data and link replacement
        current->data = successor->data;
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        delete successor;
    }

    // Restore AVL property
    while (!pathStack.empty()) {
        Node* node = pathStack.top();
        pathStack.pop();

        _updateHeight(node);
        const int balance = _getBalance(node);

        if (balance > 1 && _getBalance(node->left) >= 0) {
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _rightRotation(node);
                } else {
                    pathStack.top()->right = _rightRotation(node);
                }
            } else {
                root = _rightRotation(node);
            }
        } else if (balance > 1 && _getBalance(node->left) < 0) {
            node->left = _leftRotation(node->left);
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _rightRotation(node);
                } else {
                    pathStack.top()->right = _rightRotation(node);
                }
            } else {
                root = _rightRotation(node);
            }
        } else if (balance < -1 && _getBalance(node->right) <= 0) {
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _leftRotation(node);
                } else {
                    pathStack.top()->right = _leftRotation(node);
                }
            } else {
                root = _leftRotation(node);
            }
        } else if (balance < -1 && _getBalance(node->right) > 0) {
            node->right = _rightRotation(node->right);
            if (!pathStack.empty()) {
                if (pathStack.top()->left == node) {
                    pathStack.top()->left = _leftRotation(node);
                } else {
                    pathStack.top()->right = _leftRotation(node);
                }
            } else {
                root = _leftRotation(node);
            }
        }
    }
}

// Function to print the AVL tree using in-order traversal (non-recursive)
void AVLTree::printInOrder() const {
    std::stack<Node*> nodeStack;
    Node* current = root;

    // Iteratively traverse the tree in in-order
    while (!nodeStack.empty() || current != nullptr) {
        while (current != nullptr) {
            nodeStack.push(current); // Move left and stack each node
            current = current->left;
        }
        current = nodeStack.top();
        nodeStack.pop();
        std::cout << current->data << " "; // Print node's data
        current = current->right; // Move to right subtree
    }
    std::cout << std::endl;  // Newline after traversal
}

#endif // AVL_TREE_TPP
