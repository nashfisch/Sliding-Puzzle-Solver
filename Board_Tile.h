#ifndef BOARD_TILE_H
#define BOARD_TILE_H
#include <string>
#include <vector>
using namespace std;

class Board_Tile {
public:
    //Creates a Board_Tile object with a given configuration.
    Board_Tile(const string& tileConfig);

    /*Returns a vector of all the next possible
    configurations a given configuration can become*/
    vector<Board_Tile> nextConfigs();

    //Returns the number of moves that have been made.
    int numMoves() const;

    //Returns a string of the current configuration.
    string getPuzzle();

    /*Finds the Manhattan Distance of the Board_Tile objects
    configuration given a goal configuration.*/
    int Manhattan_Distance(const Board_Tile* goalConfig);

    //Finds the location of the empty space in the tile puzzle.
    int zeroSearch();

    //Prints a visual of the 3x3 slide puzzle.
    void printPuzzle();

    //Returns a string of the moves that have been made.
    string returnMoves();

    //Checks if a configuration can move in any given direction.
    bool canUp();
    bool canDown();
    bool canRight();
    bool canLeft();

    //Returns a new Board_Tile object of the given swapped direction.
    Board_Tile moveUp();
    Board_Tile moveDown();
    Board_Tile moveRight();
    Board_Tile moveLeft();

    //Finds the estimate of how many moves needed to get to the goal.
    int getMovesNeeded() const;

private:
    //A string representing a 3x3 tile puzzle configuration.
    string config;
    //A string storing all the moves taken to get to the current configuration.
    string movesFromStart;
    //An integer storing the Manhattan Distance of the configuration.
    int manHatD;
};

#endif // BOARD_TILE_H
