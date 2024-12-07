#ifndef TREAP_H
#define TREAP_H

#include "../include/treap.h"
#include <stack>

Treap::Treap() {
    _root = nullptr;
    _priority_counter = 0;
}

Treap::~Treap() {
    if (!_root) {
        return;
    }

    std::stack<>
}

#endif //TREAP_H
