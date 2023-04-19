#ifndef BOOK_RECOMMENDER_H
#define BOOK_RECOMMENDER_H

#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class BookRecommender {
private:
    vector<string> books; // bookTitle
    vector<string> users; // userName
    map<string, vector<double>> ratedBooks; // userName, ratings
    map<string, double> averages; // bookTitle, average 

public:
    BookRecommender() {};
    BookRecommender(string filename);
    void printRecommend(string userName);
    void printAverages();
    double getAverage(string bookTitle);
    double getSimilarity(string userName1, string userName2);
    int getBookCount();
    int getUserCount();
    double getUserBookRating(string userName, string bookTitle);
};

#endif