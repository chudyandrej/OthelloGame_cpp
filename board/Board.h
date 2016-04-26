//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H



enum Direct {D,L,LD,LU,R,RD,RU,U};

class Disk;

class BoardField {
public:
    int row;
    int col;
    int size;
    bool isFreeze;
private:
    bool freezeEnd;
    Disk *disk;

public:
    BoardField(int row, int col, int size) ;
    BoardField *nextField(int dirs) ;
    bool putDisk(Disk *disk);

    Disk* getDisk(){
        return disk;
    }
    bool getFreezeEnd() {
        return freezeEnd;
    }
};

extern BoardField* board_fields[20][20];

class Disk {
private:
    bool isWhite;
    int x, y;
public:
    Disk(bool isWhite);
    void turn();
    bool getIsWhite(){ return isWhite; }
    void setY(int x , int y);
    virtual ~Disk() {

    }
};


class Board {
public:
    int size;

public:
    Board(int size) {
        this->size = size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board_fields[i][j] = new BoardField(i, j, size);
            }
        }
    }
public:
    BoardField* getField(int row, int col){
        return board_fields[row][col];
    }
    void putField(int row, int col, BoardField *fieldn){
        board_fields[row][col] = fieldn;
    }
    int getSize(){
        return size;
    }
};



#endif //OTHELLO_BOARD_H
