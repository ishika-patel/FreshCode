// #ifndef GAME_H
// #define GAME_H
using namespace std;

class Game {
    private:
        int numToysCollected = 0;

        // const int sizePuppies = 50;
        // Puppy puppyFriends[50];

        // cosnt int sizeToys = 25;
        // Toy toys[25];
        // string printMap[][];
        //obstacles

    public:
        int random1to100(); //a probability value 60-40 percentage
        int random1to50(); //value of a variable 0 to 49
        int random0to24();//value of a variable
        void trivia();
        void setNumToysCollected(int numToysCollected_);
        int getNumToysCollected();
        void primaryGameMenu();
        void secondaryGameMenu();
        void secondaryDirectionsMenu();
        void mainGame();
};