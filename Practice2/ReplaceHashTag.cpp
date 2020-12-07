#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

/*
Write a function, ReplaceHashTag, that takes a string as input and replaces all the hashtags (#) characters with @ character. The function returns a string representing input string containing # character replaced with @ character.
Your function should be named ReplaceHashTag
Your function has one input argument of type string
Your function has one return value of type string representing input string containing # character replaced with @ character.
Your function should not print anything
*/
string ReplaceHashTag(string userInput){
    string returnVal = "";
    for (int i=0; i<userInput.length(); i++){
        if(userInput[i] == 35){
           userInput[i] = 64; 
         }
    }
return userInput; 
}

