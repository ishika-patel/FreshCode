#include <iostream>
#include <string.h>
using namespace std;

void DayOfWeek(int day) {
    switch(day){
        case (1):
            cout<< "MONDAY" << endl;
            break;
        case(2):
            cout<< "WORKDAY" << endl;
            break;
        case(3):
            cout<< "WORKDAY" << endl;
            break;
        case(4):
            cout<< "WORKDAY" << endl;
            break;
        case(5):
            cout << "FUNDAY" << endl;
            break;
        case(6):
            cout<< "SLEEPDAY" << endl;
            break;
        case(0):
            cout<< "SLEEPDAY" << endl;
            break;
        default:
            cout<< "INVALID" << endl;
            break;
    }
}