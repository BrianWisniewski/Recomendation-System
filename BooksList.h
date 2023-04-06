#ifndef BOOKSLIST_H_
#define BOOKSLIST_H_

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Book.h"

// contains a list of pointers to all book objects
class BooksList {
private:
    // create an empty list
    std::set <Book*> booksList = {};
public:
    BooksList() = default;
    ~BooksList();
    void addBook(Book* newBook);
    void displayBooks();
    int bookCount();
};

#endif