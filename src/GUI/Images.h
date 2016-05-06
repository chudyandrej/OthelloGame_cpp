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
