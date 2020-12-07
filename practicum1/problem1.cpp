// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Practicum 1 - Problem 1

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


double cakeCost(double baseCostPerCake, int numberOfToppings, double costPerTopping) {
  double cost;
    if (numberOfToppings>5){
        cost = (10.0*costPerTopping) + baseCostPerCake;
        cout<< cost << endl;
        return cost;
    }
    else {
        cost = ((double)numberOfToppings*costPerTopping) + baseCostPerCake;
         cout<< cost << endl;
        return cost;
    }
}

int main(){
    cakeCost(30, 5,5);
    cakeCost(30,7,5);
}

// Write a function named cakeCost to calculate the cost of a cake depending on the number of toppings for the cake.

// Your function should be named cakeCost
// The function has the following parameters in this order:  
// a floating point value for the baseCostPerCake (type double)
// an integer for the numberOfToppings,
// a floating point value (type double) for the costPerTopping.
// The function returns a floating point value (type double) for the total cost of the cake.
// You may assume all parameter values will be positive.
// Calculate the total cost as the number of toppings multiplied by the per topping cost, plus the base cost per cake 
//     cost = (number of toppings * cost per topping) + base cost per cake.
// If the number of toppings is greater than 5, 
//     cost = (10 * cost per topping) + base cost per cake.