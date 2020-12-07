// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 4 - Problem 1

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: exercise of declaring and poulating arrays
1. temps: an array of 10 floating point numbers initialized with -459.67 (absolute zero in Fahrenheit)
2. colors: an array of the strings “Red”, “Blue”, “Green”, “Cyan”, and “Magenta”, in that order.
3. sequencs: an array of the first 100 positive integers in order - 1,2,3,4,...etc.
    - declare this array and use a for loop to initiaize it with values 1-100
4. letters: an array of all uppercase and lowercase characters in order, A, a, B, b...
    - use the ASCII values to assign array indexes with values
    - alternate btween caps and lowercase but using a mod of odd and even number
        - even + 0 is caps, odd is lower
Input Parameters: none
Output/printing: print out each of these functions
    - temps (double)
    - colors (string)
    - sequence (int)
    - letters (char)
Returns: none, in the main function
*/

int main() {
    
    double temps[10] = {-459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67};
    for (int i=0; i<10; i++){ // prints out each value in array temps
        cout<< temps[i] << endl;
    }
    cout<< endl;
    
    string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    for(int i =0; i<5; i++){ // prints out each string value in array color
        cout<< colors[i] << endl;
    }
    cout<< endl;
    
    int sequence[100]; // declare array
    for(int i = 0; i<100; i++){ //define array
        sequence[i]= i+1;
        cout<< sequence[i]<< endl; // print array
    }
    cout<< endl;
    
    char letters[52]; //declare array
     int ASCIIchar1 =65; // used to access the ASCII schemaic for characters, 65 is A
     int ASCIIchar2 = 97; // used to access the ASCII schemaic for characters, 97 is a
    for(int i = 0; i<52; i++){
        if(i%2 == 0){ //used to define every other index i, this if statement prints the capital letters
            letters[i] = ASCIIchar1; // initialize the array at index [i] with the ASCII value
            cout<< letters[i]<< " "; //print the letter
            ASCIIchar1++; // add one to ASCII to move to next letter in table
        }

        if (i%2 != 0){ //used to define every other index i, this if statement prints the lowercase letters
            letters[i] = ASCIIchar2; // initialize the array at index [i] with the ASCII value
            cout<< letters[i] << endl; //print the letter
            ASCIIchar2++; // add one to ASCII to move to next letter in table
        }
    }
}

// void addOne(int X[]){ 
//     X[0] = X[0] + 1;
// cout << X[0] << endl;
// }

// int main(){
// int X[4] = {1, 5, 3, 2}; 
// cout << X[0] << endl; 
// addOne(X);
// cout << X[0] << endl;
// }