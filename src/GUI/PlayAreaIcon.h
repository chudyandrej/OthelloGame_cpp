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

#ifndef PLAYAREAICON_H
#define PLAYAREAICON_H

#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
#include <QMessageBox>
#include "PlayArea.h"
#include "OthelloGUI.h"

class PlayAreaIcon : public QLabel{

public:
    PlayAreaIcon(int x,PlayArea *parent, OthelloGUI *grandParent);

private:
    OthelloGUI *grandParent = nullptr;
    PlayArea *parent = nullptr;

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void leaveEvent(QEvent *);

    void setImage();
    void setHoverImage();
    void setPressedImage();

    int xCoordinate;
    bool pressed;
};

#endif // PLAYAREAICON_H
