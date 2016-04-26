#ifndef MAINMENU_H
#define MAINMENU_H

#include "ui_mainmenu.h"
#include "othellogui.h"
#include <QDialog>

namespace Ui {
    class mainMenu;
}

class mainMenu :  public QDialog{

    Q_OBJECT

public:
    explicit mainMenu(OthelloGUI *parent = 0);
    ~mainMenu();


private slots:
    void on_singlePlayerBtn_clicked();
    void on_multiPlayerBtn_clicked();
    void on_loadGameBtn_clicked();
    void on_settingsBtn_clicked();
    void on_quitBtn_clicked();

private:
    Ui::mainMenu *ui;
    OthelloGUI *parent;
};

#endif // MAINMENU_H
