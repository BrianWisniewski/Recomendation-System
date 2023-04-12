#ifndef BOOKRATINGSLIST_H_
#define BOOKRATINGSLIST_H_

#include "BookRating.h"
#include <vector>
#include <iostream>

// contains a list of all BookRating objects
class BookRatingsList {
private:
    std::vector<BookRating> bookRatingsList {};
public:
    BookRatingsList() = default;
    ~BookRatingsList();
    void addRating(BookRating newRating);
    void displayBookRatings();
    int bookRatingCount();
};

#endif