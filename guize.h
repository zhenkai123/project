#ifndef GUIZE_H
#define GUIZE_H

#include <QMainWindow>
#include <QWidget>
#include<QPushButton>
#include"sunwin.h"
#include<QPainter>

class guize : public QWidget
{
    Q_OBJECT
public:
    explicit guize(QWidget *parent = nullptr);

signals:

public slots:

private:
    QPushButton b;//开始游戏按钮

    sunwin w;//跳转游戏界面

    void start();//自定义跳转函数

    void paintEvent(QPaintEvent*);//游戏规则背景图

};

#endif // GUIZE_H
