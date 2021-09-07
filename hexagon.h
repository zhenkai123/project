#ifndef HEXAGON_H
#define HEXAGON_H

#include <QWidget>
#include<QPushButton>
class hexagon
{
public:
    hexagon();
    hexagon(int i);
    void click();
    void setClickNumber(int i);
    int getClickNumber();

private:
    int clickNumber{0};//
    QPushButton w;
};

#endif // HEXAGON_H
