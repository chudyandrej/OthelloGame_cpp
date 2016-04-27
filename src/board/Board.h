//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H

#include "../userinterface.h"
#include "disk.h"
class BoardField;

enum Direct {D,L,LD,LU,R,RD,RU,U};

extern BoardField* board_fields[20][20];
extern UserInterface *UserInt;


class Board {
/*protected:
    UserInterface *UserInt;*/

public:
    int size;

    Board(int size);
    BoardField* getField(int row, int col);
    void putField(int row, int col, BoardField *field);
    int getSize();
};



class BoardField{
private:
    bool freezeEnd;
    Disk *disk;

public:
    int row;
    int col;
    int size;
    bool isFreeze;

    BoardField(int row, int col, int size) ;
    BoardField *nextField(int dirs) ;
    bool putDisk(Disk *disk);
    Disk* getDisk();
    bool getFreezeEnd();

};






#endif //OTHELLO_BOARD_H
