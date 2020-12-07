#include <iostream>
#include <string>
using namespace std;

// takes a non-negative integer and returns the product of its digits. 
// %10 to get the last number 
// and divide by 10 to remove it

int prodDigits( int number){
    int final = 1;
    if (number == 0){
        return 0;
    }
        while (number>0) {
        int multiplyNumber = number % 10;
        //cout << multiplyNumber << endl;
        final = final * multiplyNumber;
        number = number/10;
    }
   // cout<< final<< endl;
   return final;
}

int main(){
    prodDigits(12);
}