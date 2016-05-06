#ifndef CREATEGAMEOVERMSG_H
#define CREATEGAMEOVERMSG_H

#include <string>
#include "gameObj/Game.h"

class CreateGameOverMsg
{
public:
    static std::string createSinglePlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2);
    static std::string createMultiPlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2);
};

#endif // CREATEGAMEOVERMSG_H
