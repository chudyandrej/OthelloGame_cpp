#include "CreateGameOverMsg.h"

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

std::string CreateGameOverMsg::createMultiPlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2){
    std::string msg;
    if(score1 > score2){        //player1 won
        msg = player1->getName() + " won with score: " + std::to_string(score1);
    }else{                      //player2 won
        msg = player2->getName() + " won with score: " + std::to_string(score2);
    }
    return msg;
}

