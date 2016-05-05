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

void Game::frozenFields(int counter, int maxFreezeTime, int maxChangeTime){
    unFreezeWhichCan();

    if(maxChangeTime == 0){return;}

    if(threadMtx.try_lock()){

       for (int x = 0; x < counter; x++) {
             int randomX = (int) (rand() % (sizeBoard - 1));
             int randomY = (int) (rand() % (sizeBoard - 1));
             std::cout << randomX << " " << randomY << "\n";
             board_fields[randomX][randomY]->freezeDisc(maxFreezeTime);
             frozen.push_back(board_fields[randomX][randomY]);
         }
         std::cout << "here??? " << maxChangeTime << "\n";
         std::thread(&Game::sleepThread,this, maxChangeTime).detach();

    }
}

void Game::sleepThread(int time){
    usleep(1000* (rand() % time));
    threadMtx.unlock();
}


void Game::unFreezeAll(){
    while(!frozen.empty()){
        BoardField *tmp =  frozen.back();
        tmp->isFreeze = false;
        UserInt->unFreezeField(tmp->row, tmp->col);
        frozen.remove(tmp);
    }
}


void Game::unFreezeWhichCan(){

    std::list<BoardField*>::iterator i = frozen.begin();
    while (i != frozen.end()){
        if ((*i)->freezeEnd) {
            (*i)->freezeEnd = false;
            frozen.erase(i++);  // alternatively, i = items.erase(i);
            UserInt->unFreezeField((*i)->row, (*i)->col);
        }
        else{
            ++i;
        }
    }
}



Game::Game(int size, int discsToFreeze, int CHTime, int FTime, UserInterface *UInt) {
    UserInt = UInt;
    backupGame = new Backup(size, this);
    rules = new ReversiRules(size, backupGame);
    sizeBoard = size;
    gameOver = false;
    currentPlayer = white;
    this->discsToFreeze = discsToFreeze;
    this->CHTime = CHTime;
    this->FTime = FTime;
    //this->discsToFreeze = 6;
    //this->CHTime = 5;
    //this->FTime = 1;
}


void Game::nextPlayer() {

    while(true){
        backupGame->addFrozenDisc(frozen);
        backupGame->saveBackupRecord();

        deleteRedoTurns();

        rules->calcScore(currentPlayer);

        frozenFields(discsToFreeze, FTime, CHTime);

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
        int y = lastTurn->basePoint->y;
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







