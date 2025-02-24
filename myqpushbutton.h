#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QPushButton>
#include<QPainter>
#include<QIcon>
#include<QPixmap>

class MyQPushButton : public QPushButton
{
public:
    MyQPushButton(QWidget* parent = nullptr);

protected:
    void enterEvent(QEnterEvent* event)override;//鼠标进入事件
    void leaveEvent(QEvent* event) override;//鼠标离开事件
    void paintEvent(QPaintEvent* event) override;

private:
    QIcon m_icon;
    QPixmap addpix;
public:
    bool showOverlay;
};

#endif // MYQPUSHBUTTON_H
