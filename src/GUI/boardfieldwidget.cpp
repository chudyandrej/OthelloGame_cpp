#include "boardfieldwidget.h"


boardFieldWidget::boardFieldWidget(int x, int y) : ui(new Ui::boardFieldWidget){

    ui->setupUi(this);
    pressed = false;
    //QPixmap pixmap = QPixmap (":/images/lib/field.png");
    this->setStyleSheet("background-color:green;border:2px solid black;");//setWindowIcon(QIcon(":/lib/field.png"));//setWindowIcon(QIcon(pixmap));////
    this->x = x;
    this->y = y;

}

boardFieldWidget::~boardFieldWidget(){

    delete ui;
}

void boardFieldWidget::setDisc(bool isWhite){
    pressed = true;
    if(isWhite){
        this->setStyleSheet("background-color:white;border:2px solid black;");
    }else{
         this->setStyleSheet("background-color:black;border:2px solid black;");
    }
}

void boardFieldWidget::deleteDisc(){
    pressed = false;
     this->setStyleSheet("background-color:green;border:2px solid black;");
}

void boardFieldWidget::freeze(){
    if(frozen){ return; }
    frozen = true;
    //... code will continue
}

void boardFieldWidget::unFreeze(){
    frozen = false;
    //restore background...
}

void boardFieldWidget::mousePressEvent(QMouseEvent *){
     pressed = true;
     this->setStyleSheet("background-color:blue;border:2px solid black;");
}

void boardFieldWidget::mouseMoveEvent(QMouseEvent *){
    if(!pressed){
        this->setStyleSheet("background-color:yellow;border:2px solid black;");
    }
}

void boardFieldWidget::leaveEvent(QEvent *){
    if(!pressed){
        this->setStyleSheet("background-color:green;border:2px solid black;");
    }
}

