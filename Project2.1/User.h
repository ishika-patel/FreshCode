// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 1

#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
    private:
        string username;
        int numRatings;
        const static int size = 50; //capacity of array is 50, a constant
        int ratings[50]; //number of elements should be size
    public:
        User(); //default constructor
        User(string username_, int ratings_[], int numRatings_); //parametrized constructo
        
        void setUsername(string username_); // sets username to username_
        string getUsername(); //returns username
        
        int getRatingAt(int index); // if index is larger than size or less than 0 return -2 otherwise return rating
        
        bool setRatingAt(int index, int value); // sets rating to int value at an int index, if index is withing boulds of array and value is 0-5
    
        void setNumRatings(int numRatings_);
        int getNumRatings();
        
        int getSize();
};

#endif