#include "Backup.h"


Backup::Backup(int boardSize, Game *game){
    this->boardSize = boardSize;
    this->game = game;
}

void Backup::createNewTurn(int x, int y, Player *pOnTurn){

    Point *point = new Point(x, y);
    std::cout << x << " " << y << "\n";
    newTurn = new BackupTurn(point, pOnTurn);

}

void Backup::addTurnedDisc(std::vector <BoardField*> turnedDiscs){

    newTurn->turnedDiscs.insert(newTurn->turnedDiscs.end(), turnedDiscs.begin(), turnedDiscs.end());
}

void Backup::addFrozenDisc(std::list<BoardField*> points){
    newTurn->frozenPoints = points;
}


void Backup::saveBackupRecord(){
    this->backupTurns.push_back(newTurn);

}

void Backup::serializeBackup(){
//Point *basePoint;
//std::list<BoardField*> frozenPoints;
//std::vector <BoardField*> turnedDiscs;
//Player *playerOnTurn;

    std::ofstream output;
    output.open("saved_game.txt");

    output << game->white->getName() << ":" << ((game->white->getIs_pc()) ? "bot":"hum") << ":";
    output << ((game->white->getIs_pc()) ? std::to_string(game->white->level) :"0") <<"\n";
    output << game->black->getName() << ":" << ((game->black->getIs_pc()) ? "bot":"hum") << ":";
    output << ((game->black->getIs_pc()) ? std::to_string(game->black->level) :"0") <<"\n";

    output << std::to_string(rules->getSize()) << "\n";


    for(std::vector<BackupTurn*>::iterator it = backupTurns.begin(); it != backupTurns.end(); ++it){
        output << (((*it)->playerOnTurn->getIsWhite()) ? "w":"b") << "$" ;
        output << std::to_string((*it)->basePoint->x) << "," << std::to_string((*it)->basePoint->y) << "$";

        for(std::list<BoardField*>::iterator it1 = (*it)->frozenPoints.begin(); it1 != (*it)->frozenPoints.end(); ++it1){
            output << std::to_string((*it1)->row) << "," << std::to_string((*it1)->col)<<";";
        }

        output << "$";
        for(std::vector<BoardField*>::iterator it2 = (*it)->turnedDiscs.begin(); it2 != (*it)->turnedDiscs.end(); ++it2){
            output << std::to_string((*it2)->row) << "," << std::to_string((*it2)->col)<<";";
        }

        output << "\n";
    }

    output.close();
}


BackupTurn::BackupTurn(Point *basePoint, Player *pOnTurn){
    this->basePoint = basePoint;
    this->playerOnTurn = pOnTurn;
}
