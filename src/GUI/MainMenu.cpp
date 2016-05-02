#include "MainMenu.h"


MainMenu::MainMenu(OthelloGUI *parent) :  ui(new Ui::mainMenu){

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
    //code will go here
}

void MainMenu::on_settingsBtn_clicked(){
    parent->setWidget(3);
}

void MainMenu::on_quitBtn_clicked(){
    parent->exit();
}
