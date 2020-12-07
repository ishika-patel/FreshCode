// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 6

#include <iostream> 
#include <fstream>
#include <string.h>
#include "Book.h"
using namespace std;

/* Algorithm: This function checks to see if the user's books by their favorite author from the book objects
You can assume that the number of elements in both arrays is the same. The number of books represents the number of elements in each array.
Input Parameters: Book books[], int numBooks, string authorName
Output/printing: "No books are stored" if numBooks is zero, and returns the list of books by an author if the author is found
Returns: none
*/

void printBooksByAuthor(Book books[], int numBooks, string authorName) {
     if (numBooks <= 0) { // to check if the arrays are filled
       cout << "No books are stored" << endl;
   }
   else { 
       int count = 0;
       for(int i =0; i < numBooks ; i++){ 
          if (books[i].getAuthor() == authorName){ // checks to see if the author shows up in the list
              count++; // if the author is in the array, the count is increased
          }
          else {
              count = count; 
          } 
       }
       if (count>0) { // this runs if the author has been spotted in the array
           cout << "Here is a list of books by " << authorName << endl;
           for(int i =0; i < numBooks ; i++){
               if (books[i].getAuthor() ==  authorName) {
                   cout << books[i].getTitle() << endl; //prints out the title if the selected author is found
               }
            }
       
       }
       if (count == 0) { //otherwise if the author is not found in the array, there are no books is printed
           cout << "There are no books by " << authorName << endl;
       }
    }
}

int main() {
    //test1
    // expected output: no books are stored
    Book listOfBooks[] = {};
    int numberOfBooks = 0;
    string authors = "Dan Brown";
    printBooksByAuthor(listOfBooks, numberOfBooks, authors);
    
    //test2
    //Expected output:
        // Here is a list of books by Author A
        // Book 1
        // Book 2
        // Book 3
    Book book1 = Book("Book 1", "Author A");
    Book book2 = Book("Book 2", "Author A");
    Book book3 = Book("Book 3", "Author A");
    Book listOfBook[] = {book1, book2, book3};
    int numberOfBook = 3;
    string author = "Author A";
    printBooksByAuthor(listOfBook, numberOfBook, author);
}
