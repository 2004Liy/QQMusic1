#include "mysearchwidget.h"
#include "ui_mysearchwidget.h"

MySearchWidget::MySearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MySearchWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框
    initpushbutton();
    QVBoxLayout *layout=new QVBoxLayout;
    ui->widget->setLayout(layout);

    music=new Musci(this);

    music->hide();

    manager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MySearchWidget::noReplied);

    connect(music->listwidget,&QListWidget::itemClicked,this,&MySearchWidget::do_itemClicked);
}

MySearchWidget::~MySearchWidget()
{
    delete ui;
}

void MySearchWidget::initpushbutton()
{
    ui->pushButton->setStyleSheet(
        "QPushButton{"
        "color: rgb(0, 0, 0);"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255,0);"
        "color: rgb(17,199,90);"
        "}"
        );

    ui->pushButton_2->setStyleSheet(
        "QPushButton{"
        "color: rgb(0, 0, 0);"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255,0);"
        "color: rgb(17,199,90);"
        "}"
        );

    ui->pushButton_3->setStyleSheet(
        "QPushButton{"
        "color: rgb(0, 0, 0);"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255,0);"
        "color: rgb(17,199,90);"
        "}"
        );

    ui->pushButton_4->setStyleSheet(
        "QPushButton{"
        "color: rgb(0, 0, 0);"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255,0);"
        "color: rgb(17,199,90);"
        "}"
        );

    ui->pushButton_5->setStyleSheet(
        "QPushButton{"
        "color: rgb(0, 0, 0);"
        "background-color: rgba(255, 255, 255,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255,0);"
        "color: rgb(17,199,90);"
        "}"
        );
}

void MySearchWidget::getname(QString name)
{
    musicidlist.clear();
    musicnamelist.clear();
    feelist.clear();
    authorlist.clear();
    albumlist.clear();
    music->listwidget->clear();
    QUrl url("https://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+name+"}&type=1&offset=0&total=true&limit=20");
    manager->get(QNetworkRequest(url));
}



void MySearchWidget::noReplied(QNetworkReply *reply)
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
    QJsonArray songsarr=resultobj.value("songs").toArray();
    for(int i=0;i<songsarr.count();i++){
        QJsonObject itemobj=songsarr.at(i).toObject();
        musicidlist<<itemobj.value("id").toVariant().toLongLong();
        musicnamelist<<itemobj.value("name").toString();
        feelist<<itemobj.value("fee").toInt();
        QJsonArray authorarr=itemobj.value("artists").toArray();
        QString s="";
        for(int j=0;j<authorarr.count();j++){
            QJsonObject item_1obj=authorarr.at(j).toObject();
            if(j==0){
                s+=item_1obj.value("name").toString();
            }else{
                s+="/"+item_1obj.value("name").toString();
            }
        }
        authorlist<<s;
        QJsonObject albumobj=itemobj.value("album").toObject();
        albumlist<<albumobj.value("name").toString();
    }
    for(int i=0;i<musicnamelist.count();i++){
        Itemmusic *itemmusic=new Itemmusic(music->listwidget);
        if(LinkQSL::lovemusic[musicidlist[i]]){
            itemmusic->setinit(musicidlist[i],musicnamelist[i],authorlist[i],albumlist[i],feelist[i],1);
        }else{
            itemmusic->setinit(musicidlist[i],musicnamelist[i],authorlist[i],albumlist[i],feelist[i],0);
        }
        QListWidgetItem *item=new QListWidgetItem(music->listwidget);
        music->listwidget->setItemWidget(item,itemmusic);
        item->setSizeHint(QSize(music->listwidget->width(),50));
    }
    on_pushButton_clicked();
    reply->deleteLater();

}

void MySearchWidget::on_pushButton_clicked()//点击歌曲按钮
{
    initpushbutton();
    ui->pushButton->setStyleSheet(
        "background-color: rgba(255, 255, 255,0);"
        "color: rgb(17, 199, 90);"
        );

    if(curwidget){
        ui->widget->layout()->removeWidget(curwidget);
        curwidget->hide();
    }
    ui->widget->layout()->addWidget(music);
    qDebug()<<"111111111111111"<<'\n';
    music->show();
    curwidget=music;
}

void MySearchWidget::do_itemClicked(QListWidgetItem *item)
{
    int startRow = music->listwidget->row(item);
    int endRow = music->listwidget->count() - 1;
    for(int row = startRow; row <= endRow; ++row){//遍历到免费歌曲后停止
        QListWidgetItem *currentItem = music->listwidget->item(row);
        Itemmusic *m_itemmusic = dynamic_cast<Itemmusic*>(music->listwidget->itemWidget(currentItem));
        if(m_itemmusic->fee==0||m_itemmusic->fee==8){
            music->listwidget->setCurrentItem(currentItem);
            emit getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
            emit openmusicwidget(3);
            break;
        }
    }
}

