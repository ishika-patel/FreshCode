/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #3 */

#include <iostream>
using namespace std;

/* Algorithm: takes single int parameter and prints greeting 
Input parameters: CS course number
Output: statment of Hello CS World!
Returns: none*/

void classGreeting(int courseNum) {
    
    cout<<"Hello, CS " << courseNum << " World!" << endl;
}

int main() {
    //test1
    // Expected Result: Hello, CS 1500 World!
    classGreeting(1500);
    //test2
    // Expected Result: Hello, CS 1300 World!
    classGreeting(1300);
    return 0;
}