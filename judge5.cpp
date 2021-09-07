#include "judge5.h"
#include<QPainter>
#include<QMovie>
#include<QLabel>
judge5::judge5(QWidget *parent) : QWidget(parent)
{
    //窗口标题大小
    this->setWindowTitle("Level 4");
    this->resize(500,600);

   //评价退出按钮
    b.setParent(this);
    b.setText("ONLY AN INCH TO SUCCESS!");
    b.resize(500,100);
    b.move(0,500);
    connect(&b,&QPushButton::released,this,&judge5::close);

    //动图
    QMovie *movie = new QMovie(":/timgO55PA26Z.gif");
    label=new QLabel(this);
    label->setScaledContents(true);
    label->setGeometry( 0, 0, 500,500 );
    label->setMovie(movie);
    movie->start();

}
