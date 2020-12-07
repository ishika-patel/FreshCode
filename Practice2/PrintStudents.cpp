#include <iostream> 
#include <fstream>
#include <string.h>
using namespace std;

/*Create a function named PrintStudents, which takes a string input
filename and an integer minimum score value and a string output file name 
as a parameters.  The function will read the student scores and names from the file
and output the names of the students with scores greater than or equal to the value given. 
This function returns the integer number of entries read from the file.  
If the input file cannot be opened, return -1 and do not print anything to the file.
*/

int PrintStudents(string infilename, int minValue, string outfilename){
    ifstream infile;
    ofstream outfile;
    int returnVal = 0;
    
    infile.open(infilename);
    if (infile.fail()) {
        return -1;
    }
    outfile.open(outfilename);
    
    string line;
    while(getline(infile,line)) {
        string array[3];
        split(line, ',', array, 3);
        
        if(stoi(array[1]) >= minValue) {
            outfile << array[0] << ", "<< array[2] << endl;
        }
        returnVal++;
    }
    
    infile.close();
    outfile.close();
    return returnVal;
}