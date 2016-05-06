/**
 * File contains initialization of images for Images class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#include "Images.h"

/**
 * Images constructor.
 * @param boardSize size of board
 */
Images::Images(int boardSize){
    int size=0;
    switch(boardSize){
    case 6:
        size = 63;
        break;
    case 8:
        size = 47;
        break;
    case 10:
        size = 38;
        break;
    case 12:
        size = 31;
        break;
    }

    field = new QPixmap(":/lib/field.png");
    *field = field->scaled(size, size, Qt::IgnoreAspectRatio);

    fieldCanPutDisc = new QPixmap(":/lib/fieldCanPut.png");
    *fieldCanPutDisc = fieldCanPutDisc->scaled(size, size, Qt::IgnoreAspectRatio);

    fieldFrozen = new QPixmap(":/lib/fieldFrozen.png");
    *fieldFrozen = fieldFrozen->scaled(size, size, Qt::IgnoreAspectRatio);


    fieldWhiteDisc = new QPixmap(":/lib/white2.png");
    *fieldWhiteDisc = fieldWhiteDisc->scaled(size, size, Qt::IgnoreAspectRatio);

    fieldWhiteDiscFrozen = new QPixmap(":/lib/white2frozen.png");
    *fieldWhiteDiscFrozen = fieldWhiteDiscFrozen->scaled(size, size, Qt::IgnoreAspectRatio);


    fieldBlackDisc = new QPixmap(":/lib/black2.png");
    *fieldBlackDisc = fieldBlackDisc->scaled(size, size, Qt::IgnoreAspectRatio);

    fieldBlackDiscFrozen = new QPixmap(":/lib/black2frozen.png");
    *fieldBlackDiscFrozen = fieldBlackDiscFrozen->scaled(size, size, Qt::IgnoreAspectRatio);
}

/**
 * Destructor.
 */
Images::~Images(){
    delete field;
    delete fieldCanPutDisc;
    delete fieldFrozen;
    delete fieldWhiteDisc;
    delete fieldWhiteDiscFrozen;
    delete fieldBlackDisc;
    delete fieldBlackDiscFrozen;
}
