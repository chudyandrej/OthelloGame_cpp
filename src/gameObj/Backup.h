/**
 * Header file for Point, BackupTurn and Backup class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef BACKUP_H
#define BACKUP_H

//forward declarationss
class Backup;
class BackupTurn;

//includes
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

    int serializeBackup();

    static std::tuple<int, std::string, int, std::string, int> loadSettings();
    static std::vector<std::string> split(std::string input, char delimiter);
    void loadGame();
};



#endif // BACKUP_H
