/**
 * Header file for GameLevel class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include "ui_GameLevel.h"
#include "OthelloGUI.h"
#include <QDialog>

namespace Ui {
    class GameLevel;
}

class GameLevel : public QDialog
{
    Q_OBJECT

public:
    explicit GameLevel(OthelloGUI *parent = 0);
    ~GameLevel();

private slots:
    void on_beginnerModeBtn_clicked();
    void on_advancedModeBtn_clicked();
    void on_backBtn_clicked();

private:
    Ui::GameLevel *ui = nullptr;
    OthelloGUI *parent = nullptr;
};

#endif // GAMELEVEL_H
