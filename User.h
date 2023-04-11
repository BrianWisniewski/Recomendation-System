#ifndef USER_H_
#define USER_H_

#include <string>
#include <map>
#include "Book.h"

// name of a user
class User {
private:
    std::string name;
    std::map<const Book*, double> ratedBooks;
public:
    User(std::string name) : name(name) {};
    User(std::string name, std::vector<Book*> &books);
    std::string getName();
    void addRatedBook(Book& book, double rating);
    double getRating(const Book& book);
};
 
#endif