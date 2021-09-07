#include "three.h"
#include<QPainter>
#include<QPen>
#include<QLabel>
#include<QDebug>

//第三关
three::three(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Level 3");

    //下一关按钮
    threee.setParent(this);
    threee.setText("NEXT LEVEL");
    threee.resize(200,50);
    connect(&threee,&QPushButton::released,this,&three::mythree);

    //退出评价
    quit.setParent(this);
    quit.resize(200,50);
    quit.move(0,100);
    quit.setText("Click to end");
    quit.move(0,100);
    connect(&quit,&QPushButton::released,this,&three::myj3);

    //重新开始
    b1.move(0,50);
    b1.resize(200,50);
    b1.setParent(this);
    b1.setText("Click to play again");
    connect(&b1,&QPushButton::released,this,&three::again);

    //将需要被点击的六边形的clickNumber值置为1或2
       h[3][12].setClickNumber(1);
       h[4][11].setClickNumber(1);
       h[4][12].setClickNumber(1);
       h[5][11].setClickNumber(1);
       h[5][12].setClickNumber(1);
       h[5][13].setClickNumber(1);
       h[6][10].setClickNumber(2);
       h[6][11].setClickNumber(2);
       h[6][12].setClickNumber(2);
       h[6][13].setClickNumber(2);
       h[7][10].setClickNumber(2);
       h[7][11].setClickNumber(1);
       h[7][12].setClickNumber(2);
       h[7][13].setClickNumber(0);
       h[7][14].setClickNumber(2);
       h[9][12].setClickNumber(1);
       for(int i=0;i<4;i++)
       {h[8][10+i].setClickNumber(2);}

}


void three::mythree(){

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


void three::myj3(){
    this->close();
    w1.show();
}


void three::again(){
    for(int r=0;r<10;r++)
       {
           for(int e=0;e<15;e++)
           {
             a[r][e]=0;
           }
       }

   p=7,q=13;

    h[3][12].setClickNumber(1);
    h[4][11].setClickNumber(1);
    h[4][12].setClickNumber(1);
    h[5][11].setClickNumber(1);
    h[5][12].setClickNumber(1);
    h[5][13].setClickNumber(1);
    h[6][10].setClickNumber(2);
    h[6][11].setClickNumber(2);
    h[6][12].setClickNumber(2);
    h[6][13].setClickNumber(2);
    h[7][10].setClickNumber(2);
    h[7][11].setClickNumber(1);
    h[7][12].setClickNumber(2);
    h[7][13].setClickNumber(0);
    h[7][14].setClickNumber(2);
    h[9][12].setClickNumber(1);
    for(int i=0;i<4;i++)
    {h[8][10+i].setClickNumber(2);}

     update();


}

void three::paintEvent(QPaintEvent *)//绘图
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
    QPoint polygon7[7] = {QPoint(80*12,80*3), QPoint(80*12-40,80*3+30), QPoint(80*12-40,80*3+80), QPoint(80*12,80*3+110), QPoint(40+80*12,80*3+80),QPoint(40+80*12,80*3+30),QPoint(80*12,80*3)};
    painter.drawPolygon(polygon7, 7);
    for(int n=11;n<13;n++){
        int m=4;
        QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
        painter.drawPolygon(polygon7, 7);
    }
    for(int n=11;n<14;n++)
    {
        int m=5;
        QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
        painter.drawPolygon(polygon7, 7);
    }
    for(int n=10;n<14;n++)
    {
        int m=6;
        QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
        painter.drawPolygon(polygon7, 7);
    }
    for(int n=10;n<15;n++)
    {
        int m=7;
        QPoint polygon7[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
        painter.drawPolygon(polygon7, 7);
    }
    for(int n=10;n<14;n++)
    {
        int m=8;
        QPoint polygon7[7] = {QPoint(80*n+40,80*m), QPoint(80*n,80*m+30), QPoint(80*n,80*m+80), QPoint(80*n+40,80*m+110), QPoint(80+80*n,80*m+80),QPoint(80+80*n,80*m+30),QPoint(80*n+40,80*m)};
        painter.drawPolygon(polygon7, 7);
    }
   int m=9;
   int n=12;
    QPoint polygon[7] = {QPoint(80*n,80*m), QPoint(80*n-40,80*m+30), QPoint(80*n-40,80*m+80), QPoint(80*n,80*m+110), QPoint(40+80*n,80*m+80),QPoint(40+80*n,80*m+30),QPoint(80*n,80*m)};
    painter.drawPolygon(polygon, 7);
    //画小块儿（需要经过两次的点）

    for(int n=10;n<14;n++)
    {
        int m=6;
        QPoint polygon7[7] = {QPoint(80*n+40,80*m+25), QPoint(80*n+20,80*m+40), QPoint(80*n+20,80*m+70), QPoint(80*n+40,80*m+85), QPoint(60+80*n,80*m+70),QPoint(60+80*n,80*m+40),QPoint(80*n+40,80*m+25)};
        painter.drawPolygon(polygon7, 7);
    }
    for(int n=10;n<14;n++)
    {
        int m=8;
        QPoint polygon7[7] = {QPoint(80*n+40,80*m+25), QPoint(80*n+20,80*m+40), QPoint(80*n+20,80*m+70), QPoint(80*n+40,80*m+85), QPoint(60+80*n,80*m+70),QPoint(60+80*n,80*m+40),QPoint(80*n+40,80*m+25)};
        painter.drawPolygon(polygon7, 7);
    }
    m=7;
    n=10;
    QPoint polygon0[7] = {QPoint(80*n,80*m+25), QPoint(80*n-20,80*m+40), QPoint(80*n-20,80*m+70), QPoint(80*n,80*m+85), QPoint(20+80*n,80*m+70),QPoint(20+80*n,80*m+40),QPoint(80*n,80*m+25)};
    painter.drawPolygon(polygon0, 7);
    n=12;
    QPoint polygon3[7] = {QPoint(80*n,80*m+25), QPoint(80*n-20,80*m+40), QPoint(80*n-20,80*m+70), QPoint(80*n,80*m+85), QPoint(20+80*n,80*m+70),QPoint(20+80*n,80*m+40),QPoint(80*n,80*m+25)};
    painter.drawPolygon(polygon3, 7);
    n=14;
    QPoint polygon4[7] = {QPoint(80*n,80*m+25), QPoint(80*n-20,80*m+40), QPoint(80*n-20,80*m+70), QPoint(80*n,80*m+85), QPoint(20+80*n,80*m+70),QPoint(20+80*n,80*m+40),QPoint(80*n,80*m+25)};
    painter.drawPolygon(polygon4, 7);
    //起点（画黄块儿
    painter.setBrush(Qt::yellow);
    QPoint polygon6[7] = {QPoint(80*13,80*7), QPoint(80*13-40,80*7+30), QPoint(80*13-40,80*7+80), QPoint(80*13,80*7+110), QPoint(40+80*13,80*7+80),QPoint(40+80*13,80*7+30),QPoint(80*13,80*7)};
    painter.drawPolygon(polygon6, 7);


   //update;
    for( m=0;m<10;m++){
        for( n=0;n<15;n++){
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
                        //画红色六边形
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

    //写数字
    QFont font1("微软雅黑",20,QFont::Bold,true);
    painter.setFont(font1);
    painter.setBrush(Qt::black);
    painter.drawText(945,465,"2");
    painter.drawText(865,625,"1");
    painter.drawText(945,785,"3");
    QFont font2("微软雅黑",15,QFont::Bold,true);
    painter.setFont(font2);
    painter.drawText(1005,625,"start");

}
//鼠标点击事件
void three::mousePressEvent(QMouseEvent*e)
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
 if((i==5)&&(j==12)&&(h[7][11].getClickNumber()==1)){}
 else if((i==9)&&(j==12)&&(h[5][12].getClickNumber()==1)){}
 else if(h[i][j].getClickNumber()==0){}
 else
     {
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

bool three::isHaveSmallHexagon(int i, int j)
{
    if((i==6)&&(j>=10)&&(j<=13)){return 1;}
    if((i==7)&&((j==10)||(j==12)||(j==14))){return 1;}
    if((i==8)&&(j>=10)&&(j<=13)){return 1;}
    else return 0;
}

