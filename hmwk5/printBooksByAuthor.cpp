// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 5 - Problem 4

#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/* Algorithm: This function checks to see if the user's books by their favorite author
You can assume that the number of elements in both arrays is the same. The number of books represents the number of elements in each array.
Input Parameters: string titles[], string authors[], int numBooks, string authorName
Output/printing: "No books are stored" if numBooks is zero, and returns the lsit of books by an author if the author is found
Returns: none
*/

void printBooksByAuthor(string titles[], string authors[], int numBooks, string authorName) {
     if (numBooks <= 0) { // to check if the arrays are filled
       cout << "No books are stored" << endl;
   }
   else { 
       int count = 0;
       for(int i =0; i < numBooks ; i++){ 
          if (authors[i] == authorName){ // checks to see if the author shows up in the list
              count++; // if the author is in the array, the count is increased
          }
          else {
              count = count; 
          } 
       }
       if (count>0) { // this runs if the author has been spotted in the array
           cout << "Here is a list of books by " << authorName << endl;
           for(int i =0; i < numBooks ; i++){
               if (authors[i] ==  authorName) {
                   cout << titles[i] << endl; //prints out the title if the selected author is found
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
    // No books by author A
    string book_titles[] = {"Book 1", "Book 2", "Book 3"};
    string book_authors[] = {"Author B", "Author C", "Author D"};
    int numberOfBooks = 3;
    string author = "Author A";
    printBooksByAuthor(book_titles, book_authors, numberOfBooks, author);
    
    //test2
    //two books by author A
    string titles[] = {"Book 1", "Book 2", "Book 3", "Book 4", "Book 5"};
    string authors[] = {"Author B", "Author C", "Author D", "Author A", "Author A"};
    int books = 5;
    string author1 = "Author A";
    printBooksByAuthor(titles, authors, books, author1);
}