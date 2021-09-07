#include "guize.h"

guize::guize(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("RULE");
    this->resize(2000,1000);


    //开始游戏按钮
    b.setParent(this);
    b.setText("I HAVE KNOW THE RULE!\nSTART!");
    b.resize(500,100);
    b.move(750,850);


    connect(&b,&QPushButton::released,this,&guize::start);

}

void guize::start(){
    this->hide();
    w.show();
}

void guize::paintEvent(QPaintEvent *){

    QPainter p;

    p.begin(this);

    p.drawPixmap(0,0,2000,1000,QPixmap(":/TIM20190708224721.png"));

    p.end();
}
