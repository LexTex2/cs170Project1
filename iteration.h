#ifndef ITERATION_H
#define ITERATION_H
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node   {
    int puzzle[3][3];   //2D matrix array
    int row;    //rows (j)
    int col;    //columns (i)
    int heuristic;  //h(n)
    int depth;
    
    bool operator==(const node nextVal) const;  //used to compare if final and current puzzle matrix are equiv
    bool operator<(const node nextVal) const;   
    node &operator=(const node nextVal);      
};

bool node::operator==(const node nextVal) const {
    for(int j = 0; j < 3; j++)   {     //j = row #
        for(int i = 0; i < 3; i++)   {     //i = col #
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

node &node::operator=(const node nextVal)  {
    heuristic = nextVal.heuristic;
    depth = nextVal.depth;

    for (int j = 0; j < 3; j++)   {
        for (int i = 0; i < 3; i++)   {
            puzzle[j][i] = nextVal.puzzle[j][i];
        }
    }
    return *this;
}

class algoIteration   {
    public:
        node final;     //soltuion matrix
        int algoPicked;     //for later
        node orig;      //passed in/starter matrix
        int nodesTotal;
        priority_queue<node> rawPush;   //priority queue
        vector<node> oldNodes;      //vector for nodes already visited/to not repeat

    void expand(const node &searchNode);  //
    void explore();
    bool repeatedNode(const node &searchNode);






}


#endif