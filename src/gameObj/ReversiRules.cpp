//
// Created by Andrej Oliver Chudý on 24/04/16.
//

#include "Game.h"
#include <iostream> //temp



ReversiRules::ReversiRules(int size, Backup *backupGame){
    this->size = size;
    playBoard =  new Board(size);
    this->backupGame = backupGame;


    //starting position
    board_fields[ (size/2)-1][(size/2)-1]->putDisc(new Disc(true));
    board_fields[(size/2)][(size/2)]->putDisc(new Disc(true));
    board_fields[(size/2)-1][(size/2)]->putDisc(new Disc(false));
    board_fields[(size/2)][(size/2)-1]->putDisc(new Disc(false));
}

bool ReversiRules::canPutDisc(int x, int y, Player *playerTurn) {
    BoardField* b_field =  board_fields[x][y];

    if(b_field->getDisc() == nullptr/* && !b_field->isFreeze*/) {
        BoardField *tmp;
        for ( int way = D; way != U; way++ ){
            tmp = b_field->nextField(way);
            if (tmp != nullptr /*&& !tmp->isFreeze */&& tmp->getDisc() != nullptr && tmp->getDisc()->getIsWhite() != playerTurn->getIsWhite()) {
                while (tmp != nullptr && tmp->getDisc() != nullptr/* && !tmp->isFreeze*/) {
                    if (tmp->getDisc()->getIsWhite() == playerTurn->getIsWhite() ) {
                        return true;
                    }
                    tmp = tmp->nextField(way);
                }
            }
        }
    }
    return false;
}

bool ReversiRules::putDisc(int x, int y, Player* playerTurn) {
    BoardField  *b_field =  board_fields[x][y];
    std::vector<BoardField*> discs_for_turn;
    bool success = false;
    if(b_field->getDisc() == nullptr/* && !b_field->isFreeze*/) {
        for ( int way = D; way != U; way++ ){
            discs_for_turn = chack_IN_direct(b_field, way,playerTurn );
            if (!discs_for_turn.empty()){
                if(!success){backupGame->createNewTurn(x, y, playerTurn);}
                backupGame->addTurnedDisc(discs_for_turn);
                turn_discs(discs_for_turn);
                success = true;
            }
        }
        if (success){
            b_field->putDisc(new Disc(playerTurn->getIsWhite()));
        }
    }
    return success;
}


std::vector<BoardField*> ReversiRules::chack_IN_direct(BoardField *field, int way, Player *playerTurn) {
    field = field->nextField(way);
    std::vector <BoardField*> candidate_turn;

    if (field != nullptr /*&& !field->isFreeze */&& field->getDisc() != nullptr  && field->getDisc()->getIsWhite() != playerTurn->getIsWhite()) {

        while (field != nullptr && field->getDisc() != nullptr/* && !field->isFreeze*/) {
            if (field->getDisc()->getIsWhite() == playerTurn->getIsWhite()) {
                return candidate_turn ;
            }
            candidate_turn.push_back(field);
            field = field->nextField(way);
        }
    }
    candidate_turn.clear();
    return candidate_turn;

}

void ReversiRules::turn_discs(std::vector<BoardField *> st) {
    BoardField* tmp;
    while (!st.empty()){
        tmp = st.back();
        tmp->getDisc()->turn(UserInt);
        st.pop_back();
    }

}

void ReversiRules::uiAlgorithmLevel1(Player* UI) {
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (canPutDisc(i,j,UI)){
                putDisc(i,j,UI);
                return;
            }
        }
    }
}

void ReversiRules::uiAlgorithmLevel2(Player *UI) {
    std::vector<BoardField*> discsForTurn;
    std::vector<BoardField*> maxTurns;
    BoardField* best_field = nullptr;
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (canPutDisc(i,j,UI)){
                BoardField* fieldn =  board_fields[i][j];
                for ( int way = D; way != U; way++ ){
                    discsForTurn =  chack_IN_direct(fieldn, way,UI );
                    if (!discsForTurn.empty() && discsForTurn.size() > maxTurns.size()){
                        maxTurns = discsForTurn;
                        best_field = fieldn;
                    }
                }
            }
        }
    }
    if (!maxTurns.empty()) {
        //backupGame.create_NewTurn(best_field,UI);
        //backupGame.add_TurnedDiscs(maxTurns);
        //assert best_field != null;
        best_field->putDisc(new Disc(UI->getIsWhite()));
        turn_discs(maxTurns);
    }
}

void ReversiRules::calcScore(Player *currentPlayer) {
    int white_Disc = 0;
    int blac_Dsik = 0;
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Disc* tmp = board_fields[i][j]->getDisc();
            if (tmp == nullptr){
                continue;
            }
            else if(tmp->getIsWhite()){ white_Disc++; }
            else if(!tmp->getIsWhite()){ blac_Dsik++; }
        }
    }
   UserInt->setGameState(white_Disc, blac_Dsik, currentPlayer->getIsWhite());

}

bool ReversiRules::isExitsingTurn(Player *currentPlayer) {
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (currentPlayer->canPutDisc(i,j)){
                return true;
            }
        }
    }
    return false;
}

int ReversiRules::getSize(){
    return size;
}















