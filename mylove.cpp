#include "mylove.h"

MyLove::MyLove(QWidget *parent)
    : QWidget{parent}
{

    manager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MyLove::noReplied);

    connect(this,&MyLove::nextitem,this,&MyLove::do_nextitem);

    this->setStyleSheet("background-color: white; border: none;");
    label_1=new QLabel(this);
    label_1->setText("喜欢");
    label_1->setStyleSheet(
        "color: rgb(0, 0, 0);"
        "background-color: rgba(255, 255, 255,0);"
        "font: 700 36pt \"Microsoft YaHei UI\";"
        );

    pushButton_1=new QPushButton(this);
    pushButton_2=new QPushButton(this);
    pushButton_3=new QPushButton(this);
    pushButton_4=new QPushButton(this);
    pushButton_5=new QPushButton(this);
    pushButton_6=new QPushButton(this);
    pushButton_7=new QPushButton(this);

    pushButton_1->setFixedSize(80,31);
    pushButton_2->setFixedSize(80,31);
    pushButton_3->setFixedSize(80,31);
    pushButton_4->setFixedSize(45,20);
    pushButton_5->setFixedSize(20,20);
    pushButton_6->setFixedSize(20,20);
    pushButton_7->setFixedSize(20,20);

    pushButton_1->setText("播放");
    pushButton_1->setIcon(QIcon(":/icon/42.png"));
    pushButton_1->setIconSize(QSize(18,18));
    pushButton_1->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(179, 179, 179,100);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        "QPushButton:hover{"
        "background-color: rgba(179, 179, 179,200);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        );

    pushButton_2->setText("下载");
    pushButton_2->setIcon(QIcon(":/icon/23.png"));
    pushButton_2->setIconSize(QSize(18,18));
    pushButton_2->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(179, 179, 179,100);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        "QPushButton:hover{"
        "background-color: rgba(179, 179, 179,200);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        );

    pushButton_3->setText("批量");
    pushButton_3->setIcon(QIcon(":/icon/51.png"));
    pushButton_3->setIconSize(QSize(18,18));
    pushButton_3->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(179, 179, 179,100);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        "QPushButton:hover{"
        "background-color: rgba(179, 179, 179,200);"
        "font: 10pt \"Microsoft YaHei UI\";"
        "color: rgb(0, 0, 0);"
        "border-radius:15px;"
        "}"
        );

    pushButton_4->setIcon(QIcon(":/icon/26.png"));
    pushButton_4->setIconSize(QSize(12,12));
    pushButton_4->setText("搜索");
    pushButton_4->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "}"
        );

    pushButton_5->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "border-image: url(:/icon/52.png);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "border-image: url(:/icon/53.png);"
        "}"
        );

    pushButton_6->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "border-image: url(:/icon/54.png);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "border-image: url(:/icon/55.png);"
        "}"
        );

    pushButton_7->setStyleSheet(
        "QPushButton {"
        "background-color: rgba(255, 255, 255,0);"
        "border-image: url(:/icon/56.png);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(201, 201, 201, 100);"
        "border-image: url(:/icon/57.png);"
        "}"
        );

    listwidget=new QListWidget(this);
    listwidget->setStyleSheet(
        "background-color: rgba(255, 255, 255,0);"
        );

    listwidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QHBoxLayout *layout1=new QHBoxLayout;
    layout1->addWidget(pushButton_5);
    layout1->addWidget(pushButton_6);
    layout1->addWidget(pushButton_7);
    layout1->setSpacing(0);

    spac=new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(pushButton_1);
    layout2->addWidget(pushButton_2);
    layout2->addWidget(pushButton_3);
    layout2->addSpacerItem(spac);
    layout2->addWidget(pushButton_4);
    layout2->addLayout(layout1);

    QVBoxLayout *layout3=new QVBoxLayout;
    layout3->addWidget(label_1);
    layout3->addLayout(layout2);
    layout3->addWidget(listwidget);
    layout3->setStretch(0,3);
    layout3->setStretch(1,2);
    layout3->setStretch(2,18);

    this->setLayout(layout3);

    connect(listwidget,&QListWidget::itemClicked,this,&MyLove::do_itemClicked);

    loveidlist=LinkQSL::lovelist;
    // loveidlist<<1830448879<<445154140<<2004985795<<1934251776<<2666095018<<534542079<<1866185395<<2151100117<<2648126628<<408280693;
    // loveauthorlist<<"不是花火呀"<<"洛尘鞅_"<<"陈恒媛"<<"LBI利比"<<"孙燕姿"<<"于果"<<"黄霄雲"<<"辉仔Morris"<<"沐颜Fairy"<<"___TEMPOCONTROL";
    // lovefeelist<<0<<0<<0<<0<<0<<0<<0<<0<<0<<0;
    // lovealbumlist<<"年轮"<<"最后一页"<<"光落向的地方"<<"小城夏天"<<"日落"<<"侧脸"<<"带我去很远地方"<<"落日与晚风"<<"若只如初见"<<"新热推送__TEMPOCONTROL";
    // lovenamelist<<"年轮"<<"最后一页"<<"光落向的地方"<<"小城夏天"<<"日落"<<"侧脸"<<"带我去很远地方"<<"落日与晚风"<<"时光背面的我"<<"Lone Ranger";
    emit nextitem();
}

void MyLove::do_itemClicked(QListWidgetItem *item)
{
    Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(listwidget->itemWidget(item));
    emit getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
    emit openmusicwidget(1);
}

void MyLove::noReplied(QNetworkReply *reply)
{
    qDebug()<<"3333333"<<'\n';
    QByteArray array=reply->readAll();
    qDebug()<<array.data();
    QJsonParseError err;
    QJsonDocument doc=QJsonDocument::fromJson(array,&err);
    if(err.error!=QJsonParseError::NoError){
        qDebug()<<"数据转化错误"<<'\n';
        return;
    }
    QJsonObject rootobj=doc.object();
    QJsonArray songsarr=rootobj.value("songs").toArray();
    QString author="";
    for(int i=0;i<songsarr.count();i++){
        QJsonObject itemobj=songsarr.at(i).toObject();
        lovenamelist<<itemobj.value("name").toString();
        lovefeelist<<itemobj.value("fee").toInt();
        QJsonArray artistsarr=itemobj.value("artists").toArray();
        for(int j=0;j<artistsarr.count();j++){
            QJsonObject authorobj=artistsarr.at(j).toObject();
            if(j==0){
                author+=authorobj.value("name").toString();
            }else{
                author+="/"+authorobj.value("name").toString();
            }
        }
        loveauthorlist<<author;
        QJsonObject albumobj=itemobj.value("album").toObject();
        lovealbumlist<<albumobj.value("name").toString();


    }
    reply->deleteLater();
    Itemmusic *itemmusic=new Itemmusic(this);
    //初始化每个歌曲行
    itemmusic->setinit(loveidlist[lovenamelist.count()-1],lovenamelist[lovenamelist.count()-1],loveauthorlist[loveauthorlist.count()-1],lovealbumlist[lovealbumlist.count()-1],lovefeelist[lovefeelist.count()-1],1);
    QListWidgetItem *item=new QListWidgetItem(listwidget);
    listwidget->setItemWidget(item,itemmusic);
    item->setSizeHint(QSize(listwidget->width(),50));
    emit nextitem();
}

void MyLove::do_nextitem()
{
    if(item_num>=loveidlist.count()){
        return;
    }
    QString s="http://music.163.com/api/song/detail/?id="+QString::number(loveidlist[item_num])+"&ids=%5B"+QString::number(loveidlist[item_num])+"%5D";
    item_num++;
    QUrl url(s);
    manager->get(QNetworkRequest(url));
}

