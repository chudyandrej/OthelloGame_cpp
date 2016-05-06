/**
 * Header file for Images class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef IMAGES_H
#define IMAGES_H

#include <QLabel>

class Images{

public:
    Images(int boardSize);
    ~Images();

    QPixmap *field;
    QPixmap *fieldCanPutDisc;
    QPixmap *fieldFrozen;
    QPixmap *fieldWhiteDisc;
    QPixmap *fieldWhiteDiscFrozen;
    QPixmap *fieldBlackDisc;
    QPixmap *fieldBlackDiscFrozen;
};

#endif // IMAGES_H
