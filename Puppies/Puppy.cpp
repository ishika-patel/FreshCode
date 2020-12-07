// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project Puppies

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <cctype>
#include "Puppy.h"
using namespace std;

/* Algorithm: The Puppy Class is where the user puppy information will lie. In the intro (before the while loop)
user will be prompted to pick a puppy. Then based on the user input, the program will fill in the user's puppy's info.
This will also be the class that an array of friend puppy objects will be created.
There are 50 puppy friends that make an appearnace in the Battle class
*/

// default constructor
Puppy:: Puppy(){
    puppyName = "";

    puppyBreed = "";

    puppyAge = "";

    puppyGender = "";

    puppyToy = "";

    puppyColor = "";

    cPoints = 0;
}

//parametrized constructor, this is the order the input file will be read in        
Puppy:: Puppy(string name, string breed, string age, string gender, string toy, string color, int points){
    puppyName = name;
    puppyBreed = breed;
    puppyAge = age;
    puppyGender = gender;
    puppyToy = toy;
    puppyColor = color;
    cPoints = points;
}

/* the following are the getters and setters for the puppy class, this will be useful as objects to compare the user's puppy and the puppy friends
introduced with the other classes*/

void Puppy:: setPuppyName(string name){
    puppyName = name;
}
string Puppy:: getPuppyName(){
    return puppyName;
}
void Puppy:: setPuppyBreed(string breed){
    puppyBreed = breed;
}
string Puppy:: getPuppyBreed(){
    return puppyBreed;
}
void Puppy:: setPuppyAge(string age){
    puppyAge = age;
}
string Puppy:: getPuppyAge(){
    return puppyAge;
}
void Puppy:: setPuppyGender(string gender){
    puppyGender = gender;
}
string Puppy:: getPuppyGender(){
    return puppyGender;
}
void Puppy:: setPuppyToy(string toy){
    puppyToy = toy;
}
string Puppy:: getPuppyToy(){
    return puppyToy;
}
void Puppy:: setPuppyColor(string color){
    puppyColor = color;
}
string Puppy:: getPuppyColor(){
    return puppyColor;
}
// cPoints or cuddle points are integer values so that the user's cuddle points can be easily maniputlated
void Puppy:: setPuppyCPoints(int points){
    cPoints = points;
}
int Puppy:: getPuppyCPoints(){
    return cPoints;
}