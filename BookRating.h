#ifndef BOOKRATING_H_
#define BOOKRATING_H_

#include "Book.h"
#include "User.h"
#include <tuple>
#include <string>

class BookRating {
private:
    Book* book;
    User* user;
    int userRating;
public:
    BookRating(Book* book, User* user, int userRating): 
        book(book), user(user), userRating(userRating) {};
    std::tuple<std::string, std::string, int> getBookRating() 
        {return std::make_tuple(book->getName(), user->getName(), userRating);}
};

#endif