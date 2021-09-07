#include "two.h"
#include<QPainter>
#include<QPen>
#include<QLabel>
#include<QDebug>

//第二关
two::two(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Level 2");

//下一关按钮
twoo.setParent(this);
twoo.setText("NEXT LEVEL");
twoo.resize(200,50);
connect(&twoo,&QPushButton::released,this,&two::mytwo);


//退出判断按钮
quit.setParent(this);
quit.resize(200,50);
quit.move(0,100);
quit.setText("Click to end");
quit.move(0,100);
connect(&quit,&QPushButton::released,this,&two::myj2);


//重新开始按钮
b1.move(0,50);
b1.resize(200,50);
b1.setParent(this);
b1.setText("Click to play again");
connect(&b1,&QPushButton::released,this,&two::again);

//将需要被点击的六边形的clickNumber值置为1或2
   h[3][11].setClickNumber(1);
   h[4][11].setClickNumber(1);
   h[4][12].setClickNumber(1);
   h[5][9].setClickNumber(1);
   h[5][11].setClickNumber(1);
   h[5][12].setClickNumber(1);
   h[5][13].setClickNumber(1);
   h[5][14].setClickNumber(1);
    for(int i=9;i<=14;i++)
     h[6][i].setClickNumber(1);
    for(int i=10;i<=14;i++)
     h[7][i].setClickNumber(1);
    for(int i=10;i<=13;i++)
    h[8][i].setClickNumber(1);



}

//自定义下一关函数
void two::mytwo(){
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
{
    this->hide();
    w.resize(2000,1000);
    w.show();
}
}



//自定义退出评价函数
void two::myj2(){
    this->close();
    w1.show();
}



//自定义重新开始
void two::again(){
    for(int r=0;r<9;r++)
       {
           for(int e=0;e<15;e++)
           {
             a[r][e]=0;
           }
       }
    h[3][11].setClickNumber(1);
    h[4][11].setClickNumber(1);
    h[4][12].setClickNumber(1);
    h[5][9].setClickNumber(1);
    h[5][11].setClickNumber(1);
    h[5][12].setClickNumber(1);
    h[5][13].setClickNumber(1);
    h[5][14].setClickNumber(1);
     for(int i=9;i<=14;i++)
      h[6][i].setClickNumber(1);
     for(int i=10;i<=14;i++)
      h[7][i].setClickNumber(1);
     for(int i=10;i<=13;i++)
     h[8][i].setClickNumber(1);

     update();

}

void two::paintEvent(QPaintEvent *)//绘图
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
            QPoint polygon[7] = {QPoint(40+80*i,80*8), QPoint(80*i,80*8+30), QPoint(80*i,80*8+80), QPoint(40+80*i,80*8+110), QPoint(80+80*i,80*8+80),QPoint(80+80*i,80*8+30),QPoint(40+80*i,80*8)};
            painter.drawPolygon(polygon, 7);
        }
        for(int i=10;i<=14;i++)
        {
            QPoint polygon[7] = {QPoint(80*i,80*7), QPoint(80*i-40,80*7+30), QPoint(80*i-40,80*7+80), QPoint(80*i,80*7+110), QPoint(40+80*i,80*7+80),QPoint(40+80*i,80*7+30),QPoint(80*i,80*7)};
            painter.drawPolygon(polygon, 7);
        }
        for(int i=9;i<=14;i++)
        {
            QPoint polygon[7]={QPoint(40+80*i,80*6), QPoint(80*i,80*6+30), QPoint(80*i,80*6+80), QPoint(40+80*i,80*6+110), QPoint(80+80*i,80*6+80),QPoint(80+80*i,80*6+30),QPoint(40+80*i,80*6)};
           painter.drawPolygon(polygon, 7);

        }
        for(int i=11;i<=14;i++)
        {
            QPoint polygon[7] = {QPoint(80*i,80*5), QPoint(80*i-40,80*5+30), QPoint(80*i-40,80*5+80), QPoint(80*i,80*5+110), QPoint(40+80*i,80*5+80),QPoint(40+80*i,80*5+30),QPoint(80*i,80*5)};
            painter.drawPolygon(polygon, 7);
        }
        QPoint polygon0[7]={QPoint(40+80*11,80*4), QPoint(80*11,80*4+30), QPoint(80*11,80*4+80), QPoint(40+80*11,80*4+110), QPoint(80+80*11,80*4+80),QPoint(80+80*11,80*4+30),QPoint(40+80*11,80*4)};
        painter.drawPolygon(polygon0, 7);
        QPoint polygon_[7]={QPoint(40+80*12,80*4), QPoint(80*12,80*4+30), QPoint(80*12,80*4+80), QPoint(40+80*12,80*4+110), QPoint(80+80*12,80*4+80),QPoint(80+80*12,80*4+30),QPoint(40+80*12,80*4)};
        painter.drawPolygon(polygon_, 7);
        QPoint polygon1[7] = {QPoint(80*9,80*5), QPoint(80*9-40,80*5+30), QPoint(80*9-40,80*5+80), QPoint(80*9,80*5+110), QPoint(40+80*9,80*5+80),QPoint(40+80*9,80*5+30),QPoint(80*9,80*5)};
        painter.drawPolygon(polygon1, 7);
        QPoint polygon2[7] = {QPoint(80*11,80*3), QPoint(80*11-40,80*3+30), QPoint(80*11-40,80*3+80), QPoint(80*11,80*3+110), QPoint(40+80*11,80*3+80),QPoint(40+80*11,80*3+30),QPoint(80*11,80*3)};
        painter.drawPolygon(polygon2, 7);
        //起点（画黄块儿
       painter.setBrush(Qt::yellow);
       QPoint polygon6[7] = {QPoint(80*13,80*7), QPoint(80*13-40,80*7+30), QPoint(80*13-40,80*7+80), QPoint(80*13,80*7+110), QPoint(40+80*13,80*7+80),QPoint(40+80*13,80*7+30),QPoint(80*13,80*7)};
       painter.drawPolygon(polygon6, 7);
       QPoint polygon[7] = {QPoint(40+80*13,80*6), QPoint(80*13,80*6+30), QPoint(80*13,80*6+80), QPoint(40+80*13,80*6+110), QPoint(80+80*13,80*6+80),QPoint(80+80*13,80*6+30),QPoint(40+80*13,80*6)};
       painter.drawPolygon(polygon, 7);



   //update;
    for(int m=0;m<9;m++){
        for(int  n=0;n<15;n++){
          if(a[m][n]==1)
                  {
                   if(m%2==0)
                      {
                        painter.setBrush(Qt::yellow);
                        QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
                        painter.drawPolygon(polygon7, 7);
                       }
                   else{
                       painter.setBrush(Qt::yellow);
                       QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
                       painter.drawPolygon(polygon7, 7);
                       }
          }
    }

}
    //数字
    QFont font1("微软雅黑",20,QFont::Bold,true);
    painter.setFont(font1);
    painter.setBrush(Qt::black);
    painter.setPen(QPen(Qt::gray,3));
    painter.drawText(826,540,"3");
    painter.drawText(906,540,"1");
    painter.drawText(1146,540,"2");
    QFont font2("微软雅黑",15,QFont::Bold,true);
    painter.setFont(font2);
    painter.drawText(1002,625,"start");
    painter.drawText(1042,545,"start");
}
//鼠标点击事件
void two::mousePressEvent(QMouseEvent*e)
{
if(e->button()==Qt::LeftButton)//鼠标左键
{
 int i=0,j=0;

 //以下用于判断鼠标点击位置的六边形的数组编号
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
 if((i==6)&&(j==14)&&h[6][11].getClickNumber()==1){}
 else if((i==6)&&(j==10)&&h[6][14].getClickNumber()==1){}
 else if((((i==6)&&(j==13))||((i==7)&&(j==13)))&&h[i][j].getClickNumber()==1)
 {
     h[i][j].click();
     p=i;
     q=j;
 }
else if(p==100&&q==100){}
 else {
       if(p==i){
    if(((j==(q-1))||(j==(q+1)))&&h[i][j].getClickNumber()>0)
    {
        p=i;
        q=j;
        a[p][q]=1;
    }
}
       else if(i==(p+1)||i==(p-1))
{
     if(p%2==0)
   {
    if((j==(q+1)||j==q)&&h[i][j].getClickNumber()>0)
    {
        p=i;
        q=j;
        a[p][q]=1;
    }
   }
     else{
         if((j==(q-1)||j==q)&&h[i][j].getClickNumber()>0)
         {
             p=i;
             q=j;
             a[p][q]=1;
         }
     }
}
           h[p][q].click();//该六边形还能被点击的次数-1
           update();  //将该六边形变色
   }

}

}
