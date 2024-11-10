#ifndef B_TREE_NODE_TPP
#define B_TREE_NODE_TPP

#include <array>

#include "b_tree_node.h"
#include <stack>

BTreeNode::BTreeNode(const int t, const bool is_leaf) {
    _t = t; // Minimum degree (defines the range for the number of keys)
    _is_leaf = is_leaf; // True if leaf node, otherwise False
    _keys = {}; // List of keys in the node
    _children = {}; // List of child nodes
}

BTreeNode::~BTreeNode() {
    std::stack<BTreeNode*> stackNodes;  // Stack of pointers to BTreeNode in this subtree
    for (auto* child : _children) {     // Push all child pointers of the root node
        if (child) stackNodes.push(child);
    }

    while (!stackNodes.empty()) {
        const auto& currentNode = stackNodes.top(); // Take last node from stack stack
        stackNodes.pop(); // Delete from stack last picked node

        // Ierate over children of currentNode
        for (auto* currentChild : currentNode->_children) {
            if (currentChild) stackNodes.push(currentChild);  // Push non-null children onto the stack
        }

        delete currentNode; // Delete currentNode that prevent overflowing of data
    }
}

void BTreeNode::splitChild(const int& i, BTreeNode* y) {
    const int t = static_cast<int>(_t);
    auto* z = new BTreeNode(t, y->_is_leaf);

    z->_keys.assign(y->_keys.begin() + t, y->_keys.end());
    if (!y->_is_leaf) {
        z->_children.assign(y->_children.begin() + t, y->_children.end());
    }

    y->_keys.resize(t - 1);
    y->_children.resize(t);

    _children.insert(_children.begin() + i + 1, z);
    _keys.insert(_keys.begin() + i, y->_keys.back());
}

void BTreeNode::insertNonFull(const int& key) {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.emplace(this);

    while (!stackNodes.empty()) {
        int i = static_cast<int>(_keys.size()) - 1;
        BTreeNode* currentNode = stackNodes.top();
        stackNodes.pop();

        if (currentNode->_is_leaf) {
            currentNode->_keys.push_back(0);
            while (i >= 0 && key < currentNode->_keys[i]) {
                currentNode->_keys[i + 1] = currentNode->_keys[i];
                i -= 1;
            }
            currentNode->_keys[i + 1] = key;
        } else {
            while (i >= 0 && key < currentNode->_keys[i]) i--;
            i++;
            if (currentNode->_children[i]->_keys.size() == 2 * currentNode->_t - 1) {
                splitChild(i, currentNode->_children[i]);
                if (key > currentNode->_keys[i]) i++;
            }
            stackNodes.emplace(currentNode->_children[i]);
        }
    }
}

BTreeNode* BTreeNode::search(const int& key) {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.push(this);

    while (!stackNodes.empty()) {
        auto* currentNode = stackNodes.top();
        stackNodes.pop();

        const size_t i = currentNode->findKey(key);
        if (i < currentNode->_keys.size() && currentNode->_keys[i] == key) {
            return currentNode;
        }
        if (currentNode->_is_leaf) return nullptr;
        stackNodes.push(currentNode->_children[i]);
    }
    return nullptr;
}

void BTreeNode::remove(const int& key) {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.push(this);

    while (!stackNodes.empty()) {
        auto* currentNode = stackNodes.top();
        stackNodes.pop();

        const size_t idx = findKey(key);

        if (idx < currentNode->_keys.size() && currentNode->_keys[idx] == key) {
            if (currentNode->_is_leaf) removeFromLeaf(idx);
            else removeFromNonLeaf(idx, stackNodes);
        } else {
            if (currentNode->_is_leaf) return;
            const size_t flag = idx == currentNode->_keys.size();
            if (currentNode->_children[idx]->_keys.size() < currentNode->_t) currentNode->fill(idx);
            if (flag && idx > currentNode->_keys.size()) {
                stackNodes.push(currentNode->_children[idx - 1]);
            } else {
                stackNodes.push(currentNode->_children[idx]);
            }
        }
    }
}

size_t BTreeNode::findKey(const int& key) const {
    size_t idx = 0;
    while (idx < _keys.size() && _keys[idx] < key) {
        idx += 1;
    }
    return idx;
}

int BTreeNode::getPred(const size_t& idx) const {
    const BTreeNode* cur = _children[idx];
    while (!cur->_is_leaf) {
        cur = cur->_children.back();
    }
    return cur->_keys.back();
}

int BTreeNode::getSucc(const size_t& idx) const {
    const BTreeNode* cur = _children[idx + 1];
    while (!cur->_is_leaf) {
        cur = cur->_children[0];
    }
    return cur->_keys[0];
}

void BTreeNode::removeFromLeaf(const size_t& idx) {
    _keys.erase(_keys.begin() + static_cast<int>(idx));
}

void BTreeNode::removeFromNonLeaf(const size_t& idx, std::stack<BTreeNode*>& stackNodes) {
    if (_children[idx]->_keys.size() >= _t) {
        const int pred = getPred(idx);
        _keys[idx] = pred;
        stackNodes.push(_children[idx]);  // Push child to continue removal iteratively
    } else if (_children[idx + 1]->_keys.size() >= _t) {
        const int succ = getSucc(idx);
        _keys[idx] = succ;
        stackNodes.push(_children[idx + 1]);  // Push child to continue removal iteratively
    } else {
        merge(idx);
        stackNodes.push(_children[idx]);  // Push merged child to continue removal
    }
}


void BTreeNode::fill(const size_t& idx) {
    if (idx != 0 && _children[idx - 1]->_keys.size() >= _t) {
        borrowFromPrev(idx);
    } else if (idx != _keys.size() && _children[idx + 1]->_keys.size() >= _t) {
        borrowFromNext(idx);
    } else {
        if (idx != _keys.size()) merge(idx);
        else merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(const size_t& idx) {
    BTreeNode* child = _children[idx];
    BTreeNode* sibling = _children[idx + 1];

    child->_keys.insert(child->_keys.begin(), _keys[idx]);
    if (!child->_is_leaf || !sibling->_children.empty()) {
        // Pop the last element from sibling's children
        BTreeNode* lastChild = sibling->_children.back();
        sibling->_children.pop_back();

        // Insert it at the beginning of child's children
        child->_children.insert(child->_children.begin(), lastChild);
    }
    _keys[idx - 1] = sibling->_keys.back();
    sibling->_keys.pop_back();
}

void BTreeNode::borrowFromNext(const size_t& idx) {
    BTreeNode* child = _children[idx];
    BTreeNode* sibling = _children[idx + 1];

    child->_keys.push_back(_keys[idx]);
    if (!child->_is_leaf) {
        child->_children.push_back(sibling->_children.back());
        sibling->_children.pop_back();
    }
    _keys[idx] = sibling->_keys.back();
    sibling->_keys.pop_back();
}

void BTreeNode::merge(const size_t& idx) {
    BTreeNode* child = _children[idx];
    BTreeNode* sibling = _children[idx + 1];

    child->_keys.push_back(_keys[idx]);
    _keys.pop_back();
    child->_keys.insert(child->_keys.begin(), sibling->_keys.begin(), sibling->_keys.end());

    if (!child->_is_leaf) {
        child->_children.insert(child->_children.begin(), sibling->_children.begin(), sibling->_children.end());
    }
    _children.erase(_children.begin() + static_cast<int>(idx) + 1);
}

void BTreeNode::printNode(const int level) const {
    std::queue<std::pair<const BTreeNode*, int>> nodeQueue;  // Queue to hold nodes and their levels
    nodeQueue.emplace(this, 0);  // Start with the root node at level 0

    while (!nodeQueue.empty()) {
        auto [currentNode, level] = nodeQueue.front();  // Get the node and level
        nodeQueue.pop();

        // Print the current node's level and keys
        std::cout << "Level " << level << " Keys: ";
        for (const auto& key : currentNode->_keys) {
            std::cout << key << " ";
        }
        std::cout << std::endl;

        // Add children of the current node to the queue with an incremented level
        for (const auto* child : currentNode->_children) {
            if (child) {
                nodeQueue.emplace(child, level + 1);
            }
        }
    }
}

#endif // B_TREE_NODE_TPP