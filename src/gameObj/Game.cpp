/**
 * File contains implemented methods of Game class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "Game.h"
#include "iostream" //temp


/**
 * Constructor, initializes the game.
 * @param size board size
 * @param discsToFreeze number of disc, which can be made frozen
 * @param CHTime time after which can be discs made unfrozen
 * @param FTime time for which are the discs hold frozen
 * @param user interface (GUI or CLI) to be used
 */
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
}

/**
 * Method deletes redo turns.
 */
void Game::deleteRedoTurns(){
    while(!tempFutureTurns.empty()){
        delete tempFutureTurns.back();
        tempFutureTurns.pop_back();
    }
}

/**
 * Function for generating frozen fields.
 * @param count How much fields will be frozen
 * @param max_timeFreeze Max time (seconds) for which will be the fields frozen
 * @param max_timeChange Max time (seconds) to change
 */
void Game::frozenFields(int counter, int maxFreezeTime, int maxChangeTime){
    unFreezeWhichCan();

    if(maxChangeTime == 0){return;}

    if(threadMtx.try_lock()){

       for (int x = 0; x < counter; x++) {
             int randomX = (int) (rand() % (sizeBoard - 1));
             int randomY = (int) (rand() % (sizeBoard - 1));

             board_fields[randomX][randomY]->freezeDisc(maxFreezeTime);
             frozen.push_back(board_fields[randomX][randomY]);
         }

         std::thread(&Game::sleepThread, this, maxChangeTime).detach();
    }
}

/**
 * Method makes thread sleep untill random time is up.
 * @param time max time for which will the thread sleep
 */
void Game::sleepThread(int time){
    usleep(1000* (rand() % time));
    threadMtx.unlock();
}

/**
 * Method makes all board fields unfrozen.
 */
void Game::unFreezeAll(){
    while(!frozen.empty()){
        BoardField *tmp =  frozen.back();
        tmp->isFreeze = false;
        UserInt->unFreezeField(tmp->row, tmp->col);
        frozen.remove(tmp);
    }
}

/**
 * Method checks if any board field change its state to unfrozen
 * and if so, method calls user interface.
 */
void Game::unFreezeWhichCan(){

    std::list<BoardField*>::iterator i = frozen.begin();
    while (i != frozen.end()){
        if ((*i)->checkUnfreeze()) {
            (*i)->isFreeze = false;
            UserInt->unFreezeField((*i)->row, (*i)->col);
            frozen.erase(i++);
        }
        else{
            ++i;
        }
    }
}

/**
 * Method sets current player and checks if the player has any possible move, 
 * if not, other player is sets or game over is raised.
 */
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

/**
 * Method provides undo operation.
 */
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

/**
 * Method provides redo operation.
 */
void Game::redo(){

    //unFreezAll();
    gameOver = false;
    BackupTurn *lastTurn;

    if (tempFutureTurns.size() > 0) {

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

/**
 * @return instance of player on turn
 */
Player* Game::getCurrentPlayer(){ return currentPlayer; }

/**
 * Game over status getter.
 * @return true if game is over, else false
 */
bool Game::getIsGameOver(){
    return gameOver;
}

/**
 * Methods adds player to the game.
 * @param newPlayer instance of a new player
 * @return true if success, else false (f.e. player already exists)
 */
bool Game::addPlayer(Player *newPlayer) {

    if(newPlayer->getIsWhite() && white == nullptr){
        this->white = newPlayer;
        this->currentPlayer = newPlayer;
        return true;

    }else if (!newPlayer->getIsWhite() && black == nullptr){
        this->black = newPlayer;
        return true;
    }
    return false;
}

