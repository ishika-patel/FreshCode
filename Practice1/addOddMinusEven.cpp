// FOR FOR LOOPS, DO NOT NEED I++ DUMMY
#include <iostream>
#include <string.h>
using namespace std;

// Write a function addOddMinusEven that takes two integers indicating
// the starting point and the end point. Then calculate the sum of all the odd
// integers minus the sum of all even integers between the two points. The calculation
// includes the starting point but excludes the end point.
// You can always assume the starting point is smaller than the end point.

int addOddMinusEven( int start, int end) {
    int odd = 0;
    int even = 0;
    for(int i = start; i<end; i++) {
    
    if (i%2==0){
        even = even +i;
    }
    
    if(i%2 != 0) {
        odd = odd + i;
    }
}
    int total = odd - even;
}

int main() {
    cout << addOddMinusEven(1, 7) << endl;
}