#ifndef USER_RATINGS_MAP_H_
#define USER_RATINGS_MAP_H_

#include "BookRating.h"
#include "BookRatingsList.h"
#include <string>
#include <map>

// contains a map where user name is the key and book ratings is the value
class UserRatingsMap {
private:
    std::map<std::string, BookRating> userRatingsMap {};
public:
    UserRatingsMap() = default;
    ~UserRatingsMap();
    void addUserRating(BookRating);
    void displayUserRatings();
    int userRatingsCount();
    BookRatingsList getUserRatings(std::string userName);
};

#endif