#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Player.cpp"
#include "Team.h"
#include "Team.cpp"
using namespace std;

int main() {
// checking default constructor
//expected output: empty, 0
Team team1;
cout << team1.getTeamName() << endl;
cout << team1.getNumPlayers() << endl;

// checking teamName setter
//expected output: Llamas Pajamas, 0
Team team2;
team2.setTeamName("Llamas Pajamas");
cout << team2.getTeamName() << endl;
cout << team2.getNumPlayers() << endl;

// checking parameterized constructor
//expected output: Seg Faultline, 0
Team team3("Seg Faultline");
cout << team3.getTeamName() << endl;
cout << team3.getNumPlayers() << endl;

// checking readRoster gets the right number of players (getNumPlayers)
// expeted output: Seg Faultline, 5
Team team4("Seg Faultline");
cout << team4.getTeamName() << endl;
team4.readRoster("roster1.txt");
int n4 = team4.getNumPlayers();
cout << n4 << endl;

// checking readRoster, multiple files
/* Expected output:
Awkward Turtles
O'Flaherty 5.5
Ioana Fleming 6.1
Behera 8
Ku 4.9
Sankaralingam 1.7
*/
Team team5("Awkward Turtles");
cout << team5.getTeamName() << endl;
team5.readRoster("roster3.txt");
team5.readRoster("roster1.txt");
int n5 = team5.getNumPlayers();
for (int i = 0; i < n5; i++) {
    cout << team5.getPlayerName(i) << " ";
    cout << team5.getPlayerPoints(i) << endl;
}

// checking getter player name functions
// Expected output: ERROR
Team team6("Llamas Pajamas");
cout << team6.getTeamName() << endl;
team6.readRoster("roster2.txt");
cout << team6.getPlayerName(-1) << endl;

// checking getter player name functions
//expected output: Reddy, -1, 8, -1
Team team7("Reddy");
cout << team7.getTeamName() << endl;
team7.readRoster("roster2.txt");
cout << team7.getPlayerPoints(-1) << endl;
cout << team7.getPlayerPoints(4) << endl;
cout << team7.getPlayerPoints(5) << endl;
}