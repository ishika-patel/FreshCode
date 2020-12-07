// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 1

#include <iostream>
#include <string>
#include "User.h"
using namespace std;

/* Algorithm: define a constructor variable. define a parametrized constructor. Define other functions in User (setter and getter methods)
data regarding number of books and the respective ratings of these books
Input Parameters: User(string username_, int ratings_[], int numRatings_);
Output/printing: none
Return: a value or string based on what memebr function is called on
*/

//         string username;
//         int numRatings;
//         const int size = 50; //capacity of array is 50, a constant
//         int ratings[size]; //number of elements should be size

    

User:: User() { //default constructor
    username = ""; // username to an empty string
    numRatings = 0; // numRatings back to zero
    for(int i =0; i< size; i++){ //sets all emeents of ratings[] to 0
        ratings[i] = 0;
    }
}

User:: User(string username_, int ratings_[], int numRatings_){ //parametrized constructor
   if(numRatings_<=50) { // makes sure numRatings isnt greater than size
       
        username = username_; //sets username
        numRatings = numRatings_;//sets numratings to variable
        
        for(int i; i<size; i++) { //goes through the array to set the temp array to teh official array
            ratings[i] = ratings_[i];
        }
        
        if(numRatings_ != 50) { //fills in the other boxes after numRatings
            for(int i = numRatings_; i<size; i++){
                ratings[i] = 0;
            }
        }
   }
    else { //if numRatings is > size
        for(int i =0; i< size; i++){ //sets all emeents of ratings[] to 0
            ratings[i] = 0;
        }
    }
}
        
void User:: setUsername(string username_){ // sets username to username_
    username = username_;
}

string User:: getUsername(){ //returns username
    return username;
}

int User:: getRatingAt(int index){ // if index is larger than size or less than 0 return -2 otherwise return rating
    if(index>=size || index<0){
        return -1;
    }
    else {
        return ratings[index];
    }
}

bool User:: setRatingAt(int index, int value){ // sets rating to int value at an int index, if index is withing boulds of array and value is 0-5
    if((index>=0&& index<size) && (value>=0 && value<=5)) { //checks index and rating value
            ratings[index] = value;
            return true;
    }
    else { 
        return false;
    }
}

void User:: setNumRatings(int numRatings_){
    numRatings = numRatings_;
}

int User:: getNumRatings(){
    return numRatings;
}
        
int User:: getSize(){ //size is a constant
    return size;
}