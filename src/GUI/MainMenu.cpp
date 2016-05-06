/**
 * File contains methods for MainMenu page.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "MainMenu.h"

/**
 * Constructor of GameLevel menu page.
 */
MainMenu::MainMenu(OthelloGUI *parent) :  ui(new Ui::MainMenu){

    this->parent = parent;
    ui->setupUi(this);
    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");
}

/**
 * Destructor.
 */
MainMenu::~MainMenu(){
    delete ui;
}

/**
 * Implements behaviour when on SIngle Player button clicked.
 */
void MainMenu::on_singlePlayerBtn_clicked(){
    parent->setWidget(1);
    parent->setSinglePlayer(true);
}

/**
 * Implements behaviour when on multiPlayer button clicked.
 */
void MainMenu::on_multiPlayerBtn_clicked(){
    parent->setWidget(2);
    parent->setSinglePlayer(false);
}

/**
 * Implements behaviour when on load game button clicked.
 */
void MainMenu::on_loadGameBtn_clicked(){
    //create new game

    std::string p1Name, p2Name;
    int level1, level2, size;

    //init loading of game
    std::tie(size, p1Name, level1, p2Name, level2) = Backup::loadSettings();

    if(size == 0){ //means error
        QMessageBox::information(this, "Save Game Process",
                                 "<font color='#ffffff'>Loading game FAILED, no saved game exists!</font>", QMessageBox::Ok);
        return;
    }

    if(level2 != 0){    //it's computer player
        parent->setGameMode(level2);
        parent->setNames(p1Name, "Player2", p2Name);
    }
    else{
        parent->setNames(p1Name, p2Name, "Computer");
    }
    parent->setBoardSize(size);

    parent->setWidget(5);
}

/**
 * Implements behaviour when on settings button clicked.
 */
void MainMenu::on_settingsBtn_clicked(){
    parent->setWidget(3);
}

/**
 * Implements behaviour when on quit button clicked.
 */
void MainMenu::on_quitBtn_clicked(){
    parent->exit();
}
