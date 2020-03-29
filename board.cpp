#include "board.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

Board::Board() {
    mineRem = 0;
    size = 0;
    turn = 0;
}

Board::Board(int size) {
    turn = 0;
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
    //for loop to find all mines adjacent to every cell
    //make a function for this in the future
    for(int r = 0; r < 16; r++) {
        for(int c = 0; c < size; c++) {


            if(r == 0 && c == 0) {
                for(int rsub = r; rsub <= r + 1; rsub++)
                    for(int csub = c; csub <= c + 1; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }
            else if(r == 0 && c == size - 1) {
                for(int rsub = r; rsub <= r + 1; rsub++)
                    for(int csub = c - 1; csub <= c; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }
            else if(r == 16 - 1 && c == size - 1) {
                for(int rsub = r - 1; rsub <= r; rsub++)
                    for(int csub = c - 1; csub <= c; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }
            else if(r == 16 - 1 && c == 0) {
                for(int rsub = r - 1; rsub <= r; rsub++)
                    for(int csub = c; csub <= c + 1; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }
            else if(r == 0) {
                for(int rsub = r; rsub <= r + 1; rsub++)
                    for(int csub = c - 1; csub <= c + 1; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }       
            else if(r == 16 - 1) {
                for(int rsub = r - 1; rsub <= r; rsub++)
                    for(int csub = c - 1; csub <= c + 1; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }     
            else if(c == 0) {
                for(int rsub = r - 1; rsub <= r + 1; rsub++)
                    for(int csub = c; csub <= c + 1; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            }   
            else if(c == size - 1) {
                for(int rsub = r - 1; rsub <= r + 1; rsub++)
                    for(int csub = c - 1; csub <= c; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
            } 
            else /*(r >= 1 && r < 16 - 1 && c >= 1 && c < size - 1)*/ {
                for(int rsub = r - 1; rsub <= r + 1; rsub++)
                    for(int csub = c - 1; csub <= c + 1; csub++)
                        gameBoard[r][c].adjMines += (gameBoard[rsub][csub].mine)? 1 : 0;
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

bool Board::findMines(int row, int col) {
    row--;
    col--;
    if(turn == 0 && gameBoard[row][col].mine) {
        gameBoard[row][col].mine = false;
        for(int i = 0; i < size; i++) {
            if(!gameBoard[0][i].mine) {
                gameBoard[0][i].mine = true;
                //call the ajacentMines function to redo the check for all mines on board now that one has switched
                break;
            }
        }
    }


    //to test first click
    if(turn == 1)
        return true;
    turn ++;
    return false;
}

void Board::printGameBoard() {
    cout << "\n\n\n";
    cout << "Mines left: " << mineRem << "  Turn: " << turn << "\n\n";
    for(int r = 0; r < 16; r++){
        for(int c = 0; c < size; c++){
            if(gameBoard[r][c].mine)
                cout << "x ";
            else
                cout << gameBoard[r][c].adjMines << " ";
                // cout << "o ";
        }
        cout << endl;
    }
}