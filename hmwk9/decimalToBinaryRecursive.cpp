// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 9 - Problem 2

#include <iostream>
#include <string>
using namespace std;


/* Algorithm:decimalToBinaryRecursive that converts a decimal value to binary using recursion. 
This function takes a single parameter, a non-negative integer,
and returns a string corresponding to the binary representation of the given value.
Input Parameters: int decimal val
Output/printing: none
Returns: binary conversion (string)
*/

string decimalToBinaryRecursive(int decimal){
    if (decimal == 0){ // edge case if the decimal value is only 0
          return "0";  
    }
    
    if(decimal%2 != 0) { // if there is. remainder
        decimal = decimal / 2; // do the division for the next case, rounds down
        return decimalToBinaryRecursive(decimal) + "1"; // return the string with 1 added to the end
        
     }
        
    if (decimal%2 == 0) {
        decimal = decimal / 2; // do the division for the next case, rounds down
        return decimalToBinaryRecursive(decimal) + "0"; // return the string with 0 added to the end
    }
    
}

int main() {
    //test1
    // expected output: 01101 
    cout << decimalToBinaryRecursive(13) << endl;
    
    //test2
    // expected output: 01100
    cout << decimalToBinaryRecursive(12) << endl;
    
}