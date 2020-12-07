// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - EC

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


/* Algorithm: this function takes an array of integers, number of elements n, and number of shifts k. 
The function should shift each element in the array by k positions. 
If k is greater than n, each element should be shifted by k mod n positions.
Input Parameters: an array of integers, number of elements n, and number of shifts k. 
Output/printing: “No shift”, if the number of shifts is negative or 0.
Returns: none 
*/

void shiftElements(int array[], int numberOfElements, int shift) {

int lastElement = 0;

    if (shift <=0 ){ //checks to see if the number of shifts is positive
        cout << "No shift" << endl; // if negative or 0, there is no shift
    }
    
    if (shift > 0 && shift> numberOfElements){ // If shift is greater than numberOfElements, each element should be shifted by shift mod numberOf Elements positions.
        shift = shift % numberOfElements;
    }

    for (int i = 0; i < shift ; i++) { // this will allow the elements to be moved shift times
            lastElement = array[numberOfElements-1]; // to remember last element so it doesnt disappear when array is shifted down
            
            for(int j= numberOfElements-1; j>=0; j--) { //shifts the array one element at a time
            array[j] = array[j-1]; //move all element to the right except last one which is repalced 
        }
        array[0] = lastElement; // reassign the first value to the last
        }
}

    
// for (int i= 0; i< numberOfElements; i++) {
//   cout << array [i] << endl; 
// }
// }


int main() {
    //test 1
    // expected result: 30, 10, 20
    int arr1[3] = {10, 20, 30}; 
    shiftElements(arr1, 3, 1); 

    //test 2
    // expected result : No Shift, 10, 20, 30, 40, 50
    int arr2[5] = {10, 20, 30, 40, 50};
    shiftElements(arr2, 5, -2);
}

