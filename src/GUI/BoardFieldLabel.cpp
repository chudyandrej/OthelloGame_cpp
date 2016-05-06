#include "BoardFieldLabel.h"


BoardFieldLabel::BoardFieldLabel(int x, int y, PlayArea *parent, Images *I){

    this->setMouseTracking(true);
    this->I = I;
    //this->setScaledContents(true);

    switch(parent->getParent()->getBoardSize()){
    case 6:
        this->setMaximumSize(63,63);
        break;
    case 8:
        this->setMaximumSize(47,47);
        break;
    case 10:
        this->setMaximumSize(38,38);
        break;
    case 12:
        this->setMaximumSize(31,31);
        break;
    }


    this->parent = parent;
    pressed = false;
    frozen = false;

    this->setStyleSheet("QWidget {border:2px solid black;}");
    this->setPixmap(*I->field);
    currentBg = I->field;

    this->x = x;
    this->y = y;
}

BoardFieldLabel::~BoardFieldLabel(){

}

void BoardFieldLabel::setDisc(bool isWhite){
    pressed = true;

    if(isWhite){

        this->setPixmap(*I->fieldWhiteDisc);
        currentBg = I->fieldWhiteDisc;
    }else{
        this->setPixmap(*I->fieldBlackDisc);
        currentBg = I->fieldBlackDisc;
    }
}

void BoardFieldLabel::deleteDisc(){
    pressed = false;
    this->setPixmap(*I->field);
}

void BoardFieldLabel::freeze(){
    if(frozen){ return; }
    frozen = true;
    std::cout << "freeze\n";

    if(currentBg == I->fieldWhiteDisc){
        std::cout<< "white one\n";
        this->setPixmap(*I->fieldWhiteDiscFrozen);
    }
    else if (currentBg == I->fieldBlackDisc){
        std::cout<< "black one\n";
        this->setPixmap(*I->fieldBlackDiscFrozen);
    }
    else{   //field without disc
        std::cout<< "just Field\n";
        this->setPixmap(*I->fieldFrozen);
    }
}

void BoardFieldLabel::unFreeze(){
    frozen = false;
    std::cout << "unfreeze\n";
    this->setPixmap(*currentBg);

}

void BoardFieldLabel::mousePressEvent(QMouseEvent *){
    Player *tmp = parent->getCurrentGame()->getCurrentPlayer();

    if(tmp->putDisc(x, y)){
        pressed = true;
        parent->getCurrentGame()->nextPlayer();

        if(parent->getCurrentGame()->getIsGameOver()){
            parent->showGameOverDialog();
        }
    }
}

void BoardFieldLabel::mouseMoveEvent(QMouseEvent *){

    if(parent->getCurrentGame()->getCurrentPlayer()->canPutDisc(x, y)){
        this->setPixmap(*I->fieldCanPutDisc);
    }
}

void BoardFieldLabel::leaveEvent(QEvent *){
    if(!pressed && !frozen){    //if there is no disc and it's not frozen
        this->setPixmap(*I->field);
    }
}
