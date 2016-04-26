#include "playarea.h"


playArea::playArea(OthelloGUI *parent) : ui(new Ui::playArea){

    ui->setupUi(this);
    this->parent = parent;

    int size = parent->getBoardSize();
    boardFieldWidget *boardFields[size][size];


    QGridLayout *grid = new QGridLayout;
    ui->board->setLayout(grid);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            boardFields[i][j] = new boardFieldWidget(i, j);
            grid->addWidget(boardFields[i][j],i,j,-1,-1,0 );
        }
    }
}


playArea::~playArea(){
    delete ui;
}
