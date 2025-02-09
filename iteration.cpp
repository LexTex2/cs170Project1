#include "iteration.h"
#include <iostream>

using namespace std;

void algoIteration::findChildren(const node &searchNode)   {
    node quickUse = searchNode;
    if (quickUse.row > 0)   {                           //up on matrix if possible
        node childNode = quickUse;
        swap(childNode.puzzle[childNode.row - 1][childNode.col], childNode.puzzle[childNode.row][childNode.col]);
        //update heurist for A* functs later
        setHeuristic(childNode);
        childNode.row -= 1;
        childNode.depth += 1;
        if (isNewNode(childNode))   {
            rawPush.push(childNode);
        }
    }
    
    if (quickUse.row < 2)   {                           //down on matrix if possible
        node childNode = quickUse;
        swap(childNode.puzzle[childNode.row + 1][childNode.col], childNode.puzzle[childNode.row][childNode.col]);
        //update heurist for A* functs later
        setHeuristic(childNode);
        childNode.row += 1;
        childNode.depth += 1;
        if (isNewNode(childNode))   {
            rawPush.push(childNode);
        }
    }
    
    if (quickUse.col < 2)   {                           //right on matrix is possible
        node childNode = quickUse;
        swap(childNode.puzzle[childNode.row][childNode.col + 1], childNode.puzzle[childNode.row][childNode.col]);
        //update heurist for A* functs later
        setHeuristic(childNode);
        childNode.depth += 1;
        childNode.col += 1;
        if (isNewNode(childNode))   {
            rawPush.push(childNode);
        }
    }

    if (quickUse.col > 0)   {                           //left on matrix is possible
        node childNode = quickUse;
        swap(childNode.puzzle[childNode.row][childNode.col - 1], childNode.puzzle[childNode.row][childNode.col]);
        //update heurist for A* functs later
        setHeuristic(childNode);
        childNode.depth += 1;
        childNode.col -= 1;
        if (isNewNode(childNode))   {
            rawPush.push(childNode);
        }
    }
}  
    
void algoIteration::explore()   {
    node currentNode;
    rawPush.push(orig);                                 //set initial node in priority q
    bool solutionFound = false;

    while (!solutionFound && rawPush.size() > 0)   {
        currentNode = rawPush.top();                    //fetch top of priority q
        setHeuristic(currentNode);
        viewProgress(currentNode, solutionFound);       //so we can see whats happening!
        oldNodes.push_back(currentNode);                //save used nodes to avoid repeat loops
        if (rawPush.size() > mostNodes)   {
            mostNodes = rawPush.size();
        }
        rawPush.pop();                                  //remove node just visited in priority q
        if (currentNode == endState)   {
            cout << "solution found!" << endl;
            cout << "final depth: ";
            cout << currentNode.depth << endl;  
            solutionFound = true;
            break;
        }
        else   {
            findChildren(currentNode);                  //finding and making them kids
        }
        // if (!solutionFound)   {
        //     cout << "no sol yet" << endl;
        // }

    }
}
void algoIteration::viewProgress(const node printme, bool finalMatrix)  {
    for(int j = 0; j < 3; j++)   {  
        cout << endl; 
        for(int i = 0; i < 3; i++)   {
           cout << printme.puzzle[j][i] << "   ";
        }
    } 
    cout << endl;
    if (!finalMatrix)   {
        cout << "current depth g(n): " << printme.depth << endl;
        cout << "h(n): " << printme.heuristic << endl;
    }
    else {
        cout << "final depth g(n): " << printme.depth << endl;
        cout << "final heuristic h(n): " << printme.heuristic << endl;
    }
    cout << endl;
}

void algoIteration::setHeuristic(node &getHeur)   {
    if (algoPicked == 1)   {
        getHeur.heuristic = 0;
    }
    if (algoPicked == 2)   {
        int count = 0;
        for (int j = 0; j < 3; j++)   {
            for (int i = 0; i < 3; i++)   {
                if (getHeur.puzzle[j][i] != endState.puzzle[j][i])   {
                    count++;
                }
            }
        }
       getHeur.heuristic = count; 
    }
    if (algoPicked == 3)   {
        double aproxDistance = 0.0;
        int x = 0;
        int y = 0;
        
        for (int k = 0; k < 3; k++)   {
            for (int l = 0; l < 3; l++)   {

                if (getHeur.puzzle[k][l] != endState.puzzle[k][l])  {

                    for (int j = 0; j < 3; j++)   {
                        for (int i = 0; i < 3; i++)   {
                                if(getHeur.puzzle[k][l] == endState.puzzle[j][i])   {
                                    x = j;
                                    y = i;
                                    break;
                                }
                        }
                    }
                    aproxDistance += euclideanMath(k-x, l-y);
                }
            }
        }
        getHeur.heuristic = aproxDistance;
    }
}


double algoIteration::euclideanMath(int x, int y)   {
    return sqrt(pow(x, 2) + pow(y, 2));
}

algoIteration::algoIteration(int userChoice, int startMatrix[3][3])   {
    algoPicked = userChoice;    
    setInit(startMatrix);
    setHeuristic(orig);
    orig.depth = 0;
    mostNodes = 0;
    setSolution();
}

void algoIteration::setSolution()   {
    for (int j = 0; j < 3; j++)   {   
        for (int i = 0; i < 3; i++)   {
            endState.puzzle[j][i] = final[j][i];
            if (final[j][i] == 0)   {
                endState.row = j;
                endState.col = i;
            } 
        }
    }
}
  
void algoIteration::setInit(int tempArray[3][3])  {
    for (int j = 0; j < 3; j++)   {   
        for (int i = 0; i < 3; i++)   {
            orig.puzzle[j][i] = tempArray[j][i];
            if (tempArray[j][i] == 0)   {
                orig.row = j;
                orig.col = i;
            } 
        }
    }    
}

bool algoIteration::isNewNode(const node &searchNode)   {
    for (int k = 0; k < oldNodes.size(); k++)   {   
            if (searchNode == oldNodes.at(k))   {
                return false;
            }
    }
    return true;
}