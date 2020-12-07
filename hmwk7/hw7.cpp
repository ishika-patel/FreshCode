#include <iostream> 
#include <fstream>
#include <string.h>
#include <cctype>
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"

using namespace std;

/* Algorithm: This function put together functions performed on book and user objects, the menue shows which funcitons should be performed
quit to stop teh simuation
    1. read books
    2. read ratings
    3. get rating
    4. find number of books
    5. get average rating
    6. quit
Based on these options the code will print out differnt items. assume teh max number of book objects in an array is 50
Input Parameters:
    1. read books
    2. read ratings
    3. get rating
    4. find number of books
    5. get average rating
    6. quit
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

int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize, int maxColumns){
    int num = numUsersStored;
    if (num >= usersArrSize) { // checks case 2: numUsersStored is equal to usersArrSize upfront
             return -2; 
    }
    
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    file.open(fileName); //opens the file
    
    if (!(file.is_open())) { //checks case 4: file cannot open
        return -1;
    }
    
    else if (file.is_open()) { //checks to see if file is open
        while (getline(file,line) && num<usersArrSize) { //reads line by 
            int count = 0; 
            if (line != "") { //checks to make sure array is not full nor is the line empty
                string testArray[maxColumns+1]; // plus one to go through all of the column numbers

                split(line, ',', testArray, maxColumns);  // used to separate the rows
                
            
                for(int c =0; c<maxColumns; c++){   // checks to see how many columns are occupied so that the program doesnt overload when "copying" the columns
                    if(testArray[c] != "") { 
                        count ++; // if thre is something stored the count is incremented
                    }
                    else {
                        count = count; // otherwise the count is kept at count
                    }
                }
                 users[num].setUsername(testArray[0]); //sets the username using the data from the testarray given from split
                 
                for(int j = 1; j<=count; j++){
                    if(testArray[j]!="")
                    users[num].setRatingAt(j-1,stoi(testArray[j])); //inserts the testArray into the "official" array and stoi converts string to decimal
                }
                 num++;  //increment counter if a varible is stored
           }
        }
    }
    
    file.close();
    return num; // return number of books stored
}

string makeLower(string s){
    char c;
    string lowerCase = "";
    
    for (int i=0; i<s.length(); i++) {  //goes through all the characters in the array
        c = s[i]; //accesses the single character the the index
        c = tolower(c); //makes it lowercase
        lowerCase = lowerCase + c; //adds it to the end
    }
    return lowerCase; //returns the lowercase string
}

int getRating(string username, string title, User users[], Book books[], int numOfUser, int numOfBook){
    int countUser= 0;
    int accessUser=-1;
    for (int i  = 0; i<numOfUser; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) {
            countUser++;
            accessUser = i;
        }
    }
    if (countUser==0) { //if no users were found
        return -3; //return -3 and stop
    }
    else {
        int countBook = 0;
        int accessBook=-1;
        for (int i = 0; i< numOfBook; i++){
            if(makeLower(books[i].getTitle()) == makeLower(title)) {
                countBook++;
                accessBook = i;
            }
        }
        if (countBook==0) {
            return -3;
        }
        else {
            return users[accessUser].getRatingAt(accessBook);
        }
    }
}

int getCountReadBooks(string username, User users[], int numOfUser, int numOfBook) {
    int countUser= 0;
    int accessUser=-1;
    for (int i  = 0; i<numOfUser; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            countUser++; // if the user is present then the user count is incremented
            accessUser = i; //when the user is found the index they are found at are stored
        }
    }
    if (countUser==0 || numOfBook == 0 ) { //if no users were found
        return -3; //return -3 and stop
    }
    else {
        int countBook = 0;
        for (int i = 0; i< numOfBook; i++){ // goes thrugh all book objects to see if teh title is present
            if(users[accessUser].getRatingAt(i)!= 0) { //checks to see if the lowercase verison of the book object equsls th lowercase of the book seached for
                countBook++; //if book is found the count of books is incremented
            }
            else{ 
            countBook = countBook;
            }
        }
            return countBook; // if user and book were found, return the rating!
        }
}

double calcAverageRating(User users[], Book books[], int numOfUser, int numOfBook, string title) {
    double countBook= 0;
    double accessBook=-1;
    double sum = 0;
    double countUser = 0;
    
    for (int i  = 0; i<numOfBook; i++){
        if(makeLower(books[i].getTitle()) == makeLower(title)) { //goes through all book objects to see if the book is present, lowercase font
            countBook++; // if the book is present then the book count is incremented
            accessBook = i; //when the book is found the index it is found at is stored
        }
    }
    if (countBook==0 || numOfUser == 0) { // if the book is not found or if there are no users them return -3
        return -3; //return -3 and stop
    }
    else {
        for (int i = 0; i< numOfUser; i++){ // goes thrugh all user objects to add all the rating of the book together
            if (users[i].getRatingAt(accessBook) !=0){ //only add values that are NOT zero
                sum = sum + users[i].getRatingAt(accessBook);
                countUser++; // if the rating is zero the user shouldn’t be counted in calculating the average so we keep this in the if statement
            }
        }
         if (countUser==0) { // if no users have read the book, return 0
            return 0;
        }
    }
        return sum / countUser; // return the average rating
}

void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Get rating" << endl;
    cout << "4. Find number of books user rated" << endl;
    cout << "5. Get average rating" << endl;
    cout << "6. Quit" << endl;
}

void hw7() {
    string bookFileName; // declarisng the file that will be looked through
    string userFileName;
    Book books[50]; // declare the array with max 50 array boxes
    User users[100];
    int size = 50;
    int numBookStored = 0;
    int numUsersStored = 0;
    int getRatingStored = 0;
    int getCountReadBooksStored = 0;
    double averageRatingStored = 0.0;
    string userInput; 

while(true){
    
    printMenu();
    getline(cin,userInput);
    if (stoi(userInput) == 1) {
        cout<< "Enter a book file name:" << endl;
        getline(cin,bookFileName);
        int returnValue = readBooks(bookFileName, books, numBookStored, 50); // we need to reassigning the numBooksStored so it is not zero in all the other options
        
        if(returnValue == -1) {
             cout<< "No books saved to the database." << endl;
        }
        
        else if(returnValue == -2) {
            cout << "Database is already full. No books were added." << endl;
        }
        
        else if(returnValue==size){
            numBookStored = returnValue;
            cout<< "Database is full. Some books may have not been added." << endl;
        }
        
        else {
            numBookStored = returnValue;   
            cout<< "Total books in the database: " << numBookStored << endl;
        }
    }

    if (stoi(userInput) == 2) { //use s to i becuase you are asking user to input a string number value
        cout<< "Enter a user file name:" << endl;
        getline(cin,userFileName);
        int returnValue = readRatings(userFileName, users, numUsersStored, 100, 50);
        
        if(returnValue == -1) {
             cout<< "No users saved to the database." << endl;
        }
        
        else if(returnValue == -2) {
            cout << "Database is already full. No users were added." << endl;
        }
        
        else if(returnValue==100){
            numUsersStored = returnValue;
            cout<< "Database is full. Some users may have not been added." << endl;
        }
        else {
            numUsersStored = returnValue;
            cout<< "Total users in the database: " << numUsersStored << endl;
        }
    }

    if (stoi(userInput) == 3) {
        string userName;
        cout << "Enter a user name: "<< endl;
        cin.clear();
        getline(cin,userName); // use get line in order to get the whole author name
        string bookTitle;
        cout << "Enter a book title: "<< endl;
        cin.clear();
        getline(cin,bookTitle); // use get line in order to get the whole author name
        
        getRatingStored = getRating(userName, bookTitle, users, books, 100, 50);
        
        if(getRatingStored == 0) {
             cout<< userName << " has not rated " << bookTitle << endl;
        }
        
        else if(getRatingStored == -3) {
            cout<< userName << " or " << bookTitle << " does not exist." << endl;
        }
        
        else {
            cout<< userName << " rated " << bookTitle << " with " << getRatingStored << endl;
        }
    }
    
    if (stoi(userInput) == 4) {
        string userName;
        cout << "Enter a user name:"<< endl;
        getline(cin,userName); // use get line in order to get the whole author name
        getCountReadBooksStored = getCountReadBooks(userName, users, 100, 50);
        
        if(getCountReadBooksStored == 0) {
             cout<< userName << " has not rated any books."<< endl;
        }
        
        else if(getCountReadBooksStored == -3) {
            cout<< userName << " does not exist." << endl;
        }
        
        else {
            cout<< userName << " rated " <<  getCountReadBooksStored << " books." << endl;
        }
        continue;
    }
    
    if (stoi(userInput) == 5) {
        string bookTitle;
        cout << "Enter a book title:"<< endl;
        getline(cin,bookTitle); 
        averageRatingStored =  calcAverageRating(users,books, 100, 50, bookTitle);
        
        if(averageRatingStored == -3) {
             cout<< bookTitle << " does not exist."<< endl;
        }
        
        else {
            cout<< "The average rating for " <<  bookTitle << " is " << averageRatingStored<< endl;
        }
    }
    
    if (stoi(userInput) == 6) {
        cout << "Good bye!" << endl;
        return;
    }

    if(stoi(userInput)< 1 || stoi(userInput) > 6) {
        cout << "Invalid input." << endl;
    }
}
}

int main(){
    hw7();
}