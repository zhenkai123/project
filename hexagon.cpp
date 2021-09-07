#include "hexagon.h"

//六边形
hexagon::hexagon()
{

}

//点击数减一
void hexagon::click()
{
    clickNumber--;
}

//获取点击数
int hexagon::getClickNumber()
{
    return clickNumber;
}

void hexagon::setClickNumber(int i)
{
    clickNumber=i;
}
