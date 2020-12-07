/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #8 */

#include <iostream>
using namespace std;

/* Algorithms: this function takes a single integer parameter and prints print all positive odd integers less than or equal to a max value.
1. starting at 1 add 2 each time to the starting value until the starting value surpases the max value
Input parameters: max value (int)
Output: print the positive odd integers less than or equal to the max value 
Returns: none */

void printOddNumsWhile(int max) { 
    int startingNumber = 1; // starting at the first odd number 1
    while (startingNumber<=max) { // the series continues until the max number is reached
        cout << startingNumber<< endl;
        startingNumber = startingNumber +2; // moves to the next odd number
    }
}

int main(){
    //test1
    // expected output: 1 2 5 7 9 11 (on a new line for each number)
    printOddNumsWhile(11);
    //test2
    // expected output: 1 3 5 7 9 11 13 15 17 19 21 (on a new line for each number)
    printOddNumsWhile(21);
}