#include "sunwin.h"
#include<QPainter>
#include<QPen>
#include<QLabel>

//第一关
sunwin::sunwin(QWidget *parent) : QWidget(parent)
{
    //窗口标题
    this->setWindowTitle("Level 1");

    //下一关按钮设置
    b.setParent(this);
    b.setText("NEXT LEVEL");
    b.resize(200,50);
    connect(&b,&QPushButton::released,this,&sunwin::my);


    //重新开始
    b1.resize(200,50);
    b1.move(0,50);
    b1.setParent(this);
    b1.setText("Click to play again");
    connect(&b1,&QPushButton::released,this,&sunwin::again);

    //退出游戏
    b2.move(0,100);
    b2.resize(200,50);
    b2.setParent(this);
    b2.setText("Click to end");
    connect(&b2,&QPushButton::released,this,&sunwin::quit);

    //设置起始点击次数
    for(int i=0;i<4;i++)
    h[3][10+i].setClickNumber(1);
    h[3][11].setClickNumber(0);//起点设为零
    h[4][9].setClickNumber(1);
    h[4][10].setClickNumber(1);
    h[4][11].setClickNumber(1);
    h[4][13].setClickNumber(1);
    h[5][10].setClickNumber(1);
    h[5][11].setClickNumber(1);
    h[5][13].setClickNumber(1);
    h[6][9].setClickNumber(1);
    h[6][12].setClickNumber(1);
    h[7][10].setClickNumber(1);
    h[7][11].setClickNumber(1);
    h[7][12].setClickNumber(1);

}

//退出自定义函数，评价出现
void sunwin::quit(){
    this->close();
    j.show();
}

//自定义重开始
void sunwin::again(){
    for(int r=0;r<20;r++)
       {
           for(int e=0;e<20;e++)
           {
               g[r][e]=0;
           }
       }
    for(int i=0;i<4;i++)
        h[3][10+i].setClickNumber(1);
        h[3][11].setClickNumber(0);//起点设为零
        h[4][9].setClickNumber(1);
        h[4][10].setClickNumber(1);
        h[4][11].setClickNumber(1);
        h[4][13].setClickNumber(1);
        h[5][10].setClickNumber(1);
        h[5][11].setClickNumber(1);
        h[5][13].setClickNumber(1);
        h[6][9].setClickNumber(1);
        h[6][12].setClickNumber(1);
        h[7][10].setClickNumber(1);
        h[7][11].setClickNumber(1);
        h[7][12].setClickNumber(1);
        p=3,q=11;

   update();

}

//自定义下一关函数
void sunwin::my(){
    int num=1;

for(int i=0;i<12;i++){
    for(int j=0;j<25;j++)
    {
        if(h[i][j].getClickNumber()>0){
            num=0;
        }
    }
}
if(num)
{this->hide();
    w.resize(2000,1000);
    w.show();}
}


void sunwin::paintEvent(QPaintEvent *)//绘图
{

    QPainter painter(this);
    setWindowState(Qt::WindowMaximized);
    painter.setPen(QPen(Qt::gray,3));
    painter.setBrush(Qt::black);

    //画背景
    for(int j=0;j<12;j++)
        for(int i=0;i<25;i++)
   {
        if(j%2==0)
        {
            QPoint polygon[7] = {QPoint(40+80*i,80*j), QPoint(80*i,80*j+30), QPoint(80*i,80*j+80), QPoint(40+80*i,80*j+110), QPoint(80+80*i,80*j+80),QPoint(80+80*i,80*j+30),QPoint(40+80*i,80*j)};
            painter.drawPolygon(polygon, 7);
        }
        else
        {
            QPoint polygon[7] = {QPoint(80*i,80*j), QPoint(80*i-40,80*j+30), QPoint(80*i-40,80*j+80), QPoint(80*i,80*j+110), QPoint(40+80*i,80*j+80),QPoint(40+80*i,80*j+30),QPoint(80*i,80*j)};
            painter.drawPolygon(polygon, 7);
        }
    }

    //画白块儿
    painter.setPen(QPen(Qt::gray,3));
    painter.setBrush(Qt::white);
    for(int i=10;i<=13;i++)
    {
        QPoint polygon[7] = {QPoint(80*i,80*3), QPoint(80*i-40,80*3+30), QPoint(80*i-40,80*3+80), QPoint(80*i,80*3+110), QPoint(40+80*i,80*3+80),QPoint(40+80*i,80*3+30),QPoint(80*i,80*3)};
        painter.drawPolygon(polygon, 7);
    }

    for(int i=9;i<=11;i++)
    {
        QPoint polygon[7]={QPoint(40+80*i,80*4), QPoint(80*i,80*4+30), QPoint(80*i,80*4+80), QPoint(40+80*i,80*4+110), QPoint(80+80*i,80*4+80),QPoint(80+80*i,80*4+30),QPoint(40+80*i,80*4)};
        painter.drawPolygon(polygon, 7);
    }
    QPoint polygon0[7]={QPoint(40+80*13,80*4), QPoint(80*13,80*4+30), QPoint(80*13,80*4+80), QPoint(40+80*13,80*4+110), QPoint(80+80*13,80*4+80),QPoint(80+80*13,80*4+30),QPoint(40+80*13,80*4)};
    painter.drawPolygon(polygon0, 7);
    QPoint polygon1[7] = {QPoint(80*10,80*5), QPoint(80*10-40,80*5+30), QPoint(80*10-40,80*5+80), QPoint(80*10,80*5+110), QPoint(40+80*10,80*5+80),QPoint(40+80*10,80*5+30),QPoint(80*10,80*5)};
    painter.drawPolygon(polygon1, 7);
    QPoint polygon2[7] = {QPoint(80*11,80*5), QPoint(80*11-40,80*5+30), QPoint(80*11-40,80*5+80), QPoint(80*11,80*5+110), QPoint(40+80*11,80*5+80),QPoint(40+80*11,80*5+30),QPoint(80*11,80*5)};
    painter.drawPolygon(polygon2, 7);
    QPoint polygon3[7] = {QPoint(80*13,80*5), QPoint(80*13-40,80*5+30), QPoint(80*13-40,80*5+80), QPoint(80*13,80*5+110), QPoint(40+80*13,80*5+80),QPoint(40+80*13,80*5+30),QPoint(80*13,80*5)};
    painter.drawPolygon(polygon3, 7);
    QPoint polygon4[7]={QPoint(40+80*9,80*6), QPoint(80*9,80*6+30), QPoint(80*9,80*6+80), QPoint(40+80*9,80*6+110), QPoint(80+80*9,80*6+80),QPoint(80+80*9,80*6+30),QPoint(40+80*9,80*6)};
    painter.drawPolygon(polygon4, 7);
    QPoint polygon5[7]={QPoint(40+80*12,80*6), QPoint(80*12,80*6+30), QPoint(80*12,80*6+80), QPoint(40+80*12,80*6+110), QPoint(80+80*12,80*6+80),QPoint(80+80*12,80*6+30),QPoint(40+80*12,80*6)};
    painter.drawPolygon(polygon5, 7);
    for(int i=10;i<=12;i++)
    {
        QPoint polygon[7] = {QPoint(80*i,80*7), QPoint(80*i-40,80*7+30), QPoint(80*i-40,80*7+80), QPoint(80*i,80*7+110), QPoint(40+80*i,80*7+80),QPoint(40+80*i,80*7+30),QPoint(80*i,80*7)};
        painter.drawPolygon(polygon, 7);
    }

    //起点（画红块儿
painter.setBrush(Qt::yellow);
   QPoint polygon6[7] = {QPoint(80*11,80*3), QPoint(80*11-40,80*3+30), QPoint(80*11-40,80*3+80), QPoint(80*11,80*3+110), QPoint(40+80*11,80*3+80),QPoint(40+80*11,80*3+30),QPoint(80*11,80*3)};
   painter.drawPolygon(polygon6, 7);

    //update

   int m;
       int n;
       for( m=0;m<8;m++){
           for( n=0;n<14;n++){
               if(m%2==0){


               if(g[m][n]==1){
                   painter.setBrush(Qt::yellow);
                   QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
                   painter.drawPolygon(polygon7, 7);
               }
             }
               else{
                   if(g[m][n]==1){
                       painter.setBrush(Qt::yellow);
                       QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
                       painter.drawPolygon(polygon7, 7);
               }
           }
       }

   }

}

//鼠标点击
void sunwin::mousePressEvent(QMouseEvent*e)
{
if(e->button()==Qt::LeftButton)//鼠标左键
{
 int i=0,j=0;

 //以下用于判断鼠标点击位置的六边形的数组编号，很复杂想了一个多小时，不要试图搞懂这些代码，略过就好
 if(((e->y()/80)%2==0)&&(e->y()/80!=0))
 {
     if(((e->x()%80)<((30-e->y()%80)*4/3))||(e->x()%80)>80-((30-e->y()%80)*4/3))
     {
         i=e->y()/80-1;
         j=e->x()/80+(e->x()%80)/40;
     }
     else
     {
         i=e->y()/80;
         j=e->x()/80;
     }
 }
 else if (e->y()/80==0)
 {
     i=0;
     j=e->x()/80;
 }
 else
 {
     if(((e->x()%80)<((e->y()%80)*4/3))||((e->x()%80)>(80-((e->y()%80)*4/3))))
     {
         i=e->y()/80;
         j=e->x()/80+(e->x()%80)/40;
     }
     else
     {
         i=e->y()/80-1;
         j=e->x()/80;
     }
 }
//结束了 h[i][j]就是六边形的编号
 if(p==i){
    if(((j==(q-1))||(j==(q+1)))&&h[i][j].getClickNumber()==1)
    {
        p=i;
        q=j;
        g[p][q]=1;
    }
}
 else if(i==(p+1)||i==(p-1))
{
     if(p%2==0)
   {
    if((j==(q+1)||j==q)&&h[i][j].getClickNumber()==1)
    {
        p=i;
        q=j;
        g[p][q]=1;
    }
   }
     else{
         if((j==(q-1)||j==q)&&h[i][j].getClickNumber()==1)
         {
             p=i;
             q=j;
            g[p][q]=1;
         }
     }
}
     h[p][q].click();//该六边形还能被点击的次数-1
      update();  //将该六边形变色

}

}


