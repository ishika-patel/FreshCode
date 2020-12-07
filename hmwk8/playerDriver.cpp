#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Player.cpp"
using namespace std;

int main() {
    // checking name setters and getters
    // expected output: Stella
    Player stella;
    stella.setName("Stella");
    cout << stella.getName() << endl;
    
    // checking points setters and getters
    // expected output: 13.1
    stella.setPoints(13.1);
    cout << stella.getPoints() << endl;
    
    //checking parametrized constructor
    // expected output: ishika, 7.3
    Player ishika = Player("ishika", 7.3);
    cout << ishika.getName() << endl;
    cout << ishika.getPoints() << endl;
    
    //default constructor
    // expected output: empty, 0
    Player newP = Player();
    cout << newP.getName() << endl;
    cout << newP.getPoints() << endl;
}