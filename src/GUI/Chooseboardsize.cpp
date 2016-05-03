#include "ChooseBoardSize.h"


ChooseBoardSize::ChooseBoardSize(OthelloGUI *parent) : ui(new Ui::ChooseBoardSize){

    ui->setupUi(this);
    this->parent = parent;
    parent->setBoardSize(8); //set default value

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");
}

ChooseBoardSize::~ChooseBoardSize(){
    delete ui;
}


void ChooseBoardSize::on_playBtn_clicked(){
    //init board

   parent->setWidget(4);
}

void ChooseBoardSize::on_backBtn_clicked(){
    this->~ChooseBoardSize();
}

void ChooseBoardSize::on_size6x6RadioBtn_clicked(){
    parent->setBoardSize(6);
}

void ChooseBoardSize::on_size8x8RadioBtn_clicked(){
    parent->setBoardSize(8);
}

void ChooseBoardSize::on_size10x10RadioBtn_clicked(){
    parent->setBoardSize(10);
}

void ChooseBoardSize::on_size12x12RadioBtn_clicked(){
    parent->setBoardSize(12);
}
