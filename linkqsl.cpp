#include "linkqsl.h"

std::map<long long,bool > LinkQSL::lovemusic;
std::map<long long,bool> LinkQSL::heardmusic;
QList<long long> LinkQSL::lovelist;
QList<long long> LinkQSL::heardlist;

LinkQSL::LinkQSL() {

    sql=QSqlDatabase::addDatabase("QMYSQL");
    sql.setHostName("localhost");
    sql.setUserName("root");
    sql.setPassword("20041203Li?");
    sql.setDatabaseName("test");
    if(!sql.open()){
        qDebug()<<sql.lastError();
        return;
    }else{
        qDebug()<<"打开成功"<<'\n';
    }

    QSqlQuery q;
    //QString s="select *from lovemusic;";
    q.exec("select * from lovemusic order by num desc;");
    while(q.next()){
        long long m_id=q.value("id").toLongLong();
        if(!lovemusic[m_id]){
            lovelist<<m_id;
        }
        lovemusic[m_id]=1;
    }
    QString s="select *from heardmusic order by num desc;";
    q.exec(s);
    while(q.next()){
        long long m_id=q.value("id").toLongLong();
        if(!heardmusic[m_id]){
            heardlist<<m_id;
        }
        heardmusic[m_id]=1;

    }

}

void LinkQSL::initmap()
{


}

void LinkQSL::insertlovemusic(long long id, QString name, QString author)//往喜欢表中插入
{
    QSqlQuery q;
    QString s="insert into lovemusic(id,name,author) value('"+QString::number(id)+"','"+name+"','"+author+"');";
    q.exec(s);
}

void LinkQSL::insertheardmusic(long long id, QString name, QString author)//往最近播放表中插入
{
    QSqlQuery q;
    int sum=-1;
    q.exec("select count(*) from heardmusic;");
    while(q.next()){
        sum=q.value(0).toInt();
    }
    if(sum<100){
        QString s="insert into heardmusic(id,name,author) value('"+QString::number(id)+"','"+name+"','"+author+"');";
        q.exec(s);
    }else{
        QString s="delete from heardmusic where num=(select min(num) from heardmusic);";
        q.exec(s);
        s="insert into heardmusic(id,name,author) value('"+QString::number(id)+"','"+name+"','"+author+"');";
        q.exec(s);
    }
}

void LinkQSL::deletelovemusic(long long id)//删除喜欢列表的记录
{
    QSqlQuery q;
    QString s="delete from lovemusic where id='"+QString::number(id)+"';";
    q.exec(s);
}
