// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 5

#include <iostream> 
#include <fstream>
#include <string.h>
#include "Book.h"
using namespace std;

/* Algorithm: a function that prints the arrays from the readBooks function. read books pulls from book objects.
Input Parameters: Book books[], int numBooks
Output/printing: If the number of books is 0 or less than 0, print “No books are stored”
if there are books “Here is a list of books by <author>” and the book objects are printed
Returns: none
*/

void printAllBooks (Book books[], int numBooks) {
   if (numBooks <= 0) { // to check if the arrays are filled
       cout << "No books are stored" << endl;
   }
   else { // if the arrays are filled then the arrays will be printed using a for loop
       cout<< "Here is a list of books" << endl;
       for (int i = 0; i<numBooks; i++) {
           cout << books[i].getTitle() << " by " << books[i].getAuthor()<< endl;
       }
    }
}

int main(){
    //test1
    // expected output: no books are stored
    Book book[10];
    printAllBooks(book, 0);
    
    // test2
    //expected output:
        // Here is a list of books
        // Calculus by Gottfried Leibniz
        // Algebra by Alan Turing
        // Physics by Isaac Newton
    Book books[3];
    
    // putting books in the books array
    books[0].setTitle("Calculus");
    books[0].setAuthor("Gottfried Leibniz");
    
    books[1].setTitle("Algebra");
    books[1].setAuthor("Alan Turing");
    
    books[2].setTitle("Physics");
    books[2].setAuthor("Isaac Newton");
    
    printAllBooks(books, 3);
    return 0;
}