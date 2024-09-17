#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "node.h"


class linkedList {
private:
node* head;
public:
    linkedList() : head(nullptr) {}

    void push_front(std::string data);

    void push_back(std::string data);

    void pop_front();

    void print() const;

    ~linkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }
};



#endif