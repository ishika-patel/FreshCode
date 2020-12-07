// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 1

#include <iostream>
#include <string>
#include "User.h"
using namespace std;

int main() {
//test1
// expected output: Ishika, 12
int rating [7] {2,2,2,2,2,4,4};
int size = 50;
User testUser;
testUser.setUsername("Ishika");
testUser.setNumRatings(12);
cout << testUser.getUsername() << endl;
cout<< testUser.getNumRatings() << endl;

//test2
//expected output: Pat, 7, 0
User user2("Pat", rating, 7);
cout<< user2.getUsername()<< endl;
cout<< user2.getNumRatings() << endl;
cout<< user2.getSize() << endl;
cout<< user2.getRatingAt(0) << endl;
}