#include "BookRecommender.h"


// creates an object and processes the data in the specified file
// initializes all data members as necessary given the data
BookRecommender::BookRecommender(string filename) {
    set<string> bookSet,
                userSet;
    string userName,
           bookTitle,
           rating;

    // open the input file
    ifstream dataFile;
    dataFile.open(filename);
    
    // for each rating, read in the attributes
    for (;getline(dataFile, userName);) {
        getline(dataFile, bookTitle);
        getline(dataFile, rating);
        
        // add userName and bookTitle to the set
        bookSet.insert(bookTitle);
        userSet.insert(userName);
    }

    // convert the sets into vectors
    books.assign(bookSet.begin(), bookSet.end());
    users.assign(userSet.begin(), userSet.end());

    // create the ratedBooks map and set vector size for each user
    vector<double> zeroVector(getBookCount(), 0);
    for (string user : users) {
        ratedBooks.emplace(user, zeroVector);
    }

    // return back to the beginning of the file to get ratings
    dataFile.close();
    dataFile.open(filename);

    // reiterate through the file and assign all ratings
    for (;getline(dataFile, userName);) {
        getline(dataFile, bookTitle);
        getline(dataFile, rating);
        
        // store ratings for user in temporary vector
        // then update vector to add new rating
        vector<double> updatedRating = ratedBooks[userName];

        // find index of book in the rating vector
        auto iterator = find(books.begin(), books.end(), bookTitle);
        int index = distance(books.begin(), iterator);

        // modify the rating vector to include the new rating and re-assign
        // the vector to the username in the map
        updatedRating[index] = stod(rating);
        ratedBooks[userName] = updatedRating;
    }

    // calculate averages for each book
    for (string book : books) {
            int totalRating = 0;
            for (string user : users) {
                totalRating += getUserBookRating(user, book);
            }
            double average = totalRating / getUserCount();
            averages.emplace(book, average);
        }
}

// displays the book recommendations for a given user per the 
// specifications given
void BookRecommender::printRecommend(string userName) {

}

// displays the book average ratings per the specifications
void BookRecommender::printAverages() {
    for (auto pair : averages) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// returns the average rating for a specified book
double BookRecommender::getAverage(string bookTitle) {
    // find the average in the map
    return averages.at(bookTitle);
}

// returns the similarity value for recommender userName1 compared to userName2
double BookRecommender::getSimilarity(string userName1, string userName2) {
    vector<double> user1 = ratedBooks.at(userName1);
    vector<double> user2 = ratedBooks.at(userName2);
    double rating = 0;

    for (int i=0; i<getBookCount(); i++) {
        rating += user1[i] * user2[i];
    }

    return rating;
}

// returns the number of books in the vector
int BookRecommender::getBookCount() {
    return (int) books.size();
}

// returns the number of users in the vector
int BookRecommender::getUserCount() {
    return (int) users.size();
}

// FIXME: needs some work
// gets the users rating of the bookTitle
double BookRecommender::getUserBookRating(string userName, string bookTitle) {
    vector<double> usersRatings = ratedBooks.at(userName);
    auto iterator = find(books.begin(), books.end(), bookTitle);
    int index = distance(books.begin(), iterator);

    return (ratedBooks.at(userName))[index];
}