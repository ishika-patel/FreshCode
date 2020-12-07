// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Homework 6 - Problem 1

#ifndef PLANET_H
#define PLANET_H
using namespace std;

class Planet {
    private:
    string planetName;
    double planetRadius;
    
    public:
    Planet(); //default constructor
    Planet(string name, double radius); // parameterized constructor
    
    void setName(string name);
    string getName();
    
    void setRadius(double radius);
    double getRadius();

    double getVolume();

};

#endif