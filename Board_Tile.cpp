#include "Board_Tile.h"
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

/*Sets the config data mamber to the tileConfig string parameter,
as well as the movesFromStart data member to an empty string.*/
Board_Tile::Board_Tile(const string& tileConfig) {
   config = tileConfig;
   movesFromStart = "";
}

/*Returns the length of the movesFromStart data member,
as this is equal to the number of moves that have been made.*/
int Board_Tile::numMoves() const{
    return movesFromStart.length();
}

/*Returns the data member config.*/
string Board_Tile::getPuzzle() {
    return config;
}

/*Checks each direction of the configuration
to see if a change from the current configuration is possible.
If it is for a given direction, then the new
configuration is added to a vector. The vector of all
possible next configurations is returned at the functions end.*/
vector<Board_Tile> Board_Tile::nextConfigs() {
    string temp = config;
    vector<Board_Tile> nextBoards;
    if(this->canUp()) {
        Board_Tile up = moveUp();
        nextBoards.push_back(up);
    }
    if(this->canDown()) {
        Board_Tile down = moveDown();
        nextBoards.push_back(down);
    }
    if(this->canRight()) {
        Board_Tile right = moveRight();
        nextBoards.push_back(right);
    }
    if(this->canLeft()) {
        Board_Tile left = moveLeft();
        nextBoards.push_back(left);
    }
    return nextBoards;
}

/*Searches config to find the spot of the empty space '0'.
When found, this location is.*/
int Board_Tile::zeroSearch() {
    for(int i = 0; i < config.length(); i++) {
        if (config[i] == '0')
            return i;
    }
    return -1;
}

/*Goes through config and prints a visual
representation of the 3x3 tile puzzle.*/
void Board_Tile::printPuzzle() {
    cout<<"---------"<<endl;
    for(int i = 0; i < config.length(); i++) {
        if(i % 3 == 0) {
            cout<< "| ";
        }
        if(i % 3 == 2) {
            cout<<config[i]<<" |"<<endl;
        } else {
            cout<<config[i]<<" ";
        }
    }
    cout<<"---------"<<endl;
}

/*Checks if the configuration can be moved up. If it can,
a new Board_Tile object of this new configuration is returned.*/
Board_Tile Board_Tile::moveUp() {
    string temp = config;
    int zeroPos = zeroSearch();
    if (canUp())
      std::swap(temp[zeroPos], temp[zeroPos-3]);
    else
      cout <<endl<<"Can't move up"<<endl;
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'U';
    return newTile;
}

/*Checks if the configuration can be moved up.
Returns true if yes, false if not*/
bool Board_Tile::canUp() {
    int zeroPos = this->zeroSearch();
    if(zeroPos - 3 > 0) {
        return true;
    }
    return false;
}

/*Checks if the configuration can be moved down. If it can,
a new Board_Tile object of this new configuration is returned.*/
Board_Tile Board_Tile::moveDown() {
    string temp = config;
    int zeroPos = zeroSearch();
    if (canDown())
      std::swap(temp[zeroPos], temp[zeroPos+3]);
    else
      cout <<endl<<"Can't move down"<<endl;
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'D';
    return newTile;
}

/*Checks if the configuration can be moved down.
Returns true if yes, false if not*/
bool Board_Tile::canDown() {
    int zeroPos = this->zeroSearch();
    if(zeroPos + 3 <= 8) {
        return true;
    }
    return false;
}

/*Checks if the configuration can be moved right. If it can,
a new Board_Tile object of this new configuration is returned.*/
Board_Tile Board_Tile::moveRight() {
    string temp = config;
    int zeroPos = zeroSearch();
    if (canRight())
      std::swap(temp[zeroPos], temp[zeroPos+1]);
    else
      cout <<endl<<"Can't move right"<<endl;
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'R';
    return newTile;
}

/*Checks if the configuration can be moved right.
Returns true if yes, false if not*/
bool Board_Tile::canRight() {
    int zeroPos = this->zeroSearch();
    if(zeroPos % 3 < 2) {
        return true;
    }
    return false;
}

/*Checks if the configuration can be moved left. If it can,
a new Board_Tile object of this new configuration is returned.*/
Board_Tile Board_Tile::moveLeft() {
    string temp = config;
    int zeroPos = zeroSearch();
    if (canLeft())
      std::swap(temp[zeroPos], temp[zeroPos-1]);
    else
      cout <<endl<<"Can't move left"<<endl;
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'L';
    return newTile;
}

/*Checks if the configuration can be moved left.
Returns true if yes, false if not*/
bool Board_Tile::canLeft() {
    int zeroPos = this->zeroSearch();
        if(zeroPos % 3 >= 1) {
        return true;
    }
    return false;
}

/*Finds the Manhattan Distance of the calling configuration compared to a given goal configuration.*/
int Board_Tile:: Manhattan_Distance(const Board_Tile* goalconfig) {
  int  i = 0;
  int sum = 0;

  while (i < config.length()){
    string che = "0";
    if (config[i] == goalconfig->config[i]) {
      i++;
    } else {
      int j = 0;
      do {
        /*Checks to see if the current value of the puzzle
        is equal to that of the value found in the goal configuration.
        If it is, the distance from the current configuration to the goal
        configuration is calculated and added to the sum variable.
        This comparison is then done for each value on the current
        configuration compared to the goal configuration.*/
        if(config[i] == goalconfig->config[j]) {
          int row1, col1, row2, col2;
          row1 = i / 3;
          col1 = i % 3;
          row2 = j / 3;
          col2 = j % 3;

          if (config[i] == che[0]){
            sum = sum + 0;
          } else
          if ((fabs(row2 - row1) == 2 && fabs(col2 - col1) == 2)) {
            sum = sum + 4;
          } else if ((fabs(row2 - row1) == 1 && fabs(col2 - col1) == 1)) {
            sum = sum + 2;
          } else if ((fabs(row2 - row1) == 2 && fabs(col2 - col1) == 1) || (fabs(row2 - row1)
          == 1 && fabs(col2 - col1) == 2)) {
            sum = sum + 3;
          } else if (fabs(row2 - row1) == 1 || fabs(col2 - col1) == 1) {
            sum = sum + 1;
          } else if (fabs(row2 - row1) == 2 || fabs(col2 - col1) == 2) {
            sum = sum + 2;
          }
          j = config.length();
        } else {
          j++;
        }
      } while (j < config.length());
      i++;
    }
  }
  /*The total Manhattan Distance is set equal to
  the total sum recieved over the course of the
  do while loop, and the sum is returned.*/
  manHatD = sum;
  return sum;
}

/*Returns the number of moves taken plus
the Manhattan Distance to use for the
ordering of the minHeap.*/
int Board_Tile::getMovesNeeded() const{
    return numMoves() + manHatD;
}

/*Returns the string representing the moves taken.*/
string Board_Tile::returnMoves() {
    return movesFromStart;
}


