//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H

#include <vector>
#include <list>
#include <string>
#include "../board/Board.h"
#include "../UserInterface.h"

class Player;
class Game;
class ReversiRules;
extern ReversiRules *rules;

#include "Backup.h"
#include <mutex>

class Game {
public:
    Backup *backupGame;
    Player *black = nullptr;
    Player *white = nullptr;


private:
    int sizeBoard;
    Player *currentPlayer;

    bool gameOver;

    int discsToFreeze;
    int CHTime;
    int FTime;

    std::mutex threadMtx;
    std::vector<BackupTurn*> tempFutureTurns;

    void deleteRedoTurns();
    void frozenFields(int counter, int maxFreezeTime, int maxChangeTisleeme);
    void sleepThread(int time);
    void unFreezeWhichCan();
    void unFreezeAll();
    std::list<BoardField*> frozen;


public:
    Game(int size, int discsToFreeze, int CHTime, int FTime, UserInterface *UI);
    bool addPlayer(Player *newPlayer);
    Player* getCurrentPlayer();
    bool getIsGameOver();
    void nextPlayer();
    void undo();
    void redo();

};


class ReversiRules {
private:
    int size;
    Board *playBoard;
    Backup *backupGame;

public:
    ReversiRules(int size, Backup *backupGame);
    int getSize();

    bool canPutDisc(int x, int y, Player *playerTurn);
    bool putDisc(int x, int y, Player* playerTurn);
    void reversePutDisc(int x, int y, Player* playerTurn);
    std::vector<BoardField*> chack_IN_direct(BoardField* field, int way, Player *playerTurn);
    void turn_discs(std::vector<BoardField*> st);
    void uiAlgorithmLevel1(Player* UI);
    void uiAlgorithmLevel2(Player* UI);
    void calcScore(Player* currentPlayer);
    bool isExitsingTurn(Player* currentPlayer);

};


class Player {
public:
    int level;

private:
    bool isWhite;    
    bool is_pc = false;
    std::string name;

public:
    Player(bool isWhite, std::string name) {
        this->isWhite = isWhite;
        this->name = name;
    }

    Player(bool isWhite, int level, std::string name) {
        this->is_pc = true;
        this->level = level;
        this->isWhite = isWhite;
        this->name = name;
    }

    std::string getName(){
        return this->name;
    }

    bool getIsWhite(){
        return isWhite;
    }

    bool canPutDisc(int x, int y){
        return rules->canPutDisc(x, y, this);
    }

    bool putDisc(int x, int y){
        return rules->putDisc(x, y, this);

    }

    void uiTurn() {
        if (level == 1) {
            rules->uiAlgorithmLevel1(this);
        }
        else {
            rules->uiAlgorithmLevel2(this);
        }
    }

    bool getIs_pc() {
        return is_pc;
    }

};

#endif //OTHELLO_GAME_H
