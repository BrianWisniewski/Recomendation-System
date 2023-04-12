#include "BookRecommender.h"

//
std::vector<std::pair<double, std::string>> BookRecommender::similarity(User recommender) const {

}

// removes all the spaces from a string, leaving one long word
std::string BookRecommender::removeWhiteSpace(std::string line) {
    std::remove(line.begin(), line.end(), ' ');
    return line;
}

//
BookRecommender::BookRecommender() {

}

//
BookRecommender::BookRecommender(const std::string& filename) {

}

//
void BookRecommender::addBook(std::string title) {

}

//
User* BookRecommender::addUser(std::string name) {

}

//
bool BookRecommender::loadData(const std::string& filename) {

}

//
void BookRecommender::printRecommend(std::string userName) const {

}

//
void BookRecommender::printAverages() const {

}