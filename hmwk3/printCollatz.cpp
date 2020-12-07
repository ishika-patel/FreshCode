/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #7 */

#include <iostream>
using namespace std;

/* Algorithms: this function takes a single integer parameter and prints a series of integers based on
whether the parameter is odd, even or negative
1. if the input is 0 or a negative number it must print “invalid number”
2. if the input is even the function will divide it by 2 and provide this sequence
3. if the input is odd the function takes the parameter and triples it and adds 1
4. based on the output of the first computation, the sequnce will continue with steps 2 or 3 until the seuqnce cannot be computed further
Input parameters: integer number (int)
Output: the sequence of numbers based on odd or even or "invalid number" is printed
Returns: none */

void printCollatz(int number) {
    
    if (number<= 0) {
        cout<< "invalid number" << endl; 
    }
    else {
        cout<< number << " " ; //prints the input number and moves to the while loop to create the rest of the series
    }
    while (number>1) {
        if (number%2 == 0){ // checks if the number is even
            number = number/2;
            cout <<number<< " " ;
        }
        else if (number%2 != 0) { //checks if the number is odd
            number= (number*3) +1 ; 
            cout << number << " ";
        }
    }
     cout << "" << endl; // allows the next test function to move to the next line (formatting for the output)
}

int main(){
    // test1
    // Expected output: 4 2 1
    printCollatz(4);
    //test2
    //expected output: "invalid number"
    printCollatz(-4);
}