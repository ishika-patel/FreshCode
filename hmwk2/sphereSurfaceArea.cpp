/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #6 */

#include <iostream>
#include <math.h>
using namespace std;

/* Algorithm: computes the surface area of a sphere using Surface Area=4*pi*radius^2 
equation. This computed SA is then input on the screen. This program uses the imported math
library 
Input parameters: radius
Output: sphere surface area
Returns: none */

void sphereSurfaceArea(double radius){
    double surfaceArea;
    surfaceArea = 4.0 * M_PI * pow(radius,2); //surface area computation
    cout << "surface area: " << surfaceArea << endl;
}
int main() {
    //test1
    // Expected result: surface area: 314.159
    sphereSurfaceArea(5);
    //test2
    // expected result: surface area: 50.2655
    sphereSurfaceArea(2);
}