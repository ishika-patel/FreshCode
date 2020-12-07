// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 2

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm: populates a pair of arrays with the titles and authors found in books.txt.
Your function should return the number of books stored in the array, after you populate them.
Empty lines should not be added to the arrays.
    - When numBookStored is equal to the size, return -2.
    - When the file is not opened successfully, return -1.
Input Parameters: string line, character delimiter, string array[], integer arraySize
Output/printing: none
Returns: the number of books stored in the array, after you populate them.
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


int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) {
    if (numBookStored == size) {
        return -2;
    }
    
    string line; // declared to hold the getline values
    string tempArray[2] = {"", ""}; // this is the array that the split function stores in
    ifstream file; //says there is a file we will access and we are taking data from it
    
    file.open(fileName); //opens the file
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
           if (line != "" && numBookStored<size) { //checks to make sure array is not full nor is the line empty
             split(line, ',', tempArray, 2); 
             authors[numBookStored] = tempArray[0]; //assign the split function array to the apporopriate author or title arrays
             titles[numBookStored] = tempArray[1];
             numBookStored++;  //increment counter if a varible is stored
           }
        }
        
    }
    else {
        return -1;
    }
    file.close();
    return numBookStored;
}

int main() {
    //test1
    // expected output:2
    string authors[10] = {};
    string titles[10] = {}; 
    cout << readBooks("fileNameReadBook.txt", titles, authors, 0, 10) << endl;
    
    //test2
    //expected output: 50
    string author[60] = {};
    string title[60] = {}; 
    cout << readBooks("books.txt", title, author, 0, 60) << endl;
}