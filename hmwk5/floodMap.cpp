// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 5

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm: the function prints out a “map” of which points in the array are below or above the water level.
The function takes a two-dimentional array where each element indicates the height of the terrain at a particular point (assume that there are 4 columns).
Each point at or below the water level will be represented with a * and each position above the water level will be represented with an underscore _.
Input Parameters: double array[][4], int rows, double currentWaterLevel
Output/printing: either an * or an _
Returns: none
*/

void floodMap(double array[][4], int rows, double currentWaterLevel) {
    for(int i = 0; i<rows; i++) { //runs through the rows
        for (int j = 0;j <4 ; j++){ //runs through the columns
            if (array[i][j] > currentWaterLevel){ //checks to see if the double stored is above water level
                cout << "_" ;
            }
            if (array[i][j] <= currentWaterLevel) { //checks to see if the double stored is below or equal to water level
                cout << "*" ;
            }
        }
        cout << endl;
    }
}

int main() {
    //test1
    //expected output: *_*_
    double map[1][4] = {{5.0, 7.6, 3.1, 292}};
    floodMap(map, 1, 6.0);
    
    //test2
    //expected output **** ****
    double maps[2][4] = {{0.2, 0.8, 0.8, 0.2}, {0.2, 0.2, 0.8, 0.5}};
    floodMap(maps, 2, 1.0);
}