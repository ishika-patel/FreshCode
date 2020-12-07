// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - Problem 4

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* Algorithm: this function swaps the first and last elements of the given array of integers
- access the first array element and reassign it to the value stored in the final array element
Input Parameters: An array of integers and The number of elements in the array, type int
Output/printing: none
Returns none 
*/

void swapFirstLast(int array[], int length){
    
    int swap = array[0]; // saves the value in the first element
    
    array[0] = array[length-1]; // reassigns the value in the first element to that in the last
    array[length-1] = swap; // reassined the value in the last with the initial saved value
}

int main() {
    //test 1
    // expected output if printed: 30 \n 20 \n \10
    int arr1[3] = {10, 20, 30};
    swapFirstLast(arr1, 3); 
    //prints the array 1
    for (int i = 0; i <3; i++){ 
    cout << arr1[i]<< endl;
    }
    
    cout << endl;
    
    //test 2
    // expected output if printed: 10
    int arr2[] = {10};
    swapFirstLast(arr2, 1);
    //prints array 2
    for (int i = 0; i <1; i++){ 
    cout << arr2[i]<< endl;
    }
}