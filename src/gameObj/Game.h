/**
 * Header file for Game, ReversiRules and Player class.
 * Player is also implemented here.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H

#include <vector>
#include <list>
#include <string>
#include "../board/Board.h"
#include "../UserInterface.h"

//forward declarations
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

    Game(int size, int discsToFreeze, int CHTime, int FTime, UserInterface *UI);
    bool addPlayer(Player *newPlayer);
    Player* getCurrentPlayer();
    bool getIsGameOver();
    void nextPlayer();
    void undo();
    void redo();


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
    void loadFrozen(std::list<BoardField*> frozen);
    std::list<BoardField*> frozen;
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
    /**
    * Constructor method, initializes player, color and name.
    * @param isWhite boolean color of player
    * @param name player's name
    */
    Player(bool isWhite, std::string name) {
        this->isWhite = isWhite;
        this->name = name;
    }

    /**
     * The second constructor method, which initializes AI player (bot)
     * @param isWhite color (true if white)
     * @param level level of AI
     * @param name player's name
     */
    Player(bool isWhite, int level, std::string name) {
        this->is_pc = true;
        this->level = level;
        this->isWhite = isWhite;
        this->name = name;
    }

    /**
     * Player name getter.
     * @return name of the player
     */
    std::string getName(){
        return this->name;
    }

    /**
     * Player color getter.
     * @return true if the player is white
     */
    bool getIsWhite(){
        return isWhite;
    }

    /**
     * Method finds out if player can put disc to the field
     * @param x x-coordinate of field
     * @param y y-coordinate of field
     * @return true if success, else false
     */
    bool canPutDisc(int x, int y){
        return rules->canPutDisc(x, y, this);
    }

    /**
     * Methods put disc to the field.
     * @param x x-coordinate of field
     * @param y y-coordinate of field
     * @return true if success, else false
     */
    bool putDisc(int x, int y){
        return rules->putDisc(x, y, this);

    }

    /**
     * Methods runs AI algorithm depends on level.
     */
    void uiTurn() {
        if (level == 1) {
            rules->uiAlgorithmLevel1(this);
        }
        else {
            rules->uiAlgorithmLevel2(this);
        }
    }

    /**
     * @return true if the player is bot
     */
    bool getIs_pc() {
        return is_pc;
    }
};

#endif //OTHELLO_GAME_H
