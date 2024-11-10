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
    if (_root) {
        std::stack<std::pair<BTreeNode*, int>> stack;
        stack.emplace(_root, 0);

        while (!stack.empty()) {
            auto* currentNode = stack.top().first;
            const auto& currentLevel = stack.top().second;
            stack.pop();

            std::cout << "Level " << currentLevel << ": ";
            std::cout << "[";
            for (size_t i = 0; i < currentNode->_keys.size(); ++i) {
                std::cout << currentNode->_keys[i];
                if (i != currentNode->_keys.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "] ";

            if (!currentNode->_is_leaf) {
                for (auto* child : currentNode->_children) {
                    if (!child->_keys.empty()) stack.emplace(child, currentLevel + 1);
                }
            }

            std::cout << std::endl;
        }
    } else {
        std::cout << "Tree is empty." << std::endl;
    }
}

#endif //B_TREE_TPP
