#include "playarea.h"
#include <stdio.h>


playArea::playArea(OthelloGUI *parent) : ui(new Ui::playArea){

    ui->setupUi(this);
    this->parent = parent;

    int size = parent->getBoardSize();
    //boardFieldWidget *boardFields[size][size];



    //create board
    QGridLayout *grid = new QGridLayout;
    ui->board->setLayout(grid);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            boardFields[i][j] = new boardFieldWidget(i, j, this);
            grid->addWidget(boardFields[i][j],i,j,-1,-1,0 );
        }
    }


    //init game
    newGame = new Game(size, 0, 0, 0, this);
    newGame->addPlayer(new Player(true, parent->getP1Name()));

    if(parent->getIsGameSinglePlayer()){
        newGame->addPlayer(new Player(false, parent->getGameMode(), parent->getComputerName()));
    }else{
        newGame->addPlayer(new Player(false, parent->getP2Name()));
    }

}


playArea::~playArea(){
    delete ui;
}

Game *playArea::getCurrentGame(){
    return newGame;
}

void playArea::showGameOverDialog(){

}

void playArea::changeDisc(int x, int y, bool isWhite){
    boardFields[x][y]->setDisc(isWhite);
}

void playArea::deleteDisc(int x, int y){
    boardFields[x][y]->deleteDisc();
}

void playArea::freezeField(int x, int y){
    boardFields[x][y]->freeze();
}

void playArea::unFreezeField(int x, int y){
    boardFields[x][y]->unFreeze();
}

void playArea::setGameState(int score1, int score2, bool isWhite){

}
