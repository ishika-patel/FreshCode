#ifndef PUPPY_H
#define PUPPY_H
using namespace std;

class Puppy {
    private:
        // satified 4 data members requirement
        //name of puppy, user will give this in the game
        string puppyName;
        // breed of puppy, for the user use a menu to pick a breed
        string puppyBreed;
        //charateristic to add dynamics
        string puppyAge;
        //characteristic to add dynamics
        string puppyGender;
        // characteristic of puppy to add dynamics
        // puppy's favorite toy
        string puppyToy;
        // characteristic of puppy to add dynamics
        //puppy's favorite color
        string puppyColor;
        // used as HP points to determine status
        int cPoints;
        
    public:
        // default constructor
        Puppy();
        //parametrized constructor        
        Puppy(string name, string breed, string age, string gender, string toy, string color, int points);
        //getters and setters
        void setPuppyName(string name);
        string getPuppyName();
        //getters and setters
        void setPuppyBreed(string breed);
        string getPuppyBreed();
        //getters and setters
        void setPuppyAge(string age);
        string getPuppyAge();
        //getters and setters
        void setPuppyGender(string gender);
        string getPuppyGender();
        //getters and setters
        void setPuppyToy(string toy);
        string getPuppyToy();
        //getters and setters
        void setPuppyColor(string color);
        string getPuppyColor();
        //initial cuddle points are based off of chosen puppies
        void setPuppyCPoints(int points);
        int getPuppyCPoints();
};
#endif