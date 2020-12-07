// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 7

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm: the function goes through a list of ratings and sorts ratingw based on users and their scores
Case1: Return the total number of users in the system, as an integer.
Case2: When numUsers is equal to the maximum number of rows in the ratings 2D array, return -2
Case3: When numUsers is smaller than the maximum number of rows in theratings 2D array, keep the existing elements in users array and ratings array,
then read data from file and add (append) the data to the arrays. The number of users stored in the arrays cannot exceed the size of the arrays.
Case4: If the file cannot be opened, return -1
Input Parameters: string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns
Output/printing: none
Returns: the number of users in the file if the file can be opened and function can be run, -2 if the numUsers is equal to max number of rows, -1 if the file cannot be open
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

int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns){
    int num = numUsers;
    if(num == maxRows) { // checks case 2: numUsers is equal to maxRows upfront
             return -2; 
    }
    
    
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    file.open(fileName); //opens the file
    
    if (!(file.is_open())) { //checks case 4: file cannot open
        return -1;
    }
    else if(file.is_open()) { //checks to see if file is open
        while (getline(file,line) && num<maxRows) { //reads line by 
            int count = 0; 
            if (line != "") { //checks to make sure array is not full nor is the line empty
                string testArray[maxColumns+1];
                //cout << "asdf" << endl;
                split(line, ',', testArray, maxColumns);  // used to separate the rows
                
                for(int k =0; k<maxColumns; k++){   // checks to see how many columns are occupied so that the program doesnt overload when "copying" the columns
                    if(testArray[k] != "") { 
                        count ++; // if thre is something stored the count is incremented
                    }
                    else {
                        count = count; // otherwise the count is kept at count
                    }
                }
                 users[num] = testArray[0];
                 //cout<<num<<','<<users[num]<<endl;
                for(int j =1; j<=count; j++){
                    //cout << num<<","<<users[num] << endl;
                   
                    if(testArray[j]!="")
                    ratings[num][j-1] = stoi(testArray[j]); //inserts the testArray into the "official" array and stoi converts string to decimal
                    //            cout<<"adfasf"<<endl;

                    
                }

                
                 num++;  //increment counter if a varible is stored
           }
        }
    }
    
    file.close();
    return num;
}