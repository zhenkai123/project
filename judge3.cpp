#include "judge3.h"
#include<QPainter>
#include<QMovie>
#include<QLabel>
judge3::judge3(QWidget *parent) : QWidget(parent)
{
    //窗口大小标题
    this->setWindowTitle("Level 3");
    this->resize(500,600);

    //退出评价按钮
    b.setParent(this);
    b.setText("STILL HOPE!");
    b.resize(500,100);
    b.move(0,500);
    connect(&b,&QPushButton::released,this,&judge3::close);

     //动图
    QMovie *movie = new QMovie(":/3.gif");
    label=new QLabel(this);
    label->setScaledContents(true);
    label->setGeometry( 0, 0, 500,500 );
    label->setMovie(movie);
    movie->start();

}
