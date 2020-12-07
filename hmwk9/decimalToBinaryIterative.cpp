// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 9 - Problem 1

#include <iostream>
#include <string>
using namespace std;


/* Algorithm: decimalToBinaryIterative that converts a decimal value to binary using a loop.
This function takes a single parameter, a non-negative integer, and returns a string corresponding 
to the binary representation of the given value.
Input Parameters: int decimal val
Output/printing: none
Returns: the binary conversion of the decimal number (string)
*/

string decimalToBinaryIterative(int decimal) {
    string binary; // return this string at the end
    
    if (decimal == 0){ //edge case if the only number is 0
          return "0";  
    }
        
    while(decimal > 0) { // while the decimal value is greater than 0
        if(decimal%2 != 0) { // if there is a remainder
            binary = "1"+ binary; // add 1 to the string
        }
        
        if (decimal%2 == 0) { // if there is no remainder
            binary = "0" + binary; // add 0 to the string
        }
        
        decimal = decimal/2; // divide by 2 for the next value, rounds down
    }
    return binary;
}

int main() {
    // test1
    // expected output: 1110000
    cout << decimalToBinaryIterative(112) << endl;
    
    //test2
    // expected output: 0
     cout << decimalToBinaryIterative(0) << endl;
    
}