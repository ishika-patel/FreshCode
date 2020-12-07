/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #10*/

#include <iostream>
using namespace std;

/* Algorithms: this function takes a single integer representing the number of rows and columns in a grid, and prints a grid

Input parameters: number n of rows and columns (int)
Output: print a grid based on the given number n of rows and columns 
Returns: none */

// note for the future: try assining one of the rows to an even number and one to and odd number so that you dont have to add an extra row at the end!
void printGrid(int n) {
 
   int number = 0;
    if (n<=0){
        cout<< "The grid can only have a positive number of rows and columns." << endl;
        number--;
    }
    else {
        while(number<n){
        
        for (int i = 0; i < n; i++){
            cout << "+--";
        }
        
        cout << "+" << endl; // this is to account for the extra plus at the end and moves the pattern to the next line
        
        for (int i = 0; i < n; i++){
                cout<< "|  ";
                }
        cout<< "|" << endl; //this is to account for the extra plus at the end and moves the pattern to the next line
    
        number ++;
        }
        // how to add the last +-- line without another separate loop???
        
    }

    if (number == n) {
        for (int i=0; i< n; i++) { // accounts for the extra +-- line to the end of the pattern
            cout << "+--";
        }
        
        cout << "+" << endl; // this is to account for the extra plus at the end and moves the pattern to the next line
    }
}

int main() {
    //test1
    // expected output: pattern of 3*3 box
    printGrid(3);
    
    //test2
    // expected output: pattern of 5*5 box
    printGrid(0);
}