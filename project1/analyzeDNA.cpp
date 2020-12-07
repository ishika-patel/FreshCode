// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 7

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: call on the menu function to allow the user to start his/her journey. based on the number chosen 1-4 the user will see a similairty score, the best similarity score or the best genome match
1. helper function calcSimScore is called on. the input options fill in the parameters to this function. return back to the menu
2. helper function findBestSimScore is called on. the input options fill in the parameters to this function. return back to the menu
3. helper function findMatchedGenome is called on. the input options fill in the parameters to this function. return back to the menu
4. quits the simulation
5.if number beyond 1-4 is chosen output Invalid
Input Parameters: based on which number is chosen on the menu, there are certian uder inputs necessary
Output/printing: 1. similarity score (double) 2. best similarity score(double) 3. best matched genome (output)
Returns: none
*/

// Show menu function
void showMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
}

double calcSimScore(string sequence1, string sequence2){
    int string_length = sequence1.length();
    
    if (sequence1 == "" || sequence2 == "") { //checks to see if parameters were let empty, if so returns 0
        return 0;
    }
    
    if (sequence1.length() == sequence2.length()){ 
        int hamming_distance = 0; //this variable represents the number of differences between the sequences
        for(int i = 0; i <=sequence1.length(); i++) { //loops through each index of the sequence, only occurs when the lengths of both seuqnces are the same
            if (sequence1[i] != sequence2[i]) { // adds to the hamming_distance when chracters are not the same, otherwise no arithmetic occurs
                hamming_distance = hamming_distance +1;
            }
        }
       double similarity_score = (string_length - hamming_distance); // the following two lines compute the similairty_score arithmetic
       similarity_score = similarity_score/string_length; 
       return similarity_score;
    }
    else { 
        return 0;
    }
}

double findBestSimScore (string genome, string sequence){
    double final_similarity_score =0; // this variable will be used to check for the greatest similairty score later in the program
     if (genome == "" || sequence == "") { //checks to see if parameters were let empty, if so returns 0
        return 0;
    }
    
    if (sequence.length() > genome.length()) { //checks to see if  the sequence length is greater than the genome
        return 0;
    }
    
    else{ 
        for (int i = 0; i <=genome.length()-sequence.length(); i++){ // this for loop only goes through the gemone
        // genome.length()-sequence.length() was deployed so that the final set of characters in teh string compared did not surpass genome's length 
            double similarity_score;
            int hamming_distance= 0; // this is the number of differences
            string genomeCompare = genome.substr(i,sequence.length()); // this variable selects the chunk of the genome that is being compared based on how long the sequence is
            // the step of i is used to move one chracter forward in the sequence phrase for comparison
            for (int j= 0; j<=sequence.length(); j++){ // this loop computes the comparison between two same length strings (made possible by the string genomeCompare)
                if (genomeCompare[j] != sequence[j]){
                    hamming_distance ++;
                }
            }
            similarity_score = ((double)sequence.length() - hamming_distance) / ((double)sequence.length());
        
            if (similarity_score> final_similarity_score) { // this if block compares all of the similarity score values to determine the highest, which is stored in final_similarity_score
                final_similarity_score = similarity_score;
            }
            else {
                similarity_score = similarity_score;
            }
        }
    }
    return final_similarity_score;
}

void findMatchedGenome(string genome1, string genome2, string genome3, string sequence) {
    if (genome1 == "" || genome2 == "" || genome3 == "" || sequence == "") { //checks to see if any parameters were left empty
        cout << "Genomes or sequence is empty." << endl;
    }
    else if (genome1.length() != genome2.length() || genome1.length() !=genome3.length() || genome2.length() != genome3.length()) { //checks lengths of parameters (must be same)
        cout << "Lengths of genomes are different." << endl;
    }
    
    else{
        double bestGenome1 = findBestSimScore(genome1,sequence);
        double bestGenome2 = findBestSimScore(genome2, sequence);
        double bestGenome3 = findBestSimScore(genome3, sequence);
        
// iterate once to find the max score between all the doubles
        double bestMatch = bestGenome1;
        if (bestGenome2 > bestMatch){
            bestMatch = bestGenome2;
        }
        if (bestGenome3> bestMatch){
            bestMatch = bestGenome3;
        }
// iterate a second  time. this time comapring each genomes score to the max score       
        if (bestMatch == bestGenome1) {
            cout<< "Genome 1 is the best match." << endl;
        }
        
        if(bestMatch == bestGenome2) {
            cout<< "Genome 2 is the best match." << endl;
        }
        
        if(bestMatch == bestGenome3){
            cout<< "Genome 3 is the best match." << endl;
        }
    }
}


void analyzeDNA() {
    showMenu();
    int userInputNumber;
    cin >> userInputNumber;
    
    if(userInputNumber == 1){
    // Find similarity score
    cout<< "Enter sequence 1:" << endl;
    string sequence1;
    cin >> sequence1;
    cout<< "Enter sequence 2:" << endl;
    string sequence2;
    cin >> sequence2;
    cout << "Similarity score: " << calcSimScore(sequence1,sequence2) << endl; //call on helper function
    
    analyzeDNA(); //goes back to main menu until user decides to quit (option 4) 
    }
    
    else if(userInputNumber == 2){
        // Find the best similarity score
        cout<< "Enter genome:" << endl;
        string genome;
        cin >> genome;
        cout<< "Enter sequence:" << endl;
        string sequence;
        cin >> sequence;
        cout << "Best similarity score: " << findBestSimScore (genome, sequence) << endl; //call on helper function
    
        analyzeDNA(); //goes back to main menu until user decides to quit (option 4)
    }
    
    else if(userInputNumber == 3){
        //Analyze the genome sequences
        cout<< "Enter genome 1:" << endl;
        string genome1;
        cin >> genome1;
        cout<< "Enter genome 2:" << endl;
        string genome2;
        cin >> genome2;
        cout<< "Enter genome 3:" << endl;
        string genome3;
        cin >> genome3;
        cout<< "Enter sequence:" << endl;
        string sequence;
        cin >> sequence;
        findMatchedGenome(genome1,genome2,genome3,sequence); //calls on helper function
        
        analyzeDNA(); //goes back to main menu until user decides to quit (option 4)
    }

    else if(userInputNumber == 4) {
        // QUIT
        cout<< "Good bye!" << endl;
    } 
    
    else{ 
        cout<< "Invalid option." << endl;
        
        analyzeDNA(); //goes back to main menu until user decides to quit (option 4)
    }
}

int main() {
  analyzeDNA();  
}