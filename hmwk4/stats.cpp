// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - Problem 3

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// GET HELP ON SET PRECISION

/* Algorithm: this function computess and prints the minimum value in the array, the maximum value in the array and the average value of all the values in the array.
min: loop through the array to find the smallest value using  less than symbol
max: loop through the array to find the largest value usign greater than symbol
average: loop through to add all the values in the array then divide by number of values
Input Parameters: An array of type double and The number of elements in the array, type int
Output/printing: minimum, maximum and average with set precision 0
Returns: none 
*/

void stats(double array[], int length){
    
    double min = array[0];
    for(int i = 0; i<length; i++){
        if (array[i] < min) {
            min = array[i];
        }
        else{
            min = min;
        }
    }
    cout << "Min: " << fixed << setprecision(2) << min << endl;
   
    
    double max = 0.00;
        for(int i = 0; i<length; i++){
        if (array[i] > max) {
            max = array[i];
        }
        else{
            max = max;
        }
    }
    
    cout << "Max: " << fixed << setprecision(2) << max << endl;
    
    double arrTotal = 0;
    for(int i = 0; i<length; i++){
        arrTotal = arrTotal + array[i];
        }
    double avg = arrTotal / length;
    cout << "Avg: " << fixed << setprecision(2) << avg << endl;
    
}

int main() {
    //test 1
    //expected output: Min: 0.00 \n Max: 9.00 \n Avg: 4.50
    double arr[] = {0,1,2,3,4,5,6,7,8,9};
    int len = 10;
    stats(arr, len);
    
    //test 2
    // expected output:Min: 0.21 \n Max: 154.12 \n Avg: 69.98
    double arr2[] = {.2134, 123.23, 2.345, 154.124};
    int len2 = 4;
    stats(arr2, len2);
}