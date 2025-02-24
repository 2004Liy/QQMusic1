#include "audittion.h"
#include "ui_audittion.h"

Audittion::Audittion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Audittion)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框

    tryidlist<<1830448879<<445154140<<2004985795<<1934251776<<2666095018<<534542079<<1866185395<<2151100117<<2648126628<<408280693;
    tryauthorlist<<"不是花火呀"<<"洛尘鞅_"<<"陈恒媛"<<"LBI利比"<<"孙燕姿"<<"于果"<<"黄霄雲"<<"辉仔Morris"<<"沐颜Fairy"<<"___TEMPOCONTROL";
    tryfeelist<<0<<0<<0<<0<<0<<0<<0<<0<<0<<0;
    tryalbumlist<<"年轮"<<"最后一页"<<"光落向的地方"<<"小城夏天"<<"日落"<<"侧脸"<<"带我去很远地方"<<"落日与晚风"<<"若只如初见"<<"新热推送__TEMPOCONTROL";
    trynamelist<<"年轮"<<"最后一页"<<"光落向的地方"<<"小城夏天"<<"日落"<<"侧脸"<<"带我去很远地方"<<"落日与晚风"<<"时光背面的我"<<"Lone Ranger";

    manager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&Audittion::noReplied);

    QUrl url("https://music.163.com/api/playlist/detail?id=902424933");
    manager->get(QNetworkRequest(url));

    this->setStyleSheet("background-color: white; border: none;");

    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(179, 179, 179,100);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(179, 179, 179,200);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        );

    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(179, 179, 179,100);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(179, 179, 179,200);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        );

    ui->pushButton_3->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(179, 179, 179,100);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(179, 179, 179,200);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        );


    ui->pushButton_4->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "}"
        );

    ui->pushButton_5->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "border-image: url(:/icon/52.png);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "border-image: url(:/icon/53.png);"
        "}"
        );

    ui->pushButton_6->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "border-image: url(:/icon/54.png);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "border-image: url(:/icon/55.png);"
        "}"
        );

    ui->pushButton_7->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "border-image: url(:/icon/56.png);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "border-image: url(:/icon/57.png);"
        "}"
        );

    ui->listWidget->setStyleSheet(
        "background-color: rgba(255, 255, 255,0);"
        "QListWidget::item:hover {"
        "    background-color: rgba(201, 201, 201, 100);"
        "}"
        );

    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

Audittion::~Audittion()
{
    delete ui;
}

void Audittion::noReplied(QNetworkReply *reply)
{
    QByteArray array=reply->readAll();
    qDebug()<<array.data();
    QJsonParseError err;
    QJsonDocument doc=QJsonDocument::fromJson(array,&err);
    if(err.error!=QJsonParseError::NoError){
        qDebug()<<"数据转化错误"<<'\n';
        return;
    }
    QJsonObject rootobj=doc.object();
    QJsonObject resultobj=rootobj.value("result").toObject();
    QJsonArray tracksarray=resultobj.value("tracks").toArray();
    for(int i=0;i<30&&i<tracksarray.count();i++){
        QJsonObject itemobj=tracksarray.at(i).toObject();
        tryfeelist<<itemobj.value("fee").toInt();
        tryidlist<<itemobj.value("id").toVariant().toLongLong();
        trynamelist<<itemobj.value("name").toString();
        QJsonArray artistsarray=itemobj.value("artists").toArray();
        QString s="";
        for(int j=0;j<artistsarray.count();j++){
            QJsonObject authorobj=artistsarray.at(j).toObject();
            if(j==0){
                s+=authorobj.value("name").toString();
            }else{
                s+="/"+authorobj.value("name").toString();
            }
        }
        tryauthorlist<<s;
        QJsonObject albumobj=itemobj.value("album").toObject();
        tryalbumlist<<albumobj.value("name").toString();
    }
    insertmusic();

    reply->deleteLater();
}

void Audittion::insertmusic()
{
    qDebug()<<"trycount:"<<trynamelist.count()<<'\n';
    for(int i=0;i<trynamelist.count();i++){
        Itemmusic *itemmusic=new Itemmusic(this);
        //初始化每个歌曲行
        if(LinkQSL::lovemusic[tryidlist[i]]){
            itemmusic->setinit(tryidlist[i],trynamelist[i],tryauthorlist[i],tryalbumlist[i],tryfeelist[i],1);
        }else{
            itemmusic->setinit(tryidlist[i],trynamelist[i],tryauthorlist[i],tryalbumlist[i],tryfeelist[i],0);
        }
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
        ui->listWidget->setItemWidget(item,itemmusic);
        item->setSizeHint(QSize(ui->listWidget->width(),50));
    }
}

void Audittion::changedlove()
{
    QListWidgetItem *item=ui->listWidget->currentItem();
    Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(ui->listWidget->itemWidget(item));
    m_itemmusic->changedlove();
}

void Audittion::changedunlove()
{
    QListWidgetItem *item=ui->listWidget->currentItem();
    Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(ui->listWidget->itemWidget(item));
    m_itemmusic->changedunlove();
}




void Audittion::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(ui->listWidget->itemWidget(item));
    emit getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
    emit openmusicwidget(0);
}

