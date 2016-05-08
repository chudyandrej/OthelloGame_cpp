/**
 * Header file for Board class and BoardField class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H

#include <mutex>
#include <thread>       //-std=c++0x -pthread
#include <unistd.h>

#include "../UserInterface.h"
#include "Disc.h"

//forward declarations
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
    bool isFreeze = false;
    bool freezeEnd = true;

    BoardField(int row, int col, int size);
    BoardField *nextField(int dirs);
    bool putDisc(Disc *disc);
    Disc* getDisc();
    bool getFreezeEnd();
    void deleteDisc();
    void freezeDisc(int time);
    void setFreeze();

    void sleepFunction(int time);
    std::mutex freezeEndMtx;
    bool checkUnfreeze();
};




#endif //OTHELLO_BOARD_H
