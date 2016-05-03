#ifndef BOARDFIELDWIDGET_H
#define BOARDFIELDWIDGET_H

#include <QDialog>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "ui_BoardFieldWidget.h"
#include "../gameObj/Game.h"
class BoardFieldWidget;
#include "PlayArea.h"

namespace Ui {
    class BoardFieldWidget;
}

class BoardFieldWidget : public QDialog{

    Q_OBJECT

public:
    explicit BoardFieldWidget(int x, int y, PlayArea *parent = 0);
    ~BoardFieldWidget();
    void setDisc(bool isWhite);
    void deleteDisc();
    void freeze();
    void unFreeze();


private:
    Ui::BoardFieldWidget *ui;
    PlayArea *parent = nullptr;

    bool pressed;
    bool frozen;
    int x;
    int y;

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
};

#endif // BOARDFIELDWIDGET_H
