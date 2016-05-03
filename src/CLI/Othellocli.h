#ifndef OTHELLOCLI_H
#define OTHELLOCLI_H

#include <string>
#include <iostream>
#include "src/gameObj/Game.h"

class OthelloCLI : UserInterface{

public:
    OthelloCLI();

private:
    int boardSize;
    bool singlePlayer = false;
    int gameMode;
    std::string player1Name;
    std::string player2Name;
    std::string computerName;

    Game *newGame;
    Player *player1;
    Player *player2;
    int score1;
    int score2;
    bool onTurn;
    char boardFields[12][12];

    /*int discsToFreeze;
    int frozeTime;
    int changeTimer;*/

    void getSettings();
    void commandListener();
    void printBoard();

    void changeDisc(int x, int y, bool isWhite);
    void deleteDisc(int x, int y);
    void freezeField(int x, int y);
    void unFreezeField(int x, int y);
    void setGameState(int score1, int score2, bool isWhite);
};

#endif // OTHELLOCLI_H
