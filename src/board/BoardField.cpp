//
// Created by Andrej Oliver Chudý on 25/04/16.
//

#include "Board.h"



BoardField::BoardField(int row, int col, int size){
        this->row = row;
        this->col = col;
        this->size = size;
        this->disk = nullptr;
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

bool BoardField::putDisk(Disk *disk) {

    bool ret_val = false;
    if (this->disk == nullptr){
        disk->setY(row, col, UserInt);
        this->disk = disk;
        ret_val = true;
    }
    return ret_val;

}

Disk* BoardField::getDisk(){
    return disk;
}

bool BoardField::getFreezeEnd() {
    return freezeEnd;
}

