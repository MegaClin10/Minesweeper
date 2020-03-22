#ifndef CELL_H
#define CELL_H

struct Cell {
    bool mine;
    bool flag;
    int idval;
    int mines;

    Cell() {
        mine = 0;
        flag = 0;
        idval = -1;
        mines = 0;
    };

    Cell(int idval) {
        mine = 0;
        flag = 0;
        this->idval = idval;
        mines = 0;
    }
};


#endif