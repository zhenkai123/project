#include "four.h"
#include<QPainter>
#include<QPen>
#include<QLabel>
#include<QDebug>

//第四关
four::four(QWidget *parent) : QWidget(parent)
{
    //窗口标题
    this->setWindowTitle("Level 4");

    //下一关按钮
    fourr.setParent(this);
    fourr.setText("NEXT LEVEL");
    fourr.resize(200,50);
    connect(&fourr,&QPushButton::released,this,&four::myfour);

    //退出评价跳转
    quit.setParent(this);
    quit.resize(200,50);
    quit.move(0,100);
    quit.setText("Click to end");
    quit.move(0,100);
    connect(&quit,&QPushButton::released,this,&four::myj4);

    //重新开始
    b1.move(0,50);
    b1.resize(200,50);
    b1.setParent(this);
    b1.setText("Click to play again");
    connect(&b1,&QPushButton::released,this,&four::again);


    //将需要被点击的六边形的clickNumber值置为1或2

            h[2][13].setClickNumber(1);
            h[2][14].setClickNumber(1);
            h[2][15].setClickNumber(1);
            h[3][13].setClickNumber(1);
            h[3][16].setClickNumber(1);
            h[4][10].setClickNumber(1);
            h[4][11].setClickNumber(2);
            h[4][12].setClickNumber(1);
            h[4][15].setClickNumber(1);
            h[4][16].setClickNumber(1);
            h[5][9].setClickNumber(1);
            h[5][10].setClickNumber(1);
            h[5][11].setClickNumber(1);
            h[5][13].setClickNumber(1);
            h[5][16].setClickNumber(2);
            h[6][8].setClickNumber(1);
            h[6][9].setClickNumber(2);
            h[6][10].setClickNumber(1);
            h[6][11].setClickNumber(2);
            h[6][13].setClickNumber(1);
            h[6][14].setClickNumber(1);
            h[6][15].setClickNumber(2);
            for(int i=9;i<=11;i++)
            h[7][i].setClickNumber(1);
            h[7][16].setClickNumber(1);
            h[8][9].setClickNumber(1);
            h[9][9].setClickNumber(0);

}

void four::myfour(){
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


void four::myj4(){
    this->close();
    w1.show();
}


void four::again(){

    for(int r=0;r<12;r++)
       {
           for(int e=0;e<25;e++)
           {
             a[r][e]=0;
           }
       }

        p=9,q=9;

    h[2][13].setClickNumber(1);
    h[2][14].setClickNumber(1);
    h[2][15].setClickNumber(1);
    h[3][13].setClickNumber(1);
    h[3][16].setClickNumber(1);
    h[4][10].setClickNumber(1);
    h[4][11].setClickNumber(2);
    h[4][12].setClickNumber(1);
    h[4][15].setClickNumber(1);
    h[4][16].setClickNumber(1);
    h[5][9].setClickNumber(1);
    h[5][10].setClickNumber(1);
    h[5][11].setClickNumber(1);
    h[5][13].setClickNumber(1);
    h[5][16].setClickNumber(2);
    h[6][8].setClickNumber(1);
    h[6][9].setClickNumber(2);
    h[6][10].setClickNumber(1);
    h[6][11].setClickNumber(2);
    h[6][13].setClickNumber(1);
    h[6][14].setClickNumber(1);
    h[6][15].setClickNumber(2);
    for(int i=9;i<=11;i++)
    h[7][i].setClickNumber(1);
    h[7][16].setClickNumber(1);
    h[8][9].setClickNumber(1);
    h[9][9].setClickNumber(0);

     update();
}

void four::paintEvent(QPaintEvent *)//绘图
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
          for(int i=13;i<=15;i++)
           {
               QPoint polygon[7] = {QPoint(40+80*i,80*2), QPoint(80*i,80*2+30), QPoint(80*i,80*2+80), QPoint(40+80*i,80*2+110), QPoint(80+80*i,80*2+80),QPoint(80+80*i,80*2+30),QPoint(40+80*i,80*2)};
               painter.drawPolygon(polygon, 7);
           }
           QPoint polygon0[7] = {QPoint(80*13,80*3), QPoint(80*13-40,80*3+30), QPoint(80*13-40,80*3+80), QPoint(80*13,80*3+110), QPoint(40+80*13,80*3+80),QPoint(40+80*13,80*3+30),QPoint(80*13,80*3)};
           painter.drawPolygon(polygon0, 7);
           QPoint polygon1[7] = {QPoint(80*16,80*3), QPoint(80*16-40,80*3+30), QPoint(80*16-40,80*3+80), QPoint(80*16,80*3+110), QPoint(40+80*16,80*3+80),QPoint(40+80*16,80*3+30),QPoint(80*16,80*3)};
           painter.drawPolygon(polygon1, 7);
           for(int i=10;i<=12;i++)
           {
               QPoint polygon[7]={QPoint(40+80*i,80*4), QPoint(80*i,80*4+30), QPoint(80*i,80*4+80), QPoint(40+80*i,80*4+110), QPoint(80+80*i,80*4+80),QPoint(80+80*i,80*4+30),QPoint(40+80*i,80*4)};
               painter.drawPolygon(polygon, 7);
           }
           QPoint polygon2[7]={QPoint(40+80*15,80*4), QPoint(80*15,80*4+30), QPoint(80*15,80*4+80), QPoint(40+80*15,80*4+110), QPoint(80+80*15,80*4+80),QPoint(80+80*15,80*4+30),QPoint(40+80*15,80*4)};
           painter.drawPolygon(polygon2, 7);
           QPoint polygon3[7]={QPoint(40+80*16,80*4), QPoint(80*16,80*4+30), QPoint(80*16,80*4+80), QPoint(40+80*16,80*4+110), QPoint(80+80*16,80*4+80),QPoint(80+80*16,80*4+30),QPoint(40+80*16,80*4)};
           painter.drawPolygon(polygon3, 7);
           for(int i=9;i<=11;i++)
           {
               QPoint polygon[7] = {QPoint(80*i,80*5), QPoint(80*i-40,80*5+30), QPoint(80*i-40,80*5+80), QPoint(80*i,80*5+110), QPoint(40+80*i,80*5+80),QPoint(40+80*i,80*5+30),QPoint(80*i,80*5)};
               painter.drawPolygon(polygon, 7);
           }
           QPoint polygon4[7] = {QPoint(80*13,80*5), QPoint(80*13-40,80*5+30), QPoint(80*13-40,80*5+80), QPoint(80*13,80*5+110), QPoint(40+80*13,80*5+80),QPoint(40+80*13,80*5+30),QPoint(80*13,80*5)};
           painter.drawPolygon(polygon4, 7);
           QPoint polygon5[7] = {QPoint(80*16,80*5), QPoint(80*16-40,80*5+30), QPoint(80*16-40,80*5+80), QPoint(80*16,80*5+110), QPoint(40+80*16,80*5+80),QPoint(40+80*16,80*5+30),QPoint(80*16,80*5)};
           painter.drawPolygon(polygon5, 7);
           for(int i=8;i<=11;i++)
           {
               QPoint polygon[7]={QPoint(40+80*i,80*6), QPoint(80*i,80*6+30), QPoint(80*i,80*6+80), QPoint(40+80*i,80*6+110), QPoint(80+80*i,80*6+80),QPoint(80+80*i,80*6+30),QPoint(40+80*i,80*6)};
               painter.drawPolygon(polygon, 7);
           }
           for(int i=13;i<=15;i++)
           {
               QPoint polygon[7]={QPoint(40+80*i,80*6), QPoint(80*i,80*6+30), QPoint(80*i,80*6+80), QPoint(40+80*i,80*6+110), QPoint(80+80*i,80*6+80),QPoint(80+80*i,80*6+30),QPoint(40+80*i,80*6)};
               painter.drawPolygon(polygon, 7);
           }
           for(int i=9;i<=11;i++)

           {

               QPoint polygon[7] = {QPoint(80*i,80*7), QPoint(80*i-40,80*7+30), QPoint(80*i-40,80*7+80), QPoint(80*i,80*7+110), QPoint(40+80*i,80*7+80),QPoint(40+80*i,80*7+30),QPoint(80*i,80*7)};
               painter.drawPolygon(polygon, 7);

           }

           QPoint polygon[7] = {QPoint(80*16,80*7), QPoint(80*16-40,80*7+30), QPoint(80*16-40,80*7+80), QPoint(80*16,80*7+110), QPoint(40+80*16,80*7+80),QPoint(40+80*16,80*7+30),QPoint(80*16,80*7)};
           painter.drawPolygon(polygon, 7);
           QPoint polygon6[7]={QPoint(40+80*9,80*8),QPoint(80*9,80*8+30), QPoint(80*9,80*8+80), QPoint(40+80*9,80*8+110), QPoint(80+80*9,80*8+80),QPoint(80+80*9,80*8+30),QPoint(40+80*9,80*8)};
           painter.drawPolygon(polygon6, 7);
           QPoint polygon7[7] = {QPoint(80*9,80*9), QPoint(80*9-40,80*9+30), QPoint(80*9-40,80*9+80), QPoint(80*9,80*9+110), QPoint(40+80*9,80*9+80),QPoint(40+80*9,80*9+30),QPoint(80*9,80*9)};
          painter.drawPolygon(polygon7, 7);

         //画小六边形
              painter.setBrush(Qt::white);
              QPoint polygon9[7]={QPoint(40+80*11,80*4+27.5), QPoint(80*11+20,80*4+30+12.5), QPoint(80*11+20,80*4+80-12.5), QPoint(40+80*11,80*4+110-27.5), QPoint(80+80*11-20,80*4+80-12.5),QPoint(80+80*11-20,80*4+30+12.5),QPoint(40+80*11,80*4+27.5)};
              painter.drawPolygon(polygon9, 7);
              QPoint polygon13[7] = {QPoint(80*16,80*5+27.5), QPoint(80*16-40+20,80*5+30+12.5), QPoint(80*16-40+20,80*5+80-12.5), QPoint(80*16,80*5+110-27.5), QPoint(40+80*16-20,80*5+80-12.5),QPoint(40+80*16-20,80*5+30+12.5),QPoint(80*16,80*5+27.5)};
              painter.drawPolygon(polygon13, 7);
              QPoint polygon10[7]={QPoint(40+80*11,80*6+27.5), QPoint(80*11+20,80*6+30+12.5), QPoint(80*11+20,80*6+80-12.5), QPoint(40+80*11,80*6+110-27.5), QPoint(80+80*11-20,80*6+80-12.5),QPoint(80+80*11-20,80*6+30+12.5),QPoint(40+80*11,80*6+27.5)};
              painter.drawPolygon(polygon10, 7);
              QPoint polygon11[7]={QPoint(40+80*9,80*6+27.5), QPoint(80*9+20,80*6+30+12.5), QPoint(80*9+20,80*6+80-12.5), QPoint(40+80*9,80*6+110-27.5), QPoint(80+80*9-20,80*6+80-12.5),QPoint(80+80*9-20,80*6+30+12.5),QPoint(40+80*9,80*6+27.5)};
              painter.drawPolygon(polygon11, 7);
              QPoint polygon12[7]={QPoint(40+80*15,80*6+27.5), QPoint(80*15+20,80*6+30+12.5), QPoint(80*15+20,80*6+80-12.5), QPoint(40+80*15,80*6+110-27.5), QPoint(80+80*15-20,80*6+80-12.5),QPoint(80+80*15-20,80*6+30+12.5),QPoint(40+80*15,80*6+27.5)};
              painter.drawPolygon(polygon12, 7);

        //起点（画黄块儿
         painter.setBrush(Qt::yellow);
         QPoint polygon8[7] = {QPoint(80*9,80*9), QPoint(80*9-40,80*9+30), QPoint(80*9-40,80*9+80), QPoint(80*9,80*9+110), QPoint(40+80*9,80*9+80),QPoint(40+80*9,80*9+30),QPoint(80*9,80*9)};
         painter.drawPolygon(polygon8, 7);
         //写start
         QFont font2("微软雅黑",15,QFont::Bold,true);
         painter.setFont(font2);
         painter.drawText(685,785,"start");
   //update;
         for(int m=0;m<10;m++){
             for(int n=0;n<17;n++){
                 if(a[m][n]==1)
                 {

                     if(isHaveSmallHexagon(m,n))
                     {
                         if(h[m][n].getClickNumber()==1)
                         {
                             //画白色六边形
                             if(m%2==0)
                             {
                                 painter.setBrush(Qt::white);
                                 QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
                                 painter.drawPolygon(polygon7, 7);
                             }
                             else {
                                  painter.setBrush(Qt::white);
                                  QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
                                  painter.drawPolygon(polygon7, 7);

                             }
                         }
                         else
                         {
                             //画黄色六边形
                             if(m%2==0)
                             {
                                 painter.setBrush(Qt::yellow);
                                 QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
                                 painter.drawPolygon(polygon7, 7);
                             }
                             else
                                 {
                                 painter.setBrush(Qt::yellow);
                                 QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
                                 painter.drawPolygon(polygon7, 7);
                                 }
                         }
                     }
                     else
                         {
                         //正常画图
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

     }
}
//鼠标点击事件
void four::mousePressEvent(QMouseEvent*e)
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
if(p==i){
    if(((j==(q-1))||(j==(q+1)))&&h[i][j].getClickNumber()>0)
    {
        p=i;
        q=j;
        a[p][q]=1;
        h[p][q].click();//该六边形还能被点击的次数-1
        update();  //将该六边形变色
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
        h[p][q].click();//该六边形还能被点击的次数-1
        update();  //将该六边形变色
    }
   }
     else{
         if((j==(q-1)||j==q)&&h[i][j].getClickNumber()>0)
         {
             p=i;
             q=j;
             a[p][q]=1;
             h[p][q].click();//该六边形还能被点击的次数-1
             update();  //将该六边形变色
         }
     }
}


}

}


bool four::isHaveSmallHexagon(int m, int n)
{
    if(m==4&&n==11)return 1;
    if(m==5&&n==16)return 1;
    if(m==6&&n==9)return 1;
    if(m==6&&n==11)return 1;
    if(m==6&&n==15)return 1;
    return 0;
}


