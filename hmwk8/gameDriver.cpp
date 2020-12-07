// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 8 - Problem 4

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Player.cpp"
#include "Team.h"
#include "Team.cpp"
using namespace std;

/* Algorithm: this function takes 2 team objects and comapres their scores
Input Parameters: two team objects are taken in 
Output/printing: no printed output 
Return: the team that wins, or if there is a draw or forfeitx
*/

string game(Team team1, Team team2) {
    if (team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4) { // if either team has less than 4 plyers there must be a forfeit
        return "forfeit";
    }   
    
    else {
        double team1Points = 0.0;
        double team2Points = 0.0;
        for (int i = 0; i< 4; i++) { //calcute the total points for team 1
            team1Points = team1Points + team1.getPlayerPoints(i);
        }
        for (int j = 0; j< 4; j++) { //calculate the total points for team 2
            team2Points = team2Points + team2.getPlayerPoints(j);
        }
        //return team names
        if (team1Points == team2Points) { //comapre the point vlaues, if they are the same ther eis a draw
            return "draw";
        }
        else if (team1Points>team2Points) {//checks to see if team 1 wins
            return team1.getTeamName();
        }
        else { // if team one did not win then team 2 must win since neother team forfeir or drawed.
             return team2.getTeamName();
        }
    }
}

int main() {
//test1
// expected output: The winner is: Seg Faultline
Team team1("Seg Faultline");
team1.readRoster("roster1.txt");
Team team2("Team Maim");
team2.readRoster("roster2.txt");
string winner = game(team1, team2);
cout << "The winner is: " << winner << endl;

//test2
//expected output: The winner is: draw
Team team4("Thats so Ravenclaw");
team4.readRoster("roster1.txt");
Team team5("Planes on a Snake");
team5.readRoster("roster1.txt");
string winner1 = game(team4, team5);
cout << "The winner is: " << winner1 << endl;

//test3
//expected output: The winner is: forfeit
Team team3("Hurt Shoebox");
team3.readRoster("roster0.txt");
Team team12("Team Maim");
team2.readRoster("roster2.txt");
string winner2 = game(team3, team12);
cout << "The winner is: " << winner2 << endl;
}