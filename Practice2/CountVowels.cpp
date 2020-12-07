#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

/*
Write a function, CountVowels, that takes a string as input and count the number of vowels (a,e,i,o,u either upper or lower case) alphabetic characters. The function returns an integer value for the number of vowels.

Your function should be named CountVowels
Your function has one input argument of type string
Your function has one return value of type integer representing the number of vowels in the input string
Your function should not print anything
*/

string makeLower(string s){
    char c;
    string lowerCase = "";
    
    for (int i=0; i<s.length(); i++) {  //goes through all the characters in the array
        c = s[i]; //accesses the single character the the index
        c = tolower(c); //makes it lowercase
        lowerCase = lowerCase + c; //adds it to the end
    }
    return lowerCase; //returns the lowercase string
}


int CountVowels(string userInput){
    int count = 0;
    string newInput = makeLower(userInput);
    
    if (newInput == "") {
        return -1;
    }
    else {
    for(int i = 0; i<userInput.length(); i++){
        if(newInput[i]=='a' ||newInput[i]=='e' ||newInput[i]=='i' || newInput[i]=='o' || newInput[i]=='u'){
          count ++;  
        }
    }
    return count;
    }
}