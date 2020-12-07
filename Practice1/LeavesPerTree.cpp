#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

// Your function prints/displays/outputs the number of leaves per tree and, 
// if the trees are producing more leaves per tree, it also displays "More leaves than last year", on the next line.
// Last year the university estimated 10,000 leaves per tree.

// Each leaf weighs 0.001 pounds and there are 1,031 trees on campus.

void LeavesPerTree(double pounds_of_leaves)
{
    int last_year_leaves = 10000;
    double total_leaves;
    double leaves_in_tree;
 
    total_leaves = pounds_of_leaves / 0.001;
    leaves_in_tree = total_leaves / 1031;
    cout << leaves_in_tree << endl;
   
    if (leaves_in_tree > last_year_leaves)
    {
        cout << "More leaves than last year";
    }
}
 
 
int main()
{
    LeavesPerTree(13);
}