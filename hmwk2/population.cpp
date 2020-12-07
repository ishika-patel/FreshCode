/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #8 */

#include <iostream>
using namespace std;

/* Algorithms: provides info on US poopulation after a year of differnt changes
1. There is a birth every 8 seconds
2. There is a death every 12 seconds
3.There is a new immigrant arriving in the US every 27 seconds 
Input parameters: initial population (int type)
Output: final population after all three rates are applied
Returns: none */

int population(int initialPop) {
    
    int seconds_in_year = 365*24*60*60; //seconds_in_year is a conversion of 365 days to seconds
    int birth = 0;
    int death= 0;
    int immigrant= 0;
    int seconds_elapsed=0;

while(seconds_elapsed < seconds_in_year) {
   if (seconds_elapsed % 8 == 0) {
       birth++;
   }
   if (seconds_elapsed % 12 == 0) {
       death++;
   }
   if (seconds_elapsed % 27 == 0) {
      immigrant++; 
   }
   seconds_elapsed++;
}

    int final = initialPop + birth - death + immigrant;
    return final;
    
}

int main(){
    //test1
    //Expected Result: 3482000
    population(1000000);
    //test2
    //Expected Result: 14847478
    population(12365478);
}