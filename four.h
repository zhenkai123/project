#ifndef FOUR_H
#define FOUR_H

#include <QWidget>
#include<QPushButton>
#include"five.h"
#include"judge4.h"
#include"hexagon.h"
#include<QPainter>
#include<QMouseEvent>

namespace Ui {
class Four;
}


class four : public QWidget
{
    Q_OBJECT
public:
    explicit four(QWidget *parent = nullptr);

signals:

public slots:
private:


    QPushButton b1;
    QPushButton quit;
    QPushButton fourr;

    void myfour();
    void myj4();
    void again();
    void paintEvent(QPaintEvent*);//绘图
    void mousePressEvent(QMouseEvent*e);//鼠标点击事件
    bool isHaveSmallHexagon(int m,int n);


     five w;
     judge4 w1;
     Ui::Four *ui;
     int p=9,q=9;
     int a[12][25]{0}; //该六边形是否经过过，经过为1，未经过为0
     hexagon h[12][25]{};//所有六边形


};

#endif // FOUR_H
