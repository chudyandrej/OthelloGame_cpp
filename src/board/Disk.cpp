//
// Created by Andrej Oliver Chudý on 25/04/16.
//

#include "disk.h"


Disk::Disk(bool isWhite) {
    this->isWhite = isWhite;
}

void Disk::turn(UserInterface *UserInt) {
    this->isWhite = !isWhite;
    UserInt->changeDisc(x, y, isWhite);
}

void Disk::setY(int x, int y, UserInterface *UserInt) {
    this->x = x;
    this->y = y;
    UserInt->changeDisc(x, y, isWhite);
}





