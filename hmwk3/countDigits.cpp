/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #4 */

#include <iostream>
using namespace std;

/* Algorithms: this function returns the number of digits as an integer
1. if the number input is negative, first muliply by -1 then continue to determine how many digits there are
2. once the number is positive or if it is given positive
    a. if the number is zero add one to the digit counter and return the counter
    b. if the number is >0, divide the number by 10 to lose a digits place then add one to the counter
    continue this process while the number is greater than 0.
Input parameters: 3 number value (int)
Output: no printing
Returns: the counter (int) of the number of digits  */

int countDigits(int number) {
    
    int counter = 0; // keeps track of the number of digits
    
    if (number<0) {
        number = number * -1; // turns the number positive
        
    }
    if (number == 0) {
        counter++; // one digit for number 0
    }
    
    while (number>0) {
        number = number / 10 ; // "removes" one digit of the number and adds one to the coutner each time
        counter++;
    }

    return counter;
}

int main() {
    //test1
    // Expected return: 7
    countDigits(-1123241);
    //test2
    // Expected return: 2
    countDigits(24);
}