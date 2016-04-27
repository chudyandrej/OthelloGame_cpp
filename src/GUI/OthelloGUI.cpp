#include "othellogui.h"
#include <iostream> //just temporary


OthelloGUI::OthelloGUI(int argc, char *argv[]) : QApplication(argc, argv){

    //set default values
    boardSize = 8;
    player1Name = "Player1";
    player2Name = "Player2";
    computerName = "Computer";


    mainMenuPage = new mainMenu(this);
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(mainMenuPage);
    stackedWidget->show();

    exec();

}

OthelloGUI::~OthelloGUI(){

    delete mainMenuPage;
    delete stackedWidget;

}

void OthelloGUI::setBoardSize(int size){
    boardSize = size;
}

void OthelloGUI::setSinglePlayer(bool single){
    //std::cout << player1Name <<" "<< player2Name << " "<< computerName <<"\n";
    singlePlayer = single;
}

void OthelloGUI::setGameMode(int mode){
    gameMode = mode;
}

void OthelloGUI::setNames(std::string player1Name, std::string player2Name, std::string computerName){
    this->player1Name = player1Name;
    this->player2Name = player2Name;
    this->computerName = computerName;
}

void OthelloGUI::setFreezingOptions(int discs, int FTime, int CHTimer){
    discsToFreeze = discs;
    frozeTime = FTime;
    changeTimer = CHTimer;
}

void OthelloGUI::setWidget(int page){
    switch(page){
        case 1:
            gameModePage = new GameLevel(this);
            stackedWidget->addWidget(gameModePage);
            stackedWidget->setCurrentWidget(gameModePage);
            break;
        case 2:
            chooseBoardSizePage = new chooseBoardSize(this);
            stackedWidget->addWidget(chooseBoardSizePage);
            stackedWidget->setCurrentWidget(chooseBoardSizePage);
            break;
        case 3:
            settingsPage = new settings(this);
            stackedWidget->addWidget(settingsPage);
            stackedWidget->setCurrentWidget(settingsPage);
            break;
        case 4:
            playAreaPage = new playArea(this);
            stackedWidget->addWidget(playAreaPage);
            stackedWidget->setCurrentWidget(playAreaPage);
    }
}

int OthelloGUI::getBoardSize(){
    return boardSize;
}

int OthelloGUI::getGameMode(){
    return gameMode;
}

bool OthelloGUI::getIsGameSinglePlayer(){
    return singlePlayer;
}

std::string OthelloGUI::getP1Name(){
    return player1Name;
}

std::string OthelloGUI::getP2Name(){
    return player2Name;
}

std::string OthelloGUI::getComputerName(){
    return computerName;
}

int OthelloGUI::getDiscsToFreeze(){
    return discsToFreeze;
}

int OthelloGUI::getFrozeTime(){
    return frozeTime;
}

int OthelloGUI::getChangeTimer(){
    return changeTimer;
}
