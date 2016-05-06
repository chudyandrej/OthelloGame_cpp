/**
 * This class implements static functions which create messages to show when game is over.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "CreateGameOverMsg.h"

/**
 * Creates summary of scores when game was single player.
 * @param  score1  score of player1
 * @param  score2  score of player2
 * @param  player1 pointer to player1
 * @param  player2 pointer to player2
 * @return         game summary
 */
std::string CreateGameOverMsg::createSinglePlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2){
   std::string msg;
   if(player1->getIs_pc()) {
       msg = (score1 > score2) ? "You LOST. Computer won.<br>" : "Congratulation!<br>You WON.<br>";
       msg = msg + "Your score: " + std::to_string(score2) + "<br>" +player1->getName()+": "+std::to_string(score1);
   }
   else{
       msg = (score1 < score2) ? "You LOST. Computer won.<br>" : "Congratulation!<br>You WON.<br>";
       msg = msg + "Your score: " + std::to_string(score1) + "<br>" +player2->getName()+": "+std::to_string(score2);
   }
   return msg;
}

/**
 * Creates summary of scores when game was multiplayer.
 * @param  score1  score of player1
 * @param  score2  score of player2
 * @param  player1 pointer to player1
 * @param  player2 pointer to player2
 * @return         game summary
 */
std::string CreateGameOverMsg::createMultiPlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2){
    std::string msg;
    if(score1 > score2){        //player1 won
        msg = player1->getName() + " won with score: " + std::to_string(score1);
    }else{                      //player2 won
        msg = player2->getName() + " won with score: " + std::to_string(score2);
    }
    return msg;
}

