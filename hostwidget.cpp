#include "hostwidget.h"

HostWidget::HostWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("QWidget{background-color:rgb(255,255,255); border: none;border-radius:10px;}");

    label=new QLabel(this);
    label->setText("   热门搜索");
    label->setStyleSheet(
        "background-color: rgb(255,255,255);border: none;border-radius:0px;"
        );


    listwidget=new QListWidget(this);
    listwidget->setStyleSheet(
        "background-color: rgb(255, 255, 255);border-radius:0px;"
        );

    QVBoxLayout *layout=new QVBoxLayout;
    layout->setSpacing(0);
    layout->addWidget(label);
    layout->addWidget(listwidget);

    layout->setStretch(0,1);
    layout->setStretch(1,10);

    this->setLayout(layout);

    namelist<<"爱我还是爱他"<<"唯一"<<"把回忆拼好给你"<<"爱错"<<"如果爱忘了"<<"如果可以"<<"无名的人"<<"我想念"<<"悬溺"<<"夜空中最亮的星";

    connect(listwidget,&QListWidget::itemClicked,this,&HostWidget::do_itemClicked);

    initlistwidget();

}

void HostWidget::do_itemClicked(QListWidgetItem *item)
{
    Hotitem *hotitem=dynamic_cast<Hotitem*>(listwidget->itemWidget(item));
    emit search(hotitem->name);
}

void HostWidget::initlistwidget()
{
    for(int i=0;i<10;i++){
        QListWidgetItem *item=new QListWidgetItem(listwidget);
        Hotitem *hotitem=new Hotitem(this);
        hotitem->changedtext(namelist[i]);
        listwidget->setItemWidget(item,hotitem);
        item->setSizeHint(QSize(listwidget->width(),30));
    }
}
