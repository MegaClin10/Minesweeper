#include "board.h"
#include "cell.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    bool gameOver = false;
    string input;
    int width;
    int x, y;
    cout << "Type 'help' to learn how to play, or type 'play' to start playing: ";
    cin >> input;
    if(input == "help")
        cout << "Type play" << endl;
    else if(input == "play"){
        cout << "Enter tile width amount (16 or 30): ";
        cin >> width;
    Board firstBoard(width);
        while(!gameOver) {
            firstBoard.printGameBoard();
            cout << "Enter x coordinate to clear: ";
            cin >> x;
            cout << "Enter y coordinate to clear: ";
            cin >> y;
            gameOver = firstBoard.findMines(y, x);
        }
    }

}