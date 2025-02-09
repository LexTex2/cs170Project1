#include <iostream>
#include "iteration.h"

using namespace std;

int main() {

    // int testMatrix[3][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {0, 7, 8}};

   

    int testMatrix[3][3] = {
        {1, 6, 7},
        {5, 0, 3},
        {4, 8, 2}};
    
       
    int choice; 

    cout << "Would you like to input a matix or use this one?\n";
    for(int j = 0; j < 3; j++)   {  
        cout << endl; 
        for(int i = 0; i < 3; i++)   {
           cout << testMatrix[j][i] << "   ";
        }
    }
    cout << endl;
    cout << "Type 1 for this one, or type 2 to input another\n";
    int input;
    cin >> input;
    cout << "Input: \n";

    if (input == 2)   {
        for(int j = 0; j < 3; j++)   {  
            for(int i = 0; i < 3; i++)   {
                cin >> testMatrix[j][i];
            }
        }
    }
    cout << "your matrix\n";
    for(int j = 0; j < 3; j++)   {  
        cout << endl; 
        for(int i = 0; i < 3; i++)   {
            cout << testMatrix[j][i] << "   ";
        }
    }
    cout << endl;
    cout << "Input '1' for Uniform Cost Search and '2' for Misplaced Tile and '3' for Manhattan Distance: \n";
    cin >> choice;
    cout << endl;

    algoIteration matrix(choice, testMatrix);
    matrix.explore();
    matrix.viewOptSolution();

    return 0;
}