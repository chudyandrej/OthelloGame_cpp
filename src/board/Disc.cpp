/**
 * This class implements methods for disc which will
 * be placed on a board field.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "Disc.h"

/**
 * Disc constructor
 * @param isWhite color of the disc
 */
Disc::Disc(bool isWhite) {
    this->isWhite = isWhite;
}

/**
 * Method turns disc
 * @param UserInt user interface (CLI or GUI)
 */
void Disc::turn(UserInterface *UserInt) {
    this->isWhite = !isWhite;
    UserInt->changeDisc(x, y, isWhite);
}

/**
 * Method sets disc and puts its to the board
 * @param x       x-coordinate
 * @param y       y-coordinate
 * @param UserInt user interface (CLI or GUI)
 */
void Disc::setY(int x, int y, UserInterface *UserInt) {
    this->x = x;
    this->y = y;
    UserInt->changeDisc(x, y, isWhite);
}