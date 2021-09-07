#ifndef THREE_H
#define THREE_H

#include <QWidget>
#include<QPushButton>
#include"four.h"
#include"judge3.h"
#include"hexagon.h"
#include<QPainter>
#include<QMouseEvent>

namespace Ui {
class Third;
}


class three : public QWidget
{
    Q_OBJECT
public:
    explicit three(QWidget *parent = nullptr);

signals:

public slots:
private:

QPushButton threee;
QPushButton b1;
QPushButton quit;

void again();
void myj3();
void mythree();
void paintEvent(QPaintEvent*);//绘图
void mousePressEvent(QMouseEvent*e);//鼠标点击事件
void Repaint(QPainter *painter,QWidget *widget);//重绘（鼠标事件后）
bool isHaveSmallHexagon(int i,int j);


four w;
judge3 w1;
Ui::Third *ui;
int p=7,q=13;
int a[10][15]{0}; //该六边形是否经过过，经过为1，未经过为0
hexagon h[12][25]{};//所有六边形


};

#endif // THREE_H
