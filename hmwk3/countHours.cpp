/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #5 */

#include <iostream>
using namespace std;

/* Algorithms: this function returns the number of of total hours present in the month input
based on the days in a specific month, multiply that number of days by 24 to recieve the return value
1. Month 1: 31 days * 24 hours per day
2. Month 2: 28 days * 24 hours per day 
3. Month 3: 31 days * 24 hours per day 
4. Month 4: 30 days * 24 hours per day
5. Month 5: 31 days * 24 hours per day 
6. Month 6: 30 days * 24 hours per day 
7. Month 7: 31 days * 24 hours per day 
8. Month 8: 31 days * 24 hours per day 
9. Month 9: 30 days * 24 hours per day 
10. Month 10: 31 days * 24 hours per day 
11. Month 11: 30 days * 24 hours per day 
12: Month 12: 31 days * 24 hours per day 
Input parameters: month number (int)
Output: no printing
Returns:number of hours (int)  */

int countHours(int month) { //takes in the month value
    int hours = 0; 
    switch (month){
    // each case represents a month and hours are computed based on how many days per that month there are
        case(1):
            hours = 31 * 24;
            break;
        case(2):
            hours = 28 * 24;
            break;
        case(3):
            hours = 31 * 24;
            break;
        case(4):
            hours = 30 * 24;
            break;
        case (5):
            hours = 31 * 24;
            break;
        case (6):
            hours = 30 * 24;
            break;
        case (7):
            hours = 31 * 24;
            break;
        case (8):
            hours = 31 * 24;
            break;
        case (9):
            hours = 30 * 24;
            break;
        case (10):
            hours = 31 * 24;
            break;
        case (11):
            hours = 30 * 24;
            break;
        case (12):
            hours = 31 * 24;
            break;
        default:
            hours;
    }

    return hours;
}

int main() {
    //test1
    // Expected return: 744
    countHours(1);
    //test2
    // Expected return: 672
    countHours(2);
    //test3
    // Expected return: 720
    countHours(4);
    
}