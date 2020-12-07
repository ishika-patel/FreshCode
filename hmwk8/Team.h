// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 8 - Problem 3

#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

/* Algorithm: implementing the team class
    1. Team(); //default constructor
        no imputs nor return values
    2. Team(string teamName_); //parametrized constructor
        team name input because player array is already initialzied and empty
    3. void setTeamName(string teamName_); // sets teamName to teamName_
        user input of team name no return
    4. string getTeamName(); //returns teamName
        returns team name
    5. void readRoster(string fileName); // reads input and apprens players to the team vector
        reads a file and inputs data of player and points into vector
    6. string getPlayerName(int indexPlayer); //returns the name of the player at position i 
        returns player name
    7. double getPlayerPoints(int indexPlayer); //returns the points of the layer at position i
        return player points
    8. int getNumPlayers(); // returns the number of players on this team
        returns player size
    Output: based on function (stated above)
    Return: based on function (stated above)
*/

class Team {
    private:
        string teamName;
        vector<Player> players;
    public:
        Team(); //default constructor
        Team(string teamName_); //parametrized constructor
        
        void setTeamName(string teamName_); // sets teamName to teamName_
        string getTeamName(); //returns teamName
    
        void readRoster(string fileName); // reads input and apprens players to the team vector
        
        string getPlayerName(int indexPlayer); //returns the name of the player at position i 
        
        double getPlayerPoints(int indexPlayer); //returns the points of the layer at position i
        
        int getNumPlayers(); // returns the number of players on this team

};

#endif