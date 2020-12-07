// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Practicum 1 - Problem 3

#include <iostream>
#include <string>
using namespace std;

double smallestNumber (double number1, double number2, double number3){
    double smallest = number1;
    if (number2 < smallest){
        smallest = number2;
    }
    else{ 
        smallest = smallest;
    }
    if (number3 < smallest){
        smallest = number3;
    }
    else {
        smallest = smallest;
    }
return smallest;
}

int main() {
  cout<<  smallestNumber(4,9,2.5) << endl;
  
}