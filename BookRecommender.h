#ifndef BOOK_RECOMMENDER_H
#define BOOK_RECOMMENDER_H

#include "Book.h"
#include "User.h"
#include <vector>
#include <algorithm>

class BookRecommender {
private:
    std::vector<Book*> books;
    std::vector<User*> users;
    std::vector<std::pair<double, std::string>> 
        similarity(User recommender) const;
    std::string removeWhiteSpace(std::string line);
public:
    BookRecommender();
    BookRecommender(const std::string& filename);
    void addBook(std::string title);
    User* addUser(std::string name);
    bool loadData(const std::string& filename);
    void printRecommend(std::string userName) const;
    void printAverages() const;
};

#endif