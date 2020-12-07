#include <iostream>
#include <string>
using namespace std;


// Write a function sumOfMultiples, that inputs two integers - seed and cap. The function should return the sum of all the multiples of seed present between 1 and cap (both inclusive).
// Your function should be named sumOfMultiples.
// Your function has two parameters in the order:
// seed: integer argument whose multiples need to be summed.
// cap: integer argument indicating the upper limit of the multiples to be added.
// Your function should return the sum of the multiples: an integer value.
// Your function should not print/output anything

// Examples:  
// For the input arguments sumOfMultiples(6, 20), the function should return 36. (Explanation: the multiples of 6 between 1 and 20 are 6, 12 and 18. The sum of which being 36).

 int sumOfMultiples(int seed, int cap) {
int sum = 0;
if (seed==0){
    return 0;
}
else if (seed<0){
    return 0;
}
else {
     for (int i =1; i<=cap; i++) {
        if(i%seed ==0){
            sum += i;
        }
 }
return sum;
 }
 }
 
 int main(){
     sumOfMultiples(6,20);
 }