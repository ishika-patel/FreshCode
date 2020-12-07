#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/*
Write a function calcPay which takes a single input argument, a file name, as a string. Your function should read each line from the given filename, parse and process the data, and print the required information. Once the file has been read, your function should print the total pay from all lines. Your function should return the number of entries read from the file.  Empty lines do not count as entries. If the input file cannot be opened, return -1 and do not print anything.
Your function should be named calcPay
Your function should have one input argument: a file name, as a string.
Your function should return an int, representing the number of entries read from the file.
If the given file name can not be opened, your function should return -1.
Empty lines in the file should not be counted as entries.
Each line of the file contains three elements, separated by commas (,)
EMPLOYEE NAME, HOURS WORKED, PAY RATE
After parsing each line, you should print:
EMPLOYEE NAME: EMPLOYEE PAY
Where EMPLOYEE PAY is the total pay EMPLOYEE NAME has earned; the product of HOURS WORKED and PAY RATE.
Once the file has been read, print to the screen the total pay, which is the sum of all employees' pay, formatted as:
Total: TOTAL PAY
Note: The split() function is provided, and functions as it does in the homework assignments, to make parsing the output easier. Recall that split takes a string s and splits it at the input delimiter sep, to fill the array words[] up to a capacity of max_words. The return value of split is the number of actual words the string is split into.
 int split(string s, char sep, string words[], int max_words)
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


int calcPay(string fileName) {
    string tempArray[3];
    int size = 3;
    double total = 0.0;
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    
    file.open(fileName); //opens the file
    int i = 0; //counter to be returned
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
          if (line != "") { //checks to make sure array is not full nor is the line empty
                split(line, ',', tempArray, size);
                double totalEPay = stod(tempArray[1]) * stod(tempArray[2]);
                cout << tempArray[0]  << ": " << totalEPay<< endl;
                total = total + totalEPay;
                i++;
           }
        }
    }
    else {
        return -1;
    }
    cout << "Total: "<< total << endl;
    return i;
    file.close();
}