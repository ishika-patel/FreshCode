// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 2

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: this function searches the substring in the given string and returns how many times the substring appears in the string.
1. declare and initialize a counter variable, this will be returned if there are any matches
2. if either parameter is empty return -1
3. otherwise, loop through every set of subsequent set of characters the length of the substring being searched for
    a. compare this substring (formulated from a starting point in the suerPhrase and ending based on how long the match is) to the parameter 2 listed below
        i. if this substring from the userPhrase is the same as the substring whose count is to be found, add one to the count
        ii. if not move to the next character in the userPhrase's seqeunce and continue this sampe process to see if strings match
4. return the count of how many matches are found
Input Parameters: two string parameters in the following order
1. String where the substring is searched
2. Substring whose count is to be found.
Output/printing: none
Returns: return the number of matches as an integer value (the number of occurrences of a substring in a given string), return -1 if one or both parameters are empty.
*/

int countMatches(string userPhrase, string substringCount) {
    
    int count = 0; // this value will be returned if there are any matches
    
    
    if (userPhrase.length() == 0 || substringCount.length() ==0) { //checks to see if either parameter is empty
        return -1;
    }
    else {
        for (int i =0; i<userPhrase.length(); i++) { //allows for movement down the string chracters
        if (userPhrase.substr(i,substringCount.length()) == substringCount) {
            // .substr accesses a certain section of the string called on based on the index values placed in its (a,b) parameters, start index a, go b places forward
            // the inqueality above checks to see if the two conditions match
    
            count++; // if the conditions match the count is incremetned by one match
        }
        
    }
    return count;
}
}


int main () {
    //test1
    //Expected return: 2
   countMatches("mississippi", "si");
    
    //test2
    //Expected return: -1
    countMatches("" , "");
    
    //test3
    //Expected return: -1
    countMatches("" , "pineapple");
    
    //test4
    //Expected return: -1
    countMatches("computer science" , "");
}