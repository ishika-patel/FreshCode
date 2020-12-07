#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/*
Athletes must have an age in the range [14, 18] including both the values, in order to participate in the Youth Olympic Games. Write a function printIneligibleAthletes that takes in two arrays, one of the athlete names and one of their ages,
and prints out all the eligible athletes.
Your function should have three parameters in this order:
an array of strings which contains the athletes' names
an array of floating point (as double) numbers containing the athletes' ages
an integer that gives the number of elements in the arrays of athlete names and ages
Your function should not return anything.
*/

void printIneligibleAthletes(string name[], double age[], int size) {
    for (int i = 0; i<size; i++) {
        if (age[i]<14 || age[i]>18){
            cout << name[i] << ", " << age[i] << endl;
        }
    }
}