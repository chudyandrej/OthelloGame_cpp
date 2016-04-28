#ifndef OTHELLOGUI_H
#define OTHELLOGUI_H


#include <QApplication>
#include <QStackedWidget>
#include <qboxlayout.h>
#include <string>
class OthelloGUI;
#include "mainmenu.h"
#include "gamelevel.h"
#include "chooseboardsize.h"
#include "settings.h"
#include "playarea.h"

class OthelloGUI : public QApplication{

public:
    OthelloGUI(int argc, char *argv[]);
    ~OthelloGUI();

    void setWidget(int page);
    void initMenuAgain();
    void setBoardSize(int size);
    void setSinglePlayer(bool single);
    void setGameMode(int mode);
    void setNames(std::string player1Name, std::string player2Name, std::string computerName);
    void setFreezingOptions(int discs, int FTime, int CHTimer);

    int getBoardSize();
    int getGameMode();
    bool getIsGameSinglePlayer();
    std::string getP1Name();
    std::string getP2Name();
    std::string getComputerName();
    int getDiscsToFreeze();
    int getFrozeTime();
    int getChangeTimer();


private:
    int boardSize;
    bool singlePlayer;
    int gameMode;
    std::string player1Name;
    std::string player2Name;
    std::string computerName;
    int discsToFreeze;
    int frozeTime;
    int changeTimer;

    QWidget *mainMenuPage;
    QWidget *gameModePage;
    QWidget *chooseBoardSizePage;
    QWidget *settingsPage;
    QWidget *playAreaPage;
    QStackedWidget *stackedWidget;
};


#endif // OTHELLOGUI_H
