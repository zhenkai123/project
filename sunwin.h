#ifndef SUNWIN_H
#define SUNWIN_H

#include <QWidget>
#include<QPushButton>
#include"hexagon.h"
#include<QPainter>
#include<QMouseEvent>
#include"two.h"
#include"judge1.h"
class sunwin : public QWidget
{
    Q_OBJECT
public:
    explicit sunwin(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);//绘图

    void mousePressEvent(QMouseEvent*e);//鼠标点击事件

    void Repaint(QPainter *painter,QWidget *widget);//重绘（鼠标事件后）

    int p=3,q=11;

signals:

public slots:
private :

    int g[20][20]={0};


    QPushButton b;
    QPushButton b1;
    QPushButton b2;

    judge1 j;
    two w;

    void my();
    void again();
    void quit();
    hexagon h[12][25]{};//所有六边形

};


#endif // SUNWIN_H
