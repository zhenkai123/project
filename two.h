#ifndef TWO_H
#define TWO_H

#include <QWidget>
#include<QPushButton>
#include"hexagon.h"
#include<QPainter>
#include<QMouseEvent>
#include"three.h"
#include"judge2.h"
namespace Ui {
class Second;
}

class two : public QWidget
{
    Q_OBJECT
public:
    explicit two(QWidget *parent = nullptr);

signals:

public slots:
private:




    QPushButton twoo;
    QPushButton quit;
    QPushButton b1;


    void again();
    void myj2();
    void mytwo();
    void paintEvent(QPaintEvent*);//绘图
    void mousePressEvent(QMouseEvent*e);//鼠标点击事件

    three w;
    judge2 w1;
    int p=100,q=100;
    int a[9][15]{0}; //该六边形是否经过过，经过为1，未经过为0

    hexagon h[12][25]{};//所有六边形
    Ui::Second *ui;


};

#endif // TWO_H
