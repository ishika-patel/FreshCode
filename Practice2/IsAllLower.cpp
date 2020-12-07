#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

/*
Write a function, IsAllLower, that takes a string as input and returns true if all the alphabetic characters in the string are lowercase alphabetic characters. The function returns false otherwise. If input string contains non-alphabetic character, return false.

Your function should be named IsAllLower
Your function has one input argument of type string
Your function has one return value of type boolean evaluating to true if the input string contains all lowercase alphabets, false otherwise
Your function should not print anything
*/


bool IsAllLower(string userInput){
    int count = 0;
    if (userInput == "") {
        return true;
    }
    else {
        for(int i = 0; i< userInput.length(); i++){
            if (userInput[i] < 97){ //97 is letter a lowrcase in  ASKII, and all uppre case are before lower case a!
                count ++;
            }
        }
        if(count>0) {
            return false;
        }
        else {
            return true;
        }
    }
}