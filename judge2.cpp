#include "judge2.h"
#include<QPainter>
#include<QMovie>
#include<QLabel>

//第二关推出评价
judge2::judge2(QWidget *parent) : QWidget(parent)
{
    //窗口大小标题
    this->setWindowTitle("Level 2");
    this->resize(800,600);

    //退出评价按钮
      b.setParent(this);
      b.setText("KEEP TRYING!");
      b.resize(800,100);
      b.move(0,500);
      connect(&b,&QPushButton::released,this,&judge2::close);

      //动图
      QMovie *movie = new QMovie(":/timg.gif");
      label=new QLabel(this);
      label->setScaledContents(true);
      label->setGeometry( 0, 0, 800,500 );
      label->setMovie(movie);
      movie->start();

}
