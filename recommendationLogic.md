## Recommendation System Logic
Brian Wisniewski (4/5/2023)

### Terminology
- **program-user:** the person running your program who is looking for book recommendations
- **recommendation-user:** these come from the recommendation file and are compared against the requested-user
- **requested-user:** recommendation-user that the program user is asking for their recommendations to be based upon
- **rating averages:** the average recommendation for each book
- **books-list:** list of the names of all the books known to your program, read in from a file, the name of the file comes from the command line
- **average-ratings:** a list of that contains the averages of the ratings from the top three recommendation for a each book
- **ratings-dictionary:** a dictionary containing each recommendation-user and their list of ratings for each book
- **program-user commands:** a list of commands the program must recognize and process; these are: averages, recommend, quit
- **ratings.dat:** a large text file of book ratings used in testing
- **small_ratings.dat:** a small text file of books ratings used in testing

### Process
1. Read user data from a file (given on command line)
2. Turn all books into a vector. Convert to set and back to vector to get unique vector
3. Create dictionary with each person as a key and a vector with the rating of each book as the value
4. Calculate averages
5. Wait for command "recommend", "averages", or "quit" (no prompt)

### Averages
1. Create list of tuples or structs holding rating and book name
2. Iterate list for each book and count nonzero items while keeping total rating
3. Find average book score by dividing total rating by nonzero count
4. Create new list holding book names and averages in tuple or struct
5. Sort by ratings and for ties in ratings use alphabetic order

### Calculating recommendations
1. Read in requested-user name. If not in the dictionary, output averages instead
2. For each user, find the dot product of that user and the requested-user to get a similarity rating
    (look out for the requested user in the list)
3. Store pairs with the similarity rating and the name of the other user in a list
4. Sort the list by similarity rating and take the top 3 recommendation-users
5. Average these three users to make a new list the same list as the list of books
6. This new list can be turned into pairs with the book title and average rating
7. Sort this list of pairs to get a list of books to recommend