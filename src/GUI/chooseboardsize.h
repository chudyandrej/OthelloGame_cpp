#ifndef CHOOSEBOARDSIZE_H
#define CHOOSEBOARDSIZE_H

#include "ui_chooseboardsize.h"
#include "othellogui.h"
#include <QDialog>

namespace Ui {
class chooseBoardSize;
}

class chooseBoardSize : public QDialog
{
    Q_OBJECT

public:
    explicit chooseBoardSize(OthelloGUI *parent = 0);
    ~chooseBoardSize();


private slots:
    void on_playBtn_clicked();
    void on_backBtn_clicked();
    void on_size6x6RadioBtn_clicked();
    void on_size8x8RadioBtn_clicked();
    void on_size10x10RadioBtn_clicked();
    void on_size12x12RadioBtn_clicked();

private:
    Ui::chooseBoardSize *ui;
    OthelloGUI *parent;
};

#endif // CHOOSEBOARDSIZE_H
