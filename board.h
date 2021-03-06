#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <vector>
#include <queue>
class Board {
private:
    int mineRem, size, turn;
    std::vector<std::vector<Cell>> gameBoard;
    std::vector<int> assignMines();
    void adjacentMines(int r, int rStart, int rEnd, int c, int cStart, int cEnd);
    void findAllAdjacentMines();
    void clearAdjacentCells(int row, int col);
    void clearHelper(int r, int rStart, int rEnd, int c, int cStart, int cEnd, std::queue<Cell*>& mines);

public:
    Board();
    Board(int size);
    bool clearCells(int row, int col);
    void printGameBoard();
};

#endif
