#ifndef B_TREE_TPP
#define B_TREE_TPP

#include "b_tree.h"
#include <stack>

BTree::BTree(const int& t) {
    _root = new BTreeNode(t, true);
    _t = t;
}

BTree::~BTree() {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.push(_root);

    while (!stackNodes.empty()) {
        const auto* currentNode = stackNodes.top();
        stackNodes.pop();

        if (currentNode && !currentNode->_children.empty()) {
            for (auto* child : currentNode->_children) {
                stackNodes.push(child);
            }
        }

        delete currentNode;
    }
}

void BTree::insert(const int& key) {
    BTreeNode* root = _root;
    if (root->_keys.size() == 2 * _t - 1) {  // Root is full
        auto* new_root = new BTreeNode(_t, false);
        new_root->_children.push_back(_root);
        new_root->splitChild(0, root);

        const size_t idx = key < new_root->_keys[0] ? 0 : 1;
        new_root->_children[idx]->insertNonFull(key);
        _root = new_root;
    } else {
        root->insertNonFull(key);
    }
}

BTreeNode* BTree::search(const int& key) const {
    return _root ? _root->search(key) : nullptr;
}

void BTree::remove(const int& key) {
    if (!_root) {
        return;
    }

    _root->remove(key);

    if (_root->_keys.empty()) {
        _root = !_root->_is_leaf ? _root->_children[0] : nullptr;
    }
}

void BTree::printTree() const {
    std::stack<std::pair<BTreeNode*, int>> stack;
    stack.emplace(_root, 0);

    while (!stack.empty()) {
        auto* currentNode = stack.top().first;
        const auto& currentLevel = stack.top().second;
        stack.pop();

        if (!currentNode->_keys.empty()) {
            std::cout << "Level " << currentLevel << ": ";
            std::cout << "[";
            for (const auto& key : currentNode->_keys) {
                if (key == currentNode->_keys.back()) {
                    std::cout << key << "]";
                } else {
                    std::cout << key << ", ";
                }
            }
        }

        if (!currentNode->_is_leaf) {
            for (auto* child : currentNode->_children) {
                if (!child->_keys.empty()) stack.emplace(child, currentLevel + 1);
            }
        }
    }
}

#endif //B_TREE_TPP
