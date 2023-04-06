#include "BookRatingsList.h"

// adds a new BookRating object to the list
void BookRatingsList::addRating(BookRating newRating) {
    bookRatingsList.push_back(newRating);
}

// displays a list of BookRatings in the format: [book name, user name, rating]
void BookRatingsList::displayBookRatings() {
    // interate through each rating
    for (BookRating rating : bookRatingsList) {
        // get each element from the tuple
        std::string bookTitle = std::get<0>(rating.getBookRating());
        std::string userName = std::get<1>(rating.getBookRating());
        int userRating = std::get<2>(rating.getBookRating());
        // print the formatted information to the console
        std::cout << "[" << bookTitle << ", " << userName << ", " << userRating
            << "]" << std::endl;
    }
}

// returns the number of ratings in the list
int BookRatingsList::bookRatingCount() {
    return (int) bookRatingsList.size();
}