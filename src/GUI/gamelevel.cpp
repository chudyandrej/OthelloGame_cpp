#include "gamelevel.h"


GameLevel::GameLevel(OthelloGUI *parent) : ui(new Ui::GameLevel){

    this->parent = parent;
    ui->setupUi(this);
}

GameLevel::~GameLevel(){
    delete ui;
}

void GameLevel::on_beginnerModeBtn_clicked(){
    parent->setGameMode(1);
    parent->setWidget(2);
}

void GameLevel::on_advancedModeBtn_clicked(){
    parent->setGameMode(2);
    parent->setWidget(2);
}

void GameLevel::on_backBtn_clicked(){
    this->~GameLevel();
}
