/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 3 - Problem EC*/

#include <iostream>
#include <string>
using namespace std;

/* Algorithms: this function keeps asking which story the user would like to play until they opt to quit. 
Based on the user’s story selection, prompt the user for the words for that particular story.
Story1:
Be careful not to vacuum the <NOUN> when you clean under your bed.
Story2:
<NAME> is a <OCCUPATION> who lives in <PLACE>.
Story3:
In the book War of the <PLURAL NOUN>, the main character is an anonymous <OCCUPATION> who records the arrival of the <ANIMAL>s in <PLACE>.
Input parameters: no parameters input. however, there is user input using cin>>
Output: print a story based on the option chosen
Returns: none */

void storyGenerator() {
    int userInputNumber;
    cout<< "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type 4 to quit" << endl;
    cin >> userInputNumber;
    
    if(userInputNumber == 1){
        string noun;
        cout << "Enter a noun:" << endl;
        cin>> noun;
        
        cout<< "Be careful not to vacuum the " << noun << " when you clean under your bed."<< endl;

        cout<< ""<< endl;
        storyGenerator();
    }
    
    if(userInputNumber == 2){
        cout<<"Enter a name:" << endl;
        string name;
        cin>> name;
        
        cout << "Enter an occupation:" << endl;
        string occupation;
        cin>> occupation;
        
        cout << "Enter a place:" << endl;
        string place;
        cin>> place;
        
        cout<< name << " is a " << occupation << " who lives in " << place << "." << endl;
    
        cout<< ""<< endl;
        storyGenerator();
    }
    
    if(userInputNumber == 3){
        cout << "Enter a plural noun:" << endl;
        string pNoun;
        cin>> pNoun;
        
        cout << "Enter an occupation:" << endl;
        string occupation;
        cin>> occupation;
        
        cout << "Enter an animal:" << endl;
        string animal;
        cin>> animal;
        
        cout << "Enter a place:" << endl;
        string place;
        cin>> place;
        
        cout<< "In the book War of the "<< pNoun<< ", the main character is an anonymous " << occupation
        << " who records the arrival of the "<< animal <<"s in " << place << "." << endl;
        
        cout<< ""<< endl;
        storyGenerator();
    }

    if(userInputNumber == 4) {
        cout<< "Good bye!" << endl;
    } 

}

int main(){
    storyGenerator();
}