#include "SocialMediaPlatform.h"
#include "User.h"
#include "SortedLinkedList.h"
#include "LinkedListNode.h"

using namespace std;

// Implement functions in the "SocialMediaPlatform.h"
SocialMediaPlatform::SocialMediaPlatform() : users(new SortedLinkedList()) {}

SocialMediaPlatform::~SocialMediaPlatform() { delete users; }

bool SocialMediaPlatform::addUser(const int userId, const std::string name) {
    if (users->checkIfExist(userId)) return false;

    User *newUser = new User();

    newUser->setId(userId);
    newUser->setName(name);
    users->add(newUser);
    return true;
} 

bool SocialMediaPlatform::removeUser(const int userId) {
    // Iterate through all users in the platform
    LinkedListNode *currentUserNode = users->getHead();
    while (currentUserNode != nullptr) {
        // Remove the user to be deleted from the current user's followeds and followers list
        currentUserNode->u->removeFollowed(userId);
        currentUserNode->u->removeFollower(userId);

        // Move to the next user
        currentUserNode = currentUserNode->next;
    }

    // Remove the user from the platform
    return users->remove(userId);
}





bool SocialMediaPlatform::followUser(const int firstUserId, const int secondUserId) {
    LinkedListNode *firstUserNode = users->getPointerTo(firstUserId);
    LinkedListNode *secondUserNode = users->getPointerTo(secondUserId);

    if (firstUserNode == nullptr || secondUserNode == nullptr) return false;

    if (firstUserNode->u->getFolloweds()->checkIfExist(secondUserId)) {
        // User is already following the second user
        return false;
    }

    firstUserNode->u->addFollowed(secondUserNode->u);
    secondUserNode->u->addFollower(firstUserNode->u);
    return true;
}


bool SocialMediaPlatform::unfollowUser(const int firstUserId, const int secondUserId) {
    LinkedListNode *firstUserNode = users->getPointerTo(firstUserId);
    LinkedListNode *secondUserNode = users->getPointerTo(secondUserId);

    if (firstUserNode == nullptr || secondUserNode == nullptr) return false;

    if (!firstUserNode->u->getFolloweds()->remove(secondUserId) ||
        !secondUserNode->u->getFollowers()->remove(firstUserId)) {
        return false; // Either user not found or user not followed, return false
    }

    return true;
}


void SocialMediaPlatform::showFollowersOf(const int userId) const {
    LinkedListNode *userNode = users->getPointerTo(userId);
    if (userNode != nullptr) {
        std::cout << "Users following the user with ID " << userId << ":" << std::endl;
        if (!userNode->u->getFollowers()->isEmpty()) {
            userNode->u->getFollowers()->print();
        } else {
            std::cout << "None" << std::endl;
        }
    } else {
        std::cout << "Cannot show. There is no user with ID " << userId << "." << std::endl;
    }
}





void SocialMediaPlatform::showAllUsers() const {
    std::cout << "Users in the social media platform:" << std::endl;
    if (users->isEmpty()) {
        std::cout << "None" << std::endl;
    } else {
        users->print();
    }
}





