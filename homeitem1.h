#ifndef HOMEITEM1_H
#define HOMEITEM1_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QLayout>
#include<QScrollBar>
#include<QTimer>
#include<mybtn.h>
#include"linkqsl.h"

namespace Ui {
class Homeitem1;
}

class Homeitem1 : public QWidget
{
    Q_OBJECT

public:
    explicit Homeitem1(QWidget *parent = nullptr);
    ~Homeitem1();

protected:
    void enterEvent(QEnterEvent *event)override;
    void leaveEvent(QEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void do_start();

    void on_pushButton_clicked();

    void do_start2();

private:
    QTimer *timer,*timer2;
    int maxvalue=0;//记录滑动条最大值
    int minvalue=0;//记录滑动条最小值
    MyBtn *btn1,*btn2,*btn3,*btn4,*btn5,*btn6,*btn7;
    QLabel *lab1,*lab2,*lab3,*lab4,*lab5,*lab6,*lab7;
    Ui::Homeitem1 *ui;

public:signals:
    void openmusicwidget(int p);
    void openmusic1(long long id,QString m_name,QString m_author,QString m_album,int m_fee,bool islove);
};

#endif // HOMEITEM1_H
