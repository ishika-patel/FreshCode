// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 8 - Problem 2

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
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

class Player {
    private:
        string name;
        double points;
    public:
        Player(); //default constructor
        Player(string name_, double points_); //parametrized constructo
        
        void setName(string name_); // sets name to name_
        string getName(); //returns name
    
        void setPoints(double points_);
        double getPoints(); //returns points
};

#endif