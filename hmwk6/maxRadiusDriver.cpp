// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 2

#include <iostream>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

/* Algorithm: this function calls on the Planet class and determines what the max value of the radius is and which index that fall at
1. run through to determine the max value
2. each time the consecutive number is bigger, reassign the max and the index where it falls
Input Parameters: Planet array[], int sizeArray
Output/printing: none
Return: index where the max is.
*/

int maxRadius(Planet array[], int sizeArray) {
    double max = 0.0; // the maximum value within the array is stored here
    int index = 0; // this is the value returned of the index where the max value is
    
    if(sizeArray==0){
        return -1; // if the array is empty return -1, exit program
    }
    else {
        if (sizeArray>0){ //if array is not empty
            for(int i = 0; i<sizeArray; i++){ // go through the entire array
               if(array[i].getRadius() > max) {
                    max = array[i].getRadius(); //changes to the newer max value 
                    index = i; // when the new max is determeined the index where the max is changes too
                }
            }
        }
    }
return index; //return the index where the max is
}

int main() {
    //test1
    //expected outcome: Bird World, 4321, 3.37941e+11
    Planet planets1[5];
    planets1[0] = Planet("On A Cob Planet",1234);
    planets1[1] = Planet("Bird World",4321);
    int user = maxRadius(planets1, 2);
    cout << planets1[user].getName() << endl;
    cout << planets1[user].getRadius() << endl;
    cout << planets1[user].getVolume() << endl;
    
    // test2
    //expected outcome: -1
    Planet planets[3];
    int idx = maxRadius(planets, 0);
    cout << idx << endl;
}