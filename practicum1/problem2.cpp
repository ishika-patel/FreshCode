// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Practicum 1 - Problem 2

#include <iostream>
#include <string>
using namespace std;

void gameMenu(int num) {
    
    switch(num){
        case (1):
            cout << "Choice 1: Play Game" << endl;
            break;
        case (2):
            cout<<  "Choice 2: View Stats" << endl;
            break;
        case (3):
            cout<< "Choice 3: Save Game" << endl;
            break;
        case(4):
            cout<< "Choice 4: Exit Game" << endl;
            break;
        default:
            cout<< "Choice " << num << ": Invalid" << endl;
            break;
    }
    
}

int main() {
    gameMenu(1);
    gameMenu(2);
    gameMenu(3);
    gameMenu(4);
    gameMenu(14);
}