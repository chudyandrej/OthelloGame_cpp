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
    void setBoardSize(int size);
    void setSinglePlayer(bool single);
    void setGameMode(int mode);
    void setNames(std::string player1Name, std::string player2Name, std::string computerName);
    int getBoardSize();


private:
    int boardSize;
    bool singlePlayer;
    int gameMode;
    std::string player1Name;
    std::string player2Name;
    std::string computerName;

    QWidget *mainMenuPage;
    QWidget *gameModePage;
    QWidget *chooseBoardSizePage;
    QWidget *settingsPage;
    QWidget *playAreaPage;
    QStackedWidget *stackedWidget;
};


#endif // OTHELLOGUI_H
