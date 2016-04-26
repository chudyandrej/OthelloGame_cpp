#ifndef BOARDFIELDWIDGET_H
#define BOARDFIELDWIDGET_H

#include <QDialog>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "ui_boardfieldwidget.h"

namespace Ui {
    class boardFieldWidget;
}

class boardFieldWidget : public QDialog
{
    Q_OBJECT

public:
    explicit boardFieldWidget(int x, int y);
    ~boardFieldWidget();
    void setDisc(bool isWhite);
    void deleteDisc();
    void freeze();
    void unFreeze();


private:
    Ui::boardFieldWidget *ui;

    bool pressed;
    bool frozen;
    int x;
    int y;

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
};

#endif // BOARDFIELDWIDGET_H
