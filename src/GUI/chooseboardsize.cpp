#include "chooseboardsize.h"


chooseBoardSize::chooseBoardSize(OthelloGUI *parent) : ui(new Ui::chooseBoardSize){

    ui->setupUi(this);
    this->parent = parent;
    parent->setBoardSize(8); //set default value
}

chooseBoardSize::~chooseBoardSize(){
    delete ui;
}


void chooseBoardSize::on_playBtn_clicked(){
    //init board

   parent->setWidget(4);
}

void chooseBoardSize::on_backBtn_clicked(){
    this->~chooseBoardSize();
}

void chooseBoardSize::on_size6x6RadioBtn_clicked(){
    parent->setBoardSize(6);
}

void chooseBoardSize::on_size8x8RadioBtn_clicked(){
    parent->setBoardSize(8);
}

void chooseBoardSize::on_size10x10RadioBtn_clicked(){
    parent->setBoardSize(10);
}

void chooseBoardSize::on_size12x12RadioBtn_clicked(){
    parent->setBoardSize(12);
}
