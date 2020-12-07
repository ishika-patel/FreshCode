#include <iostream>
#include <string.h>
using namespace std;

double TuitionCost(int units, double cost_per_unit) {
    double cost;
    if (units<0 || cost_per_unit<0){
        return -1;
    }
    else if (units<=16){
        cost = (double) units * cost_per_unit;
        return cost;
    }
    else if (units>16) {
        cost = ((double)16 * cost_per_unit) + ((double)units - 16) * (cost_per_unit*0.5);
        return cost;
    }
    else {
        return -1;
    }
}

int main() {
    cout << TuitionCost(16,200)<<endl;
}