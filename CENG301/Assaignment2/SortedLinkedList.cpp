#include "User.h"
#include "SortedLinkedList.h"
#include "LinkedListNode.h"

#include<iostream>
#include<string>

using namespace std;

// Implement the functions in the "SortedLinkedList.h"


SortedLinkedList::SortedLinkedList() {
    head = nullptr;
}

SortedLinkedList::~SortedLinkedList() {
    LinkedListNode *current = head;
    while (current != nullptr) {
        LinkedListNode *next = current->next;
        delete current;
        current = next;
    }
}

bool SortedLinkedList::isEmpty() const {
    return head == nullptr;
}

bool SortedLinkedList::add(User *u) {
    LinkedListNode *newNode = new LinkedListNode();
    newNode->u = u;
    newNode->next = nullptr;

    if (head == nullptr || head->u->getId() > u->getId()) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    LinkedListNode *current = head;
    while (current->next != nullptr && current->next->u->getId() < u->getId()) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool SortedLinkedList::remove(int userId) {
    LinkedListNode *temp = head, *prev = nullptr;

    if (temp != nullptr && temp->u->getId() == userId) {
        head = temp->next;
        delete temp;
        return true;
    }

    while (temp != nullptr && temp->u->getId() != userId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return false;

    prev->next = temp->next;
    delete temp;
    return true;
}

bool SortedLinkedList::checkIfExist(int userId) {
    LinkedListNode *current = head;
    while (current != nullptr) {
        if (current->u->getId() == userId) return true;
        current = current->next;
    }
    return false;
}

LinkedListNode* SortedLinkedList::getPointerTo(int userId) {
    LinkedListNode* current = head;
    while (current != nullptr) {
        if (current->u->getId() == userId) return current;
        current = current->next;
    }
    return nullptr;
}

void SortedLinkedList::print() {
    LinkedListNode *current = head;
    while (current != nullptr) {
        std::cout << current->u->getId() << ", " << current->u->getName() << std::endl;
        current = current->next;
    }
}