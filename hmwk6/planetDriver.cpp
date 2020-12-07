// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 1

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    //test1
    // expected return:
        // Planet 1 name: Pluto
        // Planet 1 radius: 2
        // Planet 1 Volume: 33.5103
    Planet planet1;
    
    planet1.setName("Pluto");
    cout << "Planet 1 name: " << planet1.getName() << endl;
    
    planet1.setRadius(2.0);
    cout << "Planet 1 radius: " << planet1.getRadius() << endl;
    
    cout<< "Planet 1 Volume: " << planet1.getVolume() << endl;
    
    //test1
    // expected return:
        // Planet 2 name: Dog World
        // Planet 2 radius: 12.5
        // Planet 2 Volume: 8181.23
    Planet planet2("Dog World", 12.5);
    cout << "Planet 2 name: " << planet2.getName() << endl;
    cout << "Planet 2 radius: " << planet2.getRadius() << endl;
    cout<< "Planet 2 Volume: " << planet2.getVolume() << endl;
    
    return 0;
}