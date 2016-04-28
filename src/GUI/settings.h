#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMessageBox>
#include "othellogui.h"
#include "ui_settings.h"

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(OthelloGUI *parent = 0);
    ~settings();

private slots:
    void on_confirmBtn_clicked();

private:
    Ui::settings *ui;
    OthelloGUI *parent;

};

#endif // SETTINGS_H
