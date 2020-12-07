// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 7

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* Algorithm: This function put together functions performed on Book objects
    1. Read 
        - enter book file name, print out total number of books
    2. Print all books
        - simply call on the function
    3. Print books by author
        - asks for an author name
    4. Quit
Based on these options the code will print out differnt items. assume teh max number of book objects in an array is 50
Input Parameters:
    1. Read books: file name
    2. Print all books
    3. Print books by author: author name
    4. Quit
Output/printing: prints respective function values 
Returns: none
*/


int split(string line, char delimiter, string array[], int arraySize){
    
    int count =0; // this allows us to return the counter
    int start =0; // this will track where in the string we are as we are looking for the delimiter
    
    if (line == "") { //checks to see if the parameter for string is empty
        return 0; //if it is, returns 0 and exits code
    }
    if (line[line.length()-1] == delimiter) { //checks to see if the last value in the string is the delimiter
        line = line.substr(0, line.length()-1); // if it is, the delimiter at the end is cut off and the process is continued
    }
    
    for (int i = 0; i<line.length(); i++) {
        if (line[i] == delimiter) { // we are now searching for the delimiter
            
            if (count == arraySize) { // this is a fail safe to make sure that the count is not greater than the value that the array can hold
                return -1; //If the string is split into more pieces than the array of string can hold return -1
            }
            else {
                string arrayInput = line.substr(start, i-start); // int i is where the delimiter was found, thefore we want to print the strin from the beinning to int i
                if (i-start !=0 && start+1 !=0) { // the first condition checks to make sure two delimiters are together, the second condition checks the starting position
                    array[count] = arrayInput;  // store the value that is extrapolated from arrayInput
                    count ++; // add one to the count to return the number of words at the end, note that count doesnt include the very final word
                }
                }
            start = i + 1; // becuase you are moving past the whole word so you have to move up to i where the delimiator was and 1 past i so you pass the delimiter
            }
         }
         
         string arrayInput = line.substr(start, line.length() - start); 
             if (arrayInput != "") {// keeps the process going until the string itself ends
                 array[count] = arrayInput;
             }
         return ++count; //preincrement in order to account for index vs length discrepecy
         }


int readBooks(string fileName, Book books[], int numBookStored, int size) {
    if (numBookStored == size) {
        return -2;
    }
    
    string line; // declared to hold the getline values
    string tempArray[2] = {"", ""}; // this is the array that the split function stores in
    ifstream file; //says there is a file we will access and we are taking data from it
    
    file.open(fileName); //opens the file
    
    if(file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
           if (line != "" && numBookStored<size) { //checks to make sure array is not full nor is the line empty
             split(line, ',', tempArray, 2); 
             books[numBookStored].setAuthor(tempArray[0]); //assign the split function array to the apporopriate author or title arrays of the book objects
             books[numBookStored].setTitle(tempArray[1]);
             numBookStored++;  //increment counter if a varible is stored
           }
        }
        
    }
    else {
        return -1;
    }
    file.close();
    return numBookStored;
}

void printAllBooks (Book books[], int numBookStored) {
   if (numBookStored<=0) { // to check if the arrays are filled
       cout << "No books are stored" << endl;
   }
   else { // if the arrays are filled then the arrays will be printed using a for loop
       cout<< "Here is a list of books" << endl;
       for (int i = 0; i<numBookStored; i++) {
           cout << books[i].getTitle() << " by " << books[i].getAuthor()<< endl;
       }
    }
}

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

void printMenu(){ // prints the menu that users see
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Print all books" << endl;
    cout << "3. Print books by author" << endl;
    cout << "4. Quit" << endl;
}

void hw6() {
    string fileName; // declaring the file that will be looked through
    Book books[50]; // declare the array with max 50 array boxes
    int size = 50;
    int numBookStored = 0;
    string userInput; 

while(getline(cin,userInput)){
    printMenu();
    if (stoi(userInput) == 1) {
        cout<< "Enter a book file name:" << endl;
        getline(cin,fileName);
        numBookStored = readBooks(fileName, books, numBookStored, size); // we need to reassigning the numBooksStored so it is not zero in all the other options
        
        if(numBookStored == -1) {
             cout<< "No books saved to the database." << endl;
        }
        
        else if(numBookStored == -2) {
            cout << "Database is already full. No books were added." << endl;
        }
        
        else if(numBookStored==size){
            cout<< "Database is full. Some books may have not been added." << endl;
        }
        
        else {
        cout<< "Total books in the database: " << numBookStored << endl;
        }
    }

    if (stoi(userInput) == 2) { //use s to i becuase you are asking user to input a string number value
        printAllBooks (books, numBookStored);
    }

    if (stoi(userInput) == 3) {
        string userAuthor;
        cout << "Enter name of author:"<< endl;
        getline(cin,userAuthor); // use get line in order to get the whole author name
        
        printBooksByAuthor(books, numBookStored, userAuthor);

    }
    
    if (stoi(userInput) == 4) {
       cout << "Good bye!" << endl;
       return;
    }

    if(stoi(userInput) !=1 && stoi(userInput) !=2 && stoi(userInput) !=3 && stoi(userInput) !=4) {
        cout << "Invalid input." << endl;
    }
}
}

int main(){
    hw6();
}