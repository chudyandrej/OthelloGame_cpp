/**
 * Header file for ChooseBoardSize class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef CHOOSEBOARDSIZE_H
#define CHOOSEBOARDSIZE_H

#include "ui_ChooseBoardSize.h"
#include "OthelloGUI.h"
#include <QDialog>

namespace Ui {
class ChooseBoardSize;
}

class ChooseBoardSize : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseBoardSize(OthelloGUI *parent = 0);
    ~ChooseBoardSize();


private slots:
    void on_playBtn_clicked();
    void on_backBtn_clicked();
    void on_size6x6RadioBtn_clicked();
    void on_size8x8RadioBtn_clicked();
    void on_size10x10RadioBtn_clicked();
    void on_size12x12RadioBtn_clicked();

private:
    Ui::ChooseBoardSize *ui;
    OthelloGUI *parent = nullptr;
};

#endif // CHOOSEBOARDSIZE_H
