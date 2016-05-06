/**
 * File contains methods of ChooseBoardSize page.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "ChooseBoardSize.h"

/**
 * Constructor method.
 */
ChooseBoardSize::ChooseBoardSize(OthelloGUI *parent) : ui(new Ui::ChooseBoardSize){

    ui->setupUi(this);
    this->parent = parent;
    parent->setBoardSize(8); //set default value

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");
}

/**
 * Destructor.
 */
ChooseBoardSize::~ChooseBoardSize(){
    delete ui;
}

/**
 * Method implements behaviour when "Play" button was clicked.
 */
void ChooseBoardSize::on_playBtn_clicked(){
   parent->setWidget(4);
}

/**
 * When "Back" button is clicked, delete itself.
 */
void ChooseBoardSize::on_backBtn_clicked(){
    this->~ChooseBoardSize();
}

/**
 * Sets board size according to button.
 */
void ChooseBoardSize::on_size6x6RadioBtn_clicked(){
    parent->setBoardSize(6);
}

/**
 * Sets board size according to button.
 */
void ChooseBoardSize::on_size8x8RadioBtn_clicked(){
    parent->setBoardSize(8);
}

/**
 * Sets board size according to button.
 */
void ChooseBoardSize::on_size10x10RadioBtn_clicked(){
    parent->setBoardSize(10);
}

/**
 * Sets board size according to button.
 */
void ChooseBoardSize::on_size12x12RadioBtn_clicked(){
    parent->setBoardSize(12);
}
