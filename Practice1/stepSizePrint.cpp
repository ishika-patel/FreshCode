#include <iostream>
using namespace std;

//  This function takes three integer parameters: a starting point, an ending point, and a step size. 
//  This function should print out all the numbers between the starting point and the ending point
//  with intervals of the step size.

void stepSizePrint(int start, int end, int stepSize)
{
  if(stepSize == 0)
  {
    cout << "Step size cannot be zero." << endl;
  }
  else if(stepSize > 0 && end < start)
  {
    cout << "Wrong settings!" << endl;
  }
  else if(stepSize < 0 && end > start)
  {
    cout << "Wrong settings!" << endl;
  }
  else if(stepSize > 0 && end > start)
  {
    for(int i = start; i < end; i+=stepSize) // positive numbers
    {
      cout << i << endl;
    }
  }
  else // negative numbers
  {
    for(int i = start; i > end; i+=stepSize)
    {
      cout << i << endl;
    }
  }
}

int main() {
    stepSizePrint(-3, -10, -2);
}