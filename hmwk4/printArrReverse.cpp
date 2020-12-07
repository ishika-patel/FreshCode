// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - Problem 2

#include <iostream>
#include <string>
using namespace std;

/* Algorithm prints the numbers in the given array in the reverse order
Input Parameters: integer array and length of the array 
Output/printing: print out each value in the array, in reverse order
Returns: none
*/

void printArrReverse(int array[], int length){

    while (length>0){
        cout << array[length-1] << endl; // length - 1 because arrays are accessed using index
        length--; // decrement length by 1 to move to the next stored value in the array
    }
}
 
int main() {
    //test 1
    // expected output: 7, 9, 1
    int arr[] = { 1, 9, 7 };
    int len = 3;
    printArrReverse(arr,len);
    cout<< endl;
    
    //test 2
    // expected output: 
    int negarr[] = {-1, -8, -78};
    int length = 3;
    printArrReverse(negarr, length);


}