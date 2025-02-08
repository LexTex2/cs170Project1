#include "iteration.h"
#include <iostream>

using namespace std;

int main() {

    node node1;
    int test = 1;
    for(int j = 0; j < 3; j++)   {   
        for(int i = 0; i < 3; i++)   {
            node1.puzzle[j][i] = test;
            cout << node1.puzzle[j][i] << "   ";
            test++;
        }
    }
    cout << endl;
    node final;
    int test2 = 1;      //1 for true, 2 for false test for == operator overwrite
    for(int j = 0; j < 3; j++)   {   
        for(int i = 0; i < 3; i++)   {
            final.puzzle[j][i] = test2;
            cout << final.puzzle[j][i] << "   ";
            test2++;
        }
    }
        if (node1 == final) {
            cout << "true";
        } 
        else {cout << "false";}





    return 0;
}