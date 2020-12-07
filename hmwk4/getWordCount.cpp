// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - Problem 5

#include <iostream>
#include <string>

using namespace std;

/* Algorithm: this function takes an English sentence and returns the number of words in the sentence.
- move throgh each of the characters of the string to check for space character
Input Parameters: a string parameter for the sentence
Output/printing: none
Returns: number of words in a sentence from string s
- "" return 0
*/

int getWordCount(string s) {
int count = 0; // counter for how many spaces there are
    if (s == ""){ //checks to see if parameter is empty
        return 0;
    }
    else {
        for (int i =0; i< s.length(); i++) { // loop through the string, strings are arrays
            if (s[i] == 32) { // check for a space (ASCII char number 32)
                count ++; //if found add one to the counter
            }
        }
    return count + 1; // add the count plus 1 to account for the final word.
    }
}

int main(){
    //test 1
    //expected return: 2
   getWordCount("I went");
   
   //test2
   // expected return: 0
    getWordCount("");

}