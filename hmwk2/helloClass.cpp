/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #2 */

#include <iostream>
using namespace std;

/*
*Algorithm: program takes input from the user on course number and outputs intro to class
Input parameters: user input of course number
Output: statment of Hello World!
Returns: 0
*/

int main() {
    int courseNumber;
    cout << "Enter a CS course number:" << endl;
    cin >> courseNumber; //ask for user to input course number
    cout<<"Hello, CS " << courseNumber << " World!"<< endl;
    
    return 0;
}