#ifndef B_TREE_NODE_H
#define B_TREE_NODE_H

#pragma once
#include <vector>
#include <cstddef>

class BTreeNode {
public:
 inline BTreeNode(int t, bool is_leaf);
 inline ~BTreeNode();

 inline BTreeNode* search(const int& key);
 inline void remove(const int& key);
 inline void fill(const size_t& idx);
private:
 size_t _t;
 bool _is_leaf;
 std::vector<int> _keys;
 std::vector<BTreeNode*> _children;

 inline void insertNonFull(const int& key);
 inline void splitChild(const int& i, BTreeNode*y);
 inline size_t findKey(const int& key) const;
 inline int getPred(const size_t& idx) const;
 inline int getSucc(const size_t& idx) const;
 inline void removeFromLeaf(const size_t& idx);
 inline void removeFromNonLeaf(const size_t& idx, std::stack<BTreeNode*>& stackNodes);
 inline void borrowFromPrev(const size_t& idx);
 inline void borrowFromNext(const size_t& idx);
 inline void merge(const size_t& idx);
 inline void printNode(int level=0) const;
};

#include "b_tree_node.tpp"

#endif // B_TREE_NODE_H