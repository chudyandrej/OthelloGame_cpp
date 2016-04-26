//
// Created by Andrej Oliver Chudý on 25/04/16.
//

#include "Board.h"

Disk::Disk(bool isWhite) {
    this->isWhite = isWhite;
}

void Disk::turn() {
    this->isWhite = !isWhite;
    //BoardGUI.changeDisc(x,y, isWhite);
}

void Disk::setY(int x, int y) {
    this->x = x;
    this->y = y;
    //BoardGUI.changeDisc(x,y, isWhite);
}





