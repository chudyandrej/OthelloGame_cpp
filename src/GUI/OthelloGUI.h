/**
 * File contains methods for OthelloGUI class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef OTHELLOGUI_H
#define OTHELLOGUI_H


#include <QApplication>
#include <QStackedWidget>
#include <qboxlayout.h>
#include <string>
class OthelloGUI;       //forward declaration
#include "MainMenu.h"
#include "GameLevel.h"
#include "ChooseBoardSize.h"
#include "Settings.h"
#include "PlayArea.h"

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

    QWidget *mainMenuPage = nullptr;
    QWidget *gameModePage = nullptr;
    QWidget *chooseBoardSizePage = nullptr;
    QWidget *settingsPage = nullptr;
    QWidget *playAreaPage = nullptr;
    QStackedWidget *stackedWidget = nullptr;
};


#endif // OTHELLOGUI_H
