#ifndef NODE_H
#define NODE_H
#include <iostream>

class node {
public:
    std::string data;
    node* next;
    node(std::string data) : data(data), next(nullptr) {}

    ~node() = default;
};

#endif //NODE_H
