#include "myqpushbutton.h"

MyQPushButton::MyQPushButton(QWidget* parent ): QPushButton(parent) {}

void MyQPushButton::enterEvent(QEnterEvent *event)
{
    m_icon=this->icon();

    QIcon addicon(":/icon/89.png");
    addpix= addicon.pixmap(addicon.actualSize(QSize(200, 200)));
    showOverlay = true;
    update();  // 触发重绘
    QPushButton::enterEvent(event);

}

void MyQPushButton::leaveEvent(QEvent *event)
{
    showOverlay = false;
    update();  // 触发重绘
    QPushButton::leaveEvent(event);
}

void MyQPushButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QSize m_iconSize = iconSize();
    QRect iconRect(QPoint((width() - m_iconSize.width()) / 2, (height() - m_iconSize.height()) / 2), m_iconSize);
    if(showOverlay){
        painter.setOpacity(0.8);
        painter.drawPixmap(iconRect, addpix.scaled(m_iconSize, Qt::KeepAspectRatio));
    }

}

