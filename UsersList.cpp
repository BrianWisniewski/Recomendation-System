#include "UsersList.h"

// deletes all user objects and frees the memory they were using
UsersList::~UsersList() {
    for (User* user : usersList)
        delete user;
}

// adds a user to the booksList set
void UsersList::addUser(User* newUser) {
    usersList.insert(newUser);
}

// displays the list of users in alphabetical order
void UsersList::displayUsers() {
    // convert the set to a vector
    std::vector<User*> userVector(usersList.begin(), usersList.end());

    // sort the vector in alphabetical order by name
    std::sort(userVector.begin(), userVector.end(), [](User* a, User* b) {
        return a->getName() < b->getName();
    });

    // print the name of each user to stdout
    for (User* user : userVector)
        std::cout << user->getName() << ", ";
}

// returns the size of the usersList set
int UsersList::userCount() {
    return (int) usersList.size();
}