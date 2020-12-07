// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 4

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

/* Algorithm: function that counts how many books a given user has rated.
finds the user first then goes to see how mny books he/she has rated. count for a ratign when the rating is not zero
Input Parameters: string username, User users[], int numOfUser, int numOfBook
Output/printing: none
*/

int getCountReadBooks(string username, User users[], int numOfUser, int numOfBook) {
    int countUser= 0;
    int accessUser=-1;
    for (int i  = 0; i<numOfUser; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            countUser++; // if the user is present then the user count is incremented
            accessUser = i; //when the user is found the index they are found at are stored
        }
    }
    if (countUser==0 || numOfBook == 0 ) { //if no users were found
        return -3; //return -3 and stop
    }
    else {
        int countBook = 0;
        for (int i = 0; i< numOfBook; i++){ // goes thrugh all book objects to see if teh title is present
            if(users[accessUser].getRatingAt(i)!= 0) { //checks to see if the lowercase verison of the book object equsls th lowercase of the book seached for
                countBook++; //if book is found the count of books is incremented
            }
            else{ 
            countBook = countBook;
            }
        }
            return countBook; // if user and book were found, return the rating!
        }
}

int main() {
    //Test1
    //Expected output: -3
    User users[10];
    int numUsers = 0;
    int usersArrSize = 10;
    cout <<getCountReadBooks("User4",users,numUsers,3)<< endl;
    
    //test2
    // expected output: -3
    cout <<getCountReadBooks("User1",users,numUsers,3)<< endl;
    
}