/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #6 */

#include <iostream>
using namespace std;

/* Algorithms: this function takes a single integer representing a year and returns true if it is a leap year and false otherwise.
Def: years that are divisible by 100 are not leap years but years divisible by 400 are after 1582
Input parameters: integer number (int)
Output: no printing
Returns: boolean value, true or false, according to the leap year definition */

bool checkLeapYear(int year) {
    
    if (year<=1582) { //checks leap years every 4 years prior to changes
        if (year%4 == 0) {
            return true;  
        }
        if (year % 4 != 0){
            return false;
        }
    }
    
    if (year>1582) {//Gregorian Calendar chages
        if (year%400==0 && year%100 == 0) { //years divisible by 400 are always leap years no matter what other divisibility
            //cout<< true << endl;
            return true;
        }
        
    if (year%400 != 0 && year%100 != 0 && year%4==0) { //checks for years like 1616 that are leap years because of 4 divisibility
        //cout<< true << endl;
        return true;
        }
    
    if (year%100==0 || year%4 !=0) { //checks for non-leap years
        //cout<< false<< endl;
        return false;
        }
    
    if (year%4==0 && year%100 != 0) { // redundant for leap years divisible by 4
        //cout<< true << endl; 
        return true;
    }
    
    }
}


int main(){
    //test1
    //expected result: 0 (false)
    checkLeapYear(1900);
    //test2
    //expected result: 1 (true)
    checkLeapYear(2000);
    // test3
    //expected result: 1 (true)
    checkLeapYear(1616);


}