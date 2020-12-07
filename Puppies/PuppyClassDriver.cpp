#include <iostream>
#include <string>
#include "Puppy.h"
#include "Puppy.cpp"
using namespace std;

int main() {
    Puppy testPuppy;
    testPuppy.setPuppyName("Crying rn");
    cout << testPuppy.getPuppyName() << endl;
    testPuppy.setPuppyBreed("Sad boi");
    cout << testPuppy.getPuppyBreed() << endl;
    testPuppy.setPuppyAge("12");
    cout << testPuppy.getPuppyAge() << endl;
    testPuppy.setPuppyGender("Confused");
    cout << testPuppy.getPuppyGender() << endl;
    testPuppy.setPuppyToy("Napping");
    cout << testPuppy.getPuppyToy() << endl;
    testPuppy.setPuppyColor("Pink");
    cout << testPuppy.getPuppyColor()<< endl;
   testPuppy.setPuppyCPoints(15);
    cout << testPuppy.getPuppyCPoints() << endl;
    
}