#ifndef AUDITTION_H
#define AUDITTION_H

#include <QWidget>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QListWidgetItem>
#include "itemmusic.h"
#include "linkqsl.h"

namespace Ui {
class Audittion;
}

class Audittion : public QWidget
{
    Q_OBJECT

public:
    explicit Audittion(QWidget *parent = nullptr);
    ~Audittion();

private slots:
    void noReplied(QNetworkReply *reply);//当接收到数据


    void on_listWidget_itemClicked(QListWidgetItem *item);

public:signals:
    void getid(long long id,QString name,QString author,QString album,int fee,bool islove);
    void openmusicwidget(int p);

private:
    void insertmusic();

private:
    QStringList trynamelist;//试听列表的歌名
    QStringList tryauthorlist;//试听列表的作者
    QStringList tryalbumlist;//试听列表的专辑名
    QList<long long>tryidlist;//试听列表的id
    QList<int>tryfeelist;//试听列表的歌曲是否免费
    QNetworkAccessManager *manager;
    Ui::Audittion *ui;

public:
    void changedlove();
    void changedunlove();


};

#endif // AUDITTION_H
