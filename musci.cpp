#include "musci.h"

Musci::Musci(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框
    this->setStyleSheet(
        "background-color: rgba(255, 255, 255,0); border: none;"
        );
    listwidget=new QListWidget(this);
    listwidget->setStyleSheet(
        "background-color: rgba(255, 255, 255,0);"
        );

    listwidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(listwidget);
    this->setLayout(layout);
}
