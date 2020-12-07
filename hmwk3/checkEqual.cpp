/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #2 */

#include <iostream>
using namespace std;

/* Algorithms: this function checks to see if the inputs are all the same, all different or neither
1. checks to see if num 1,2 and 3 are the same, if all the same print: "all same"
2. checks to see if num1,2 and 3 are all differetn, if so print: "all different"
3. checks all other renditions where two numbers are the same no matter their location, print : "neither"
Input parameters: 3 number value (int)
Output: prints based on conditions met
Returns: none  */

void checkEqual(int num1, int num2, int num3) {
    if (num1==num2 && num1==num3){ // checks if all inputs are the same value
        cout<< "All same" << endl;
    }
    else if (num1!=num2 && num1 !=num3 && num2!=num3) { //checks if imputs are all different
        cout << "All different"<< endl;
    }
    else { // if inputs are not all same or all different, this means 2 are same
        cout<< "Neither" << endl;
    }
}

int main(){
    //test1
    //Expected Output: All different
    checkEqual(1,2,3);
    //test2
    //Expected Output: all same
    checkEqual(2,2,2);
    //test3
    //Expected Output: neither
    checkEqual(1,1,2);
}