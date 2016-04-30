#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QDialog>
#include <QMessageBox>
#include "othellogui.h"
class playArea;
#include "boardfieldwidget.h"
#include "playareaicon.h"
#include "ui_playarea.h"
#include "../userinterface.h"
#include <sstream>


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

private slots:
    void on_saveLabel_linkHovered();
    void on_saveLabel_linkActivated();

signals:
    void linkHovered(QString);

private:
    Ui::playArea *ui;
    OthelloGUI *parent;
    Game *newGame;
    Player *player1;
    Player *player2;
    boardFieldWidget *boardFields[12][12];
    int score1;
    int score2;

    std::string gameOverDialogMsg();
    std::string createSinglePlayerGameOverMsg();
    std::string createMultiPlayerGameOverMsg();
    void initNewGame();

    void changeDisc(int x, int y, bool isWhite);
    void deleteDisc(int x, int y);
    void freezeField(int x, int y);
    void unFreezeField(int x, int y);
    void setGameState(int score1, int score2, bool isWhite);

};

#endif // PLAYAREA_H
