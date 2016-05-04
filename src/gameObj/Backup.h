#ifndef BACKUP_H
#define BACKUP_H
#include <vector>

class Backup;
class BackupTurn;
#include "Game.h"


class Point{

public:
    int x;
    int y;

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};



class BackupTurn{

public:
    BackupTurn(Point *basePoint, Player *pOnTurn);

    Point *basePoint;
    std::vector<BoardField*> frozenPoints;
    std::vector <BoardField*> turnedDiscs;
    Player *playerOnTurn;
};



class Backup{
private:
    int boardSize;

public:
    Backup(int boardSize);
    std::vector<BackupTurn*> backupTurns;
    BackupTurn *newTurn;
    Player *player1;
    Player *player2;

    void createNewTurn(int x, int y, Player *pOnTurn);
    void addFrozenDisc(std::vector<BoardField*> points);
    void addTurnedDisc(std::vector <BoardField*> turnedDiscs);
    void saveBackupRecord();
};



#endif // BACKUP_H
