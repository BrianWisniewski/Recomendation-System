#include "BookRecommender.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    bool exit = false;
    string userChoice;
    string name;
    BookRecommender recommender(argv[1]);

    // while exit is false
    while (!exit) {
        // get user input
        cin >> userChoice;

        if (userChoice == "recommend") {
            cin >> name;
            recommender.printRecommend(name);
        }

        else if (userChoice == "averages") {
            recommender.printAverages();
        }

        else if (userChoice == "quit") {
            exit = true;
        }
    }


    return 0;
}