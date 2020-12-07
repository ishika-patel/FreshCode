/* CS1300 Fall 2019
Author: Ishika Patel
Recitation: 104 - Anuj P
Homework 2 - Problem #4 */

#include <iostream>
#include <math.h>
using namespace std;

/* Algorithm: prints surface area and volume given radius
Input parameters: user input of radius
Output: volume: and surface area: 
Returns: surface area and volume calculations */

int main(){
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    
    double surfaceArea;
    surfaceArea = 4.0 * M_PI * pow(radius,2);
    cout << "surface area: " << surfaceArea << endl;
   
}