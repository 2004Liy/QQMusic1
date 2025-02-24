#include "mybtn.h"

MyBtn::MyBtn(QWidget *parent):QPushButton(parent) {
    m_animation = new QPropertyAnimation(this, "geometry");
    m_animation->setDuration(200);
}

void MyBtn::enterEvent(QEnterEvent *event)
{
    QRect startRect = geometry();
    if(isok==0){
        rect=startRect;
        isok=1;
    }
    QRect endRect = rect.adjusted(0, -8, 0, -8); // 向上移动5像素
    m_animation->setStartValue(rect);
    m_animation->setEndValue(endRect);
    m_animation->start();
    QPushButton::enterEvent(event);
}

void MyBtn::leaveEvent(QEvent *event)
{
    QRect startRect = rect.adjusted(0, -8, 0, -8);
    m_animation->setStartValue(startRect);
    m_animation->setEndValue(rect);
    m_animation->start();
    QPushButton::leaveEvent(event);
}
