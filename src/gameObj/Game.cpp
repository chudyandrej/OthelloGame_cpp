//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#include "Game.h"
#include "iostream" //temp


void Game::deleteRedoTurns(){
    while(!tempFutureTurns.empty()){
        delete tempFutureTurns.back();
        tempFutureTurns.pop_back();
    }
}

Game::Game(int size, int discsToFreeze, int CHTime, int FTime, UserInterface *UInt) {
    UserInt = UInt;
    backupGame = new Backup(size);
    rules = new ReversiRules(size, backupGame);
    sizeBoard = size;
    gameOver = false;
    currentPlayer = white;

}


void Game::nextPlayer() {

    while(true){
        //backupGame->addFrozenDisc();
        backupGame->saveBackupRecord();

        deleteRedoTurns();

        rules->calcScore(currentPlayer);

        //frozenFields(discsToFreeze, CHTime, FTime);

        this->currentPlayer = currentPlayer->getIsWhite() ? black: white;
        if (currentPlayer->getIs_pc()) {
            currentPlayer->uiTurn();
        }
        else if(rules->isExitsingTurn(currentPlayer)) {
            return;
        }
        else if (!rules->isExitsingTurn(white) && !rules->isExitsingTurn(black)){
            rules->calcScore(currentPlayer);
            gameOver = true;
            return;
        }
    }
}

void Game::undo() {

    //unFreezAll();
    gameOver = false;
    BackupTurn *lastTurn;

    if (backupGame->backupTurns.size() > 0) {

        lastTurn = backupGame->backupTurns.back();
        tempFutureTurns.push_back(lastTurn);
        backupGame->backupTurns.pop_back();

        int x = lastTurn->basePoint->x;
        int y = lastTurn->basePoint->y;
        board_fields[x][y]->deleteDisc();
        rules->turn_discs(lastTurn->turnedDiscs);

        //loadFrezed(lastTurn->freeze);
        currentPlayer = lastTurn->playerOnTurn;

        if (currentPlayer->getIs_pc()){
            undo();
        }
        Player *tmp = currentPlayer->getIsWhite() ? black: white;
        rules->calcScore(tmp);
    }
}

void Game::redo(){

    //unFreezAll();
    gameOver = false;
    BackupTurn *lastTurn;

    if (tempFutureTurns.size() > 0) {
        std::cout << tempFutureTurns.size();
        lastTurn = tempFutureTurns.back();
        tempFutureTurns.pop_back();
        backupGame->backupTurns.push_back(lastTurn);


        int x = lastTurn->basePoint->x;
        std::cout << "PICA+"<<"\n";
        int y = lastTurn->basePoint->y;
        std::cout << "PICA"<<"\n";
        currentPlayer = lastTurn->playerOnTurn;

        board_fields[x][y]->putDisc(new Disc(currentPlayer->getIsWhite()));
        rules->turn_discs(lastTurn->turnedDiscs);
        currentPlayer = currentPlayer->getIsWhite() ? black: white;
        //loadFrezed(lastTurn->freeze);

        if (currentPlayer->getIs_pc()){
            redo();
        }
        Player *tmp = currentPlayer->getIsWhite() ? black: white;
        rules->calcScore(tmp);
    }

}


Player* Game::getCurrentPlayer(){ return currentPlayer; }

bool Game::getIsGameOver(){
    return gameOver;
}

bool Game::addPlayer(Player *newPlayer) {

    if(newPlayer->getIsWhite() && white == nullptr){
        this->white = newPlayer;
        this->currentPlayer = newPlayer;
        //backupGame.setPlayer1(white);
        return true;

    }else if (!newPlayer->getIsWhite() && black == nullptr){
        this->black = newPlayer;
        //backupGame.setPlayer2(black);
        return true;
    }
    return false;

}







