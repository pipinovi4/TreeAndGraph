#ifndef AVL_TREE_TPP
#define AVL_TREE_TPP

#include "avl_tree.h"
#include <stack>
#include <cmath>

AVLTree::AVLTree() {
    root = nullptr;
}

inline AVLTree::~AVLTree() {
    std::stack<Node> stackNodes;
    stackNodes.push(*root);

    while (!stackNodes.empty()) {
        const auto current = &stackNodes.top();
        stackNodes.pop();

        stackNodes.push(*current->left);
        stackNodes.push(*current->right);

        delete current;
    }
}

size_t AVLTree::_height(const Node* node) {
    if (!node) {
        return 0;
    }
    return node->height;
}

void AVLTree::_updateHeight(Node* node) {
    if (node) {
        node->height = 1 + std::max(_height(node->left), _height(node->right));
    }
}

int AVLTree::_getBalance(const Node* node) {
    if (!node) {
        return 0;
    }
    return static_cast<int>(_height(node->left) - _height(node->right));
}

Node* AVLTree::_rightRotation(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    _updateHeight(y);
    _updateHeight(x);

    return x;
}

Node* AVLTree::_leftRotation(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    _updateHeight(x);
    _updateHeight(y);

    return y;
}

void AVLTree::insert(const int data) {
        std::stack<Node*> pathStack;
        Node* current = root;
        Node* parent = nullptr;

        // Traverse to the insertion point and save the path
        while (current != nullptr) {
            pathStack.push(current);
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else if (data > current->data) {
                current = current->right;
            } else {
                return; // Data is already in the tree, no duplicates
            }
        }

        // Insert the new node
        const auto newNode = new Node(data);
        if (parent == nullptr) {
            root = newNode; // Tree was empty
        } else if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        // Backtrack to balance the tree
        while (!pathStack.empty()) {
            Node* node = pathStack.top();
            pathStack.pop();

            // Update the height
            _updateHeight(node);

            // Check the balance factor
            const int balance = _getBalance(node);

            // Perform rotations if the node becomes unbalanced
            // Left Left Case
            if (balance > 1 && data < node->left->data) {
                if (!pathStack.empty()) {
                    if (pathStack.top()->left == node) {
                        pathStack.top()->left = _rightRotation(node);
                    } else {
                        pathStack.top()->right = _rightRotation(node);
                    }
                } else {
                    root = _rightRotation(node);
                }
            }
            // Right Right Case
            else if (balance < -1 && data > node->right->data) {
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
            // Left Right Case
            else if (balance > 1 && data > node->left->data) {
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
            }
            // Right Left Case
            else if (balance < -1 && data < node->right->data) {
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

bool AVLTree::search(const int target) const {
    std::stack<Node> stackNodes;
    stackNodes.push(*root);

    while (!stackNodes.empty()) {
        const Node* currentNode = &stackNodes.top();
        stackNodes.pop();
        if (!currentNode) {
            return false;
        }
        if (target == currentNode->data) {
            return true;
        }
        if (target < currentNode->data) {
            stackNodes.push(*currentNode->left);
        } else if (target > currentNode->data) {
            stackNodes.push(*currentNode->right);
        }
    }

    return false;
}

void AVLTree::remove(const int data) {
        if (!root) return;

        std::stack<Node*> pathStack;
        Node* node = root;
        Node* parent = nullptr;

        // Traverse to find the node to delete and push nodes onto the pathStack
        while (node && node->data != data) {
            pathStack.push(node);
            parent = node;
            if (data < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        if (!node) return;  // Node not found

        // Deleting the node
        if (node->left == nullptr || node->right == nullptr) {
            // Node has one child or no child
            Node* newChild = (node->left) ? node->left : node->right;

            // If deleting the root node
            if (!parent) {
                root = newChild;
            } else if (parent->left == node) {
                parent->left = newChild;
            } else {
                parent->right = newChild;
            }
            delete node;
        } else {
            // Node has two children, replace with in-order successor
            pathStack.push(node);
            Node* successorParent = node;
            Node* successor = node->right;

            while (successor->left) {
                pathStack.push(successor);
                successorParent = successor;
                successor = successor->left;
            }

            // Replace data and delete the in-order successor node
            node->data = successor->data;
            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }
            delete successor;
        }

        // Backtracking to rebalance the tree
        while (!pathStack.empty()) {
            Node* currentNode = pathStack.top();
            pathStack.pop();

            // Update the height of the current node
            _updateHeight(currentNode);

            // Check the balance factor
            const int balance = _getBalance(currentNode);

            // Perform rotations based on balance factor to maintain AVL property
            if (balance > 1) {
                if (_getBalance(currentNode->left) >= 0) {
                    // Left Left Case
                    if (!pathStack.empty()) {
                        if (pathStack.top()->left == currentNode)
                            pathStack.top()->left = _leftRotation(currentNode);
                        else
                            pathStack.top()->right = _leftRotation(currentNode);
                    } else {
                        root = _leftRotation(currentNode);
                    }
                } else {
                    // Left Right Case
                    currentNode->left = _leftRotation(currentNode->left);
                    if (!pathStack.empty()) {
                        if (pathStack.top()->left == currentNode)
                            pathStack.top()->left = _leftRotation(currentNode);
                        else
                            pathStack.top()->right = _leftRotation(currentNode);
                    } else {
                        root = _leftRotation(currentNode);
                    }
                }
            } else if (balance < -1) {
                if (_getBalance(currentNode->right) <= 0) {
                    // Right Right Case
                    if (!pathStack.empty()) {
                        if (pathStack.top()->left == currentNode)
                            pathStack.top()->left = _leftRotation(currentNode);
                        else
                            pathStack.top()->right = _leftRotation(currentNode);
                    } else {
                        root = _leftRotation(currentNode);
                    }
                } else {
                    // Right Left Case
                    currentNode->right = _leftRotation(currentNode->right);
                    if (!pathStack.empty()) {
                        if (pathStack.top()->left == currentNode)
                            pathStack.top()->left = _leftRotation(currentNode);
                        else
                            pathStack.top()->right = _leftRotation(currentNode);
                    } else {
                        root = _leftRotation(currentNode);
                    }
                }
            }
        }
}

void AVLTree::printInOrder() const {
    std::stack<Node*> nodeStack;
    Node* current = root;

    while (!nodeStack.empty() || current != nullptr) {
        // Traverse to the leftmost node
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        // Process the node at the top of the stack
        current = nodeStack.top();
        nodeStack.pop();
        std::cout << current->data << " ";

        // Traverse the right subtree
        current = current->right;
    }
    std::cout << std::endl;
}

#endif //AVL_TREE_TPP
