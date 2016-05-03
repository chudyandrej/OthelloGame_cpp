#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QDialog>
#include "OthelloGUI.h"
class PlayArea;
#include "BoardFieldWidget.h"
#include "PlayAreaIcon.h"
#include "ui_PlayArea.h"
#include "../UserInterface.h"
#include <sstream>


namespace Ui {
class PlayArea;
}

class PlayArea : public QDialog, UserInterface{

    Q_OBJECT

public:
    explicit PlayArea(OthelloGUI *parent = 0);
    ~PlayArea();
    Game *getCurrentGame();
    void showGameOverDialog();

signals:
    void linkHovered(QString);

private:
    Ui::PlayArea *ui = nullptr;
    OthelloGUI *parent = nullptr;
    Game *newGame = nullptr;
    Player *player1 = nullptr;
    Player *player2 = nullptr;
    BoardFieldWidget *boardFields[12][12];
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
