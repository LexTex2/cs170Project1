#ifndef ITERATION_H
#define ITERATION_H
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;


struct node   {
    int puzzle[3][3];
    int row;
    int col;
    int heuristic;
    int depth;
    


    bool operator==(const node nextVal) const;  //used to compare if final and current puzzle matrix are equiv

    bool operator<(const node nextVal) const;   

    //node::node();
      
};

bool node::operator==(const node nextVal) const {

    for(int j = 0; j < 3; j++)   {     //j = row #
        for(int i = 0; i < 3; i++)   {     //i = col #
            cout << "u";
            if (nextVal.puzzle[j][i] != puzzle[j][i])   {     //compare equiv positions value between current puzzle and puzzle soltion
                return false;
            }
        }
    }
    return true;
}

bool node::operator<(const node nextVal) const {
    if (heuristic + depth > nextVal.heuristic + nextVal.depth)   {
        return true;
    }
    else {
        return false;
    }
}

// node::node()   {
//     for(int j = 0; j < 3; j++)   {     //j = row #
//         for(int i = 0; i < 3; i++)   {     //i = col #
//             puzzle[j][i] = 0;
//         }
//     }
// }



#endif