#include <iostream>
#include "iteration.h"


using namespace std;

int main() {

    int testMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {0, 7, 8}};

   
    int choice;
    cout << "Input '1' for Uniform Cost Search and '2' for Missing Tile: \n";
    cin >> choice;
    cout << endl;

    // for(int j = 0; j < 3; j++)   {  
    //     cout << endl; 
    //     for(int i = 0; i < 3; i++)   {
    //        cout << testMatrix[j][i] << "   ";
    //     }
    // }

    algoIteration matrix(choice, testMatrix);
    matrix.explore();

    return 0;
}