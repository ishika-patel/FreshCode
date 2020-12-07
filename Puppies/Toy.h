#ifndef TOY_H
#define TOY_H
using namespace std;

class Toy {
    private:
        // reading in from files
        //satifies 4 data memers requirement
        string toyName;
        string question;
        string choice;
        string answer;
        
    public:
        // default constructor
        Toy();
        // parametrized constuctor based on reading in from a file
        Toy(string toyName_, string question_,string choice_, string answer_);
        //getters and setters
        void setToyName(string toyName_);
        string getToyName();
        //getters and setters
        void setQuestion(string question_);
        string getQuestion();
        //getters and setters
        void setChoice(string choice_);
        string getChoice();
        //getters and setters
        //will have to use stoi to check if user input is correct
        void setAnswer(string answer_);
        string getAnswer();
};
#endif