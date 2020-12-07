/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #5 */

#include <iostream>
#include <math.h>
using namespace std;

/* Algorithm: computes volume of a sphere using volume=(4/3)pi*radius^3 equation.
This computed volume is then input on the screen
Input parameters: radius
Output: sphere volume!
Returns: none */

void sphereVolume(double radius) {
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3); //using the math library we access the power and pi functions
    cout << "volume: " << volume << endl;
}

int main() {
    //test1
    // Expected value: volume: 523.599
    sphereVolume(5);
    //test2
    // Expected value: volume: 33.5103
    sphereVolume(2);
}