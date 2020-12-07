#include <iostream>
#include <string.h>
using namespace std;

//set precision -> cout.precision(precision number)

// takes two floating numbers and one operator and prints out the answer based on arithmetic.
// Assume that there are no overflow, underflow and division by zero cases.

// Your function should be named calculator
// Your function takes three parameters: two double numbers and one char operator
// Your function does not return anything
// Your function prints answer in the format specified below
// Your function should set precision point to 2

double calculator( double n1, double n2, char arithmetic){
    switch(arithmetic){
        case ('+'):
        cout.precision(2);
            cout << n1 << " + " << n2 <<" = " << n1 + n2 << endl;
            break;
        case ('-'):
        cout.precision(2);
            cout<<  n1 << " - " << n2 <<" = " << n1 - n2 << endl;
            break;
        case ('/'):
        cout.precision(2);
            cout<<  n1 << " / " << n2 <<" = " << n1 / n2 << endl;
            break;
        case('*'):
        cout.precision(2);
            cout<<  n1 << " * " << n2 <<" = " << n1 * n2 << endl;
            break;
        default:
            cout<< "Invalid operator!" << endl;
            break;
    }
}

int main() {
    calculator(3, -7, '+');
}

#include <iostream>

using namespace std;

 

// void showMenu ();
// int getOption();
// int getNumbers();
// int addNumbers();
// int divideNumbers();
// int subtractNumbers();
// int multiplyNumbers();
// void displayResults();
 

// void showMenu ()
// {
// cout<<" 1. Select 1 to add two numbers."<<endl;
// cout<<" 2. Select 2 to divide two numbers. " <<endl;
// cout<<" 3. Select 3 to subtract two number. " <<endl;
// cout<<" 4. Select 4 to multiply two number. " <<endl;
// }

 

// int getOption (int selection)
// {
// cin>>selection;
// return selection;
// }


// void getNumbers(int& num1, int& num2)
// {
// cout<<"Enter two numbers: ";
// cin>>num1 >>num2;
// }

 
// int addNumbers(int num1, int num2, int& sum)
// {
// sum=num1+num2;
// return sum;
// }

 
// int divideNumbers(int num1, int num2, int& sum)
// {
// sum=num1/num2;
// return sum;
// }


// int subtractNumbers(int num1, int num2, int& sum)
// {
//     sum=num1-num2;
//     return sum;
// }


// int multiplyNumbers(int num1, int num2, int& sum)
// {
//     sum=num1 * num2;
//     return sum;
// }

 

// void displayResults(int num1, int num2, int& sum)
// {
//     cout<<num1 << " + " <<num2 << " = " <<sum <<endl;
// }
