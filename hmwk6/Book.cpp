// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 3

#include <iostream>
#include <string>
#include <math.h>
#include "Book.h"

/* Algorithm: define a constructor variable. define a parametrized constructor. Define other functions in Book (setter and getter methods)
Input Parameters: Book objects are made up of string titles and string authors
Output/printing: testing the getter and setter methods
Return: return title and name when such methods are called 
*/

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