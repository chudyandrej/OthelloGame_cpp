/**
 * File contains implemented methods of RiversiRules class.
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

/**
 * Constructor, initializes Reversi rules
 * @param size Size of board
 * @param backupGame Backup of game
 */
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

/**
 * Method decides if the player on turn can put disc to the place.
 * @param x x-coordinate of the field
 * @param y y-coordinate of the field
 * @param playerTurn instance of player on turn
 * @return true if the player can put disc, else false
 */
bool ReversiRules::canPutDisc(int x, int y, Player *playerTurn) {
    BoardField* b_field =  board_fields[x][y];

    if(b_field->getDisc() == nullptr && !b_field->isFreeze) {
        BoardField *tmp;
        for ( int way = D; way <= U; way++ ){
            tmp = b_field->nextField(way);
            if (tmp != nullptr && !tmp->isFreeze && tmp->getDisc() != nullptr && tmp->getDisc()->getIsWhite() != playerTurn->getIsWhite()) {
                while (tmp != nullptr && tmp->getDisc() != nullptr && !tmp->isFreeze) {
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

/**
 * Method puts disc to the field.
 * @param x x-coordinate of the field
 * @param y y-coordinate of the field
 * @param playerTurn instance of player on turn
 * @return true if success, false otherwise
 */
bool ReversiRules::putDisc(int x, int y, Player* playerTurn) {
    BoardField  *b_field =  board_fields[x][y];
    std::vector<BoardField*> discs_for_turn;
    bool success = false;
    if(b_field->getDisc() == nullptr && !b_field->isFreeze) {
        for ( int way = D; way <= U; way++ ){
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

/**
 * Checks color of discs in a direction.
 * @param field Start field
 * @param way Direction of checking
 * @param playerTurn Player on turn
 * @return vector of turned fields
 */
std::vector<BoardField*> ReversiRules::chack_IN_direct(BoardField *field, int way, Player *playerTurn) {
    field = field->nextField(way);
    std::vector <BoardField*> candidate_turn;

    if (field != nullptr && !field->isFreeze && field->getDisc() != nullptr  && field->getDisc()->getIsWhite() != playerTurn->getIsWhite()) {

        while (field != nullptr && field->getDisc() != nullptr && !field->isFreeze) {
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

/**
 * Method turns discs given.
 * @param st vector of fields to be turned.
 */
void ReversiRules::turn_discs(std::vector<BoardField *> st) {
    BoardField* tmp;
    while (!st.empty()){
        tmp = st.back();
        tmp->getDisc()->turn(UserInt);
        st.pop_back();
    }
}

/**
 * Method implements AI algorithm of level 1 (beginner)
 * @param UI instance of AI player
 */
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

/**
 * Method implements AI algorithm of level 2 (advanced)
 * @param UI instance of AI player
 */
void ReversiRules::uiAlgorithmLevel2(Player *UI) {
    std::vector<BoardField*> discsForTurn;
    std::vector<BoardField*> maxTurns;
    BoardField* best_field = nullptr;
    int size = rules->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (canPutDisc(i,j,UI)){
                BoardField* fieldn =  board_fields[i][j];
                for ( int way = D; way <= U; way++ ){
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
        backupGame->createNewTurn(best_field->row, best_field->col, UI);
        backupGame->addTurnedDisc(maxTurns);
        best_field->putDisc(new Disc(UI->getIsWhite()));
        turn_discs(maxTurns);
    }
}

/**
 * Method calculates score of current player.
 * @param currentPlayer instance of current player
 */
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

/**
 * Method finds out if current player has possibility to place disc somewhere,
 * otherwise it's game over.
 * @param currentPlayer instance of current player
 * @return true if exists, else false
 */
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

/**
 * Board size getter.
 * @return size of board
 */
int ReversiRules::getSize(){
    return size;
}

