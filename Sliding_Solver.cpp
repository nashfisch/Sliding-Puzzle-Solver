#include "Sliding_Solver.h"
#include "Board_Tile.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/*Sets the original, and goal configuration,
and creates a Board_Tile object representing the
original configuration and sets the first spot
in the priority queue to this object*/
Sliding_Solver::Sliding_Solver(string& startConfig, string& goalConfig) {
    ogConfig = startConfig;
    finalConfig = goalConfig;
    Board_Tile board(startConfig);
    tileQueue.push(board);
}

/*Solves the puzzle using the A* algorithm.*/
Board_Tile Sliding_Solver::Solve_Puzzle() {
/*Initializes vectors to store next possible
configurations and previous configurations.*/
  std::vector<Board_Tile> previousConfigures;
  std::vector<Board_Tile> nextConfigures;
  Board_Tile* goalB = new Board_Tile(finalConfig);
  previousConfigures.push_back(tileQueue.top());

  /*Creats a Board_Tile object that currently
  represents the original configuration.*/
  Board_Tile temp(ogConfig);

  /*A while loop that runs while the
  priority queue is not empty*/
  while (!tileQueue.empty()) {
    /*Sets the temp Board_Tile object we made
    to the top item on the minHeap. This object is
    then removed from the top of the heap.*/
    temp = tileQueue.top();
    cout<<"This is the current board"<<endl;
    temp.printPuzzle();
    tileQueue.pop();

    /*Sets the next configuration vector
    to the next possible configurations
    returned from the current
    configuration of temp.*/
    nextConfigures = temp.nextConfigs();

    /*We then check if any of the next
    possible configurations are equal
    to the final and automatically set
    our temp configuration to the final
    and return it. The function is then done.*/
    for(int i = 0; i < nextConfigures.size(); i++) {
        if(nextConfigures[i].getPuzzle() == finalConfig) {
            temp = nextConfigures[i];
            return temp;
        }
    }

    /*We have a for loop that cycles through
    all the next possible configurations.*/
    for (int i = 0; i < nextConfigures.size(); i++) {
      bool notRepeat = true;
      /*Another for loop that cycles through all
      the configurations ours has previously been.*/
      for (int j = 0; j < previousConfigures.size(); j++) {
        /*If any of the next possible configurations
        have been had before, a boolean variable returns false,
        and we check the next next possible configurations.*/
        if (nextConfigures[i].getPuzzle() == previousConfigures[j].getPuzzle()) {
          notRepeat = false;
        }
      }

      /*If the boolean returns true for a
      configuration, we find its Manhattan Disance
      so that it can be added to the minHeap,
      and then add this new configuration to the
      previously seen vector so it can be
      compared against others in the future.*/
      if (notRepeat) {
        nextConfigures[i].Manhattan_Distance(goalB);
        tileQueue.push(nextConfigures[i]);
        previousConfigures.push_back(nextConfigures[i]);
      }
    }
  }

  /*A Board_Tile object with the final
  configuration is returned.*/
  Board_Tile tile(finalConfig);
  return tile;
}

/*Overloads the > operator to help determine
which order Board_Tile objects go into the minHeap.*/
bool operator>(const Board_Tile& boardA, const Board_Tile& boardB) {
  return (boardA.getMovesNeeded() > boardB.getMovesNeeded());
}
