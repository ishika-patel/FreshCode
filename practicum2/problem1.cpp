#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;


/*
Write a function Count_m_z that takes a string as an input parameter argument and counts the number of m, n, o, ... z characters in it. The function returns an integer value for the number of times those 14 lowercase letters appear in the input string.

Your function should be named Count_m_z
Your function should take one string parameter
Your function should return the number of m, n, o, ... z characters as an integer
Your function should not print/output anything
 
Edge Cases
If the string is empty, return -1
If there are no m, n, o, ... z characters in the string, return -2
*/
//m is 109 z is 122
int Count_m_z(string userInput){
    int count = 0;
    
    if (userInput == "") {
        return -1;
    }
    else {
        for(int i = 0; i<userInput.length(); i++){
            if(userInput[i]>=109 && userInput[i]<=122){
              count ++;  
            }
        }
        if (count == 0){
            return -2;
        }
        else {
        return count;
        }
        }
}