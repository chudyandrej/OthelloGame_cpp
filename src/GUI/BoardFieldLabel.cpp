/**
 * This class implements methods of board field such as:
 * set or delete disc, froze or unfroze field according to its content.
 * The class also provides board field features such as changing background
 * of field, when mouse hovers and player can put disc to the field 
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "BoardFieldLabel.h"

/**
 * Constructor method initialize one board field
 * @param row number of row, where field is placed
 * @param col number of col, where field is placed
 * @param parent instance of PlayArea for access to game and Game method
 * @param I instance of Images class containing all images needed for field
 */
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

/**
 * Method sets background to background with disc according to color of a player.
 * @param isWhite color of a player
 */
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

/**
 * Deletes disc, so changes background to the one without a disc.
 */
void BoardFieldLabel::deleteDisc(){
    pressed = false;
    this->setPixmap(*I->field);
    currentBg = I->field;
}

/**
 * Freeze the field.
 */
void BoardFieldLabel::freeze(){
    if(frozen){ return; }
    frozen = true;

    if(currentBg == I->fieldWhiteDisc){
        this->setPixmap(*I->fieldWhiteDiscFrozen);
    }
    else if (currentBg == I->fieldBlackDisc){
        this->setPixmap(*I->fieldBlackDiscFrozen);
    }
    else{   //field without disc
        this->setPixmap(*I->fieldFrozen);
    }
}

/**
 * Unfreeze the field.
 */
void BoardFieldLabel::unFreeze(){
    frozen = false;
    this->setPixmap(*currentBg);
}

/**
 * Method implements behaviour of the field when mouse press the field
 */
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

/**
 * Method implements behaviour of the field when mouse moves on the field
 */
void BoardFieldLabel::mouseMoveEvent(QMouseEvent *){

    if(parent->getCurrentGame()->getCurrentPlayer()->canPutDisc(x, y)){
        this->setPixmap(*I->fieldCanPutDisc);
    }
}

/**
 * Method implements behaviour of the field when mouse leaves the field
 */
void BoardFieldLabel::leaveEvent(QEvent *){
    if(!pressed && !frozen){    //if there is no disc and it's not frozen
        this->setPixmap(*I->field);
    }
}
