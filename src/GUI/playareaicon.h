#ifndef PLAYAREAICON_H
#define PLAYAREAICON_H

#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
#include "playarea.h"

class playAreaIcon : public QLabel{
     //Q_OBJECT

public:
    playAreaIcon(QDialog *parent = 0);

private:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
};

#endif // PLAYAREAICON_H
