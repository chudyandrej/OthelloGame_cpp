/**
 * File contains methods for PlayArea class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QDialog>
#include <sstream>
#include "OthelloGUI.h"
class PlayArea;         //forward declaration
#include "BoardFieldLabel.h"
#include "PlayAreaIcon.h"
#include "ui_PlayArea.h"
#include "Images.h"
#include "../CreateGameOverMsg.h"
#include "../UserInterface.h"


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
