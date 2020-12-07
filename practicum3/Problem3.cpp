Create a class named AntonymDictionary which will hold a list of words and their associated antonyms, and will allow a user to search for a particular word or its antonym.
AntonymDictionary should have the following private data members:
 words (a string array of size 50 with all the words)
 antonyms (a string array of size 50 for the antonyms). 

AntonymDictionary should have a default constructor and should initialize the words and antonyms array to empty strings ("") and the following public methods: 
int LoadWords(string filename)
int SearchForWord(string wordName)
string GetAntonym(string wordName)

LoadWords should read in a filename where each line is the name of a word and its antonym, separated by a comma. If the file does not exist, return -1. Otherwise, return 0. The method should read the file and put the appropriate data into words and antonyms. Each word and its antonym will only appear once. The last line may or may not end in '\n'.

Few lines from the file to be loaded:
good,bad
beautiful,ugly
up,down
slow,fast
SearchForWord will search for a particular word, and return the index where that word is located. It should return -1 if the word is not found.
GetAntonym will take in a word and return the corresponding antonym. It should return an empty string ("") if the word is not found.

You only need to write the class definition and any code that is required for that class.
NOTE: We have provided a function that may make the parsing easier:
      int split(string str, char sep, string array[], int arraySize);
      
      
      
// answer
      class AntonymDictionary {
    private:
        string words[50];
        // words (a string array of size 50 with all the words)
        string antonyms[50];
        //antonyms (a string array of size 50 for the antonyms).  
    
    public:
    AntonymDictionary();
    int LoadWords(string filename);
    int SearchForWord(string wordName);
    string GetAntonym(string wordName);
};

AntonymDictionary:: AntonymDictionary() {
    for(int i = 0; i<50; i++){
        words[i] = "";
        antonyms[i] = "";
    }
}

int AntonymDictionary:: LoadWords(string filename){
    int i = 0;
    string line; 
    ifstream file; //says there is a file we will access and we are taking data from it
    
    file.open(filename); //opens the file
    
    string testArray[2];
    
    if(file.is_open()) {
        while(getline(file, line)) {
            if(line != "") {
                split(line, ',', testArray, 2);
                
                words[i] = testArray[0];
                antonyms[i] = testArray[1];
                i++;
            }
        }
    return 0;
    }
    else if (!file.is_open()) {
        return -1;
    }
}

int AntonymDictionary:: SearchForWord(string wordName){
    int index = -1;
    for (int i = 0; i<50; i++) {
        if (words[i] == wordName) {
        index = i;
         }
    }
     return index;
}

string AntonymDictionary:: GetAntonym(string wordName){
    int i = SearchForWord(wordName);
    if (i == -1) {
        return "";
    }
    else {
        return antonyms[i];
    }
}
