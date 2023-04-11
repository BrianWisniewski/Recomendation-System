#include "User.h"

// TODO: need clarification on this
User::User(std::string name, std::vector<Book*>& books) {

}

// returns the name of the user
std::string User::getName() {
    return name;
}

// adds a new book to the user's ratedBooks map
void User::addRatedBook(Book& book, double rating) {
    ratedBooks.emplace(&book, rating);
}

// returns the user's rating of a given book in the map
double User::getRating(const Book& book) {
    // make sure book is in the map, if it is not, return 0
    if (ratedBooks.find(&book) != ratedBooks.end())
        return ratedBooks[&book];
    else
        return 0;
}