// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 3

#include <iostream> 
#include <fstream>
#include <string.h>
#include <cctype>
#include "Book.h"
#include "User.h"
using namespace std;

/* Algorithm: make a string of different cases all lowercase
loop through all teh characters and use the tolower() cpp function to convernt to lower
Input Parameters: string
Output/printing: none 
Return: the string in lowercase
*/

string makeLower(string s){
    char c;
    string lowerCase = "";
    
    for (int i=0; i<s.length(); i++) {  //goes through all the characters in the array
        c = s[i]; //accesses the single character the the index
        c = tolower(c); //makes it lowercase
        lowerCase = lowerCase + c; //adds it to the end
    }
    return lowerCase; //returns the lowercase string
}

/* Algorithm: checks for the user and the book title and finds a rating for the book given by the user if applicable
go through all the users to chekc if the user is present
go through all the books to see if the book is present
if both are present then the rating is returned
Input Parameters: string username, string title, User users[], Book books[], int numOfUser, int numOfBook
Output/printing: none
Return: the rating of the book based on the user
*/

int getRating(string username, string title, User users[], Book books[], int numOfUser, int numOfBook){
    int countUser= 0;
    int accessUser=-1;
    for (int i  = 0; i<numOfUser; i++){ //goes through all the users
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //checsk to finda a username match between the two values
            countUser++; 
            accessUser = i; //saves the index teh user is found
        }
    }
    if (countUser==0) { //if no users were found
        return -3; //return -3 and stop
    }
    else {
        int countBook = 0;
        int accessBook=-1;
        for (int i = 0; i< numOfBook; i++){ //goes through the book objects
            if(makeLower(books[i].getTitle()) == makeLower(title)) { //checks to see if the title is valid
                countBook++;
                accessBook = i; //saves the index of the book where it is found
            }
        }
        if (countBook==0) {
            return -3;
        }
        else {
            return users[accessUser].getRatingAt(accessBook); //returns the users rating of teh book
        }
    }
}

int main() {
    //Creating 3 books
    Book books[3];
    //Setting book title and author for book 1
    books[0].setTitle("Title1");
    books[0].setAuthor("Author1");
    //Setting book title and author for book 2
    books[1].setTitle("Title2");
    books[1].setAuthor("Author2");
    //Setting book title and author for book 3
    books[2].setTitle("Title3");
    books[2].setAuthor("Author3");  
    
    //Printing values in each book object
    // cout<<"Books: "<<endl;
    // cout<<books[0].getTitle()<<" by "<<books[0].getAuthor()<<endl;
    // cout<<books[1].getTitle()<<" by "<<books[1].getAuthor()<<endl;
    // cout<<books[2].getTitle()<<" by "<<books[2].getAuthor()<<endl;
    
    //Creating 2 users
    User users[2];
    //Setting username and ratings for User1
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);
    //Setting username and ratings for User2
    users[1].setUsername("User2");
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);
    users[1].setRatingAt(1,5);
    users[1].setRatingAt(2,3);
    
    //TEST1
    // expected output: 4
    cout << getRating("User1", "Title2", users, books, 2, 3)<< endl;
    
    //TEST2
    //expected output: -3
    cout << getRating("User4", "Title1", users, books, 2, 3)<< endl;
}