// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project2 - Problem 0

#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "User.h"
using namespace std;

class Library {
    private:
    // capacity of books array 
        const int sizeBook = 50;
    //capacity of users array
        const int sizeUser = 100;
    //array of book objects   
        Book books[50];
    // array of User objects;
        User users[100];
    //number of books in library database
        int numBooks;
    //numer of users in the library database
        int numUsers;
    
    public:
        Library(); // default constructor
        int getSizeBook(); 
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks(string fileName); //returns total number of books in array
        void printAllBooks(); 
        void printBooksByAuthor(string bookByAuthor); //prints all books by specific author
        int readRatings(string userFile); // returns a total number of users in the users array
        int getRating(string username, string bookTitle); // returns usrs rating for a specific book
        int getCountReadBooks(string username); // returns number of books read by a user
        void viewRatings(string username, int minVal); //prints books with a ratig graer than the minVal
        double calcAvgRating(string bookTitle); //returns average rating of specified book
        double calcAvgRatingByAuthor(string author); //returns average rating of specified author
        int addUser(string username); //checks to see if user exists and if not adds if database isnt full
        int checkOutBook(string username, string title, int newRating); // inputs ratings (if valid)
        void getRecommendations(string username); // prints fist 5 books recs
};

#endif