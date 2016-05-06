/**
 * Header file for Disc class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef DISC_H
#define DISC_H

#include "../UserInterface.h"

class Disc {
private:
    bool isWhite;
    int x, y;

public:
    Disc(bool isWhite);
    void turn(UserInterface *UserInt);
    bool getIsWhite(){ return isWhite; }
    void setY(int x , int y, UserInterface *UserInt);
    virtual ~Disc(){}
};



#endif // DISC_H
