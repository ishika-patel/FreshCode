// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 7 - Problem 2

#include <iostream> 
#include <fstream>
#include <string.h>
#include "Book.h"
#include "User.h"
using namespace std;

/* Algorithm: the function goes through a list of ratings and sorts ratingw based on users and their scores
Case1: Return the total number of users in the system, as an integer.
Case2: When numUsersStored is equal to the maximum number of rows in the ratings 2D array, return -2
Case3: When numUsersStored is smaller than the maximum number of rows in theratings 2D array, keep the existing elements in users array and ratings array,
then read data from file and add (append) the data to the arrays. The number of users stored in the arrays cannot exceed the size of the arrays.
Case4: If the file cannot be opened, return -1
Input Parameters: string fileName, string users[], int ratings[][50], int numUsersStored, int maxRows, int maxColumns
Output/printing: none
Returns: the number of users in the file if the file can be opened and function can be run, -2 if the numUsersStored is equal to max number of rows, -1 if the file cannot be open
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

/* Algorithm: this fucntion returns the number of books stored in the file. this will assign rating values to each user based on 
Input Parameters: string fileName, User users[], int numUsersStored, int usersArrSize, int maxColumns
Output/printing: none
Returns: number of books stored
*/

int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize, int maxColumns){
    int num = numUsersStored;
    if (num >= usersArrSize) { // checks case 2: numUsersStored is equal to usersArrSize upfront
             return -2; 
    }
    
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    file.open(fileName); //opens the file
    
    if (!(file.is_open())) { //checks case 4: file cannot open
        return -1;
    }
    
    else if (file.is_open()) { //checks to see if file is open
        while (getline(file,line) && num<usersArrSize) { //reads line by 
            int count = 0; 
            if (line != "") { //checks to make sure array is not full nor is the line empty
                string testArray[maxColumns+1]; // plus one to go through all of the column numbers

                split(line, ',', testArray, maxColumns);  // used to separate the rows
                
            
                for(int c =0; c<maxColumns; c++){   // checks to see how many columns are occupied so that the program doesnt overload when "copying" the columns
                    if(testArray[c] != "") { 
                        count ++; // if thre is something stored the count is incremented
                    }
                    else {
                        count = count; // otherwise the count is kept at count
                    }
                }
                 users[num].setUsername(testArray[0]); //sets the username using the data from the testarray given from split
                 
                for(int j = 1; j<=count; j++){
                    if(testArray[j]!="")
                    users[num].setRatingAt(j-1,stoi(testArray[j])); //inserts the testArray into the "official" array and stoi converts string to decimal
                }
                 num++;  //increment counter if a varible is stored
           }
        }
    }
    
    file.close();
    return num; // return number of books stored
}

int main() {
    // test1
    // expectd output: 5
    User userTest[50];
    cout<< readRatings("ratings1.txt", userTest, 4, 5, 50)<< endl;
    
    //test2
    //expected output: -2
    User users[2];
    users[0].setUsername("Ninja");
    users[1].setUsername("Myth");
    users[0].setRatingAt(0,0);
    users[0].setRatingAt(1,1);
    users[0].setRatingAt(2,2);
    users[0].setRatingAt(3,3);
    users[0].setRatingAt(4,4);
    users[1].setRatingAt(0,2);
    users[1].setRatingAt(1,2);
    users[1].setRatingAt(2,4);
    users[1].setRatingAt(3,5);
    users[1].setRatingAt(4,5);
    int numUsersStored = 2;
    int usersArrSize = 2;
    cout << readRatings("moreRatings.txt", users, numUsersStored, usersArrSize, 50)<< endl;
}
