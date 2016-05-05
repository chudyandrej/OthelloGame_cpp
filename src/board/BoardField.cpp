//
// Created by Andrej Oliver Chudý on 25/04/16.
//

#include "Board.h"
#include <iostream>

BoardField::BoardField(int row, int col, int size){
        this->row = row;
        this->col = col;
        this->size = size;
        this->disc = nullptr;
        isFreeze = false;
}

BoardField *BoardField::nextField(int dirs) {

    switch (dirs) {
        case D:
            if (row != size -1 ){return board_fields[row + 1][col];}
            break;
        case L:
            if (col != 0 ){return board_fields[row][col - 1];}
            break;
        case LD:
            if (row != size-1 && col != 0){return board_fields[row + 1][col - 1];}
            break;
        case LU:
            if (row != 0 && col != 0){return  board_fields[row - 1][col - 1];}
            break;
        case R:
            if (col != size-1 ){return  board_fields[row][col + 1];}
            break;
        case RD:
            if (row != size-1  && col != size-1 ){return  board_fields[row + 1][col + 1];}
            break;
        case RU:
            if (row != 0 && col != size-1 ){return  board_fields[row - 1][col + 1];}
            break;
        case U:
            if (row != 0){return  board_fields[row - 1][col];}
            break;
    }
    return nullptr;

}

bool BoardField::putDisc(Disc *disc) {

    bool ret_val = false;
    if (this->disc == nullptr){
        disc->setY(row, col, UserInt);
        this->disc = disc;
        ret_val = true;
    }
    return ret_val;

}

Disc* BoardField::getDisc(){
    return disc;
}

bool BoardField::getFreezeEnd() {
    return freezeEnd;
}

void BoardField::deleteDisc(){
    this->disc->~Disc();
    this->disc = nullptr;
    UserInt->deleteDisc(row, col);
}

void BoardField::freezeDisc(int time){
    freezeEnd = false;
    isFreeze = true;

    UserInt->freezeField(row, col);
    //freezeEnd =
    std::thread(&BoardField::sleepFunction,this, time).detach();
    std::cout << &freezeEnd << "\n";

}

void BoardField::sleepFunction(int time){
    usleep(1000* (rand() % time) );
    setSynchValue();
}

void BoardField::setSynchValue(){
    synchValMtx.lock();
    std::cout << &freezeEnd << "fuck\n";
    freezeEnd = true;
    synchValMtx.unlock();
}

bool BoardField::getSynchValue(){
    synchValMtx.lock();
    return freezeEnd;
    synchValMtx.unlock();
}



