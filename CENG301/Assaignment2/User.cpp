#include "User.h"
#include "SortedLinkedList.h"
#include "LinkedListNode.h"

using namespace std;

// Implement the functions in the "User.h"
User::User() {
    id = 0;
    name = "";
    followers = new SortedLinkedList();
    followeds = new SortedLinkedList();
}

User::~User() { 
    delete followers; 
    delete followeds; 
}

int User::getId() { 
    return id; 
}

void User::setId(int id) { 
    this->id = id; 
}

std::string User::getName() { 
    return name; 
}

void User::setName(std::string name) { 
    this->name = name; 
}

bool User::addFollower(User *u) { 
    return followers->add(u); 
}

bool User::removeFollower(int userId) { 
    return followers->remove(userId); 
}

bool User::addFollowed(User *u) { 
    return followeds->add(u); 
}

bool User::removeFollowed(int userId) { 
    return followeds->remove(userId); 
}

SortedLinkedList *User::getFollowers() { 
    return followers; 
}
SortedLinkedList* User::getFolloweds() {
    return followeds;
}
