#ifndef MYBTN_H
#define MYBTN_H

#include <QPushButton>
#include<QPropertyAnimation>
#include<QRect>

class MyBtn : public QPushButton
{
public:
    MyBtn(QWidget *parent = nullptr);

private:
    QPropertyAnimation *m_animation;

private:
    QRect rect;//记录按钮原本位置
    bool isok=0;

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

};

#endif // MYBTN_H
