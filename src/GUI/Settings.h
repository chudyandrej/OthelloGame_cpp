/**
 * File contains methods for Settings class.
 *
 * @project HRA2016
 * @author Andrej Chudý
 * @email xchudy03@stud.fit.vutbr.cz
 * @author Martin Kopec
 * @email xkopec42@stud.fit.vutbr.cz
 * 
 * @date: 06.05.2016
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMessageBox>
#include "OthelloGUI.h"
#include "ui_Settings.h"

namespace Ui {
    class Settings;
}

class Settings : public QDialog{

    Q_OBJECT

public:
    explicit Settings(OthelloGUI *parent = 0);
    ~Settings();

private slots:
    void on_confirmBtn_clicked();

private:
    Ui::Settings *ui = nullptr;
    OthelloGUI *parent = nullptr;
};

#endif // SETTINGS_H
