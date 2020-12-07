#ifndef MAP_H
#define MAP_H
using namespace std;

class Map{
    private:
        const int row = 10;
        const int col = 10;
        string mapArray[10][10];
        
    public:
        void loadMap();
        void displayMap();
};
#endif

/* function that creates map OUTSIDE LOOP (double 4 to simple part)
    function that changed the map now (double 4 loop to change specific part, mapchange(int row, int col) when getting to row and col you change to a *)
    function that simply prints map (double 4 loop)
*/