#include "PlayArea.h"
#include <stdio.h>


PlayArea::PlayArea(OthelloGUI *parent) : ui(new Ui::PlayArea){

    ui->setupUi(this);
    this->parent = parent;

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");

    initNewGame();

    //set icons above board
    QGridLayout *grid = new QGridLayout;
    ui->iconsContainerWidget->setLayout(grid);

    grid->addWidget(new PlayAreaIcon(0, this, parent), 0,0, -1,-1,0);
    grid->addWidget(new PlayAreaIcon(1, this, parent), 0,1, -1,-1,0);
    grid->addWidget(new PlayAreaIcon(2, this, parent), 0,2, -1,-1,0);
    grid->addWidget(new PlayAreaIcon(3, this, parent), 0,3, -1,-1,0);
    grid->addWidget(new PlayAreaIcon(4, this, parent), 0,4, -1,-1,0);

}


PlayArea::~PlayArea(){
    delete ui;
}

Game *PlayArea::getCurrentGame(){
    return newGame;
}

void PlayArea::showGameOverDialog(){
    std::string msg = gameOverDialogMsg();

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Game Over", "<font color='#ffffff'>"+QString::fromUtf8(msg.c_str())+"</font>", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        //start new game
        //delete game? delete players and board?
        parent->setWidget(4);
      }
      else {
         //go to main menu
          this->~PlayArea();
          parent->initMenuAgain();
      }
}

void PlayArea::initNewGame(){
    int size = parent->getBoardSize();

    //create board
    QGridLayout *grid = new QGridLayout;
    grid->setHorizontalSpacing(0);
    grid->setVerticalSpacing(0);
    ui->board->setLayout(grid);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            boardFields[i][j] = new BoardFieldWidget(i, j, this);
            grid->addWidget(boardFields[i][j],i,j,0 );//-1 -1
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
    ui->player1NameLabel->setStyleSheet("QLabel { color : white; font-size: 15pt;}");
    ui->player2NameLabel->setText(QString::fromUtf8(parent->getP2Name().c_str()));
    ui->player2NameLabel->setStyleSheet("QLabel { color : white; font-size: 15pt;}");

    ui->player1DiscLabel->setStyleSheet("QLabel {background-image: url(:/lib/whiteDisc.png)}");
    ui->player2DiscLabel->setStyleSheet("QLabel {background-image: url(:/lib/blackDisc.png)}");


    //initialize game state
    setGameState(2, 2, false);
}

void PlayArea::changeDisc(int x, int y, bool isWhite){
    boardFields[x][y]->setDisc(isWhite);
}

void PlayArea::deleteDisc(int x, int y){
    boardFields[x][y]->deleteDisc();
}

void PlayArea::freezeField(int x, int y){
    boardFields[x][y]->freeze();
}

void PlayArea::unFreezeField(int x, int y){
    boardFields[x][y]->unFreeze();
}

void PlayArea::setGameState(int score1, int score2, bool isWhite){
    if(isWhite){
        ui->scoreArrayLabel->setStyleSheet("QLabel {background-image: url(:/lib/arrow_r.png)}");
    }
    else{
        ui->scoreArrayLabel->setStyleSheet("QLabel {background-image: url(:/lib/arrow_l.png)}");
    }
    ui->score1Label->setText(QString::number(score1));
    ui->score1Label->setStyleSheet("QLabel { color : white; font-size: 15pt;}");
    ui->score2Label->setText(QString::number(score2));
    ui->score2Label->setStyleSheet("QLabel { color : white; font-size: 15pt;}");
    this->score1 = score1;
    this->score2 = score2;
}


std::string PlayArea::gameOverDialogMsg(){
    std::string msg;
    if (score1 == score2){      //stalemate
        msg = "Stalemate! Winners:<br>  -"+player1->getName()+"<br>  -"+player2->getName()+"<br>Score: "+std::to_string(score1);
    }
    else if(player1->getIs_pc() || player2->getIs_pc()){
        msg = createSinglePlayerGameOverMsg();
    }else{
        msg = createMultiPlayerGameOverMsg();
    }

    msg = msg + "<br>Would you like to play again?";

    return msg;
}

std::string PlayArea::createSinglePlayerGameOverMsg(){
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

std::string PlayArea::createMultiPlayerGameOverMsg(){
    std::string msg;
    if(score1 > score2){        //player1 won
        msg = player1->getName() + " won with score: " + std::to_string(score1);
    }else{                      //player2 won
        msg = player2->getName() + " won with score: " + std::to_string(score2);
    }
    return msg;
}
