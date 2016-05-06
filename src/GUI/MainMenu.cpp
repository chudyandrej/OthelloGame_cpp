#include "MainMenu.h"


MainMenu::MainMenu(OthelloGUI *parent) :  ui(new Ui::MainMenu){

    this->parent = parent;
    ui->setupUi(this);

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");

}

MainMenu::~MainMenu(){
    delete ui;
}


void MainMenu::on_singlePlayerBtn_clicked(){
    parent->setWidget(1);
    parent->setSinglePlayer(true);
}

void MainMenu::on_multiPlayerBtn_clicked(){
    parent->setWidget(2);
    parent->setSinglePlayer(false);
}

void MainMenu::on_loadGameBtn_clicked(){
    //create new game

    std::string p1Name, p2Name;
    bool p1, p2;
    int level1, level2, size;

    //init loading of game
    std::tie(size, p1Name, level1, p2Name, level2) = Backup::loadSettings();

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

void MainMenu::on_settingsBtn_clicked(){
    parent->setWidget(3);
}

void MainMenu::on_quitBtn_clicked(){
    parent->exit();
}
