#ifndef JUDGE2_H
#define JUDGE2_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
class judge2 : public QWidget
{
    Q_OBJECT
public:
    explicit judge2(QWidget *parent = nullptr);

signals:

public slots:
public:

    QPushButton b;

    QLabel *label;
};

#endif // JUDGE2_H
