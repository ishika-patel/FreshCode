// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 6

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm:
1. function will open and read the file specified by the fileName parameter. 
This string should include both the name and extension of the file (what type of file it is).
2. function should read the file line by line. Each line contains 4 floating point numbers
which should be stored in the corresponding columns of the 2D array.
3. If your function has added any rows to the array (meaning that the specified file exists
and could be read), it should return the number of rows added to the array.
4. return number of arrays added to origial
Input Parameters: string fileName, double array[][4], int rows
Output/printing: none
Returns: if file doest exit return -1 it it does return the number of rows added to the array
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

int readFloatMap(string fileName, double array[][4], int rows){
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    string testArray[4];
    
    file.open(fileName); //opens the file
    int i = 0; //counter to be returned
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
            if (line != "" && i<rows) { //checks to make sure array is not full nor is the line empty
            
            split(line, ',', testArray, 4);  // used to separate the rows

            for(int j =0; j<4; j++){

             array[i][j] = stod(testArray[j]); //inserts the testArray into the "official" array and stod converts string to decimal
             }
             
             i++;  //increment counter if a varible is stored
           }
        }
        return i; //return number of rows
    }
    else {
        return -1;
    }
}
            
int main() {
    //test1
    //return: -1
    double array[2][4];
    readFloatMap("notThisFile.txt", array, 2);
    //test2
    //return: 2
    double floatMap[2][4];
    readFloatMap("fileName.txt", floatMap, 2);
}