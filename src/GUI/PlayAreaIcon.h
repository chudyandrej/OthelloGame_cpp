#ifndef PLAYAREAICON_H
#define PLAYAREAICON_H

#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
#include <QMessageBox>
#include "PlayArea.h"
#include "OthelloGUI.h"

class PlayAreaIcon : public QLabel{
     //Q_OBJECT

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
