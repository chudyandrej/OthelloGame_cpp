#ifndef MAINMENU_H
#define MAINMENU_H

#include "ui_MainMenu.h"
#include "OthelloGUI.h"
#include <QDialog>

namespace Ui {
    class MainMenu;
}

class MainMenu :  public QDialog{

    Q_OBJECT

public:
    explicit MainMenu(OthelloGUI *parent = 0);
    ~MainMenu();


private slots:
    void on_singlePlayerBtn_clicked();
    void on_multiPlayerBtn_clicked();
    void on_loadGameBtn_clicked();
    void on_settingsBtn_clicked();
    void on_quitBtn_clicked();

private:
    Ui::MainMenu *ui = nullptr;
    OthelloGUI *parent = nullptr;
};

#endif // MAINMENU_H
