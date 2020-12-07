// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Practicum 1 - Problem 4

#include <iostream>
#include <string>
using namespace std;

void printSeriesSkipFour(int maxValue){
    int sum = 0;
    int i =1;
    while (i <= maxValue){
        if (i%4 != 0){
            // If the number is not divisible by 4, add it to sum and print
            cout << i;
            sum += i;
        }
        else {
            // Print 0 when number is divisible by 4
            cout << "0";
        }
        if (i != maxValue){
            // This check is added to not print the last '+'
            cout << " + ";
        }
        i++;
    }
    cout << endl;
    cout << "Result of the series is " << sum << endl;
}

int main(){
    printSeriesSkipFour(10);
}