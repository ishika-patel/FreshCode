// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 4

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: this function returns the similarity score for two sequences.
1. declare and initialize a counter variable, this will return the number of unsimiliarities
2. both parameters must be of SAME legnth, if this condition is not met similariy score is zero
3. otherwise loop through each of the characters in the string parameters at the same index
    a. if the character at the same index is the same, move to check the next character
    b. if the characters are different increment the hamming distance by 1 (for each difference)
note: in this function, we will compare only the characters at the same index in each string
note: similarity score = (string_length - hamming_distance) / string_length
Input Parameters: two string parameters in the following order
1. Seqeunce 1 (string)
2. Seqeunce  2 (string)
Output/printing: none
Returns: return the similarity score as a double
*/

double calcSimScore(string sequence1, string sequence2){
    int string_length = sequence1.length();
    
    if (sequence1 == "" || sequence2 == "") { //checks to see if parameters were let empty, if so returns 0
        return 0;
    }
    
    if (sequence1.length() == sequence2.length()){ 
        int hamming_distance = 0; //this variable represents the number of differences between the sequences
        for(int i = 0; i <=sequence1.length(); i++) { //loops through each index of the sequence, only occurs when the lengths of both seuqnces are the same
            if (sequence1[i] != sequence2[i]) { // adds to the hamming_distance when chracters are not the same, otherwise no arithmetic occurs
                hamming_distance = hamming_distance +1;
            }
        }
       double similarity_score = (string_length - hamming_distance); // the following two lines compute the similairty_score arithmetic
       similarity_score = similarity_score/string_length; 
       return similarity_score;
    }
    else { 
        return 0;
    }
}

int main () {
    //test1
    // Expected return: 0.75
    calcSimScore("ATGC", "ATGA");
    
    //test2
    // Expected return: 1
    calcSimScore("CCDCCD", "CCDCCD");
    
    //test3
    //Expected Return: 0
    calcSimScore("ATG","GAT");
    
    //test4
    //Expected return: 0
    calcSimScore("ACCDT","ACT");
    
    //test5
    //Expected return: 0
    calcSimScore("", "");
}