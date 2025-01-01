//LinkedListNode.h
//You can modify this file if needed, do not change the name of the class
#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

class User;
class SortedLinkedList;

class LinkedListNode {
public:
    User *u;
    LinkedListNode *next;

    LinkedListNode() : u(nullptr), next(nullptr) {}
    ~LinkedListNode() {}

    friend class SortedLinkedList;
};

#endif
