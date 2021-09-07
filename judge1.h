#ifndef JUDGE1_H
#define JUDGE1_H

#include <QWidget>
#include<QPushButton>
class judge1 : public QWidget
{
    Q_OBJECT
public:
    explicit judge1(QWidget *parent = nullptr);

signals:

public slots:
public:

    QPushButton b;

    void paintEvent(QPaintEvent *);
};

#endif // JUDGE1_H
