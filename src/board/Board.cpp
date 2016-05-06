/**
 * This class creates board and implements methods over it.
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

/**
 * Created array of BoardField objects
 * @param size size of board
 */
Board::Board(int size) {
    this->size = size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board_fields[i][j] = new BoardField(i, j, size);
        }
    }
}
