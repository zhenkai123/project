#include "judge1.h"
#include<QPainter>

//第一关退出评价
judge1::judge1(QWidget *parent) : QWidget(parent)
{

  this->setWindowTitle("Level 1");
  this->resize(500,600);

    //退出按钮
  b.setParent(this);
  b.setText("KEEP TRYING!");
  b.resize(500,100);
  b.move(0,500);
  connect(&b,&QPushButton::released,this,&judge1::close);


}

//花背景图
void judge1::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0,0,500,500,QPixmap(":/u=521146202,3428208538&fm=27&gp=0.png"));
    p.end();
}
