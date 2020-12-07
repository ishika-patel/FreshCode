// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project Puppies

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <cctype>
#include "Toy.h"
using namespace std;

/* Algorithm: The Toy class hold the toy objects that the user puppy are searching for
this class will be used as the trivia portion of the game (this application will be seen in the game class)
trivia objects are written in from a file that has been made
there are 25 possible toys that the puppy can find.
In the game class this is where the probability with specific outcomes will be implemeted to see if there is a toy where the puppy moved.
*/
      
Toy:: Toy(){ //default constructor
    question = "";
    answer = "";
}
Toy:: Toy(string toyName_, string question_, string choice_, string answer_){ //parametrized construtor
    toyName =  toyName_;
    question = question_;
    choice = choice_;
    answer = answer_;
}
void Toy::  setToyName(string toyName_){
    toyName = toyName_;
}
//toy name, question, choice, answer are all read from a file
string Toy:: getToyName(){
    return toyName;
}
void Toy:: setQuestion(string question_){
    question = question_;
}
string Toy::  getQuestion(){
    return question;
}
void Toy:: setChoice(string choice_){
    choice = choice_;
}
string Toy:: getChoice(){
    return choice;
}
void Toy:: setAnswer(string answer_){
    answer = answer_;
}
string Toy:: getAnswer(){
    return answer;
}