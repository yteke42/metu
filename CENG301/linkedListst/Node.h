#include "myUsers.h"

class LinkedList;

class Node {
public:
    myUsers *u;
    Node *next;

    // Constructor
    Node(myUsers *u, Node *next = nullptr) : u(u), next(next) {}

    friend class LinkedList;
};
