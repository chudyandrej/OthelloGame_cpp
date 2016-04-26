#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QDialog>
#include "othellogui.h"
#include "boardfieldwidget.h"
#include "ui_playarea.h"

namespace Ui {
class playArea;
}

class playArea : public QDialog
{
    Q_OBJECT

public:
    explicit playArea(OthelloGUI *parent = 0);
    ~playArea();

private:
    Ui::playArea *ui;
    OthelloGUI *parent;
    //QWidget boardFields[][];
};

#endif // PLAYAREA_H
