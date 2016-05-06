/**
 * Header file for BoardFieldLabel class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef BOARDFIELDLABEL_H
#define BOARDFIELDLABEL_H

#include "../gameObj/Game.h"
class BoardFieldLabel;  //forward declaration
#include "PlayArea.h"
#include "Images.h"
#include <QLabel>

class BoardFieldLabel : public QLabel{

public:
    BoardFieldLabel(int x, int y, PlayArea *parent = 0, Images *I=0);

    void setDisc(bool isWhite);
    void deleteDisc();
    void freeze();
    void unFreeze();


private:
    PlayArea *parent = nullptr;
    Images *I = nullptr;
    QPixmap *beforeFrozenBG = nullptr;
    QPixmap *currentBg = nullptr;

    bool pressed;
    bool frozen;
    int x;
    int y;

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
};

#endif // BOARDFIELDLABEL_H
