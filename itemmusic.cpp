#include "itemmusic.h"
#include "ui_itemmusic.h"

Itemmusic::Itemmusic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Itemmusic)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框
}

Itemmusic::~Itemmusic()
{
    delete ui;
}

void Itemmusic::setinit(long long m_id, QString m_name, QString m_author, QString m_album, int m_fee,bool love)
{
    id=m_id;
    name=m_name;
    author=m_author;
    album=m_album;
    fee=m_fee;
    ui->label_2->setText(name);
    ui->label_7->setText(author);
    ui->label_8->setText(album);
    if(love){
        islove=1;
        ui->label->setPixmap(QPixmap(":/icon/58.png"));
    }
}

void Itemmusic::changedlove()
{
    ui->label->setPixmap(QPixmap(":/icon/58.png"));
}

void Itemmusic::changedunlove()
{
    ui->label->setPixmap(QPixmap(":/icon/18.png"));
}
