#include "judge4.h"
#include<QPainter>
#include<QMovie>
#include<QLabel>
judge4::judge4(QWidget *parent) : QWidget(parent)
{
    //窗口标题大小
    this->setWindowTitle("Level 4");
    this->resize(500,600);

   //评价按钮
    b.setParent(this);
    b.setText("ONLY AN INCH TO SUCCESS!");
    b.resize(500,100);
    b.move(0,500);
    connect(&b,&QPushButton::released,this,&judge4::close);

    //动图
    QMovie *movie = new QMovie(":/2.gif");
    label=new QLabel(this);
    label->setScaledContents(true);
    label->setGeometry( 0, 0, 500,500 );
    label->setMovie(movie);
    movie->start();

}
