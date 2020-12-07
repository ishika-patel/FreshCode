// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 2 - implementation

#include <iostream>
#include <string>
#include "Library.h"
#include <fstream>
#include <math.h>
using namespace std;

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