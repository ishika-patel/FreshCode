// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project Puppies

#include <iostream> 
#include <fstream>
#include <string.h>
#include <cctype>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Puppy.h"
#include "Puppy.cpp"
#include "Toy.h"
#include "Toy.cpp"
#include "Map.h"
#include "Map.cpp"
using namespace std;

void Game:: setNumToysCollected(int numToysCollected_){
     numToysCollected = numToysCollected_;
}

int Game:: getNumToysCollected(){
    return numToysCollected;
}

//a probability value random function
int Game:: random1to100(){
    int num;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate number between 1 and 100: */
    num = rand() % 100 + 1;
    //cout << num << endl;
    
    //probability
    if (num <60) {
        num = 0;
    }
    else {
        num = 1;
    }
    
    return num;
    
}

//value of a variable selected ar random
int Game:: random1to50(){
    int num;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate number between 1 and 50: */
    num = rand() % 50 + 1;
    num = num - 1; // supplement 0 to 49 values of the puppies array
    //cout << num << endl;
    
    return num;
}

//value of a variable selected ar random
int Game:: random0to24() {
    int num;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate number between 1 and 25: */
    num = rand() % 25 + 1;
    num = num - 1; // supplement 0 to 24 values of the toy array
    //cout << num << endl;
    
    return num;
}

void Game:: trivia(){
    int userInput;
    cout << "YOUR SNOOT HAS SNIFFED A TOY!"<< endl;
    cout << "Answer correctly and win the toy:" << endl;
    cout << endl;
    
    /*
    int triviaNumber = random0to24();
    /*
    cout << toys[triviaNumber].getQuestion()<< endl;
    cout << toys[triviaNumber].getChoice() << endl;
    cin >> userInput;
            
    if (userInput == stoi(toys[triviaNumber].getAnswer())){
        ofstream outfile;
        outfile.open("CollectedToys.txt");
        
        outfile << toys[triviaNumber].getToyName() << endl;
        int returnVal = getNumToysCollected() + 1;
        setNumToysCollected(returnVal);

        outfile.close();
    }
    else {
        cout << "Mom yelled at you for digging :(" << endl;
        cout << "No toy for you and a loss of cuddle points." << endl;
        int newLostPoints = myPuppy.getPuppyCPoints() - 50;
        myPuppy.setPuppyCPoints(newLostPoints);
    }
    */
}

void Game:: secondaryDirectionsMenu() {
    cout << endl;
    cout << "WELCOME TO PUPPY LAND! What do you want to learn about?" << endl;
    cout << "Select a numerical option:" << endl;
    cout << "======Secondary Menu=====" << endl;
    cout << "1. General Game Directions" << endl;
    cout << "2. Love Battle Directions" << endl;
}

void Game:: secondaryGameMenu() {
    cout << "Arf Arf! NO TOY FOUND." << endl;
    cout << "Select a numerical option:" << endl;
    cout << "======Secondary Menu=====" << endl;
    cout << "1. Love Battle" << endl;
    cout << "2. Lose C Points" << endl;
}

void Game:: primaryGameMenu() {
    Map printMap;
    cout << "WELCOME TO PUPPY LAND!" << endl;
    
    printMap.displayMap();
    cout << endl;
    
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Get Directions" << endl; //simply print out
    cout << "2. Learn More About Your Puppy" << endl; //puppy class, print out myPuppy object
    cout << "3. See Your Toy Trunk" << endl; //if numToys 0 else seen from the written file
    cout << "4. Rest" << endl; //lose one toy count but win 100 c points
    cout << "5. MOVE" << endl; //game class?? ask for 2 numbers create 2D array based on this, print out 2D array at end
    cout << "6. QUIT" << endl;
}

void Game:: mainGame() {
    Puppy myPuppy;
    bool charChoice = true;
    
    //array of puppy objects
    Puppy friends[50];
    const int sizeFriends = 50;
    bool importFriends = false;
    // initializes array of puppy objects
    if(importFriends == false) {
        ifstream inFile;
        inFile.open("puppyFriends.txt");
        string line = "";
        string testArray[7];
        int i = 0;
        
        if(inFile.is_open()) {
            while(getline(inFile, line)) {
                if(line != "") {
                    split(line, ',', testArray, 7);
                    
                    friends[i].setPuppyName(testArray[0]);
                    friends[i].setPuppyBreed(testArray[1]);
                    friends[i].setPuppyAge(testArray[2]);
                    friends[i].setPuppyGender(testArray[3]);
                    friends[i].setPuppyToy(testArray[4]);
                    friends[i].setPuppyColor(testArray[5]);
                    friends[i].setPuppyCPoints(stoi(testArray[6]));
                    
                    i++;
                }
            }
            importFriends = true;
        }
    }
    else {
        importFriends = true;
    }
        
    // array of toy objects
    Toy toys[25];
    const int sizeToy = 25;
    bool importToys = false;
    //initializes array of toy objects
    if(importToys == false) {
        ifstream inFile;
        inFile.open("toys.txt");
        string line = "";
        string testArray[4];
        int i = 0;
        
        if(inFile.is_open()) {
            while(getline(inFile, line)) {
                if(line != "") {
                    split(line, ',', testArray, 4);
                    
                    toys[i].setToyName(testArray[0]);
                    toys[i].setQuestion(testArray[1]);
                    toys[i].setChoice(testArray[2]);
                    toys[i].setAnswer(testArray[3]);
                
                    i++;
                }
            }
            importToys = true;
        }
    }
    else {
        importToys = true;
    }
    
    
    string userGameInput;
    bool check = true;
    
    //choose a character
    while (charChoice == true) {
        string userPup;
        cout<< "WELCOME TO YOUR PUPPY ADVENTURE!" << endl;
        cout<< "CHOOSE YOUR LOVER!!!!" << endl;
        cout << "Please enter the number of the puppy you wish to adventure with." << endl;
        cout << "1. Tubby" << endl;
        cout << "2. Candice" << endl;
        cout << "3. Karen" << endl;
        cout << "4. Tofu" << endl;
        
        getline(cin,userPup);
        if (stoi(userPup) == 1){
            cout << "Congrats, you are Tubby the Puppy!" << endl;
            myPuppy.setPuppyName("Tubby");
            myPuppy.setPuppyBreed("German Shepherd");
            myPuppy.setPuppyAge("3");
            myPuppy.setPuppyGender("Male");
            myPuppy.setPuppyToy("Chuck It!");
            myPuppy.setPuppyColor("Green");
            myPuppy.setPuppyCPoints(1000);
            
            charChoice = false;
        }
        else if (stoi(userPup) == 2){
            cout << "Congrats, you are Candice the Puppy!" << endl;
            myPuppy.setPuppyName("Candice");
            myPuppy.setPuppyBreed("Poodle");
            myPuppy.setPuppyAge("4");
            myPuppy.setPuppyGender("Female");
            myPuppy.setPuppyToy("Rope");
            myPuppy.setPuppyColor("Yellow");
            myPuppy.setPuppyCPoints(1000);
            charChoice = false;
        }
        else if (stoi(userPup) == 3){
            cout << "Congrats, you are Karen the Puppy!" << endl;
            myPuppy.setPuppyName("Karen");
            myPuppy.setPuppyBreed("Corgie");
            myPuppy.setPuppyAge("4");
            myPuppy.setPuppyGender("Female");
            myPuppy.setPuppyToy("Ball");
            myPuppy.setPuppyColor("Pink");
            myPuppy.setPuppyCPoints(1000);
            
            charChoice = false;
        }
        else if (stoi(userPup) == 4){
            cout << "Congrats, you are Tofu the Puppy!" << endl;
            myPuppy.setPuppyName("Tofu");
            myPuppy.setPuppyBreed("Samoyed");
            myPuppy.setPuppyAge("5");
            myPuppy.setPuppyGender("Male");
            myPuppy.setPuppyToy("Stuffed Otter");
            myPuppy.setPuppyColor("Blue");
            myPuppy.setPuppyCPoints(1000);
            
            charChoice = false;
        }
        else {
            cout << "This input is invalid. Try Again." << endl;
        }
        cout << endl;
    }
    
    while(check == true){
        primaryGameMenu();
        getline(cin,userGameInput);
        // 1. Directions
        if (stoi(userGameInput) == 1) {
            string directionsChoice;
            secondaryDirectionsMenu();
            getline(cin,directionsChoice);
            
            if(stoi(directionsChoice) == 1){
                string line; 
                ifstream file; //says there is a file we will access and we are taking data from it
                file.open("mainInstructions.txt"); //opens the file with directions
    
                if(file.is_open()) { //checks to see if file is open
                    while (getline(file,line)) { //reads line by line
                        cout << line << endl;
                    }
                }
                else {
                    cout << "Uh Oh! We cannot access this file." << endl;
                }
                file.close();
            }
            
            else if(stoi(directionsChoice) == 2) {
                string line2; 
                ifstream file2; //says there is a file we will access and we are taking data from it
                file2.open("battleInstructions.txt"); //opens the file with directions
    
                if(file2.is_open()) { //checks to see if file is open
                    while (getline(file2,line2)) { //reads line by line
                        cout << line2 << endl;
                    }
                }
                else {
                    cout << "Uh Oh! We cannot access this file." << endl;
                }
                file2.close();
            }
            
            else {
              cout << "Woof! This is an Invalid Input. Sorry." << endl;
            }
            
            cout << endl;

            //printing statistics each turn
            cout << endl;
            cout << "Heres a quick update..." <<endl;
            cout << myPuppy.getPuppyName() << " here are your current game stats:" << endl;
            cout << "You have " << myPuppy.getPuppyCPoints() << " number of Cuddle Points." << endl;
            cout << "You have collected " << numToysCollected << " toys." << endl;
        }
        
        //2. Learn about user's puppy
        else if (stoi(userGameInput) == 2) {
            cout << "Learn More About Your Puppy!" << endl;
            cout << "Hi my name is " << myPuppy.getPuppyName() << " and I am so beyond excited to meet you!" << endl;
            cout << "I am a " << myPuppy.getPuppyAge() << " year old " << myPuppy.getPuppyBreed() << " puppy." << endl;
            cout << "I am a " << myPuppy.getPuppyGender() << " puppy!" << endl;
            cout << "I love playing with toys and taking walks, but my favorite toy ever is " << myPuppy.getPuppyToy() << "." << endl;
            cout << "My collar color is " << myPuppy.getPuppyColor() << ". This is my favorite color!" << endl;
            
            //printing statistics each turn
            cout << endl;
            cout << "Heres a quick update..." <<endl;
            cout << myPuppy.getPuppyName() << " here are your current game stats:" << endl;
            cout << "You have " << myPuppy.getPuppyCPoints() << " number of Cuddle Points." << endl;
            cout << "You have collected " << numToysCollected << " toys." << endl;
        }
        
        // 3. See Your Toy Trunk
        else if (stoi(userGameInput) == 3) {
            if (getNumToysCollected() == 0) {
                cout << "You are toy-less" << endl;
            }
            else {
                cout << "Toy Count: " << getNumToysCollected() << endl; 
            }
        
        //printing statistics each turn
        cout << endl;
        cout << "Heres a quick update..." <<endl;
        cout << myPuppy.getPuppyName() << " here are your current game stats:" << endl;
        cout << "You have " << myPuppy.getPuppyCPoints() << " number of Cuddle Points." << endl;
        cout << "You have collected " << numToysCollected << " toys." << endl;

        }
        
        //4. Rest
        else if (stoi(userGameInput) == 4) {
            if (getNumToysCollected() > 0) {
                cout << "You found a sun spot to nap in! You have too many toys to take to the nap spot though /n So... you lose one toy to gain 100 cuddle points" << endl;
                
                int toyMinus1 = getNumToysCollected() - 1;
                setNumToysCollected(toyMinus1);
                
                int addCPoints = myPuppy.getPuppyCPoints() + 100;
                myPuppy.setPuppyCPoints(addCPoints);
            }
            
            else {
                cout << "You cannot take a nap, there is no sun. Im sorry, you are now more soggy." << endl;
                cout << "Because you are soggy you lost 10 cuddle points" << endl;
                
                int subtractCPoints = myPuppy.getPuppyCPoints() - 10;
                myPuppy.setPuppyCPoints(subtractCPoints);
            }
        
        //printing statistics each turn
        cout << endl;
        cout << "Heres a quick update..." <<endl;
        cout << myPuppy.getPuppyName() << " here are your current game stats:" << endl;
        cout << "You have " << myPuppy.getPuppyCPoints() << " number of Cuddle Points." << endl;
        cout << "You have collected " << numToysCollected << " toys." << endl;
        }
        
        //5. MOVE
        else if (stoi(userGameInput) == 5) {
        cout << "Import Friends: " << importFriends << endl;
        cout << "Import Toys: " << importToys << endl;
        cout << "random 1 - 100: " << random1to100() << endl; //a probability value 60-40 percentage
        cout << "random 1 - 50: " << random1to50() << endl; //value of a variable 0 to 49
        cout << "random 0 - 25: "<< random0to24() << endl;//value of a variable
        int random = random1to100();
        
        if (random == 1){
            trivia();
        }
        else if (random == 0) {
            cout << "Sorry no toy found here" << endl;
            secondaryGameMenu();
            string secondChoice;
            getline(cin,secondChoice);
            
            if (stoi(secondChoice) == 1) {
                //love battle
            }
            else if (stoi(secondChoice) == 2){
                cout << "You took a chance and lost. You are a sad pup. "<< endl;
                
                int newPoints = myPuppy.getPuppyCPoints() - 50;
                myPuppy.setPuppyCPoints(newPoints);
            }
            else {
                cout << "Error. Got distracted chasing your tail. You automatically lose 10 Cuddle Points." << endl;
                int lostPoints = myPuppy.getPuppyCPoints() - 10;
                myPuppy.setPuppyCPoints(lostPoints);
            }
        }

        //printing statistics each turn
        cout << endl;
        cout << "Heres a quick update..." <<endl;
        cout << myPuppy.getPuppyName() << " here are your current game stats:" << endl;
        cout << "You have " << myPuppy.getPuppyCPoints() << " number of Cuddle Points." << endl;
        cout << "You have collected " << numToysCollected << " toys." << endl;
        }
        
        // 6. QUIT GAME
        else if (stoi(userGameInput) == 6) {
            cout << "Thank you for playing with " << myPuppy.getPuppyName()  << endl;
            cout << "Here are your stats: " << endl;
            //printing statistics each turn
            cout << endl;
            cout << "You have " << myPuppy.getPuppyCPoints() << " number of Cuddle Points." << endl;
            cout << "You have collected " << getNumToysCollected() << " toys." << endl;

            check = false;
        }
        
        //User Error
        else {
            cout << "Invalid Input Try Again" << endl;
        }
        
        cout << endl;
        
        while(myPuppy.getPuppyCPoints() < 0 && check == true){
            cout << "You do not have enough Cuddle Points to continue. Try Again Next Time." << endl;
            check = false;
        }
        
        while(getNumToysCollected() >= 25 && check == true) {
            cout << "You have WON!!! You successfully collected 25 toys! Woof Woof!!" << endl;
            check = false;
        }
    }
}