// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - Problem 6

#include <iostream>
#include <string>

using namespace std;

/* Algorithm: The function will split the input string in to pieces separated by the character,
and populate the array of strings with the split pieces up to the provided maximum number of pieces. 
Your function will return the number of pieces the string was split into.
Input Parameters: four input arguments
    1. a string to be split
    2. a character to split on
    3. an array of strings to fill with the split pieces of the input string
    4. an integer representing the maximum number of split string pieces.
Output/printing: none
Returns: the number of pieces the string was split into (int)
*/

int split(string line, char delimiter, string array[], int arraySize){
    
    int count =0; // this allows us to return the counter
    int start =0; // this will track where in the string we are as we are looking for the delimiter
    
    if (line == "") { //checks to see if the parameter for string is empty
        return 0; //if it is, returns 0 and exits code
    }
    if (line[line.length()-1] == delimiter) { //checks to see if the last value in the string is the delimiter
        line = line.substr(0, line.length()-1); // if it is, the delimiter at the end is cut off and the process is continued
    }
    
    for (int i = 0; i<line.length(); i++) {
        if (line[i] == delimiter) { // we are now searching for the delimiter
            
            if (count == arraySize) { // this is a fail safe to make sure that the count is not greater than the value that the array can hold
                return -1; //If the string is split into more pieces than the array of string can hold return -1
            }
            else {
                string arrayInput = line.substr(start, i-start); // int i is where the delimiter was found, thefore we want to print the strin from the beinning to int i
                if (i-start !=0 && start+1 !=0) { // the first condition checks to make sure two delimiters are together, the second condition checks the starting position
                    array[count] = arrayInput;  // store the value that is extrapolated from arrayInput
                    count ++; // add one to the count to return the number of words at the end, note that count doesnt include the very final word
                }
                }
            start = i + 1; // becuase you are moving past the whole word so you have to move up to i where the delimiator was and 1 past i so you pass the delimiter
            }
         }
         
         string arrayInput = line.substr(start, line.length() - start); 
             if (arrayInput != "") {// keeps the process going until the string itself ends
                 array[count] = arrayInput;
             }
         return ++count; //preincrement in order to account for index vs length discrepecy
         }

int main() {
    //test1
    //expected output : 3 \n one \n small \nstep
    string words[6];
    cout << split("one small step",' ',words,6) << endl;

    // test2
    //expected output: 3 \ncow \n big pig \nfish
    string word[6];
    cout << split("cow/big pig/fish",'/',word,6) << endl;
}