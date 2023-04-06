#include "BooksList.h"

BooksList::~BooksList() {
    for (Book* book : booksList)
        delete book;
}

// adds a book to the booksList set
void BooksList::addBook(Book* newBook) {
    booksList.insert(newBook);
}

void BooksList::displayBooks() {
    // convert the set to a vector
    std::vector<Book*> bookVector(booksList.begin(), booksList.end());

    // sort the vector in alphabetical order by name
    std::sort(booksList.begin(), booksList.end(), [](const Book* a, const Book* b) {
        return a->getName() < b->getName();
    });

    // print the name of each book to stdout
    for (Book* book : bookVector)
        std::cout << book->getName() << ", ";
}

// returns the size of the booksList set
int BooksList::bookCount() {
    return (int) booksList.size();
}