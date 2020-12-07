// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 5

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: this function takes a genome and a sequence and returns the highest similarity score found in the genome as a double.
1. declare and initize a variable that carries the similarity score(double), this variable is returned as the bestSimScore later
2. check to see if either or both parameters are empty, if so then return 0 
3. check to see if the length of the sequence is longer than the genome, if so return 0
4. if not, move to a for loop which will run thorough the genome and check it to the sequence
5. there will be 2 for loop.
    a. to increment the substring of the part of the genome that is being compared
    b. to compare the substring and genome itself
        i. if the character at the same index is the same, move to check the next character
        ii. if the characters are different increment the hamming distance by 1 (for each difference)
6. calculate the similiarity score and only store the creater similarity score
note: similarity score = (string_length - hamming_distance) / string_length
Input Parameters: two string parameters in the following order:
    1. a string parameter for the genome (complete set of genes)
    2. a string parameter for the sequence (sub-sequence of the genome)
Output/printing: none
Returns: return the highest similarity score as a double. If the length of the sequence is longer than the genome, then the function should return 0.
*/

//dont go outside string length-1


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

int main() {
    // test1: full match
    //Expected Result: 1
    findBestSimScore("ATACCAG", "TACC");

    //test2: 1/3 match, both strings even lengths
    // expected result: 0.33333
   findBestSimScore("ATACCC", "AGG");
    
    //test3: No similarity
    //expected result: 0
    findBestSimScore("AA", "TT");
    
    //test4: both empty
    // expected return: 0
    findBestSimScore("", "");
    
    //test5: one empty
    // expected return: 0
    findBestSimScore("AAA", "");
    
    //test5: sequence is large than genome
    // expected return: 0
    findBestSimScore("A", "TAGCTAGG");
}