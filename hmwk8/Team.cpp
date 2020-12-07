// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 8 - Problem 3

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Team.h"
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

int split(string line, char delimiter, string array[], int arraySize){
    
    int count =0; // this allows us to return the counter
    int start =0; // this will track where in the string we are as we are looking for the delimiter
    
    if (line == "") { //checks to see if the parameter for string is empty
        return 0; //if it is, returns 0 and exits code
    }
    if (line[line.length()-1] == delimiter) { //checks to see if the last value in the string is the delimiter
        line = line.substr(0, line.length()-1); // if it is, the delimiter at the end is cut off and the process is continued
    }
    
    for (int i = 0; i<line.length(); i++) {
        if (line[i] == delimiter) { // we are now searching for the delimiter
            
            if (count == arraySize) { // this is a fail safe to make sure that the count is not greater than the value that the array can hold
                return -1; //If the string is split into more pieces than the array of string can hold return -1
            }
            else {
                string arrayInput = line.substr(start, i-start); // int i is where the delimiter was found, thefore we want to print the strin from the beinning to int i
                if (i-start !=0 && start+1 !=0) { // the first condition checks to make sure two delimiters are together, the second condition checks the starting position
                    array[count] = arrayInput;  // store the value that is extrapolated from arrayInput
                    count ++; // add one to the count to return the number of words at the end, note that count doesnt include the very final word
                }
                }
            start = i + 1; // becuase you are moving past the whole word so you have to move up to i where the delimiator was and 1 past i so you pass the delimiter
            }
         }
         
         string arrayInput = line.substr(start, line.length() - start); 
             if (arrayInput != "") {// keeps the process going until the string itself ends
                 array[count] = arrayInput;
             }
         return ++count; //preincrement in order to account for index vs length discrepecy
}

Team:: Team(){ //default constructor
    teamName = "";
    players;
}

Team:: Team(string teamName_){ //parametrized constructor
    teamName = teamName_;
}
        
void Team:: setTeamName(string teamName_){ // sets teamName to teamName_
    teamName = teamName_;
}

string Team:: getTeamName(){ //returns teamName
    return teamName;
}
    
void Team:: readRoster(string fileName){ // reads input and apprens players to the team vector
    
    string line; // declared to hold the getline values
    string tempArray[2] = {"", ""}; // this is the array that the split function stores in
    ifstream file; //says there is a file we will access and we are taking data from it
    
    file.open(fileName); //opens the file
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
           if (line != "") { //checks to make sure array is not full nor is the line empty
             split(line, ',', tempArray, 2);

             Player newPlayer(tempArray[0], stod(tempArray[1])); //make a new player using the parametrized constructor
             players.push_back(newPlayer); // this will input in the correct vecotr loction the name and score
             
           }
        }       
    }
}

string Team:: getPlayerName(int indexPlayer){ //returns the name of the player at position i 
    if(indexPlayer >= players.size()){
        return "ERROR";
    }   
    else {
    string playerName = players[indexPlayer].getName();
    return playerName;
    }
}

double Team:: getPlayerPoints(int indexPlayer){ //returns the points of the layer at position i
    if (indexPlayer >= players.size()){
        return -1;
    }
    else {
    double playerPoints = players[indexPlayer].getPoints();
    return playerPoints;
    }
}
int Team:: getNumPlayers(){ // returns the number of players on this team
    return players.size();
}