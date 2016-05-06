/**
 * File contains method for PlayArea class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "PlayArea.h"
#include <stdio.h>


/**
 * Constructor of PlayArea page.
 */
PlayArea::PlayArea(OthelloGUI *parent, bool loadingGame) : ui(new Ui::PlayArea){

    ui->setupUi(this);
    this->parent = parent;

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");

    initBoard();
    initNewGame();

    if(loadingGame){
        newGame->backupGame->loadGame();
    }
}

/**
 * Desctructor.
 */
PlayArea::~PlayArea(){
    delete ui;
}

/**
 * Current game getter.
 * @return pointer to current game
 */
Game *PlayArea::getCurrentGame(){
    return newGame;
}

/**
 * Method creates pop up window with game summary info.
 */
void PlayArea::showGameOverDialog(){
    std::string msg = gameOverDialogMsg();

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Game Over", "<font color='#ffffff'>"+QString::fromUtf8(msg.c_str())+"</font>", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        //start new game
        parent->setWidget(4);
      }
      else {
         //go to main menu
          this->~PlayArea();
          parent->initMenuAgain();
      }
}

/**
 * Parent getter.
 * @return pointer to the parent. 
 */
OthelloGUI *PlayArea::getParent(){
    return parent;
}

/**
 * Method initializes board, sets icons above board
 * and game status bar 
 */
void PlayArea::initBoard(){
    int size = parent->getBoardSize();

    //create board
    QGridLayout *grid = new QGridLayout;
    grid->setHorizontalSpacing(0);
    grid->setVerticalSpacing(0);

    Images *I = new Images(size);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            boardFields[i][j] = new BoardFieldLabel(i, j, this, I);
            grid->addWidget(boardFields[i][j], i, j, 0);
        }
    }
    ui->board->setLayout(grid);

    //set labels on game status bar
    ui->player1NameLabel->setText(QString::fromUtf8(parent->getP1Name().c_str()));
    ui->player1NameLabel->setStyleSheet("QLabel { color : white; font-size: 15pt;}");
    ui->player2NameLabel->setText(QString::fromUtf8(parent->getP2Name().c_str()));
    ui->player2NameLabel->setStyleSheet("QLabel { color : white; font-size: 15pt;}");

    ui->player1DiscLabel->setStyleSheet("QLabel {background-image: url(:/lib/whiteDisc.png)}");
    ui->player2DiscLabel->setStyleSheet("QLabel {background-image: url(:/lib/blackDisc.png)}");


    //initialize game state
    setGameState(2, 2, false);


    //set icons above board
    QGridLayout *iconsGrid = new QGridLayout;
    ui->iconsContainerWidget->setLayout(iconsGrid);

    iconsGrid->addWidget(new PlayAreaIcon(0, this, parent), 0,0, 0);
    iconsGrid->addWidget(new PlayAreaIcon(1, this, parent), 0,1, 0);
    iconsGrid->addWidget(new PlayAreaIcon(2, this, parent), 0,2, 0);
    iconsGrid->addWidget(new PlayAreaIcon(3, this, parent), 0,3, 0);
    iconsGrid->addWidget(new PlayAreaIcon(4, this, parent), 0,4, 0);
}

/**
 * Method initializes new game
 */
void PlayArea::initNewGame(){

    //init game
    newGame = new Game(parent->getBoardSize(), parent->getDiscsToFreeze(), parent->getChangeTimer(), parent->getFrozeTime(), this);

    player1 = new Player(true, parent->getP1Name());
    newGame->addPlayer(player1);

    if(parent->getIsGameSinglePlayer()){
        player2 = new Player(false, parent->getGameMode(), parent->getComputerName());
    }
    else{
        player2 = new Player(false, parent->getP2Name());
    }

    newGame->addPlayer(player2);
}

/**
 * Method for changing disc's color
 * @param x x-coordinate
 * @param y y-coordinate
 * @param isWhite color to which disc will be changed
 */
void PlayArea::changeDisc(int x, int y, bool isWhite){
    boardFields[x][y]->setDisc(isWhite);
}

/**
 * Method for changing disc's color
 * @param x x-coordinate
 * @param y y-coordinate
 * @param isWhite color to which disc will be changed
 */
void PlayArea::deleteDisc(int x, int y){
    boardFields[x][y]->deleteDisc();
}

/**
 * Method freezes the field.
 * @param x x-coordinate
 * @param y y-coordinate
 * @param isWhite color to which disc will be changed
 */
void PlayArea::freezeField(int x, int y){
    boardFields[x][y]->freeze();
}

/**
 * Method unfreezes the field.
 * @param x x-coordinate
 * @param y y-coordinate
 * @param isWhite color to which disc will be changed
 */
void PlayArea::unFreezeField(int x, int y){
    boardFields[x][y]->unFreeze();
}

/**
 * Method sets game state information
 * @param score1  player1's score
 * @param score2  player2's score
 * @param isWhite color of player on turn
 */
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

/**
 * Method creates game summary message when game is over.
 * @return message
 */
std::string PlayArea::gameOverDialogMsg(){
    std::string msg;
    if (score1 == score2){      //stalemate
        msg = "Stalemate! Winners:<br>  -"+player1->getName()+"<br>  -"+player2->getName()+"<br>Score: "+std::to_string(score1);
    }
    else if(player1->getIs_pc() || player2->getIs_pc()){
        msg = CreateGameOverMsg::createSinglePlayerGameOverMsg(score1, score2, player1, player2);
    }else{
        msg = CreateGameOverMsg::createMultiPlayerGameOverMsg(score1, score2, player1, player2);
    }

    msg = msg + "<br>Would you like to play again?";

    return msg;
}

