/**
 * File contains methods for PlayAreaIcon class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "PlayAreaIcon.h"


/**
 * Constructor of PlayAreaIcon.
 */
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

/**
 * Implements behaviour when mouse holds the icon.
 */
void PlayAreaIcon::mousePressEvent(QMouseEvent *){
    setPressedImage();
    pressed = true;
}

/**
 * Implements behaviour when mouse enters the icon.
 */
void PlayAreaIcon::mouseMoveEvent(QMouseEvent *){
    if(!pressed){
        setHoverImage();
    }
}

/**
 * Implements behaviour when mouse clicks the icon.
 */
void PlayAreaIcon::mouseReleaseEvent(QMouseEvent *){
    pressed = false;
    QMessageBox::StandardButton reply;

    switch(xCoordinate){
        case 0:
            reply = QMessageBox::question(parent, "Reload Game", "<font color='#ffffff'>Would you like to reload game and start again?</font>", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                //start new game
                parent->~PlayArea();
                grandParent->setWidget(4);
            }
            break;
        case 1:
            reply = QMessageBox::question(parent, "Quit Game", "<font color='#ffffff'>Would you like to quit game and go to the menu?</font>", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                 //start new game
                parent->~PlayArea();
                grandParent->initMenuAgain();
            }
            break;
        case 2: // undo
            parent->getCurrentGame()->undo();
            break;
        case 3: //redo
            parent->getCurrentGame()->redo();
            break;
        case 4: //save
            std::string msg;
            if(parent->getCurrentGame()->backupGame->serializeBackup() == 0){
                msg = "Game was successfuly saved!\n";
            }
            else{
                msg = "FAIL, can't create a file\n";
            }
            QMessageBox::information(parent, "Save Game Process", "<font color='#ffffff'>"+QString::fromUtf8(msg.c_str())+"</font>", QMessageBox::Ok);
    }
}

/**
 * Implements behaviour when mouse leaves the icon.
 */
void PlayAreaIcon::leaveEvent(QEvent *){
    setImage();
}

/**
 * Method sets standard image of icon.
 */
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
            this->setStyleSheet("background-image: url(:/lib/icons/redo.png)");
            break;
        case 4:
            this->setStyleSheet("background-image: url(:/lib/icons/saveGame.png)");
            break;
    }
}

/**
 * Method sets image of icon when the icon is hovered.
 */
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
            this->setStyleSheet("background-image: url(:/lib/icons/redoEntered.png)");
            break;
        case 4:
            this->setStyleSheet("background-image: url(:/lib/icons/saveGameEntered.png)");
            break;
    }
}

/**
 * Method sets image of icon when the icon is pressed.
 */
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
            this->setStyleSheet("background-image: url(:/lib/icons/redoPressed.png)");
            break;
        case 4:
            this->setStyleSheet("background-image: url(:/lib/icons/saveGamePressed.png)");
            break;
    }
}


