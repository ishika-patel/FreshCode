#include <iostream>
#include <string.h>
using namespace std;

// PizzaParty to calculate the cost of a students pizza party.

// Your function should be named PizzaParty
//  The function takes in the following parameters: an integer for the numberOfPizzas, a floating point value for the costPerPizza (type double), and a floating point value of the discount for large orders (type double). The parameters should be in this order.
// The function returns a floating point value for the total cost of pizza (type double)

double PizzaParty (int numberOfPizzas, double costPerPizza, double discount){
    double total_cost;
    
    if(numberOfPizzas <10) {
        total_cost = (numberOfPizzas * costPerPizza) + 10;
        // Calculate the total cost as the number of pizzas multiplied by the per pizza cost, 
       // plus a $10 delivery fee if the number of pizzas is under 10: 

    }
    
    if (numberOfPizzas>=10){
        total_cost = numberOfPizzas * (costPerPizza - (discount * costPerPizza));
        // The cost for 10 or more pizzas is discounted by a percentage and delivery is free:
    }
}