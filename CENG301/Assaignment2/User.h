//User.h
// You can modify this file if needed, do not change the name of the class

#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>

class SortedLinkedList;

class User {
private:
    int id;
    std::string name;
    SortedLinkedList *followers;
    SortedLinkedList *followeds;

public:
    User();
    ~User();

    int getId();
    void setId(int id);

    std::string getName();
    void setName(std::string name);

    bool addFollower(User *u);
    bool removeFollower(int userId);

    bool addFollowed(User *u);
    bool removeFollowed(int userId);

    SortedLinkedList *getFollowers();
    SortedLinkedList *getFolloweds();

};
#endif
