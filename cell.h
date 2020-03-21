#ifndef CELL_H
#define CELL_H

struct Cell {
    bool mine;
    bool flag;
    int idval;

    Cell() {
        mine = 0;
        flag = 0;
        idval = -1;
    };

    Cell(int idval) {
        mine = 0;
        flag = 0;
        this->idval = idval;
    }
};


#endif