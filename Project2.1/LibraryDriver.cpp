#include <iostream>
#include <string>
#include "Library.h"
#include "Library.cpp"
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"
using namespace std;

int main(){

/* READ BOOKS TEST
  // make library object
Library myLibrary;
// call readBooks
int rv = myLibrary.readBooks("readBooksfileName.txt");
// print values
cout << "rv = " << rv << endl;
cout << "numBooks = ";
cout << myLibrary.getNumBooks() << endl;
//print books
myLibrary.printAllBooks();

// make library object
 Library myLibrary;
 // call readBooks and check return values
int rv1 = myLibrary.readBooks("readBooksbook1.txt");
cout << "rv1 = " << rv1 << endl;
int rv2 = myLibrary.readBooks("readBooksbook2.txt");
cout << "rv2 = " << rv2 << endl;
// check value of getNumBooks
cout << "numBooks = ";
cout << myLibrary.getNumBooks() << endl;
// print books
myLibrary.printAllBooks();

*/ 

/* PRINT BOOKS BY AUTHOR
// make library obj
Library lib;
// read book file
lib.readBooks("byAuthorbookFile.txt");
lib.printAllBooks();
// call printBooksByAuthor
string author = "AuthorA";
lib.printBooksByAuthor(author);
*/

/* READ RATINGS
// make library obj
Library lib;
// read book file
lib.readBooks("readRatingsbookFile.txt");
// call readRatings and check return values
int rv1 = lib.readRatings("readRatingratingFile.txt");
cout << "rv1 = ";
cout << rv1 << endl;
// check value of getNumUsers
cout << "numUsers = ";
cout << 
cout << lib.getNumUsers() << endl;
// print user’s ratings
string name = "Myth";
cout << lib.getRating(name, "book1") << endl;
cout << lib.getRating(name, "book2") << endl;
cout << lib.getRating(name, "book3") << endl;
cout << lib.getRating(name, "book4") << endl;
cout << lib.getRating(name, "book5") << endl;
*/

/* GET RATING
//Create a new Library
Library myLibrary;
//add books to Library
myLibrary.readBooks("getRatingbookFile.txt");
//add users to Library
myLibrary.readRatings("getRatingratingFile.txt");
cout << myLibrary.getRating("User1", "Title2") << endl;
cout << myLibrary.getRating("User4", "Title1") << endl;
cout << myLibrary.getRating("User1", "Title10") << endl;
cout << myLibrary.getRating("User12", "Title10") << endl;
*/

/* GET COUNT READ BOOKS
//Create a new Library
Library myLibrary;
//add books to Library
myLibrary.readBooks("getCountBooksbookFile.txt");
//add users
myLibrary.readRatings("getCountBooksratingFile.txt");
// viewRatings for User2
cout << myLibrary.getCountReadBooks("User2");
*/

/* VIEW RATINGS
//Create a new Library
Library myLibrary;
//add books to Library
myLibrary.readBooks("viewRatingsbookFile.txt");
//add users
myLibrary.readRatings("viewRatingsratingFile.txt");
myLibrary.viewRatings("User1", 2);
*/

/* CALC AVERAGE RATING
//Create a new Library
Library myLibrary;
//add books to Library
myLibrary.readBooks("averagebookFile.txt");
//add users
myLibrary.readRatings("averageratingFile.txt");
// calcAvgRating for Title2
cout << myLibrary.calcAvgRating("title2");
*/

/* CALC AVERAGE RATINGS BY AUTHOR
//Create a new Library
Library myLibrary;
//add books to Library
 myLibrary.readBooks("averageAuthorbookFile.txt");
 //add users
 myLibrary.readRatings("averageAuthorratingFile.txt");
 // calcAvgRatingByAuthor for Author1
cout << myLibrary.calcAvgRatingByAuthor("Author1");
*/

/* ADD USER
//Create a new Library
Library myLibrary;
myLibrary.readRatings("addUserratingFile.txt");
// checking the user count
cout << "numUsers = " << myLibrary.getNumUsers()
<< endl;
//add users
cout << myLibrary.addUser("User2") << endl;
// checking the user count
cout << "numUsers = " << myLibrary.getNumUsers()<< endl;
*/

/* CHECK OUT BOOK
//Create a new Library
Library myLib;
myLib.readBooks("checkOutbookFile.txt");
myLib.readRatings("checkOutratingFile.txt");

// int oldRating = myLib.getRating("User2", "Title1");
// int rv = myLib.checkOutBook("User2", "Title1", 2);
// int newRating = myLib.getRating("User2", "Title1");
// cout << "rv = " << rv << endl;
// cout << "oldRating = " << oldRating << endl;
// cout << "newRating = " << newRating << endl;


int oldRating = myLib.getRating("User2", "Title1");
int rv = myLib.checkOutBook("User2", "Title1", 10);
int newRating = myLib.getRating("User2", "Title1");
cout << "rv = " << rv << endl;
cout << "oldRating = " << oldRating << endl;
cout << "newRating = " << newRating << endl;
*/

//Create a new Library
Library myLib;
myLib.readBooks("getRecbookFile.txt");
myLib.readRatings("getRecratingFile.txt");

myLib.getRecommendations("User4");


}

