/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #7 */

#include <iostream>
using namespace std;

/* Algorithm: function takes input of seconds and converts it to hours, mins and secs.
1. convert seconds to maximun num hours using 3600 secs in hour conversion
2. convert remaining seconds to max mins using 60 secs in min conversion
3. display remaining seconds, calcuated mins and hours
Input parameters: seconds
Output: hours mins and seconds conversion from input
Returns: none */

void convertSeconds(int seconds){
    
    int hours = 0;
    int minutes = 0;

    hours = seconds/3600; // int data type keeps the whole value max converted hours
    seconds = seconds%3600; //mod is used to determine remaining seconds after hours conversion
    minutes = seconds/60; // minutes determined with seconds
    seconds = seconds%60; // mod is used to determine remaining seconds after minutes conversion

    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds <<  " second(s)" << endl;
    
}

int main() {
    //test1
    // Expected result: 1 hour(s) 0 minute(s) 0 second(s)
    convertSeconds(3600);
    //test2
    //Expected resutls: 18 hour(s) 12 minute(s) 16 second(s)
    convertSeconds(65536);
}