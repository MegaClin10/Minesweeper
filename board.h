#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <vector>
class Board {
private:
    int mineRem, size;
    std::vector<std::vector<Cell>> gameBoard; //dude idk how the fuck to make a 2d vector work god fucking damnit. the problem is that its not getting initialized so everything is fucked up.
    std::vector<int> assignMines();

public:
    Board();
    Board(int size);
    bool findMines(int row, int col);
    void printGameBoard();
};

#endif
