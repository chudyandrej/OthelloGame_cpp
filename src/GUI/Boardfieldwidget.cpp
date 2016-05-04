#include "BoardFieldWidget.h"

BoardFieldWidget::BoardFieldWidget(int x, int y, PlayArea *parent) : ui(new Ui::BoardFieldWidget) {

    ui->setupUi(this);
    this->parent = parent;
    pressed = false;
    frozen = false;

    this->setStyleSheet("QWidget {background-image: url( :/lib/field.png);border:2px solid black;}");

    this->x = x;
    this->y = y;

}

BoardFieldWidget::~BoardFieldWidget(){

    delete ui;
}

void BoardFieldWidget::setDisc(bool isWhite){
    pressed = true;
    if(isWhite){
        this->setStyleSheet("QWidget {background-image: url( :/lib/white2.png);border:2px solid black;}");
    }else{
        this->setStyleSheet("QWidget {background-image: url( :/lib/black2.png);border:2px solid black;}");
    }
}

void BoardFieldWidget::deleteDisc(){
    pressed = false;
    this->setStyleSheet("QWidget {background-image: url( :/lib/field.png);border:2px solid black;}");
}

void BoardFieldWidget::freeze(){
    if(frozen){ return; }
    frozen = true;
    //... code will continue
}

void BoardFieldWidget::unFreeze(){
    frozen = false;
    //restore background...
}

void BoardFieldWidget::mousePressEvent(QMouseEvent *){
    Player *tmp = parent->getCurrentGame()->getCurrentPlayer();

    if(tmp->putDisc(x, y)){
        pressed = true;
        parent->getCurrentGame()->nextPlayer();

        if(parent->getCurrentGame()->getIsGameOver()){
            parent->showGameOverDialog();
        }
    }
}

void BoardFieldWidget::mouseMoveEvent(QMouseEvent *){

    if(parent->getCurrentGame()->getCurrentPlayer()->canPutDisc(x, y)){
        this->setStyleSheet("QWidget {background-image: url( :/lib/fieldCanPut.png);border:2px solid black;}");
    }
}

void BoardFieldWidget::leaveEvent(QEvent *){
    if(!pressed && !frozen){    //if there is no disc and it's not frozen
        this->setStyleSheet("QWidget {background-image: url( :/lib/field.png);border:2px solid black;}");
    }
}

