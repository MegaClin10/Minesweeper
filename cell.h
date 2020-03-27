#ifndef CELL_H
#define CELL_H

struct Cell {
    bool mine;
    bool flag;
    int idval;
    int adjMines;

    Cell() {
        mine = 0;
        flag = 0;
        idval = -1;
        adjMines = 0;
    };

    Cell(int idval) {
        mine = 0;
        flag = 0;
        this->idval = idval;
        adjMines = 0;
    }
};


#endif