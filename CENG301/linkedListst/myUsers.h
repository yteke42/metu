#ifndef MYUSERS_H
#define MYUSERS_H

#include <string>

class myUsers {
private:
    int id;
    std::string name;
public:
    myUsers(int id, std::string name) : id(id), name(name) {}

    int getId();
    void setId(int id);
    std::string getName();
    void setName(std::string name);
};

#endif