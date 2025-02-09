#include <iostream>
#include "iteration.h"


using namespace std;

int main() {

    int testMatrix[3][3] = {
        {1, 3, 6},
        {5, 0, 7},
        {4, 8, 2}};

    // int val = 1;
    // for (int j = 0; j < 3; j++)   {
    //     for (int i = 0; i < 3; i++)   {
    //         testMatrix[j][i] = val;
    //         if (val != 0)   {
    //             val++;
    //         }
    //         if (val == 8)   {
    //             val = 0;
    //         }

    //     }
    // }

    // node final;
    // int test2 = 1;      //1 for true, 2 for false test for == operator overwrite
    // for(int j = 0; j < 3; j++)   {   
    //     for(int i = 0; i < 3; i++)   {
    //         final.puzzle[j][i] = test2;
    //         cout << final.puzzle[j][i] << "   ";
    //         test2++;
    //     }
    // }
    //     if (node1 == final) {
    //         cout << "true";
    //     } 
    //     else {cout << "false";}
    int choice;
    cout << "Input 1: \n";
    cin >> choice;
    cout << endl;

    for(int j = 0; j < 3; j++)   {  
        cout << endl; 
        for(int i = 0; i < 3; i++)   {
           cout << testMatrix[j][i] << "   ";
        }
    }

    algoIteration passin(choice, testMatrix);
    passin.explore();

    return 0;
}