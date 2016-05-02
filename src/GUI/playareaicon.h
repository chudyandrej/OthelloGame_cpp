#ifndef PLAYAREAICON_H
#define PLAYAREAICON_H

#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
#include "playarea.h"

class playAreaIcon : public QLabel{
     //Q_OBJECT

public:
    playAreaIcon(int x);

private:
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
