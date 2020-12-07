/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #9 */

#include <iostream>
using namespace std;

/* Algorithms: the carnot efficincy is calcuated, the maximum efficiency of heat engines between two temps
carnot efficiency = 1- (temp in cool reservoir/temp in hot reservoir)
Input parameters: tempHot (int) and tempCold (int)
Output: carnot efficiency
Returns: the carnot efficiency as double */

double carnot(int tempCold,int tempHot) {
    
     double carnotValue = 1.0 - ((double)tempCold/tempHot) ; // carnot value equation

     return carnotValue;

}

int main() {
    //test1
    //Expected result: 0.854545
    carnot(160,1100);
    //test2
    //Expected result: -0.0909091
    carnot(12,11);
}