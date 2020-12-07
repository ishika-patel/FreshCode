#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;
/*Write a function similarity that takes in 2 arrays of int type and their sizes 
and returns true if the two arrays are identical and returns false if two arrays are not same.
bool similarity(int arr1[ ], int size1, int arr2[], int size2)
*/

bool similarity(int arr1[], int size1, int arr2[], int size2) {
    int similarityCount = 0;
    
    if (size1 != size2){
        return false;
    }
    else {
         for (int i = 0; i<size1; i++) {
             if(arr1[i] != arr2[i]){
                 similarityCount++; //add to this if the values are not similar
             }
         }
         if (similarityCount ++ != 0) {
             return false;
         }
    return true;
    }
}