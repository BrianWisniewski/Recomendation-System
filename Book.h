#ifndef BOOK_H_
#define BOOK_H_

#include <string>

// name of the book and average rating for the book (double)
class Book
{
private:
    std::string name;
    double avgRating;
    
public:
    Book(std::string name): name(name), avgRating(0) {};
    std::string getName()  const { return name; }
    double getAverage() const { return avgRating; }
    void setAverage(double avg) { avgRating = avg; }
};

#endif