// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 8 - Problem 2

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

/* Algorithm: implementing the player class
    1. Player(); //default constructor
        no input parameters, nor return
    2. Player(string name_, double points_); //parametrized constructor
        name and point inputs, no return
    3. void setName(string name_); // sets name to name_
        name input
    4. string getName(); //returns name
        returns name
    5. void setPoints(double points_);
        points input
    6. double getPoints(); //returns points
        returns points
    Output: based on function (stated above)
    Return: based on function (stated above)
*/

Player:: Player() { //default constructor
    name = "";
    points = 0.0;
}

Player:: Player(string name_, double points_){ //parametrized constructo
    name = name_;
    points = points_;
}
        
void Player:: setName(string name_){ // sets name to name_
    name = name_;
}

string Player:: getName(){ //returns name
    return name;   
}

void Player:: setPoints(double points_){
    points = points_;
}

double Player:: getPoints(){ //returns points
    return points;
}