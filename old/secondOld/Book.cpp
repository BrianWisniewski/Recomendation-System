#include "Book.h"

// returns the title of the book
std::string Book::getTitle() {
    return title;
}

// adds a new rating to the book and updates the totalRating and ratingCount
void Book::addRating(double rating) {
    totalRating = ((totalRating*ratingCount) + rating) / (ratingCount + 1);
    ratingCount++;
}

// returns the average rating of the book
double Book::getAverageRating() {
    return totalRating;
}