#ifndef CELL_H
#define CELL_H

struct Cell {
    bool mine;
    bool flag;
    bool clear;
    bool vis;
    int idval;
    int adjMines;

    Cell();
};


#endif