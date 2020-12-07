// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 8 - Problem 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Algorithm: this function takes two decks of cards regsrdless of size and shuffles them together
Input Parameters: two vectors of a deck of cards
Output/printing: none 
Return: the new final deck (also a vector) that is a shuffle
*/

vector<int> shuffle(vector<int> deck1, vector<int> deck2) {
    vector<int> finaldeck;
    
   if (deck1.size() == 0 && deck2.size() == 0){ //return an empty deck
       return finaldeck;
   }
   
   else if (deck1.size() == deck2.size()){ //if deck 1 and deck 2 are same length, then start with deck 1
        for (int i = 0; i< deck1.size(); i++){ //go through 1 deck
            finaldeck.push_back(deck1.at(i));
            if (i<deck2.size()) { //go through second deck
                finaldeck.push_back(deck2.at(i));
            }
        }
    }
    
    else if(deck1.size() > deck2.size()){ //if deck 1 is bigger
        for (int i = 0; i < deck1.size(); i++){
            finaldeck.push_back(deck1.at(i));
            if (i<deck2.size()) { //push the second deck until the last one, if statment allows only up tot size cards from teh smaller deck to be pushed
                finaldeck.push_back(deck2.at(i));
            }
        }
    }
        
        else if(deck2.size() > deck1.size()){ //if deck 2 is bigger
        for (int i = 0; i < deck2.size(); i++){
            finaldeck.push_back(deck2.at(i)); //push card from deck 2
            if (i<deck1.size()) { //if deck 1 is within rqnge push a card otherwise skip deck 1
                finaldeck.push_back(deck1.at(i));
            }
        }
    }
    
    return finaldeck; //return the deck
}

int main() {
    //test1
    //expected output: 2 1 4 3 6 5 8 9 10
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    
    cout << endl;
    
    //test2
    // expected output: 1 5 3 -7
    vector<int> v4{1,3};
    vector<int> v5{5,-7};
    vector<int> v6 = shuffle(v4,v5);
    for (int i=0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }
    
    cout << endl;
    
    //test3
    // expected output: 2 -5 0 19
    
vector<int> v7{2,-5,0,19};
vector<int> v8;
vector<int> v9 = shuffle(v7,v8);
for (int i=0; i < v9.size(); i++) {
    cout << v9[i] << " ";
}
    
}