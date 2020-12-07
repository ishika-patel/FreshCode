// CS1300 Fall 2019
// Author: Ishika Patel
// Recitation: 104 - Anuj P
// Project 1 - Problem 6

#include <iostream>
#include <string>
using namespace std;

/* Algorithm: this function  takes three genomes and a sequence and prints the list of matched genomes.
1. Case 1: If one or more genomes or the sequence is an empty string, print “Genomes or sequence is empty.”
2. Case 2: If the length of the three genomes are different, your function should only print “Lengths of genomes are different.”
3. find the similarity score of each genome
4. sift through each of the genomes to see which one(s) are the highest
5. output includes a sentence on which genome is the best match
Input Parameters: 4 parameters in this order
    1.Genome 1, a string
    2.Genome 2, a string
    3.Genome 3, a string
    4. sequence (sub-sequence of the genomes), a string
Output/printing: which genome is the best match
Returns: none
*/

double findBestSimScore (string genome, string checkSequence){
    double final_similarity_score =0; // this variable will be used to check for the greatest similairty score later in the program
    
    if (checkSequence.length() > genome.length()) { //checks to see if  the sequence length is greater than the genome
        return 0;
    }
    
    else{ 
        for (int i = 0; i <=genome.length()-checkSequence.length(); i++){ // this for loop only goes through the gemone
        // genome.length()-checkSequence.length() was deployed so that the final set of characters in the string compared did not surpass genome's length 
            double similarity_score;
            int hamming_distance= 0; // this is the number of differences
            string genomeCompare = genome.substr(i,checkSequence.length()); // this variable selects the chunk of the genome that is being compared based on how long the sequence is
            // the step of i is used to move one character forward in the sequence phrase for comparison
            for (int j= 0; j<=checkSequence.length(); j++){ // this loop computes the comparison between two same length strings (made possible by the string genomeCompare)
                if (genomeCompare[j] != checkSequence[j]){
                    hamming_distance ++;
                }
            }
            similarity_score = ((double)checkSequence.length() - hamming_distance) / ((double)checkSequence.length());
        
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
    if (genome1 == "" || genome2 == "" || genome3 == "" || sequence == "") {
        cout << "Genomes or sequence is empty." << endl;
    }
    else if (genome1.length() != genome2.length() || genome1.length() !=genome3.length() || genome2.length() != genome3.length()) {
        cout << "Lengths of genomes are different." << endl;
    }
    
    else{
        double bestGenome1 = findBestSimScore(genome1,sequence);
        double bestGenome2 = findBestSimScore(genome2, sequence);
        double bestGenome3 = findBestSimScore(genome3, sequence);
        
// iterate once to fidn the max score between all the doubles
        double bestMatch = bestGenome1;
        if (bestGenome2 > bestMatch){
            bestMatch = bestGenome2;
        }
        if (bestGenome3> bestMatch){
            bestMatch = bestGenome3;
        }
// iterate a second time. this time comapring each genomes score to the max score       
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

int main() {
    //test1: two genomes have same similarity score
    // expected output: Genome 1 is the best match. \n Genome 2 is the best match.
    findMatchedGenome("AACT", "AACT","AATG", "AACT");
    
    //test2: genome lengths dont match
    // expected output: Lengths of genomes are different.
    findMatchedGenome("AAG","GATTACA","TGC", "TAC");
    
    //test3: empty parameter
    //expected output: Genomes or sequence is empty.
    findMatchedGenome("TTC","GCC","TCT","");
    
    //test4: Genome 1 is the best score
    //expected output: Genome 1 is the best match.
    findMatchedGenome("TAAGGCA","TCTGGGC","CTAATAT","AAG");
    
    //test5: Genome 2 is the best score
    //expected output: Genome 2 is the best match.
    findMatchedGenome("TAAGGCA","TACCTAC","AGCCAGA","TCT");
    
    //test6: Genome 3 is the best score
    //expected output: Genome 3 is the best match.
    findMatchedGenome("AATGTTTCAC","GGGGTTTCCC","GTACATTCAC","TACTA");
}