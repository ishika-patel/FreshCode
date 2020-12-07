// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 1

#include <iostream>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

/* Algorithm: define a constructor variable. define a parametrized constructor. Define other functions in Planet (setter and getter methods)
Input Parameters: Planet(string name, double radius)
Output/printing: none
Return: name, radius and volume based on what is called 
*/

Planet:: Planet() {
    planetName = ""; //clears the constructor
    planetRadius = 0.0;
}

Planet:: Planet(string name, double radius) { //parametirized constructor
   planetName = name; // link variable in Planet constructor with the private variable
   planetRadius = radius; // link variable in Planet constructor with the private variable
}

string Planet:: getName() {
    return planetName;   // link variable in Planet constructor with the private variable
}

void Planet:: setName(string name) {
    planetName = name; // link variable in Planet constructor with the private variable
}

double Planet::getRadius() {
    return planetRadius;
}

void Planet:: setRadius(double radius){
    planetRadius = radius;
}

double Planet:: getVolume() {
    double volume = (4.0/3)*M_PI*(pow(planetRadius,3)); //calculate voume of a sphere
    return volume; // returns it
}

