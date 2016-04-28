#include "playarea.h"
#include <stdio.h>


playArea::playArea(OthelloGUI *parent) : ui(new Ui::playArea){

    ui->setupUi(this);
    this->parent = parent;

    initNewGame();
}


playArea::~playArea(){
    delete ui;
}

Game *playArea::getCurrentGame(){
    return newGame;
}

void playArea::showGameOverDialog(){
    std::string msg = gameOverDialogMsg();

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Game Over", QString::fromUtf8(msg.c_str()), QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        //start new game
        //delete game? delete players and board?
        this->initNewGame();
      }
      else {
         //go to main menu
          this->~playArea();
          parent->initMenuAgain();
      }
}

void playArea::initNewGame(){
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
    newGame = new Game(size, parent->getDiscsToFreeze(), parent->getChangeTimer(), parent->getFrozeTime(), this);

    player1 = new Player(true, parent->getP1Name());
    newGame->addPlayer(player1);

    if(parent->getIsGameSinglePlayer()){
        player2 = new Player(false, parent->getGameMode(), parent->getComputerName());
    }
    else{
        player2 = new Player(false, parent->getP2Name());
    }

    newGame->addPlayer(player2);


    ui->player1NameLabel->setText(QString::fromUtf8(parent->getP1Name().c_str()));
    ui->player2NameLabel->setText(QString::fromUtf8(parent->getP1Name().c_str()));


    //initialize game state
    setGameState(2, 2, false);
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
    //arrow rotate
    ui->score1Label->setText(QString::number(score1));
    ui->score2Label->setText(QString::number(score2));
    this->score1 = score1;
    this->score2 = score2;
}


std::string playArea::gameOverDialogMsg(){
    std::string msg;
    if (score1 == score2){      //stalemate
        msg = "Stalemate! Winners:\n  -"+player1->getName()+"\n  -"+player2->getName()+"\nScore: "+std::to_string(score1);
    }
    else if(player1->getIs_pc() || player2->getIs_pc()){
        msg = createSinglePlayerGameOverMsg();
    }else{
        msg = createMultiPlayerGameOverMsg();
    }

    msg = msg + "\nWould you like to play again?";

    return msg;
}

std::string playArea::createSinglePlayerGameOverMsg(){
   std::string msg;
   if(player1->getIs_pc()) {
       msg = (score1 > score2) ? "You LOST. Computer won.\n" : "Congratulation!\nYou WON.\n";
       msg = msg + "Your score: " + std::to_string(score2) + "\n" +player1->getName()+": "+std::to_string(score1);
   }
   else{
       msg = (score1 < score2) ? "You LOST. Computer won.\n" : "Congratulation!\nYou WON.\n";
       msg = msg + "Your score: " + std::to_string(score1) + "\n" +player2->getName()+": "+std::to_string(score2);
   }
   return msg;
}

std::string playArea::createMultiPlayerGameOverMsg(){
    std::string msg;
    if(score1 > score2){        //player1 won
        msg = player1->getName() + " won with score: " + std::to_string(score1);
    }else{                      //player2 won
        msg = player2->getName() + " won with score: " + std::to_string(score2);
    }
    return msg;
}
