//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#include "Game.h"


Game::Game(int size, int discsToFreeze, int CHTime, int FTime, UserInterface *UInt) {
    UserInt = UInt;
    rules = new ReversiRules(size);
    sizeBoard = size;
    gameOver = false;
    currentPlayer = white;

}


void Game::nextPlayer() {
    rules->calcScore(currentPlayer);

    this->currentPlayer = currentPlayer->getIsWhite() ? black: white;
    if (currentPlayer->getIs_pc()) {
        currentPlayer->uiTurn(this);
        return;
    }
    else if(rules->isExitsingTurn(currentPlayer)) {
        return;
    }
    else if (!rules->isExitsingTurn(white) && !rules->isExitsingTurn(black)){
        rules->calcScore(currentPlayer);
        gameOver = true;
        return;
    }
    currentPlayer = currentPlayer->getIsWhite() ? black: white;
    if (currentPlayer->getIs_pc()) {
        currentPlayer->uiTurn(this);
    }

}

void Game::undo() {

    /*unFreezAll();
    gameOver = false;
    Backup.TurnBackUp lastTurn;
    if (backupGame.backupTurns.size() > 0) {
        lastTurn = backupGame.backupTurns.get(backupGame.backupTurns.size() - 1);
        lastTurn.base_Point.deleteDisk();
        rules.turn_disks(lastTurn.turned);
        loadFrezed(lastTurn.freeze);
        backupGame.backupTurns.remove(lastTurn);
        currentPlayer = lastTurn.turn_player;

        if (currentPlayer.is_pc()){
            undo();
        }
        rules.calcScore(currentPlayer);
    }*/

}


Player* Game::getCurrentPlayer(){ return currentPlayer; }

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







