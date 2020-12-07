#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Write a function removeCapitals which takes a string parameter.
The function removes all capital letters from the input string and returns the new string without any capital letters.
Your function should be named removeCapitals
Your function takes one parameter: string type
Your function returns the string with all the capital letters removed
*/

string removeCapitals(string userInput){
    string newInput = "";
    
    // if (userInput == "") {
    //     return -1;
    // }
    // else {
    
    //65 is A 90 is Z
        for(int i = 0; i<userInput.length(); i++){
            if(userInput[i]<65 || userInput[i]>90){
              newInput = newInput + userInput[i];
            }
        }
        return newInput;
}