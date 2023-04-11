#ifndef BOOK_H_
#define BOOK_H_

#include <string>

// name of the book and average rating for the book (double)
class Book
{
private:
    std::string title;
    double totalRating;
    double ratingCount;
public:
    Book(std::string title): title(title) {};
    std::string getTitle();
    void addRating(double rating);
    double getAverageRating();
};

#endif