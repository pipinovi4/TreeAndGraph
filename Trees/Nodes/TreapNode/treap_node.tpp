#ifndef TREAP_NODE_TPP
#define TREAP_NODE_TPP

#include "treap_node.h"
#include <random>

TreapNode::TreapNode(const int& key, const int& priority, const int& min, const int& max)
: key(key), priority(priority ? priority : getRandomInt(min, max)) {}

int TreapNode::getRandomInt(const int& min, const int& max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

#endif //TREAP_NODE_TPP