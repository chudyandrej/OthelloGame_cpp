//
// Created by Andrej Oliver Chudý on 25/04/16.
//

#include "Disc.h"


Disc::Disc(bool isWhite) {
    this->isWhite = isWhite;
}

void Disc::turn(UserInterface *UserInt) {
    this->isWhite = !isWhite;
    UserInt->changeDisc(x, y, isWhite);
}

void Disc::setY(int x, int y, UserInterface *UserInt) {
    this->x = x;
    this->y = y;
    UserInt->changeDisc(x, y, isWhite);
}





