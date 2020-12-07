#include <iostream>
#include <string>
using namespace std;

// given integer value for units used. The function will return a floating point value for the total cost.  

// Your function will calculate a cost using the following conditions as the cost of the gas depends on how much is used. 
//  First 100 units are charged at $1.23 per unit, 
//  the next 100 units are $1.14 per unit, 
//  any units above 200 are charged at $1.08 per unit.

For invalid parameter value, print "Incorrect input" and return 0

double GasBill(int gasUnits) {
    double cost;
    if (gasUnits<0){
        cout << "Incorrect input" << endl;
    }
    else{
        if (gasUnits<= 100){
           cost = 1.23 * gasUnits;
           return cost;
        }
        if (gasUnits>100 && gasUnits<=200){
            cost = (1.23 * 100.0) + ((gasUnits-100)*1.14);
            return cost;
        }
        if (gasUnits>200){
            cost = (1.23 * 100.0) + (100.0*1.14) + ((gasUnits-200)*1.08);
            return cost;
        }
    }
}

int main(){
    cout<< GasBill(150)<< endl;
}