// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 1

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm: this function reads the file line by line, and at each line if there is a number it, it should store it in the array
If a line is empty it should continue reading until it sees another integer before adding to the array. 
Empty lines should not be added to the array.
Once the array is full (length integers have been added), subsequent integers in the file should be ignored.
Input Parameters: string fileName, integer array[], integer lengthArray
Output/printing: none
Returns: number of intergers added into the array or -1 if the file does not exist or is empty
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

int getLinesFromFile(string fileName, int array[], int lengthArray) {
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    
    file.open(fileName); //opens the file
    int i = 0; //counter to be returned
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
           if (line != "" && i<lengthArray) { //checks to make sure array is not full nor is the line empty
             array[i] = stoi(line); //s to i is string to integer
             i++;  //increment counter if a varible is stored
           }
        }
    }
    else {
        return -1;
    }
    return i;
    file.close();
}

int main() {
    //test1
    //expected output: Function returned: 4 \n 1 \n 5 \n 23 \n18
    int arr[4];
    cout << getLinesFromFile("getLinesTest.txt", arr, 4);
    
    //test2
    //expected output: -1
    int arr1[4];
    cout << getLinesFromFile("notReal.txt", arr1, 4);
}