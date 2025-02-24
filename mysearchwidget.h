#ifndef MYSEARCHWIDGET_H
#define MYSEARCHWIDGET_H

#include <QWidget>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QListWidget>
#include<QLayout>
#include "itemmusic.h"
#include "musci.h"
#include "linkqsl.h"

namespace Ui {
class MySearchWidget;
}

class MySearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MySearchWidget(QWidget *parent = nullptr);
    ~MySearchWidget();

public:
    void getname(QString name);

private:
    void initpushbutton();

private slots:
    void noReplied(QNetworkReply *reply);//当接收到数据

    void on_pushButton_clicked();

public slots:

    void do_itemClicked(QListWidgetItem *item);

public:
    Musci *music;

private:
    QNetworkAccessManager *manager;
    QList<long long>musicidlist;
    QStringList musicnamelist;
    QStringList authorlist;
    QStringList albumlist;
    QList<int>feelist;
    int num=0;
    QWidget *curwidget=NULL;//记录当前的窗口

    Ui::MySearchWidget *ui;

private:signals:
    void getid(long long id,QString name,QString author,QString album,int fee,bool islove);
    void openmusicwidget(int p);
};

#endif // MYSEARCHWIDGET_H
