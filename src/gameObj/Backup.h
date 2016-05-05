#ifndef BACKUP_H
#define BACKUP_H


class Backup;
class BackupTurn;
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <set>
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
    std::list<BoardField*> frozenPoints;
    std::vector <BoardField*> turnedDiscs;
    Player *playerOnTurn;
};



class Backup{
private:
    int boardSize;

public:
    Backup(int boardSize, Game *game);
    std::vector<BackupTurn*> backupTurns;
    BackupTurn *newTurn;
    Game *game;

    void createNewTurn(int x, int y, Player *pOnTurn);
    void addFrozenDisc(std::list<BoardField*> points);
    void addTurnedDisc(std::vector <BoardField*> turnedDiscs);
    void saveBackupRecord();

    void serializeBackup();

    static std::tuple<int, std::string, bool, int, std::string, bool, int> loadSettings();
    static std::vector<std::string> split(std::string input, char delimiter);
    void loadGame();
};



#endif // BACKUP_H
