/**
 * File contains methods for GameLevel menu page.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "GameLevel.h"

/**
 * Constructor of GameLevel menu page.
 */
GameLevel::GameLevel(OthelloGUI *parent) : ui(new Ui::GameLevel){

    this->parent = parent;
    ui->setupUi(this);

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");
}

/**
 * Destructor.
 */
GameLevel::~GameLevel(){
    delete ui;
}

/**
 * Sets game mode according to the button clicked.
 */
void GameLevel::on_beginnerModeBtn_clicked(){
    parent->setGameMode(1);
    parent->setWidget(2);
}

/**
 * Sets game mode according to the button clicked.
 */
void GameLevel::on_advancedModeBtn_clicked(){
    parent->setGameMode(2);
    parent->setWidget(2);
}

/**
 * When "Back" button is clicked, delete itself.
 */
void GameLevel::on_backBtn_clicked(){
    this->~GameLevel();
}
