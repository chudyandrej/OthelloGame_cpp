#include "mainmenu.h"


mainMenu::mainMenu(OthelloGUI *parent) :  ui(new Ui::mainMenu){

    this->parent = parent;
    ui->setupUi(this);

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");

}

mainMenu::~mainMenu(){
    delete ui;
}


void mainMenu::on_singlePlayerBtn_clicked(){
    parent->setWidget(1);
    parent->setSinglePlayer(true);
}

void mainMenu::on_multiPlayerBtn_clicked(){
    parent->setWidget(2);
    parent->setSinglePlayer(false);
}

void mainMenu::on_loadGameBtn_clicked(){
    //code will go here
}

void mainMenu::on_settingsBtn_clicked(){
    parent->setWidget(3);
}

void mainMenu::on_quitBtn_clicked(){
    parent->exit();
}
