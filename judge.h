#ifndef JUDGE_H
#define JUDGE_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
class judge : public QWidget
{
    Q_OBJECT
public:
    explicit judge(QWidget *parent = nullptr);

signals:

public slots:
private:

    QPushButton b;

    QLabel *label;
};

#endif // JUDGE_H
