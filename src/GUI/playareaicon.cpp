#include "playareaicon.h"

playAreaIcon::playAreaIcon(int x){
    xCoordinate = x;
    this->setMouseTracking(true);
    this->setFixedHeight(25);
    this->setFixedWidth(25);
    pressed = false;
    setImage();
}


void playAreaIcon::mousePressEvent(QMouseEvent *){
    setPressedImage();
    pressed = true;
}

void playAreaIcon::mouseMoveEvent(QMouseEvent *){
    if(!pressed){
        setHoverImage();
    }

}

void playAreaIcon::mouseReleaseEvent(QMouseEvent *){
    pressed = false;
    switch(xCoordinate){
        case 0:

            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
    }
}

void playAreaIcon::leaveEvent(QEvent *){
    pressed = false;
    setImage();
}

void playAreaIcon::setImage(){
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

void playAreaIcon::setHoverImage(){
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

void playAreaIcon::setPressedImage(){
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


