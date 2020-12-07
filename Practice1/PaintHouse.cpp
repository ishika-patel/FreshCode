#include <iostream>
using namespace std;

// Write a function named PaintHouse to calculate the cost to paint a house.  The function will take an integer for the width, the depth of the house, and the number of windows/doors in the house. The function returns a floating point value for the total cost of the work.

// Total cost of painting of house = cost of painting wall + cost of painting doors and windows

// The cost to paint the windows and doors is $6.75 per door/window

// The cost of painting the walls is calculated as the perimeter of house times the cost per feet.
//     Perimeter of house = 2 * (width + depth)
// Painting cost for first 100 feet of the house perimeter is $8 per feet
// Painting cost for next 100 feet of the house perimeter is $10 per feet
// Painting cost for house perimeter above 200 feet is $15 per feet

// For any invalid parameter value, return -1

double PaintHouse(int w, int d, int wandd)
{
  double totalCost;
  double perimeter;
  double wallCost;
  double windowsAndDoorsCost;
 
  windowsAndDoorsCost = 6.75 * double(wandd);
 
  perimeter = 2.0 * double(w + d);
 
  if (w < 0 || d < 0 || wandd < 0)
  {
    return -1;
  }
  if (perimeter <= 100)
  {
    wallCost = perimeter * 8.0;
  }
  else if (perimeter <= 200)
  {
    double first100ft = 100.0;
    wallCost = (8.0 * first100ft) + (10.0 * (perimeter - 100));
  }
  else
  {
    double first100ft = 100.0;
    double next100ft = 100.0;
    double restOfThePerimeter = perimeter - 200.0;
   
    wallCost = (8.0 * first100ft) + ( 10.0 * next100ft) + (15.0 * restOfThePerimeter);
  }
 
  totalCost = wallCost + windowsAndDoorsCost;
  return totalCost;
}
 