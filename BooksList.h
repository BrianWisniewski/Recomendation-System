#ifndef BOOKSLIST_H_
#define BOOKSLIST_H_

#include <set>
#include <vector>
#include <iostream>
#include "Book.h"

class BooksList {
private:
    std::set <Book*> booksList = {};

public:
    BooksList() = default;
    ~BooksList();
    void addBook(Book* newBook);
    void displayBooks();
    int bookCount();

};

#endif