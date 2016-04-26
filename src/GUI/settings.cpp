#include "settings.h"


settings::settings(OthelloGUI *parent) : ui(new Ui::settings){

    ui->setupUi(this);
    this->parent = parent;
}

settings::~settings(){
    delete ui;
}


void settings::on_confirmBtn_clicked(){

    parent->setNames(ui->player1TextField->text().toLatin1().data(),    //convert QString to string
                     ui->player2TextField->text().toLatin1().data(),
                     ui->computerTextField->text().toLatin1().data());

    this->~settings();
}
