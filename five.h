#ifndef FIVE_H
#define FIVE_H

#include <QWidget>
#include<QPushButton>
#include"judge.h"
#include"judge5.h"
#include"hexagon.h"
#include<QPainter>
#include<QMouseEvent>

namespace Ui {
class Five;
}


class five : public QWidget
{
    Q_OBJECT
public:
    explicit five(QWidget *parent = nullptr);

signals:

public slots:
private:

    QPushButton b1;
    QPushButton quit;
    QPushButton fif;

    void myfif();
    void myj5();
    void again();
    void paintEvent(QPaintEvent*);//绘图
    void mousePressEvent(QMouseEvent*e);//鼠标点击事件

    judge w;
    judge5 w1;
    Ui::Five *ui;
    int p=100,q=100;
    int a[12][25]{0}; //该六边形是否经过过，经过为1，未经过为0
    hexagon h[12][25]{};//所有六边形

};

#endif // FIVE_H
