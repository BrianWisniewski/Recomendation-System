#ifndef USER_H_
#define USER_H_

#include <string>

// name of a user
class User {
private:
    std::string name;
public:
    User(std::string name) : name(name) {};
    std::string getName() const { return name; }
};
 
#endif