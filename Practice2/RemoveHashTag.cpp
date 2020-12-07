#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

/*
Write a function, RemoveHashTag, that takes a string as input and removes all the hashtags (#) characters. 
The function returns a string value without the hashtag characters.
Your function should be named RemoveHashTag
Your function has one input argument of type string
Your function has one return value of type string representing input string without the hashtag character.
Your function should not print anything
*/
string RemoveHashTag(string userInput){
    string returnVal = "";
    for (int i=0; i<userInput.length(); i++){
        if(userInput[i] != 35){
           returnVal = returnVal + userInput[i]; //adds it to the end
         }
    }
return returnVal; //returns the lowercase string
}

