#include "linkedList.h"

void linkedList::push_front(std::string data) {
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

void linkedList::push_back(std::string data) {
    node* newNode = new node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void linkedList::pop_front() {
    if (head == nullptr) {
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

void linkedList::print() const {
    node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
