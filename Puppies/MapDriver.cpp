#include <iostream>
#include <string>
#include "Map.h"
#include "Map.cpp"
using namespace std;

int main() {
    Map testMap;
   testMap.loadMap();
    testMap.displayMap();
}