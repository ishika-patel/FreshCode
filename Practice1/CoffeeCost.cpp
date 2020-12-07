#include <iostream>
#include <string.h>
using namespace std;

//  The function will take an integer for the number of cups of coffee and 
// a floating point value for the cost per cup. 
// The function will return a floating point value for the total cost of coffee. 
// The students use a coffee house that rewards the student for caffeine overload 
// by giving a free cup for buying every 12 cups.

// Calculate the cost as units times the per unit cost:  cost = units * cost per unit 

double CoffeeCost(int cups, double cost) {
    double totalCost = (double) cups * cost;
    
    int i = 0;
    while( i<=cups) {
        if (i%13 ==0 && i!=0) {
            totalCost = totalCost - cost;
        }
        i++;
    }
    cout << totalCost<< endl;
    return totalCost;
    }
    
int main() {
    coffeeCost(12,3);
}