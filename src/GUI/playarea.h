#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QDialog>
#include "othellogui.h"
class playArea;
#include "boardfieldwidget.h"
#include "ui_playarea.h"
#include "../userinterface.h"


namespace Ui {
class playArea;
}

class playArea : public QDialog, UserInterface{

    Q_OBJECT

public:
    explicit playArea(OthelloGUI *parent = 0);
    ~playArea();
    Game *getCurrentGame();
    void showGameOverDialog();

private:
    Ui::playArea *ui;
    OthelloGUI *parent;
    Game *newGame;
    boardFieldWidget *boardFields[12][12];

    void changeDisc(int x, int y, bool isWhite);
    void deleteDisc(int x, int y);
    void freezeField(int x, int y);
    void unFreezeField(int x, int y);
    void setGameState(int score1, int score2, bool isWhite);
};

#endif // PLAYAREA_H
