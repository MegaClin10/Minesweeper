#ifndef CELL_H
#define CELL_H

struct Cell {
    bool mine;
    bool flag;
    bool clear;
    int idval;
    int adjMines;

    Cell() {
        mine = 0;
        flag = 0;
        idval = -1;
        adjMines = 0;
        clear = 0;
    };
};


#endif