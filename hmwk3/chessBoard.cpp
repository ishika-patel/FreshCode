/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem #3 */

#include <iostream>
using namespace std;

/* Algorithms: this function outputs the color of the chessboard space based on the featured location. this function IS case sensitive
1. When the letter selected is a, c, e or g
    a. if the number is even the color is white
    b. if the number is odd the color is black
2. when the letter selected is b, d, f or h
    a. if the number is even the color is black
    b. if the number is off the color is white
3. if the letter selected is captial or our of the selected letter range OR the number is out of range
    a. the function will output "Chessboard squares can only have letters between a-h and numbers between 1-8"
Input parameters: chess board letter (char) and chess board number (int)
Output: black, white or "Chessboard squares can only have letters between a-h and numbers between 1-8" based on the location chosen
Returns: none  */

void chessBoard(char chessLet, int chessNumb) {
    int remainderVal = chessNumb%2; // determines whether chessNumb is odd (remain>0) or even (remain=0) based on the remainder
    
        if ((chessLet == 'a' || chessLet == 'c' || chessLet == 'e'|| chessLet == 'g') && chessNumb<=8) { // checks every other chess board column
            if (remainderVal == 0) { // prints the color based on row number
                cout<< "white" << endl; 
            }
            else {
                cout << "black" << endl; 
                }
        }
   
        if ((chessLet == 'b' || chessLet == 'd' || chessLet == 'f'|| chessLet == 'h') && chessNumb<=8) { // checks the other set of columns.
             if (remainderVal == 0) {// prints the color based on the row number
                cout<< "black" << endl; 
            }
            else {
                cout << "white" << endl; 
                }
         }
         // the line below accounts for any casing errors such as capitals and any out of range errors like calling on a row pas 8
          if (chessLet !='a' && chessLet != 'b' && chessLet != 'c'&& chessLet != 'd' && chessLet != 'e' && chessLet != 'f' && chessLet != 'g'&& chessLet != 'h'){
              cout<< "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;
          }
          if (chessNumb>8) { // when chessNumb is greater than the number of rows
              cout<< "Chessboard squares can only have letters between a-h and numbers between 1-8." << endl;
          }
}

int main() {
    //test1
    //Expected Output: Chessboard squares can only have letters between a-h and numbers between 1-8
    chessBoard('A',3);
    //test2
    //Expected Output: black
    chessBoard('a',3);
    //test3
    //Expected Output: white
    chessBoard('b', 3);
    
}