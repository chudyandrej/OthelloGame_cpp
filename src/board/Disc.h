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
    virtual ~Disc() {

    }
};



#endif // DISC_H
