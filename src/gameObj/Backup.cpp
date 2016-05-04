#include "Backup.h"
#include "iostream" //temp

Backup::Backup(int boardSize){

    this->boardSize = boardSize;
}

void Backup::createNewTurn(int x, int y, Player *pOnTurn){

    Point *point = new Point(x, y);
    std::cout << x << " " << y << "\n";
    newTurn = new BackupTurn(point, pOnTurn);

}

void Backup::addTurnedDisc(std::vector <BoardField*> turnedDiscs){
    newTurn->turnedDiscs = turnedDiscs;
}

void Backup::addFrozenDisc(std::vector<BoardField*> points){
    //newTurn->frozenPoints = points;
}


void Backup::saveBackupRecord(){
    this->backupTurns.push_back(newTurn);

}


BackupTurn::BackupTurn(Point *basePoint, Player *pOnTurn){
    this->basePoint = basePoint;
    this->playerOnTurn = pOnTurn;
}
