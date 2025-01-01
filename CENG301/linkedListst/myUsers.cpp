#include "myUsers.h"


int myUsers::getId() {
    return id;
}

void myUsers::setId(int id) {
    this->id = id;
}

std::string myUsers::getName() {
    return name;
}

void myUsers::setName(std::string name) {
    this->name = name;
}
