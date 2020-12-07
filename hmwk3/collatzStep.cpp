/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #1 */

#include <iostream>
using namespace std;

/* Algorithms: this function takes a single integer parameter and returns an integer based on
whether the parameter is odd, even or negative
1. if the input is negtive return 0 
2. if the input is even the function will return what muliple of 2 it is divisible by
3. if the input is odd, meaning it has a remainder when using the modulus with 2 is taken, the input returns
the (number*3) + 1
Input parameters: number value (int)
Output: final population after all three rates are applied
Returns: integer value based on whether parameter is odd, even or negative */

int collatzStep(int number){
    if(number>0){
      if(number%2 == 0){ // checks if number is even
          number= number/2; // divides the imput by 2
          return number; // returns number/2
    }
        if (number%2 != 0){ //checks if number is odd
            number = (number*3) + 1;// multipes number by 3 then adds 1
            return number; // returns 3*number +1
        }
    }
    
    if(number<0){ // checks if number is negative
        return 0;
    }
    
    if (number == 0) {
        return 0;
    }
    
}

int main() {
    // test1
    // expected return: 2
    collatzStep(4);
    // test2
    // expected return: 22
    collatzStep(7);
    // test3
    // expected return: 0
    collatzStep(-5);
}