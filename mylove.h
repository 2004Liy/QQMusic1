#ifndef MYLOVE_H
#define MYLOVE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QListWidget>
#include<QLayout>
#include<QSpacerItem>
#include<QListWidgetItem>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include "itemmusic.h"
#include "linkqsl.h"

class MyLove : public QWidget
{
    Q_OBJECT
public:
    explicit MyLove(QWidget *parent = nullptr);

private slots:
    void do_itemClicked(QListWidgetItem *item);

    void noReplied(QNetworkReply *reply);

    void do_nextitem();



private:


public:
    int item_num=0;
    QLabel *label_1;
    QPushButton *pushButton_1,*pushButton_2,*pushButton_3,*pushButton_4,*pushButton_5,
        *pushButton_6,*pushButton_7;
    QListWidget *listwidget;
    QSpacerItem *spac;

    QStringList lovenamelist;//喜欢列表的歌名
    QStringList loveauthorlist;//喜欢列表的作者
    QStringList lovealbumlist;//喜欢列表的专辑名
    QList<long long>loveidlist;//喜欢列表的id
    QList<int>lovefeelist;//喜欢列表的歌曲是否免费

    QNetworkAccessManager *manager;

public: signals:
    void getid(long long id,QString name,QString author,QString album,int fee,bool islove);
    void openmusicwidget(int p);

    void nextitem();

signals:
};

#endif // MYLOVE_H
