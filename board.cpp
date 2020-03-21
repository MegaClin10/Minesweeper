#include "board.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

Board::Board() {
    mineRem = 0;
    size = 0;
    for(int r = 0; r < 16; r++)
        for(int c = 0; c < size; c++)
            cout << "temp" << endl; //should be same as param board
}

Board::Board(int size) {
    if(size == 16)
        mineRem = 40;
    else if(size == 30)
        mineRem = 99;
    else {
        cout << "Enter valid board size" << endl;   
        exit(0);
    }
    //Instantiates values in 2D vector
    for(int r = 0; r < 16; r++){
        vector<Cell> gameBoardRows;
        for(int c = 0; c < size; c++){
            gameBoardRows.push_back(Cell());
        }
        gameBoard.push_back(gameBoardRows);
    }
    this->size = size;
    int count = -1;
    vector<int> mines = assignMines();
    //Changes vector attributes to match assign mines
    for(int r = 0; r < 16; r++) {
        for(int c = 0; c < size; c++) {
            count++;
            gameBoard[r][c].idval = count;
            if(mines.size() > 0) {
                if(gameBoard[r][c].idval == mines[mines.size()-1]) {
                    mines.pop_back();
                    gameBoard[r][c].mine = true;
                }
            }
        }
    }
}

vector<int> Board::assignMines() {
    vector<int> minesrand;
    int numCells;
    if(size == 16)
        numCells = 16*16;
    else
        numCells = 30*16;
    for(int i = 0; i < numCells; i++)
        minesrand.push_back(i);
    srand(time(NULL));
    random_shuffle(minesrand.begin(), minesrand.end());
    vector<int> mines;
    for(int i = 0; i < mineRem; i++)
        mines.push_back(minesrand[i]);
    sort(mines.begin(), mines.end());
    reverse(mines.begin(), mines.end());
    return mines;
}

void Board::printGameBoard() {
    for(int r = 0; r < 16; r++){
        for(int c = 0; c < size; c++){
            if(gameBoard[r][c].mine)
                cout << "x ";
            else
                cout << "o ";
        }
        cout << endl;
    }
}