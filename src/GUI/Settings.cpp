#include "Settings.h"


Settings::Settings(OthelloGUI *parent) : ui(new Ui::settings){

    ui->setupUi(this);
    this->parent = parent;

    this->setStyleSheet("QWidget {background-image: url( :/lib/background.jpg) }");

    //load current settings
    ui->player1TextField->setText(QString::fromUtf8(parent->getP1Name().c_str()));
    ui->player2TextField->setText(QString::fromUtf8(parent->getP2Name().c_str()));
    ui->computerTextField->setText(QString::fromUtf8(parent->getComputerName().c_str()));

    ui->discsToFreezeTField->setText(QString::number(parent->getDiscsToFreeze()));
    ui->frozeTimeTField->setText(QString::number(parent->getFrozeTime()));
    ui->changerTimerTField->setText(QString::number(parent->getChangeTimer()));
}

Settings::~Settings(){
    delete ui;
}


void Settings::on_confirmBtn_clicked(){

    parent->setNames(ui->player1TextField->text().toLatin1().data(),    //convert QString to string
                     ui->player2TextField->text().toLatin1().data(),
                     ui->computerTextField->text().toLatin1().data());

    int discs = ui->discsToFreezeTField->text().toInt();
    int FTime = ui->frozeTimeTField->text().toInt();
    int CHTimer = ui->changerTimerTField->text().toInt();

    //check range
    if(discs > 24 || discs < 0 || FTime > 100 || FTime < 0 || CHTimer > 100 || CHTimer < 0){
        QMessageBox::warning(this, "WARNING", "Please, make sure, time is in <0, 100> and discs in <0, 24> range");
    }
    else{
        parent->setFreezingOptions(discs, FTime, CHTimer);
        this->~Settings();
    }
}
