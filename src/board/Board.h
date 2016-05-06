//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H

#include "../UserInterface.h"
#include "Disc.h"
#include <mutex>
#include <thread>       //-std=c++0x -pthread
#include <unistd.h>


class BoardField;

enum Direct {D,L,LD,LU,R,RD,RU,U};

extern BoardField* board_fields[20][20];
extern UserInterface *UserInt;


class Board {

public:
    int size;

    Board(int size);
    BoardField* getField(int row, int col);
    void putField(int row, int col, BoardField *field);
    int getSize();
};



class BoardField{
private:   
    Disc *disc = nullptr;

public:
    int row;
    int col;
    int size;
    bool isFreeze;
    bool freezeEnd;

    BoardField(int row, int col, int size) ;
    BoardField *nextField(int dirs) ;
    bool putDisc(Disc *disc);
    Disc* getDisc();
    bool getFreezeEnd();
    void deleteDisc();
    void freezeDisc(int time);

    void sleepFunction(int time);
    std::mutex freezeEndMtx;
    bool checkUnfreeze();
};






#endif //OTHELLO_BOARD_H
