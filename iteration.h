#ifndef ITERATION_H
#define ITERATION_H
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

struct node   {
    int puzzle[3][3];       //2D matrix array
    int row;                //rows (j)
    int col;                //columns (i)
    int heuristic;          //h(n)
    int depth;              //g(n)
    int parentNode;         //to keep track of parents node for retraversal
    
    //overriding operators for algo traversal when comparing nodes
    bool operator==(const node nextVal) const {
        for(int j = 0; j < 3; j++)   {                          //j = row #
            for(int i = 0; i < 3; i++)   {                      //i = col #
                if (nextVal.puzzle[j][i] != puzzle[j][i])   {   //compare equiv positions value between current puzzle and puzzle soltion
                    return false;
                }
            }
        }
        return true;
    }
    
    bool operator<(const node nextVal) const {                  //override comparison operator for 2D matrix
        if (heuristic + depth > nextVal.heuristic + nextVal.depth)   {
            return true;
        }
        else {
            return false;
        }
    }
    
    node operator=(const node nextVal)  {                       //override assignemtn operator for 2D matrix
        heuristic = nextVal.heuristic;
        depth = nextVal.depth;
        parentNode = nextVal.parentNode;
    
        for (int j = 0; j < 3; j++)   {
            for (int i = 0; i < 3; i++)   {
                puzzle[j][i] = nextVal.puzzle[j][i];
                if (nextVal.puzzle[j][i] == 0)   {
                    row = j;
                    col = i;
                }
            }
        }
        return *this;
    }  
};

class algoIteration   {
    public:
        //data
        node endState;
        int final[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}};                 //soltuion matrix
        int algoPicked;                 //user algo choice differentation 
        node orig;                      //passed in/starter matrix
        priority_queue<node> rawPush;   //priority queue
        vector<node> oldNodes;          //vector for nodes already visited/to not repeat
        int mostNodes;
        stack<node> solutionOutput;     //stack for pushing/storing/popping solution path taken (neatly)

        //functions
        void findChildren(const node &searchNode);               //we WILL find those kids >:)
        void setSolution();                                      //move solution matrix into node type
        void explore();                                          //main organization for queue management
        bool isNewNode(const node &searchNode);                  //will check if child node already exists
        algoIteration(int userChoice, int startMatrix[3][3]);           //to add: passed in 2D array from user
        void viewProgress(node &currMatrix, bool finalMatrix);    // will print out depth/ matrix' for tracking n testing
        void setHeuristic(node &getHeur);                         //set heuristic val for seperate algos
        void setInit(int tempArray[3][3]);                       //move initial matrix into node type
        double euclideanMath(int x, int y);                      //function to do math (cleaner to see)
        void viewOptSolution();
};

#endif