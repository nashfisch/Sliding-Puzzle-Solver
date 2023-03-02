#include "Board_Tile.h"
#include "Sliding_Solver.h"
#include <iostream>
using namespace std;


int main() {

    string goalBoard;
    string initialBoard;

    cout<<"Enter the initial board: ";
    cin>>initialBoard;
    cout<<endl<<"Enter the goal board: ";
    cin>>goalBoard;

    Board_Tile* gBoard = new Board_Tile(goalBoard);
    Board_Tile* sBoard = new Board_Tile(initialBoard);

    Sliding_Solver solver(initialBoard, goalBoard);
    Board_Tile solvedBoard = solver.Solve_Puzzle();

    cout<<"Final board: "<<solvedBoard.getPuzzle()<<endl;
    cout<<"Total moves: "<<solvedBoard.numMoves()<<endl;
    cout<<"Steps taken: "<<solvedBoard.returnMoves()<<endl;


    return 0;
}
