/**
 * File contains OthelloGUI methods for game control 
 * through Graphical User Interface.
 * 
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "OthelloGUI.h"


/**
 * Constructor of OthelloGUI.
 */
OthelloGUI::OthelloGUI(int argc, char *argv[]) : QApplication(argc, argv){

    //set default values
    boardSize = 8;
    player1Name = "Player1";
    player2Name = "Player2";
    computerName = "Bot";


    mainMenuPage = new MainMenu(this);
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(mainMenuPage);
    stackedWidget->show();

    exec();
}

/**
 * Destructor.
 */
OthelloGUI::~OthelloGUI(){

    delete mainMenuPage;
    delete stackedWidget;
}

/**
 * Method sets size of board.
 * @param size size of board
 */
void OthelloGUI::setBoardSize(int size){
    boardSize = size;
}

/**
 * Method sets singlePlayer boolean value.
 * @param single true if singleplayer, else false
 */
void OthelloGUI::setSinglePlayer(bool single){
    singlePlayer = single;
}

/**
 * Method sets level of AI
 * @param mode level
 */
void OthelloGUI::setGameMode(int mode){
    gameMode = mode;
}

/**
 * Setter for players' names
 * @param player1Name  name of player1
 * @param player2Name  name of player2
 * @param computerName name of bot
 */
void OthelloGUI::setNames(std::string player1Name, std::string player2Name, std::string computerName){
    this->player1Name = player1Name;
    this->player2Name = player2Name;
    this->computerName = computerName;
}

/**
 * Method sets discs freezing options.
 * @param discsToFreeze max number of discs, which will be considered (randomly) to be frozen at each turn
 * @param FTime max time in seconds after wchich will be the discs made unfrozen
 * @param CHTimer max time in seconds after which will be random discs made frozen
 */
void OthelloGUI::setFreezingOptions(int discs, int FTime, int CHTimer){
    discsToFreeze = discs;
    frozeTime = FTime;
    changeTimer = CHTimer;
}

/**
 * Method creates page to be shown in the main frame (window).
 * @param page number of page to be set
 */
void OthelloGUI::setWidget(int page){
    switch(page){
        case 1:
            gameModePage = new GameLevel(this);
            stackedWidget->addWidget(gameModePage);
            stackedWidget->setCurrentWidget(gameModePage);
            break;
        case 2:
            chooseBoardSizePage = new ChooseBoardSize(this);
            stackedWidget->addWidget(chooseBoardSizePage);
            stackedWidget->setCurrentWidget(chooseBoardSizePage);
            break;
        case 3:
            settingsPage = new Settings(this);
            stackedWidget->addWidget(settingsPage);
            stackedWidget->setCurrentWidget(settingsPage);
            break;
        case 4:             //init board and game
            playAreaPage = new PlayArea(this);
            stackedWidget->addWidget(playAreaPage);
            stackedWidget->setCurrentWidget(playAreaPage);
            break;
        case 5:             //init board and game and load turns
            playAreaPage = new PlayArea(this, true);
            stackedWidget->addWidget(playAreaPage);
            stackedWidget->setCurrentWidget(playAreaPage);
    }
}

/**
 * Method deletes previous game and initializes new one.
 */
void OthelloGUI::initMenuAgain(){
    if(gameModePage != nullptr){
        delete gameModePage;
        gameModePage = nullptr;
    }
    if(chooseBoardSizePage != nullptr){
        delete chooseBoardSizePage;
        chooseBoardSizePage = nullptr;
    }
}

/**
 * BoardSize getter.
 * @return boardSize
 */
int OthelloGUI::getBoardSize(){
    return boardSize;
}

/**
 * Game mode getter.
 * @return gameMode
 */
int OthelloGUI::getGameMode(){
    return gameMode;
}

/**
 * Singleplayer getter.
 * @return singlePlayer
 */
bool OthelloGUI::getIsGameSinglePlayer(){
    return singlePlayer;
}

/**
 * Player1 name getter.
 * @return player1Name
 */
std::string OthelloGUI::getP1Name(){
    return player1Name;
}

/**
 * Player2 name getter.
 * @return player2Name
 */
std::string OthelloGUI::getP2Name(){
    return player2Name;
}

/**
 * Computer name getter.
 * @return computerName
 */
std::string OthelloGUI::getComputerName(){
    return computerName;
}

/**
 * Discs to freeze getter.
 * @return discsToFreeze
 */
int OthelloGUI::getDiscsToFreeze(){
    return discsToFreeze;
}

/**
 * Froze time getter.
 * @return frozeTime
 */
int OthelloGUI::getFrozeTime(){
    return frozeTime;
}

/**
 * Change timer getter.
 * @return changeTimer
 */
int OthelloGUI::getChangeTimer(){
    return changeTimer;
}
