#include "judge.h"
#include<QMovie>
#include<QLabel>

//设置通关评价
judge::judge(QWidget *parent) : QWidget(parent)
{
    //窗口
    this->setWindowTitle("FINISH");
    this->resize(500,600);

    //退出按钮
      b.setParent(this);
      b.setText("OH GOD!YOU HAVE FINISHED!");
      b.resize(500,100);
      b.move(0,500);
      connect(&b,&QPushButton::released,this,&judge::close);


      //播放动图
      QMovie *movie = new QMovie(":/timgF92IQORG.gif");
      label=new QLabel(this);
      label->setScaledContents(true);
      label->setGeometry( 0, 0, 500,500 );
      label->setMovie(movie);
      movie->start();

}
