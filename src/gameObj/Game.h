//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H

#include <vector>
#include <string>
#include "../board/Board.h"
#include "../userinterface.h"


class Player;
class ReversiRules;
extern ReversiRules *rules;


class Game {

private:
    int sizeBoard;
    Player *currentPlayer;
    Player *black = nullptr;
    Player *white = nullptr;
    bool gameOver;


public:
    Game(int size, int discsToFreeze, int CHTime, int FTime, UserInterface *UI);
    bool addPlayer(Player *newPlayer);
    Player* getCurrentPlayer();
    void nextPlayer();
    void undo();
};


class ReversiRules {
private:
    int size;
    Board *playBoard;

public:
    ReversiRules(int size);
    int getSize();

    bool canPutDisk(int x, int y, Player *playerTurn);
    bool putDisk(int x, int y, Player* playerTurn);
    std::vector<BoardField*> chack_IN_direct(BoardField* field, int way, Player *playerTurn);
    void turn_disks(std::vector<BoardField*> st);
    void uiAlgorithmLevel1(Player* UI);
    void uiAlgorithmLevel2(Player* UI);
    void calcScore(Player* currentPlayer);
    bool isExitsingTurn(Player* currentPlayer);

};


class Player {
private:
    bool isWhite;
    int level;
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

    bool getIsWhite(){
        return isWhite;
    }

    bool canPutDisk(int x, int y){
        return rules->canPutDisk(x, y, this);
    }

    bool putDisk(int x, int y){
        return rules->putDisk(x, y, this);

    }

    void uiTurn(Game *game) {
        if (level == 1) {
            rules->uiAlgorithmLevel1(this);
        }
        else {
            rules->uiAlgorithmLevel2(this);
        }
        game->nextPlayer();
    }

    bool getIs_pc() {
        return is_pc;
    }

};

#endif //OTHELLO_GAME_H
