#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/*
Write a function maxTemp which takes a filename as string argument and returns the maximum temperature as float type for the week. 
Input file will contain temperature readings for each day of the week. 
Your function should read each line from the given filename, parse and process the data, and return the required information. 
Your function should return the highest temperature for the whole week.
Empty lines do not count as entries, and should be ignored.
If the input file cannot be opened, return -1. 
Remember temperature readings can be decimal and negative numbers.
*/

double maxTemp(string fileName) {
    string line; 
    string tempArray[2];
    double maxValue = 0 ;
    ifstream file; //says there is a file we will access and we are taking data from it
    file.open(fileName); //opens the file
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
        split(line, ',',tempArray, 2);
            if (stod(tempArray[1]) > maxValue){
                maxValue = stod(tempArray[1]);
            }
            else {
                maxValue = maxValue;
            }
    }
    }
    else {
        return -1;
    }
    return maxValue;
    file.close();
}