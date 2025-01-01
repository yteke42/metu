#include "LinkedList.h"
#include <iostream>

void LinkedList::insert(myUsers *u) {
    Node *node = new Node(u);
    node->next = head;
    head = node;
}

void LinkedList::print() {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->u->getName() << std::endl;
        temp = temp->next;
    }
}
