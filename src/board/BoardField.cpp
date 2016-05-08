/**
 * In this file are implemented methods for each BoardField.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "Board.h"
#include <iostream>

/**
 * BoardField constructor
 * @param row number of row where is object placed
 * @param col number of col where is object placed
 * @param size board size
 */
BoardField::BoardField(int row, int col, int size){
        this->row = row;
        this->col = col;
        this->size = size;
        this->disc = nullptr;
        isFreeze = false;
}

/**
 * Method knows about surrounding fields.
 * @param dirs enum, direction
 * @return field in given direction
 */
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

 /**
 * Methods puts given disc to the field.
 * @param disc disc to be put on field
 * @return true if operation is successful
 */
bool BoardField::putDisc(Disc *disc) {

    bool ret_val = false;
    if (this->disc == nullptr){
        disc->setY(row, col, UserInt);
        this->disc = disc;
        ret_val = true;
    }
    return ret_val;
}

/**
 * Method returns object placed on the field.
 * @return disc or null
 */
Disc* BoardField::getDisc(){
    return disc;
}

/**
 * freezeEnd variable getter.
 * @return freezeEnd true if frozen state of the field has ended, else false
 */
bool BoardField::getFreezeEnd() {
    return freezeEnd;
}

/**
 * Method deletes disc from the field.
 */
void BoardField::deleteDisc(){
    this->disc->~Disc();
    this->disc = nullptr;
    UserInt->deleteDisc(row, col);
}

/**
 * Method makes the disc frozen for random time from time interval.
 * @param time time interval
 */
void BoardField::freezeDisc(int time){
    freezeEnd = false;
    isFreeze = true;

    UserInt->freezeField(row, col);
    std::thread(&BoardField::sleepFunction, this, time).detach();
}

/**
 * Method makes the field frozen.
 */
void BoardField::setFreeze(){
    isFreeze = true;
    freezeEnd = true;
    UserInt->freezeField(row, col);
}

/**
 * Method makes the field sleep untill random time is up
 * @param time max time for which will the field sleep
 */
void BoardField::sleepFunction(int time){
    freezeEndMtx.lock();
    usleep(1000* (rand() % time) );
    freezeEndMtx.unlock();
}

/**
 * Method checks if frozen state of the field has ended.
 * @return true if frozen state of the field has ended, else false
 */
bool BoardField::checkUnfreeze(){
    if(freezeEndMtx.try_lock()){
        freezeEndMtx.unlock();
        return true;
    }
    return false;
}
