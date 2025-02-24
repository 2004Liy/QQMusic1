#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QTimer>

namespace Ui {
class Themewidget;
}

class Themewidget : public QWidget
{
    Q_OBJECT

public:
    bool ismax=0;
    explicit Themewidget(QWidget *parent = nullptr);
    ~Themewidget();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    QPushButton *m_pushbutton;
    bool num=0;
public:
    QTimer *timer;//定时器
private:
    Ui::Themewidget *ui;

public: signals:
    void themenum1();
    void themenum2();
    void themenum3();
    void themenum4();
    void themenum5();
    void themenum6();
    void themenum7();
    void themenum8();
    void themenum9();
    void themenum10();
};

#endif // THEMEWIDGET_H
