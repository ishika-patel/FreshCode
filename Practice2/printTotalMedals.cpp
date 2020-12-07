#include <iostream> 
#include <string>
using namespace std;

/*
Write a function printTotalMedals that takes an array for Olympic sports and arrays for gold, silver, and bronze medals and prints the total number of medals by discipline.

Your function should take 5 parameters:
an array of strings disciplines
an array of ints representing the number of gold medals
an array of ints representing the number of silver medals
an array of ints representing the number of bronze medals 
an integer size for the size of the arrays 
Edge cases:

If the size < 1, print "Invalid size. Size must be at least 1."

If 1 ≤ size < the capacity of the arrays, then just print out the relevant output until you reach the size
 elements. For example, if the disciplines array is {"Figure skating", "Breakdancing", "Lightsaber dueling"} but size = 2, then only the output for Figure skating and Breakdancing are printed to the screen.
*/

void printTotalMedals (string discipline[], int gold[], int silver[], int bronze[], int size){
    if (size < 1) {
        cout << "Invalid size. Size must be at least 1." << endl;
    }
    else {
    for (int i =0; i<size; i++) {
        cout << discipline[i] << ": " << gold[i] + silver[i] + bronze[i] << endl;
    }
    }
}