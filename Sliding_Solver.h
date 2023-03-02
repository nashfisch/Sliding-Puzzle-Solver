#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H
#include <queue>
#include <string>
#include "Board_Tile.h"
using namespace std;

class Sliding_Solver {
public:
    /*Creates a Sliding_Solver object with a given
    starting configuration and ending configuration*/

    Sliding_Solver(string& startConfig, string& goalConfig);
    //A* algorithm that solves the puzzle
    Board_Tile Solve_Puzzle();

    friend bool operator>(Board_Tile&, Board_Tile&);


private:
    //A minHeap of Board_Tile objects
    priority_queue<Board_Tile, std::vector<Board_Tile>, std::greater<Board_Tile>> tileQueue;
    //A string storing the original configuration
    string ogConfig;
    //A string storing the goal configuration
    string finalConfig;




};



#endif // SLIDING_SOLVER_H
