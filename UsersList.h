#ifndef USERSLIST_H_
#define USERSLIST_H_

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include "User.h"

// contains a list of pointers to all user objects
class UsersList {
private:
    // create an empty list
    std::set <User*> usersList = {};
public:
    UsersList() = default;
    ~UsersList();
    void addUser(User* newUser);
    void displayUsers();
    int userCount();
};

#endif