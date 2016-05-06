/**
 * Header file for CreateGameOverMsg.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */


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
