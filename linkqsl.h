#ifndef LINKQSL_H
#define LINKQSL_H
#include<QtSql>
#include<QDebug>
#include<QString>
#include<map>
#include<QList>
#include<iostream>
using namespace std;

class LinkQSL
{
private:
    void initmap();
public:
    void insertlovemusic(long long id,QString name,QString author);//往lovemusic表中插入数据
    void insertheardmusic(long long id,QString name,QString author);//往heardmusic表中插入数据
    void deletelovemusic(long long id);
public:
    static map<long long,bool>lovemusic;
    static map<long long,bool>heardmusic;
    static QList<long long>lovelist;
    static QList<long long>heardlist;
    QSqlDatabase sql;

    LinkQSL();
};



#endif // LINKQSL_H
