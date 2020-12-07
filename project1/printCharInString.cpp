// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 1

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: this function takes a string argument and prints all the characters in the string on a new line.
1. check to see if the parameter is empty or not
    a. if empty cue the error statement
    b. if full move to step 2
2. run through each character of the string using a for loop and print separately
    a. access each char in the strings index independtly and print
Input Parameters: a string argument
Output/printing: if string is empty "Given string is empty!". Otherwise all characters are printed on a new line
Returns: nothing
*/

void printCharInString(string userString) {
    if (userString.length() == 0) { // if the input is blank
        cout<< "Given string is empty!" << endl;
    }
    else {
        for (int i =0; i<userString.length(); i++) { //for loop to follow every index value of the string
               cout << userString[i] << endl; // accessing each char in the userString
        }
    }
}

int main() {
    //test1
    //Expected Output: Computer - each character printed on new line
    printCharInString("Computer");
    
    //test2
    // ExpectedOutput: Given string is empty!
    printCharInString("");
}