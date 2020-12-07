#include <iostream>
using namespace std

// Write a function numberDigits that reads an integer and prints how many digits the number has, 
//by checking whether the number is ≥ 10, ≥ 100, and so on. 
//(Assume that all integers are less than ten billion.)
//If the number is negative, first multiply it with -1

void numberDigits(int number) {
    cout<< "The number " << number ; //print here bc if at end, the num would be modified from the while loop
    int count = 0;
    if (number==0){
        count = 1;
    }
    
    if (number<0){
        number = number*-1;
    }

    while (number>0) {
        number = number/10;
        count++;
    }
    cout<< " has " << count << " digits." << endl;
 }
 
 
 