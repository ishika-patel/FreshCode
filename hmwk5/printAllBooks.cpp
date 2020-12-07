// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 3

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm: a function that prints the arrays from the readBooks function
Input Parameters: string titles[], string authors[], int numBooks
Output/printing: If the number of books is 0 or less than 0, print ​“No books are stored”
if there are books “Here is a list of books by <author>”
Returns: none
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

void printAllBooks (string titles[], string authors[], int numBooks) {
   if (numBooks <= 0) { // to check if the arrays are filled
       cout << "No books are stored" << endl;
   }
   else { // if the arrays are filled then the arrays will be printed using a for loop
       cout<< "Here is a list of books" << endl;
       for (int i = 0; i<numBooks; i++) {
           cout << titles[i] << " by " << authors[i]<< endl;
       }
    }
}


int main() {
    //test1
    // expected output: the first 10 books from book.txt
    string authors[10] = {};
    string titles[10] = {};
    int nb = readBooks("books.txt",titles,authors, 0, 10);
    printAllBooks(titles, authors, nb);
    
    //test2
    // expected output:No books are stored
    string author[10] = {};
    string title[10] = {};
    printAllBooks(title, author, 0);
}