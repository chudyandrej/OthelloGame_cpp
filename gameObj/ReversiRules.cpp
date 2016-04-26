//
// Created by Andrej Oliver Chudý on 24/04/16.
//



#include "Game.h"


bool ReversiRules::canPutDisk(int x, int y, Player *playerTurn) {
    BoardField* b_field =  board_fields[x][y];
    if(b_field->getDisk() == nullptr && !b_field->isFreeze) {
        BoardField *tmp;
        for ( int way = D; way != U; way++ ){
            tmp = b_field->nextField(way);
            if (tmp != nullptr && !tmp->isFreeze && tmp->getDisk() != nullptr && tmp->getDisk()->getIsWhite() != playerTurn->getIsWhite()) {
                while (tmp != nullptr && tmp->getDisk() != nullptr && !tmp->isFreeze) {
                    if (tmp->getDisk()->getIsWhite() == playerTurn->getIsWhite() ) {
                        return true;
                    }
                    tmp = tmp->nextField(way);
                }
            }
        }
    }
    return false;
}

bool ReversiRules::putDisk(int x, int y, Player* playerTurn) {
    BoardField  *b_field =  board_fields[x][y];
    std::vector<BoardField*> disks_for_turn;
    bool success = false;
    if(b_field->getDisk() == nullptr && !b_field->isFreeze) {
        for ( int way = D; way != U; way++ ){
            disks_for_turn = chack_IN_direct(b_field, way,playerTurn );
            if (!disks_for_turn.empty()){
                //if(!success){backupGame.create_NewTurn(board_fields,playerTurn);}
                //backupGame.add_TurnedDisks(disks_for_turn);
                turn_disks(disks_for_turn);
                success = true;
            }
        }
        if (success){
            b_field->putDisk(new Disk(playerTurn->getIsWhite()));

        }
    }
    return success;
}

std::vector<BoardField*> ReversiRules::chack_IN_direct(BoardField *field, int way, Player *playerTurn) {
    field = field->nextField(way);
    std::vector <BoardField*> candidate_turn;
    if (field != nullptr && !field->isFreeze && field->getDisk() != nullptr  && field->getDisk()->getIsWhite() != playerTurn->getIsWhite()) {

        while (field != nullptr && field->getDisk() != nullptr && !field->isFreeze) {
            if (field->getDisk()->getIsWhite() == playerTurn->getIsWhite()) {
                return candidate_turn ;
            }
            candidate_turn.push_back(field);
            field = field->nextField(way);
        }
    }
    return candidate_turn ;

}

void ReversiRules::turn_disks(std::vector<BoardField *> st) {
    BoardField* tmp;
    while (!st.empty()){
        tmp = st.back();
        tmp->getDisk()->turn();
        st.pop_back();
    }

}

void ReversiRules::uiAlgorithmLevel1(Player* UI) {
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (canPutDisk(i,j,UI)){
                putDisk(i,j,UI);
                return;
            }
        }
    }
}

void ReversiRules::uiAlgorithmLevel2(Player *UI) {
    std::vector<BoardField*> disksForTurn;
    std::vector<BoardField*> maxTurns;
    BoardField* best_field = nullptr;
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (canPutDisk(i,j,UI)){
                BoardField* fieldn =  board_fields[i][j];
                for ( int way = D; way != U; way++ ){
                    disksForTurn =  chack_IN_direct(fieldn, way,UI );
                    if (!disksForTurn.empty() && disksForTurn.size() > maxTurns.size()){
                        maxTurns = disksForTurn;
                        best_field = fieldn;
                    }
                }
            }
        }
    }
    if (!maxTurns.empty()) {
        //backupGame.create_NewTurn(best_field,UI);
        //backupGame.add_TurnedDisks(maxTurns);
        //assert best_field != null;
        best_field->putDisk(new Disk(UI->getIsWhite()));
        turn_disks(maxTurns);
    }
}

void ReversiRules::calcScore(Player *currentPlayer) {
    int white_Disk = 0;
    int blac_Dsik = 0;
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Disk* tmp = board_fields[i][j]->getDisk();
            if (tmp == nullptr){
                continue;
            }
            else if(tmp->getIsWhite()){ white_Disk++; }
            else if(!tmp->getIsWhite()){ blac_Dsik++; }
        }
    }
   //BoardGUI.setGameState(white_Disk, blac_Dsik, currentPlayer.isWhite());

}

bool ReversiRules::isExitsingTurn(Player *currentPlayer) {
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (currentPlayer->canPutDisk(i,j)){
                return true;
            }
        }
    }
    return false;
}
















