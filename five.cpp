#include "five.h"
#include<QPainter>
#include<QPen>
#include<QLabel>
#include<QDebug>

//第五关
five::five(QWidget *parent) : QWidget(parent)
{
   this->setWindowTitle("Level 5");

    //下一关
   fif.setParent(this);
   fif.setText("NEXT LEVEL");
   fif.resize(200,50);
   connect(&fif,&QPushButton::released,this,&five::myfif);

   //退出评价跳转
   quit.setParent(this);
   quit.resize(200,50);
   quit.move(0,100);
   quit.setText("Click to end");
   quit.move(0,100);
   connect(&quit,&QPushButton::released,this,&five::myj5);

   //重新开始
   b1.move(0,50);
   b1.resize(200,50);
   b1.setParent(this);
   b1.setText("Click to play again");
   connect(&b1,&QPushButton::released,this,&five::again);

   //将需要被点击的六边形的clickNumber值置为1或2
   int m,n;
        for(n=8;n<16;n++)
        {
            m=2;
            if(n==10||n==12)continue;
           h[m][n].setClickNumber(1);
        }
        for(n=8;n<17;n++)
        {
            m=3;
            if(n==14)continue;
            h[m][n].setClickNumber(1);
        }
       for(n=8;n<16;n++)
        {
           m=4;
           if(n==14)continue;
            h[m][n].setClickNumber(1);

        }
         for(n=9;n<17;n++)
        {
             m=5;
             if(n==14)continue;
             h[m][n].setClickNumber(1);
        }
         h[5][13].setClickNumber(2);
         for(n=8;n<17;n++)
          {
             m=6;
             if(n==14)continue;
             h[m][n].setClickNumber(1);
          }
         for(n=8;n<10;n++)
        {
             m=7;
             h[m][n].setClickNumber(1);
        }
         for(n=8;n<10;n++)
          {
             m=8;
             h[m][n].setClickNumber(1);

          }
         for(n=9;n<11;n++)
        {
             m=9;
              h[m][n].setClickNumber(1);
        }
         qDebug()<<"aaaaaaa"<<h[5][13].getClickNumber();

}


void five::myfif(){
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
      w.show();
   }
}


void five::myj5(){
    this->hide();

   w1.show();
}


void five::again(){
    for(int r=0;r<12;r++)
       {
           for(int e=0;e<25;e++)
           {
             a[r][e]=0;
           }
       }

    p=100,q=100;

    int m,n;
         for(n=8;n<16;n++)
         {
             m=2;
             if(n==10||n==12)continue;
            h[m][n].setClickNumber(1);
         }
         for(n=8;n<17;n++)
         {
             m=3;
             if(n==14)continue;
             h[m][n].setClickNumber(1);
         }
        for(n=8;n<16;n++)
         {
            m=4;
            if(n==14)continue;
             h[m][n].setClickNumber(1);

         }
          for(n=9;n<17;n++)
         {
              m=5;
              if(n==14)continue;
              h[m][n].setClickNumber(1);
         }
          h[5][13].setClickNumber(2);
          for(n=8;n<17;n++)
           {
              m=6;
              if(n==14)continue;
              h[m][n].setClickNumber(1);
           }
          for(n=8;n<10;n++)
         {
              m=7;
              h[m][n].setClickNumber(1);
         }
          for(n=8;n<10;n++)
           {
              m=8;
              h[m][n].setClickNumber(1);

           }
          for(n=9;n<11;n++)
         {
              m=9;
               h[m][n].setClickNumber(1);
         }
        //  qDebug()<<"aaaaaaa"<<h[5][13].getClickNumber();


     update();

}

void five::paintEvent(QPaintEvent *)//绘图
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
        int m,n;
        painter.setPen(QPen(Qt::gray,3));
        painter.setBrush(Qt::white);

        for(n=8;n<16;n++)
        {
            m=2;
            if(n==10||n==12)continue;
            QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
            painter.drawPolygon(polygon7, 7);
        }
        for(n=8;n<17;n++)
        {
            m=3;
            if(n==14)continue;
            QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
            painter.drawPolygon(polygon7, 7);
        }
       for(n=8;n<16;n++)
        {
           m=4;
           if(n==14)continue;
           QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
           painter.drawPolygon(polygon7, 7);

        }
         for(n=9;n<17;n++)
        {
             m=5;
             if(n==14)continue;
             QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
             painter.drawPolygon(polygon7, 7);
        }
         for(n=8;n<17;n++)
          {
             m=6;
             if(n==14)continue;
             QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
             painter.drawPolygon(polygon7, 7);
          }
         for(n=8;n<10;n++)
        {
             m=7;
             QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
             painter.drawPolygon(polygon7, 7);
        }
         for(n=8;n<10;n++)
          {
             m=8;
             QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
             painter.drawPolygon(polygon7, 7);
          }
         for(n=9;n<11;n++)
        {
             m=9;
             QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
             painter.drawPolygon(polygon7, 7);
        }
         //画小六边形
         m=5;n=13;
         QPoint polygon3[7] = {QPoint(80*n,80*m+25), QPoint(80*n-20,80*m+40), QPoint(80*n-20,80*m+70), QPoint(80*n,80*m+85), QPoint(20+80*n,80*m+70),QPoint(20+80*n,80*m+40),QPoint(80*n,80*m+25)};
         painter.drawPolygon(polygon3, 7);
        //起点（画黄块儿
         painter.setBrush(Qt::yellow);
         m=3;n=9;
         QPoint polygon1[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
         painter.drawPolygon(polygon1, 7);
         m=6;n=15;
         QPoint polygon2[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
         painter.drawPolygon(polygon2, 7);


   //update;
       for( m=0;m<10;m++){
           for( n=0;n<17;n++){
               if(a[m][n]==1)
               {
                   if(m==5&&n==13)
                   {

                       if(h[5][13].getClickNumber()==1)
                       {
                           //画白色六边形

                                painter.setBrush(Qt::white);
                                QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
                                painter.drawPolygon(polygon7, 7);
                       }
                       else
                       {
                           //画黄色六边形
                               painter.setBrush(Qt::yellow);
                               QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
                               painter.drawPolygon(polygon7, 7);

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
       //数字
       QFont font1("微软雅黑",20,QFont::Bold,true);
       painter.setFont(font1);
       painter.setBrush(Qt::black);
       painter.setPen(QPen(Qt::gray,3));
       painter.drawText(786,305,"3");
       painter.drawText(1066,545,"1");
       painter.drawText(706,625,"2");
       painter.drawText(946,465,"4");
       painter.drawText(1146,225,"5");
       QFont font2("微软雅黑",15,QFont::Bold,true);
       painter.setFont(font2);
       painter.drawText(685,305,"start");
       painter.drawText(1205,545,"start");
}
//鼠标点击事件
void five::mousePressEvent(QMouseEvent*e)
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
 if((i==7)&&(j==9)&&h[6][13].getClickNumber()==1){}
 else if((i==3)&&(j==10)&&h[7][9].getClickNumber()==1){}
 else if((i==5)&&(j==12)&&h[3][10].getClickNumber()==1){}
 else if((i==2)&&(j==14)&&h[5][12].getClickNumber()==1){}
else if(((i==3)&&(j==9)&&h[i][j].getClickNumber()==1)||((i==6)&&(j==15)&&h[i][j].getClickNumber()==1))
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

}

