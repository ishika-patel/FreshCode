// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 5

#include <iostream> 
#include <fstream>
#include <string.h>
#include <cctype>
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

/* Algorithm: this function returns the average (mean) rating for a particular book. it funds the book first
then loops throuhg the suer ratings at thast book index and adds those
- do not add teh user to the average if he/she did not read/ rate the novel
Input Parameters: User users[], Book books[], int numOfUser, int numOfBook, string title
Output/printing: none
Return: average ratings (sum./number of users)
*/

double calcAverageRating(User users[], Book books[], int numOfUser, int numOfBook, string title) {
    double countBook= 0;
    double accessBook=-1;
    double sum = 0;
    double countUser = 0;
    
    for (int i  = 0; i<numOfBook; i++){
        if(makeLower(books[i].getTitle()) == makeLower(title)) { //goes through all book objects to see if the book is present, lowercase font
            countBook++; // if the book is present then the book count is incremented
            accessBook = i; //when the book is found the index it is found at is stored
        }
    }
    if (countBook==0 || numOfUser == 0) { // if the book is not found or if there are no users them return -3
        return -3; //return -3 and stop
    }
    else {
        for (int i = 0; i< numOfUser; i++){ // goes thrugh all user objects to add all the rating of the book together
            if (users[i].getRatingAt(accessBook) !=0){ //only add values that are NOT zero
                sum = sum + users[i].getRatingAt(accessBook);
                countUser++; // if the rating is zero the user shouldn’t be counted in calculating the average so we keep this in the if statement
            }
        }
         if (countUser==0) { // if no users have read the book, return 0
            return 0;
        }
    }
        return sum / countUser; // return the average rating
}

int main() {
//test1
//expected output: 3.0
Book books[2]; 
books[0].setTitle("Title1");
books[0].setAuthor("Author1"); 
books[1].setTitle("Title2");
books[1].setAuthor("Author2");

User users[2];
users[0].setUsername("User1"); 
users[0].setNumRatings(2); 
users[0].setRatingAt(0,2); 
users[0].setRatingAt(1,2);
users[1].setUsername("User2"); 
users[1].setNumRatings(4); 
users[1].setRatingAt(0,4); 
users[1].setRatingAt(1,4);

cout << calcAverageRating(users, books, 2, 2, "title2")<< endl;

//test2
//expected output: 3.0 
cout << calcAverageRating(users, books, 2, 2, "title1")<< endl;
}