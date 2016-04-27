#include "Board.h"

Board::Board(int size) {
    this->size = size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board_fields[i][j] = new BoardField(i, j, size);
        }
    }
}

BoardField* Board::getField(int row, int col){
    return board_fields[row][col];
}

void Board::putField(int row, int col, BoardField *field){
    board_fields[row][col] = field;
}

int Board::getSize(){
    return size;
}
