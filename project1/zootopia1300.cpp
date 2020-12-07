// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 3

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: this program assists with Zootopia's hiring 
1. provide a menu  to choose the anthropomorphic animal
2. Once an animal is selected, the program should ask two of the characteristics based on the animal. The rules for which are:
    a. Fox: agility and strength
    b. Bunny: agility and speed
    c. Sloth: strength and speed
3. compute a hireSocre based on the inputs using the weighted sum formula, display this on the screen
note: weighted sum formula = 1.8 * agility + 2.16 * strength + 3.24 * speed
4. run in a loop with all options until user quits
Input Parameters: choose an animal based on menu (int), agility (double), strength (double), speed (double)
Output/printing: hireScore (double)
Returns: nothing
*/

void printMenu() { // prints the menu that users see
    int userInput = 0;
	cout<<"Select a numerical option:"<<endl;
	cout<<"=== menu ==="<<endl;
	cout<<"1. Fox"<<endl;
	cout<<"2. Bunny"<<endl;
	cout<<"3. Sloth"<<endl;
	cout<<"4. Quit"<<endl;
}

void zootopia1300() {
    // declare all variables
    double agility;
    double strength;
    double speed;
    double hireScore;
    
    printMenu(); // jumps to printMenu() function to print the options
    
    int userInput; 
	cin >> userInput; // allows the user to choose an option
	
    if (userInput == 1) {
        cout<< "Enter agility:" << endl;
        cin>> agility;
        cout<< "Enter strength:"<< endl;
        cin>> strength;
        speed = 0.0; // assume zero speed based on animal qualifications
        hireScore = (1.8*agility) + (2.16*strength) + (3.24*speed); // calculates hire score;
        cout << "Hire Score: " << hireScore << endl;
    
         zootopia1300(); // continues the loop until user presses quit
    }

    if (userInput == 2) {
        cout<< "Enter agility:" << endl;
        cin>> agility;
        cout<< "Enter speed:"<< endl;
        cin>> speed;
        strength = 0.0; // assume zero strength based on animal qualifications
        hireScore = (1.8*agility) + (2.16*strength) + (3.24*speed); // calculates hire score;
        cout << "Hire Score: " << hireScore << endl;
        
        zootopia1300(); // continues the loop until user presses quit
    }

    if (userInput == 3) {
        cout<< "Enter strength:" << endl;
        cin>> strength;
        cout<< "Enter speed:"<< endl;
        cin>> speed;
        agility = 0.0; // assume zero agility based on  animal qualifications
        hireScore = (1.8*agility) + (2.16*strength) + (3.24*speed); // calculates hire score;
        cout << "Hire Score: " << hireScore << endl;
        
        zootopia1300(); // continues the loop until user presses quit
    }

    else {
    }
}

int main(){
    zootopia1300();
}