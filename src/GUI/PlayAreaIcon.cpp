#include "PlayAreaIcon.h"

PlayAreaIcon::PlayAreaIcon(int x, PlayArea *parent, OthelloGUI *grandParent){
    xCoordinate = x;
    this->parent = parent;
    this->grandParent = grandParent;
    this->setMouseTracking(true);
    this->setFixedHeight(25);
    this->setFixedWidth(25);
    pressed = false;
    setImage();
}


void PlayAreaIcon::mousePressEvent(QMouseEvent *){
    setPressedImage();
    pressed = true;
}

void PlayAreaIcon::mouseMoveEvent(QMouseEvent *){
    if(!pressed){
        setHoverImage();
    }

}

void PlayAreaIcon::mouseReleaseEvent(QMouseEvent *){
    pressed = false;
    QMessageBox::StandardButton reply;

    switch(xCoordinate){
        case 0:
            reply = QMessageBox::question(parent, "Reload Game", "<font color='#ffffff'>Would you like to reload game and start again?</font>", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                //start new game
                //delete game? delete players and board?
                grandParent->setWidget(4);
            }
            break;
        case 1:
            reply = QMessageBox::question(parent, "Quit Game", "<font color='#ffffff'>Would you like to quit game and go to the menu?</font>", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                 //start new game
                //delete game? delete players and board?
                parent->~PlayArea();
                grandParent->initMenuAgain();
            }
            break;
        case 2:

            break;
        case 3:

            break;
    }
}

void PlayAreaIcon::leaveEvent(QEvent *){
    setImage();
}

void PlayAreaIcon::setImage(){
    switch(xCoordinate){
        case 0:
            this->setStyleSheet("background-image: url(:/lib/icons/playAgain.png)");
            break;
        case 1:
            this->setStyleSheet("background-image: url(:/lib/icons/home.png)");
            break;
        case 2:
            this->setStyleSheet("background-image: url(:/lib/icons/undo.png)");
            break;
        case 3:
            this->setStyleSheet("background-image: url(:/lib/icons/saveGame.png)");
            break;
    }
}

void PlayAreaIcon::setHoverImage(){
    switch(xCoordinate){
        case 0:
            this->setStyleSheet("background-image: url(:/lib/icons/playAgainEntered.png)");
            break;
        case 1:
            this->setStyleSheet("background-image: url(:/lib/icons/homeEntered.png)");
            break;
        case 2:
            this->setStyleSheet("background-image: url(:/lib/icons/undoEntered.png)");
            break;
        case 3:
            this->setStyleSheet("background-image: url(:/lib/icons/saveGameEntered.png)");
            break;
    }
}

void PlayAreaIcon::setPressedImage(){
    switch(xCoordinate){
        case 0:
            this->setStyleSheet("background-image: url(:/lib/icons/playAgainPressed.png)");
            break;
        case 1:
            this->setStyleSheet("background-image: url(:/lib/icons/homePressed.png)");
            break;
        case 2:
            this->setStyleSheet("background-image: url(:/lib/icons/undoPressed.png)");
            break;
        case 3:
            this->setStyleSheet("background-image: url(:/lib/icons/saveGamePressed.png)");
            break;
    }
}

