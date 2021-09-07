#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"guize.h"
#include<QMediaPlayer>
#include"two.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();



protected:
      void paintEvent(QPaintEvent *);

private slots:
      void on_pushButton_2_clicked();

      void on_pushButton_3_clicked();

      void on_pushButton_released();

      void on_pushButton_4_clicked();

private:
      QMediaPlayer *player;
      guize w;
      Ui::Widget *ui;
};

#endif // WIDGET_H
