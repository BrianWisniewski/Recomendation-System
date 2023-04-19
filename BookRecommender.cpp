#include "BookRecommender.h"

// sorts by rating first and then by alphabetical order
bool compareAverages(avgPair rating1, avgPair rating2) {
    if (rating1.first == rating2.first)
        return rating1.second < rating2.second;
    return rating1.first > rating2.first;
}

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

    // exit with error if problems arise opening the file
    if (!dataFile) {
        cout << "Error opening file!";
        exit(0);
    }
    
    // for each rating, read in the attributes
    for (;getline(dataFile, userName);) {
        getline(dataFile, bookTitle);
        getline(dataFile, rating);

        // remove carriage return from imput if it exists
        userName.erase(remove(userName.begin(), userName.end(), '\r'), userName.end());
        bookTitle.erase(remove(bookTitle.begin(), bookTitle.end(), '\r'), bookTitle.end());

        // add userName and bookTitle to the set
        bookSet.insert(bookTitle);
        userSet.insert(userName);
    }

    // convert the sets into vectors
    books.assign(bookSet.begin(), bookSet.end());
    users.assign(userSet.begin(), userSet.end());

    // create the ratedBooks map and set vector size for each user
    vector<double> zeroVector(getBookCount(), 0);
    for (string user : users)
        ratedBooks.emplace(user, zeroVector);

    // return back to the beginning of the file to get ratings
    dataFile.close();
    dataFile.open(filename);

    // reiterate through the file and assign all ratings
    for (;getline(dataFile, userName);) {
        getline(dataFile, bookTitle);
        getline(dataFile, rating);

        // remove carriage return from imput if it exists
        userName.erase(remove(userName.begin(), userName.end(), '\r'), userName.end());
        bookTitle.erase(remove(bookTitle.begin(), bookTitle.end(), '\r'), bookTitle.end());

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

    // calculate average for each book and add it to the averages map
    for (string book : books) {
        double totalRating = 0; // holds the sum of ratings
        int numRatings = 0; // counts number of non-zero ratings
        for (string user : users) {
            int userRating = getUserBookRating(user, book);
            if (userRating != 0) {
                totalRating += userRating;
                numRatings += 1;
            }
        }
        double average = 0;
        if (numRatings != 0)
            average = totalRating / numRatings;
        averages.emplace(book, average);
    }
}

// displays the book recommendations for a given user per the 
// specifications given
void BookRecommender::printRecommend(string requestedUser) {
    vector<avgPair> similarityRatings;
    avgPair similarityPair;

    // return if name of requested user isn't in the vector
    if (find(users.begin(), users.end(), requestedUser) == users.end()) {
        printAverages();
        return;
    }

    // populate vector of similarity ratings
    for (string reccUser : users) {
        similarityPair = {getSimilarity(reccUser, requestedUser), reccUser};
        similarityRatings.push_back(similarityPair);
    }

    // sort the vector based on the similarity value
    sort(similarityRatings.begin(), similarityRatings.end());

    // remove the requested user from the vector (most similar)
    similarityRatings.pop_back();
    
    // creates a vector of pairs with each pair containing the average rating
    // from the top 3 users and the name of the book
    vector<pair<double, string>> averagePairs;
    for (string book : books) {
        int ratingCount = 0;
        double totalRating = 0;
        double averageRating = 0;
        for (int i=0; i<3; i++) {
            double userRating = getUserBookRating(similarityRatings[i].second, book);
            if (userRating != 0) 
                ratingCount++;
            totalRating += userRating;
        }
        if (ratingCount != 0)
            averageRating = totalRating / ratingCount;
        
        averagePairs.push_back( {averageRating, book} );
    }

    // sort the averagePairs by averageRating
    sort(averagePairs.begin(), averagePairs.end(), compareAverages);

    // output each book and it's average recommender rating
    for (avgPair book : averagePairs) {
        if (book.first > 0) {
            cout << book.second << " "; 
            cout << fixed << setprecision(2) << book.first << endl; 
        }
    }

}

// displays the book average ratings per the specifications
void BookRecommender::printAverages() {
    vector<avgPair> averageVector;
    avgPair bookRating;

    // convert the map to a vector of book pairs
    for (string book : books) {
        bookRating = {averages[book], book};
        averageVector.push_back(bookRating);
    }

    // sort the vector by rating and then by 
    sort(averageVector.begin(), averageVector.end(), compareAverages);

    // print the averages in proper formating
    for (avgPair bookRating : averageVector) {
        double rating = bookRating.first;
        string title = bookRating.second;
        cout << fixed << title << " " << setprecision(2) << rating << endl;
    }
}

// returns the average rating for a specified book
double BookRecommender::getAverage(string bookTitle) {
    return averages[bookTitle];
}

// returns the similarity value for recommender userName1 compared to userName2
double BookRecommender::getSimilarity(string userName1, string userName2) {
    vector<double> user1 = ratedBooks[userName1];
    vector<double> user2 = ratedBooks[userName2];
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

// gets the users rating of the bookTitle
double BookRecommender::getUserBookRating(string userName, string bookTitle) {
    vector<double> usersRatings = ratedBooks.at(userName);

    // find the index of the book in the vector
    auto iterator = find(books.begin(), books.end(), bookTitle);
    int index = distance(books.begin(), iterator);

    return (ratedBooks.at(userName))[index];
}