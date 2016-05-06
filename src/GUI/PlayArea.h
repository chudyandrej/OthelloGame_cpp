#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QDialog>
#include "OthelloGUI.h"
class PlayArea;
//#include "BoardFieldWidget.h"
#include "BoardFieldLabel.h"
#include "PlayAreaIcon.h"
#include "ui_PlayArea.h"
#include "Images.h"
#include "../UserInterface.h"
#include <sstream>


namespace Ui {
class PlayArea;
}

class PlayArea : public QDialog, UserInterface{

    Q_OBJECT

public:
    explicit PlayArea(OthelloGUI *parent = 0, bool loadingGame = false);
    ~PlayArea();
    Game *getCurrentGame();
    void showGameOverDialog();
    OthelloGUI *getParent();

    static std::string createSinglePlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2);
    static std::string createMultiPlayerGameOverMsg(int score1, int score2, Player *player1, Player *player2);

signals:
    void linkHovered(QString);

private:
    Ui::PlayArea *ui = nullptr;
    OthelloGUI *parent = nullptr;
    Game *newGame = nullptr;
    Player *player1 = nullptr;
    Player *player2 = nullptr;
    BoardFieldLabel *boardFields[12][12];
    int score1;
    int score2;

    std::string gameOverDialogMsg();
    void initBoard();
    void initNewGame();

    void changeDisc(int x, int y, bool isWhite);
    void deleteDisc(int x, int y);
    void freezeField(int x, int y);
    void unFreezeField(int x, int y);
    void setGameState(int score1, int score2, bool isWhite);
};

#endif // PLAYAREA_H
