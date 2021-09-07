#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include <qdir.h>

//主窗口封面
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Hamilton!");


    //播放音乐
    player=new QMediaPlayer;

    // player->setMedia(QUrl::fromLocalFile("../resource/11.mp3"));
     player->setMedia(QUrl("qrc:/11.mp3"));
     player->setVolume(10);
     player->play();

}

Widget::~Widget()
{
    delete ui;
}


//花背景图
void Widget::paintEvent(QPaintEvent *){
   QPainter p;
   p.begin(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/6.png"));
p.end();
}


//播放音乐
void Widget::on_pushButton_2_clicked()
{
    player->play();
}


//关闭音乐
void Widget::on_pushButton_3_clicked()
{
    player->stop();
}


//开始游戏 隐藏窗口 显示下一关游戏窗口
void Widget::on_pushButton_released()
{
    w.show();
    this->hide();
}

//退出
void Widget::on_pushButton_4_clicked()
{
    this->close();

}
