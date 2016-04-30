#include "boardfieldwidget.h"


boardFieldWidget::boardFieldWidget(int x, int y, playArea *parent) : ui(new Ui::boardFieldWidget) {

    ui->setupUi(this);
    this->parent = parent;
    pressed = false;
    frozen = false;

    this->setStyleSheet("QWidget {background-image: url( :/lib/field.png);border:2px solid black;}");

    this->x = x;
    this->y = y;

}

boardFieldWidget::~boardFieldWidget(){

    delete ui;
}

void boardFieldWidget::setDisc(bool isWhite){
    pressed = true;
    if(isWhite){
        this->setStyleSheet("QWidget {background-image: url( :/lib/white2.png);border:2px solid black;}");
    }else{
        this->setStyleSheet("QWidget {background-image: url( :/lib/black2.png);border:2px solid black;}");
    }
}

void boardFieldWidget::deleteDisc(){
    pressed = false;
    this->setStyleSheet("QWidget {background-image: url( :/lib/field.png);border:2px solid black;}");
}

void boardFieldWidget::freeze(){
    if(frozen){ return; }
    frozen = true;
    //... code will continue
}

void boardFieldWidget::unFreeze(){
    frozen = false;
    //restore background...
}

void boardFieldWidget::mousePressEvent(QMouseEvent *){
    Player *tmp = parent->getCurrentGame()->getCurrentPlayer();

    if(tmp->putDisk(x, y)){
        pressed = true;
        parent->getCurrentGame()->nextPlayer();

        if(parent->getCurrentGame()->getIsGameOver()){
            parent->showGameOverDialog();
        }
    }
}

void boardFieldWidget::mouseMoveEvent(QMouseEvent *){

    if(parent->getCurrentGame()->getCurrentPlayer()->canPutDisk(x, y)){
        this->setStyleSheet("QWidget {background-image: url( :/lib/fieldCanPut.png);border:2px solid black;}");
    }
}

void boardFieldWidget::leaveEvent(QEvent *){
    if(!pressed && !frozen){    //if there is no disc and it's not frozen
        this->setStyleSheet("QWidget {background-image: url( :/lib/field.png);border:2px solid black;}");
    }
}

