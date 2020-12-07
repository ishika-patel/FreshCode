// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 3

#include <iostream>
#include <string>
#include <math.h>
#include "Book.h"
using namespace std;

int main(){
    //test1
    //test default constructor
    // expected results:two empty lines.
    Book b1 = Book();
    cout << b1.getTitle() << endl;
    cout << b1.getAuthor() << endl;
    
    //test2
    // checking setter for author
    // expected output: is this the author?
    Book b3 = Book();
    string a = "is this the author?";
    b3.setAuthor(a);
    cout << b3.getAuthor() << endl;
}