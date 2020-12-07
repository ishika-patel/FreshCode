/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #10 */

#include <iostream>
using namespace std;

/* Algorithm: calcualte the total hours worked based on the weather specifications
1. 5 hours of work rainy day, 4 hours of work cold day and 8 hours of work sunny day
mulitply the number of each respective type of day with the hours worked 5*cold + 4*cold + 8*sunny
2. multply the sum of this value by 10 dollars earned per hour
Input parameters: rainyDay (int), coldDay (int), sunnyDay (int)
Output: no print out
Returns: salary earned */

int calculateSalary(int rainyDay, int coldDay, int sunnyDay) {
    int hoursWorked;
    hoursWorked = (5*rainyDay) + (4*coldDay) + (8*sunnyDay);
    int salary = 10* hoursWorked;
    // cout<< "The worker worked " << rainyDay << " rainy days, " << coldDay << " cold days and "
    // << sunnyDay << " sunny days. Totaling to a salary of $" << salary << endl;
    
    return salary;
    
}

int main () {
    //test1
    //expected output: Totaling to a salary of $2090
    calculateSalary(5,8,19);
    //test2
    //expected output: Totaling to a salary of $330
    calculateSalary(1,1,3);
}