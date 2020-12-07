// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 2 - driver

#include <iostream> 
#include <fstream>
#include <string.h>
#include <cctype>
#include <math.h>
using namespace std;

/*Algorithm: make a library class with private data memebers and public member functions
    1. make private data members sizeBooks (const int 50), sizeUser (const int 100), books (Book []), users (Users[]), numBooks (int), numUsers (int)
    2. make a default constructor to set numBooks and numUsers to 0
    3. getSizeBook() returns sizeBook (int)
    4. getSizeUser() returns sizeUser (int)
    5. getNumBook() returns numBooks (int)
    6. getNumUsers() returns numUsers (int)
    7. readBooks(string) returns the toatl number of books in the books array (int)
    8. printAllBooks() prints books int he array (void)
    9. printBooksByAuthor() prints books written by the author in books array
    10. readRatings(string) returns the total number of users in the users array (int)
    11. getRating(string, string) returns user's rating for a book (int)
    12. getCountReadBooks(string) returns the number of books read by a user (int)
Output/printing: prints respective function values 
Returns: none

also include split function and make lower as helper functions
*/

#include <iostream> 
#include <fstream>
#include <string.h>
#include <cctype>
#include <math.h>
using namespace std;

class Book {
    private:
        std:: string title; 
        std:: string author;
    
    public:
        Book(); // default constructor
        Book(std:: string title_, std:: string author_); //parametrized constructor
        
        void setTitle(std:: string title_); // setting and getting title
        std:: string getTitle();
        
        void setAuthor(std:: string author_); // setting and getting author
        std:: string getAuthor();
};

Book:: Book() { //default constructor
        title = ""; 
        author = "";
}

Book:: Book(std:: string title_, std:: string author_){ //parmetrized constructor
    title = title_;
    author = author_;
}

void Book:: setTitle(std:: string title_){ //setting the private data member to the variable of title_ 
    title = title_;
}

std:: string Book:: getTitle(){
    return title;
}

void Book:: setAuthor(std:: string author_){ // setting the private data member to the variable of author_
    author = author_;
}

std:: string Book:: getAuthor(){
    return author;
}

class User {
    private:
        string username;
        int numRatings;
        const static int size = 50; //capacity of array is 50, a constant
        int ratings[50]; //number of elements should be size
    public:
        User(); //default constructor
        User(string username_, int ratings_[], int numRatings_); //parametrized constructo
        
        void setUsername(string username_); // sets username to username_
        string getUsername(); //returns username
        
        int getRatingAt(int index); // if index is larger than size or less than 0 return -2 otherwise return rating
        
        bool setRatingAt(int index, int value); // sets rating to int value at an int index, if index is withing boulds of array and value is 0-5
    
        void setNumRatings(int numRatings_);
        int getNumRatings();
        
        int getSize();
};

User:: User() { //default constructor
    username = ""; // username to an empty string
    numRatings = 0; // numRatings back to zero
    for(int i =0; i< size; i++){ //sets all emeents of ratings[] to 0
        ratings[i] = 0;
    }
}

User:: User(string username_, int ratings_[], int numRatings_){ //parametrized constructor
   if(numRatings_<=50) { // makes sure numRatings isnt greater than size
       
        username = username_; //sets username
        numRatings = numRatings_;//sets numratings to variable
        
        for(int i; i<size; i++) { //goes through the array to set the temp array to teh official array
            ratings[i] = ratings_[i];
        }
        
        if(numRatings_ != 50) { //fills in the other boxes after numRatings
            for(int i = numRatings_; i<size; i++){
                ratings[i] = 0;
            }
        }
   }
    else { //if numRatings is > size
        for(int i =0; i< size; i++){ //sets all emeents of ratings[] to 0
            ratings[i] = 0;
        }
    }
}
        
void User:: setUsername(string username_){ // sets username to username_
    username = username_;
}

string User:: getUsername(){ //returns username
    return username;
}

int User:: getRatingAt(int index){ // if index is larger than size or less than 0 return -2 otherwise return rating
    if(index>=size || index<0){
        return -1;
    }
    else {
        return ratings[index];
    }
}

bool User:: setRatingAt(int index, int value){ // sets rating to int value at an int index, if index is withing boulds of array and value is 0-5
    if((index>=0&& index<size) && (value>=0 && value<=5)) { //checks index and rating value
            ratings[index] = value;
            return true;
    }
    else { 
        return false;
    }
}

void User:: setNumRatings(int numRatings_){
    numRatings = numRatings_;
}

int User:: getNumRatings(){
    return numRatings;
}
        
int User:: getSize(){ //size is a constant
    return size;
}

class Library {
    private:
    // capacity of books array 
        const int sizeBook = 50;
    //capacity of users array
        const int sizeUser = 100;
    //array of book objects   
        Book books[50];
    // array of User objects;
        User users[100];
    //number of books in library database
        int numBooks;
    //numer of users in the library database
        int numUsers;
    
    public:
        Library(); // default constructor
        int getSizeBook(); 
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks(string fileName); //returns total number of books in array
        void printAllBooks(); 
        void printBooksByAuthor(string bookByAuthor); //prints all books by specific author
        int readRatings(string userFile); // returns a total number of users in the users array
        int getRating(string username, string bookTitle); // returns usrs rating for a specific book
        int getCountReadBooks(string username); // returns number of books read by a user
        void viewRatings(string username, int minVal); //prints books with a ratig graer than the minVal
        double calcAvgRating(string bookTitle); //returns average rating of specified book
        double calcAvgRatingByAuthor(string author); //returns average rating of specified author
        int addUser(string username); //checks to see if user exists and if not adds if database isnt full
        int checkOutBook(string username, string title, int newRating); // inputs ratings (if valid)
        void getRecommendations(string username); // prints fist 5 books recs
};

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

    
Library:: Library() { //default constructor
    numBooks = 0;
    numUsers = 0;
}

int Library:: getSizeBook(){
    return sizeBook;
} 

int Library:: getSizeUser(){
    return sizeUser;
}

int Library:: getNumBooks(){
    return numBooks;
}

int Library:: getNumUsers(){
    return numUsers;
}

int Library:: readBooks(string fileName){ //returns total number of books in array
    string tempArray[2];
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    file.open(fileName); //opens the file
    
    if (numBooks == sizeBook){
       return -2;
    }
    else if (file.is_open()) { //checks to see if file is open
        while (getline(file,line)) { //reads line by line
          if (line != "" && numBooks < sizeBook) { //checks to make sure array is not full nor is the line empty
               // are we using the split function here???????
               //or are we storing it into one long line?????
               
                split(line, ',',tempArray, 2);
                books[numBooks].setAuthor(tempArray[0]);
                books[numBooks].setTitle(tempArray[1]);
                numBooks ++;
            }
         }
    }
    else {
        return -1;
    }
    
    file.close();
    return numBooks;
}

void Library:: printAllBooks(){
   if (numBooks <= 0) { // to check if there are any books
       cout << "No books are stored" << endl;
   }
   else { 
       cout<< "Here is a list of books" << endl;
       for (int i = 0; i<numBooks; i++) {
           cout << books[i].getTitle() << " by "; 
           cout << books[i].getAuthor() << endl;
       }
    }
}

void Library:: printBooksByAuthor(string authorName){ //prints all books by specific author
    if (numBooks <= 0) { // to check if the book objects are filled
        cout << "No books are stored" << endl;
    }
   else { 
       int count = 0;
       for(int i =0; i < numBooks ; i++){  //first checks to see how many times the author shows up/ if they show up
          if (books[i].getAuthor() == authorName){ // checks to see if the author shows up in the list
              count++; // if the author is in the Book object, the count is increased
          }
          else {
              count = count; //this is a fail-safe
          } 
       }
       
       if (count>0) { // this runs if the author has been spotted in the array
           cout << "Here is a list of books by " << authorName << endl;
           for(int i =0; i < numBooks ; i++){
               if (books[i].getAuthor() == authorName) {
                   cout << books[i].getTitle() << endl; //prints out the title if the selected author is found
               }
            }
       }
       if (count == 0) { //otherwise if the author is not found in the array, there are no books is printed
           cout << "There are no books by " << authorName << endl;
       }
    }
}

int Library:: readRatings(string userFile) { // returns a total number of users in the users array
    if (numUsers >= sizeUser) {
             return -2; 
    }
    
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    file.open(userFile); //opens the file
    
    if (!(file.is_open())) { //checks case 4: file cannot open
        return -1;
    }
    
    else if (file.is_open()) { //checks to see if file is open
        while (getline(file,line) && numUsers< sizeUser) { //reads line by 
            int count = 0; 
            if (line != "") { //checks to make sure array is not full nor is the line empty
                string testArray[sizeBook+1]; // plus one to go through all of the column numbers

                split(line, ',', testArray, sizeUser);  // used to separate the rows
                
            
                for(int c =0; c<sizeBook; c++){   // checks to see how many columns are occupied so that the program doesnt overload when "copying" the columns
                    if(testArray[c] != "") { 
                        count ++; // if thre is something stored the count is incremented
                    }
                    else {
                        count = count; // otherwise the count is kept at count
                    }
                }
                 users[numUsers].setUsername(testArray[0]); //sets the username using the data from the testarray given from split
                 
                for(int j = 1; j<=count; j++){
                    if(testArray[j]!="")
                    users[numUsers].setRatingAt(j-1,stoi(testArray[j])); //inserts the testArray into the "official" array and stoi converts string to decimal
                }
                 numUsers++;  //increment counter if a varible is stored
           }
        }
    }
    int num = numUsers;
    return num;
}

int Library:: getRating(string username, string bookTitle){ // returns usrs rating for a specific book
    int countUser= 0;
    int accessUser=-1;
    for (int i  = 0; i<numUsers; i++){ //goes through all the users
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //checsk to finda a username match between the two values
            countUser++; 
            accessUser = i; //saves the index the user is found
        }
    }
    if (countUser==0) { //if no users were found
        return -3; //return -3 and stop
    }
    else {
        int countBook = 0;
        int accessBook=-1;
        for (int i = 0; i< numBooks; i++){ //goes through the book objects
            if(makeLower(books[i].getTitle()) == makeLower(bookTitle)) { //checks to see if the title is valid
                countBook++;
                accessBook = i; //saves the index of the book where it is found
            }
        }
        if (countBook==0) {
            return -3;
        }
        else {
            return users[accessUser].getRatingAt(accessBook); //returns the users rating of teh book
        }
    }
}

int Library:: getCountReadBooks(string username) { // returns number of books read by a user
    int countUser= 0;
    int accessUser=-1;
    for (int i  = 0; i<numUsers; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            countUser++; // if the user is present then the user count is incremented
            accessUser = i; //when the user is found the index they are found at are stored
        }
    }
    if (countUser==0 || numBooks == 0 ) { //if no users were found
        return -3; //return -3 and stop
    }
    else {
        int countBook = 0;
        for (int i = 0; i< numBooks; i++){ // goes thrugh all book objects to see if teh title is present
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

void Library:: viewRatings(string username, int minVal){ //prints books with a ratig graer than the minVal
    bool userLocated= false;
    int accessUser=-1;
    int numberOfRatings = 0;
    for (int i  = 0; i<sizeUser; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            userLocated = true;
            accessUser = i; //when the user is found the index they are found at are stored
            break;
        }
    }
    
    if (!userLocated) {
        cout << username << " does not exist." << endl;
    }
    
    else {
       for (int i  = 0; i<numBooks; i++){
            if(users[accessUser].getRatingAt(i) >= minVal) {
                numberOfRatings++;
            } 
        }
        
        if (numberOfRatings == 0) {
            cout<< username << " has not rated any books yet." << endl;
        }
        else {
           cout<< "Here are the books that " << username << " rated" << endl;
           
            for(int j = 0; j<numBooks ; j++){
                int ratingsCompare = users[accessUser].getRatingAt(j);
                
                if(ratingsCompare >= minVal){
                    cout << "Title : " << books[j].getTitle() << endl;
                    cout << "Rating : " << ratingsCompare << endl;
                    cout << "-----" << endl;
                }
             }
        }
    }
}

double Library:: calcAvgRating(string bookTitle){ //returns average rating of specified book
    double countBook= 0;
    double accessBook=-1;
    double sum = 0;
    double countUser = 0;
    
    for (int i  = 0; i<numBooks; i++){
        if(makeLower(books[i].getTitle()) == makeLower(bookTitle)) { //goes through all book objects to see if the book is present, lowercase font
            countBook++; // if the book is present then the book count is incremented
            accessBook = i; //when the book is found the index it is found at is stored
        }
    }
    if (countBook==0 || numUsers == 0) { // if the book is not found or if there are no users them return -3
        return -3; //return -3 and stop
    }
    else {
        for (int i = 0; i< numUsers; i++){ // goes thrugh all user objects to add all the rating of the book together
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

 double Library:: calcAvgRatingByAuthor(string author){ //returns average rating of specified author
    double countAuthor= 0;
    double sum = 0;
    double numberRatings = 0;
    
    for (int i  = 0; i<numBooks; i++){
        if(makeLower(books[i].getAuthor()) == makeLower(author)) { //goes through all book objects to see if the book is present, lowercase font
            countAuthor++; // if the book is present then the book count is incremented
        }
    }
    if (countAuthor==0 || numUsers == 0) { // if the author is not found or if there are no users them return -3
        return -3; //return -3 and stop
    }
    else {
        for (int i = 0; i< numBooks; i++){ // goes thrugh all user objects to add all the rating of the book together
            if ((makeLower(books[i].getAuthor())) == (makeLower(author))){ //only add values that are NOT zero
                for(int j = 0; j < numUsers; j++){
                    if(users[j].getRatingAt(i) >0){
                        sum = sum + users[j].getRatingAt(i);
                        numberRatings ++;
                    }
                }
            }
        }
    }
    
    if (numberRatings==0) { // if no users have read the book, return 0
            return 0;
    }

    return sum / numberRatings;
 }
 
int Library:: addUser(string username){ //checks to see if user exists and if not adds if database isnt full
    User addNewUser;
    if (numUsers == sizeUser){
        return -2;
    }
    
    int countUser= 0;
    for (int i  = 0; i<numUsers; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            countUser++; // if the user is present then the user count is incremented
        }
    }
    if (countUser > 0) {
        return 0;
    }
    else {
        // cout << "numUsers = " << numUsers << endl;
        addNewUser.setUsername(username);
        users[numUsers] = addNewUser;
        numUsers++;
        //cout << "numUsers = " << numUsers << endl;
        return 1;
    }
}


int Library:: checkOutBook(string username, string title, int newRating){ // inputs ratings (if valid)
    int accessTitle = -1;
    int countUser= 0;
    int accessUser=-1;
    int countBook = 0;

    if (newRating<0 || newRating>5){
        return -4;
    } 

    for (int i  = 0; i<numUsers; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            countUser++; // if the user is present then the user count is incremented
            accessUser = i; //when the user is found the index they are found at are stored
        }
    }
    for (int i = 0; i<numBooks; i++) {
        if (makeLower(books[i].getTitle()) == makeLower(title)){
            countBook ++;
            accessTitle = i;
        }
    }
    
    if (countUser == 0 || countBook == 0) {
        return -3;
    }
    
    else {
        users[accessUser].setRatingAt(accessTitle, newRating);
        return 1;
    }

}

void Library:: getRecommendations(string username){ // prints fist 5 books recs
    bool userLocation = false;
    int accessUser=-1;
    int accessBook = 0;
    int scores[numUsers];
    int SSD = 0;
    int minSSD = 202020;
    int minSSDIndex = 0;
    int recCountTotal = 0;
    int recPrint = 0;
 
 // find out where the username we are finding a book for exists/ if it exists
    for (int i  = 0; i<numUsers; i++){
        if(makeLower(users[i].getUsername()) == makeLower(username)) { //goes through all user objects to see if the user is present, lowercase font
            userLocation = true;
            accessUser = i; //when the user is found the index they are found at are stored
        }
    }
    if (!userLocation){
        cout << username << " does not exist." << endl;
    }
 //initialize all the scores 
    else {
        for(int i = 0; i < numUsers; i++){
            if(i != accessUser){
               for (int k = 0; k < numBooks; k++){
                   SSD += pow(users[accessUser].getRatingAt(k) - users[i].getRatingAt(k),2);
               }
               
              if (SSD < minSSD && SSD != 0){
                  minSSD = SSD;
                  minSSDIndex = i;
              }
              SSD = 0; // reset SSD for new user
            }
        }
        
//find the total possible number of recs to be given
        for(int j = 0; j< numBooks; j++) {
            if(users[accessUser].getRatingAt(j) == 0 && users[minSSDIndex].getRatingAt(j) >=3) {
                recCountTotal++;
            }
        }
        
        if (recCountTotal>5){
            recCountTotal = 5;
        }
        else {
            recCountTotal = recCountTotal;
        }
        
// no recs possible
        if(recCountTotal == 0){ 
             cout << "There are no recommendations for " << username << " at present." << endl;
        }
// this occurs if there are recs
        else { 
            cout << "Here is the list of recommendations" << endl; //outside becuase we only print this once at top
// go through the process of recommending books
            for (int k = 0; k <numBooks; k++){
                if(users[accessUser].getRatingAt(k) == 0 && users[minSSDIndex].getRatingAt(k) >=3) { //only recommending if user doesnt have a rec for the book and comare user has a rec >3
                    recPrint++;
                    if (recPrint<=5){  //only recommend books
                        cout<< books[k].getTitle() << " by " << books[k].getAuthor()<< endl; // print recommended book + author
                    }
                }
            }
            
        }
    }
}


void displayMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Print all books" << endl;
    cout << "4. Print books by author" << endl;
    cout << "5. Get rating" << endl;
    cout << "6. Find number of books user rated" << endl;
    cout << "7. View ratings" << endl;
    cout << "8. Get average rating" << endl;
    cout << "9. Get average rating by author" << endl;
    cout << "10. Add a user" << endl;
    cout << "11. Checkout a book" << endl;
    cout << "12. Get recommendations" << endl;
    cout << "13. Quit" << endl;
}

int main() {
    
Library myLib;

    string bookFileName; // declarisng the file that will be looked through
    string userFileName;
    string author;
    string user;
    string title;
    Book books[50]; // declare the array with max 50 array boxes
    User users[100];
    int size = 50;
    int numBooks = 0;
    int numUsers = 0;
    int getRatingStored = 0;
    int getCountReadBooksStored = 0;
    double averageRatingStored = 0.0;
    string userInput; 
    bool check = true;

while(check == true){
    displayMenu();
    getline(cin,userInput);
    if (stoi(userInput) == 1) {
        cout<< "Enter a book file name:" << endl;
        getline(cin,bookFileName);
        int returnValue = myLib.readBooks(bookFileName); // we need to reassigning the numBooksStored so it is not zero in all the other options
        
        if(returnValue == -1 || returnValue == 0) {
             cout<< "No books saved to the database." << endl;
        }
        
        else if(returnValue == -2) {
            cout << "Database is already full. No books were added." << endl;
        }
        
        else if(returnValue==size){
            numBooks = returnValue;
            cout<< "Database is full. Some books may have not been added." << endl;
        }
        
        else {
            numBooks = returnValue;   
            cout<< "Total books in the database: " << numBooks << endl;
        }
    }

    if (stoi(userInput) == 2) { //use s to i becuase you are asking user to input a string number value
        cout<< "Enter a user file name:" << endl;
        getline(cin,userFileName);
        int returnValue = myLib.readRatings(userFileName);
        
        if(returnValue == -1) {
             cout<< "No users saved to the database." << endl;
        }
        
        else if(returnValue == -2) {
            cout << "Database is already full. No users were added." << endl;
        }
        
        else if(returnValue==100){
            numUsers = returnValue;
            cout<< "Database is full. Some users may have not been added." << endl;
        }
        else {
            numUsers = returnValue;
            cout<< "Total users in the database: " << numUsers << endl;
        }

    }
    
    if (stoi(userInput) == 3){
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
            myLib.printAllBooks();
        }
    }
    
    if (stoi(userInput) == 4) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
            cout << "Enter an author name: " << endl;
            getline(cin,author);
            myLib.printBooksByAuthor(author);
        }
    }
    
    if (stoi(userInput) == 5) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
        string userName;
        cout << "Enter a user name: "<< endl;
        cin.clear();
        getline(cin,userName); // use get line in order to get the whole author name
        string bookTitle;
        cout << "Enter a book title: "<< endl;
        cin.clear();
        getline(cin,bookTitle); // use get line in order to get the whole author name
        
        getRatingStored = myLib.getRating(userName, bookTitle);
        
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
    }
    
    if (stoi(userInput) == 6) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
            string userName;
            cout << "Enter a user name:"<< endl;
            getline(cin,userName); // use get line in order to get the whole author name
            getCountReadBooksStored = myLib.getCountReadBooks(userName);
            
            if(getCountReadBooksStored == 0) {
                 cout<< userName << " has not rated any books."<< endl;
            }
            
            else if(getCountReadBooksStored == -3) {
                cout<< userName << " does not exist." << endl;
            }
            
            else {
                cout<< userName << " rated " <<  getCountReadBooksStored << " books." << endl;
            }
             
        }
    }
    
     if (stoi(userInput) == 7) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
            string userName;
            cout << "Enter a user name: " << endl;
            getline(cin,userName);
            
            string rating_str;
            int rating;
            cout << "Enter a minimum rating: " << endl;
            getline(cin, rating_str);
            rating = stoi(rating_str);
            myLib.viewRatings(userName, rating);
        }
     }

    if (stoi(userInput) == 8) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
        string bookTitle;
        cout << "Enter a book title:"<< endl;
        getline(cin,bookTitle); 
        averageRatingStored =  myLib.calcAvgRating(bookTitle);
            
            if(averageRatingStored == -3) {
                 cout<< bookTitle << " does not exist."<< endl;
            }
            
            else {
                cout<< "The average rating for " <<  bookTitle << " is " << averageRatingStored<< endl;
            }
        }
    }
    
    if (stoi(userInput) == 9) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        
        else{
            string author1;
            cout << "Enter an author name: "<< endl;
            getline(cin, author1);
            double returnVal = myLib.calcAvgRatingByAuthor(author1);
            
            if (returnVal == -3) {
                cout << author1 << " does not exist." << endl;
            }
            
            else {
                cout << "The average rating by " << author1 << " is " << returnVal << endl;
            }
        }
    }
    
    if ((stoi(userInput) == 10)) {
            string userName;
            cout << "Enter a user name: " << endl;
            getline(cin, userName);
            
            int returnVal = myLib.addUser(userName);
            
            if(returnVal == 1){
                cout << "Welcome to the library " << userName << endl; 
            }
            else if (returnVal == 0){
                cout << userName << " already exists in the database." << endl;
            }
            
            else if (returnVal == -2){
                cout << "Database is already full. " << userName << " was not added." << endl;
            }
        }
    
    if (stoi(userInput) == 11) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        
        else {
            string userName;
            cout << "Enter a user name: " << endl;
            getline(cin, userName);
            
            string bookTitle;
            cout << "Enter a book title: " << endl;
            getline(cin, bookTitle);
            
            string rating;
            cout << "Enter a new rating: " << endl;
            getline(cin, rating);
            
            
            int returnValue = myLib.checkOutBook(userName, bookTitle, stoi(rating));
            
            if(returnValue == 1) {
                cout << "We hope you enjoyed your book. The rating has been updated." << endl;
            }
            else if(returnValue == -4) {
                cout << rating << " is not valid." << endl;
            }
            else if (returnValue == -3) {
                cout << userName << " or " << bookTitle << " does not exist." << endl;
            }
        }
    }
    
    if (stoi(userInput) == 12) {
        if(numBooks == 0 && numUsers == 0){
            cout << "Database has not been fully initialized." << endl;
        }
        else {
            string userName;
            cout << "Enter a user name: " << endl;
            getline(cin, userName);
            
            myLib.getRecommendations(userName);
        }
    }
    
    if (stoi(userInput) == 13) {
        cout << "Good bye!" << endl;
        check = false;
    }

    if(stoi(userInput)< 1 || stoi(userInput) > 13) {
        cout << "Invalid input." << endl;
    }
    cout << endl;
}
}