// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 3

#ifndef BOOK_H
#define BOOK_H

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

#endif