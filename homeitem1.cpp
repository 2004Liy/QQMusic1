#include "homeitem1.h"
#include "ui_homeitem1.h"

Homeitem1::Homeitem1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Homeitem1)
{
    ui->setupUi(this);

    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer=new QTimer(this);
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&Homeitem1::do_start2);
    connect(timer,&QTimer::timeout,this,&Homeitem1::do_start);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->setSpacing(20);
    ui->widget->setLayout(layout);
    btn1=new MyBtn(this);
    btn1->setFixedSize(150,150);
    btn1->setIconSize(QSize(200,200));
    btn1->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/126.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/127.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab1=new QLabel(this);
    lab1->setWordWrap(1);
    lab1->setText("落空 - 印子月\n猜你喜欢");
    QVBoxLayout *vlayout1=new QVBoxLayout;
    vlayout1->setSpacing(2);
    vlayout1->addWidget(btn1);
    vlayout1->addWidget(lab1);
    layout->addLayout(vlayout1);

    btn2=new MyBtn(this);
    btn2->setFixedSize(150,150);
    btn2->setIconSize(QSize(200,200));
    btn2->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/48.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/119.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab2=new QLabel(this);
    lab2->setWordWrap(1);
    lab2->setText("年轮 - 不是花火呀");
    QVBoxLayout *vlayout2=new QVBoxLayout;
    vlayout2->setSpacing(2);
    vlayout2->addWidget(btn2);
    vlayout2->addWidget(lab2);
    layout->addLayout(vlayout2);

    btn3=new MyBtn(this);
    btn3->setFixedSize(150,150);
    btn3->setIconSize(QSize(200,200));
    btn3->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/120.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/121.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab3=new QLabel(this);
    lab3->setWordWrap(1);
    lab3->setText("千千万万 - 深海鱼子酱");
    QVBoxLayout *vlayout3=new QVBoxLayout;
    vlayout3->setSpacing(2);
    vlayout3->addWidget(btn3);
    vlayout3->addWidget(lab3);
    layout->addLayout(vlayout3);

    btn4=new MyBtn(this);
    btn4->setFixedSize(150,150);
    btn4->setIconSize(QSize(200,200));
    btn4->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/128.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/129.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab4=new QLabel(this);
    lab4->setWordWrap(1);
    lab4->setText("心似烟火 - 陈壹千");
    QVBoxLayout *vlayout4=new QVBoxLayout;
    vlayout4->setSpacing(2);
    vlayout4->addWidget(btn4);
    vlayout4->addWidget(lab4);
    layout->addLayout(vlayout4);

    btn5=new MyBtn(this);
    btn5->setFixedSize(150,150);
    btn5->setIconSize(QSize(200,200));
    btn5->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/124.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/125.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab5=new QLabel(this);
    lab5->setWordWrap(1);
    lab5->setText("全部都是你 - DP龙猪/宝楽CNBALLER/王云 Cloud Wang");
    QVBoxLayout *vlayout5=new QVBoxLayout;
    vlayout5->setSpacing(2);
    vlayout5->addWidget(btn5);
    vlayout5->addWidget(lab5);
    layout->addLayout(vlayout5);

    btn6=new MyBtn(this);
    btn6->setFixedSize(150,150);
    btn6->setIconSize(QSize(200,200));
    btn6->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/116.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/118.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab6=new QLabel(this);
    lab6->setWordWrap(1);
    lab6->setText("像鱼 - 王贰浪");
    QVBoxLayout *vlayout6=new QVBoxLayout;
    vlayout6->setSpacing(2);
    vlayout6->addWidget(btn6);
    vlayout6->addWidget(lab6);
    layout->addLayout(vlayout6);

    btn7=new MyBtn(this);
    btn7->setFixedSize(150,150);
    btn7->setIconSize(QSize(200,200));
    btn7->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/122.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/123.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab7=new QLabel(this);
    lab7->setWordWrap(1);
    lab7->setText("你从未离去 - 白挺《熊出没之雪岭熊风》片尾曲");
    QVBoxLayout *vlayout7=new QVBoxLayout;
    vlayout7->setSpacing(2);
    vlayout7->addWidget(btn7);
    vlayout7->addWidget(lab7);
    layout->addLayout(vlayout7);

    connect(btn1,&QPushButton::clicked,[&](){//点击第一首歌的按钮
        if(LinkQSL::lovemusic[548885986]){
            emit openmusic1(548885986,"落空","印子月","印子月歌曲集",0,true);
        }else{
            emit openmusic1(548885986,"落空","印子月","印子月歌曲集",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn2,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1830448879]){
            emit openmusic1(1830448879,"年轮","不是花火呀","年轮",0,true);
        }else{
            emit openmusic1(1830448879,"年轮","不是花火呀","年轮",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn3,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1811459887]){
            emit openmusic1(1811459887,"千千万万","深海鱼子酱","千千万万",0,true);
        }else{
            emit openmusic1(1811459887,"千千万万","深海鱼子酱","千千万万",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn4,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1399112638]){
            emit openmusic1(1399112638,"心似烟火","陈壹千","心似烟火",0,true);
        }else{
            emit openmusic1(1399112638,"心似烟火","陈壹千","心似烟火",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn5,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[465920905]){
            emit openmusic1(465920905,"全部都是你","DP龙猪/宝楽CNBALLER/王云 Cloud Wang","全部都是你",0,true);
        }else{
            emit openmusic1(465920905,"全部都是你","DP龙猪/宝楽CNBALLER/王云 Cloud Wang","全部都是你",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn6,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1331819951]){
            emit openmusic1(1331819951,"像鱼","王贰浪","像鱼",0,true);
        }else{
            emit openmusic1(1331819951,"像鱼","王贰浪","像鱼",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn7,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[31365604]){
            emit openmusic1(31365604,"你从未离去","白挺","熊出没之雪岭熊风 电影原声带",0,true);
        }else{
            emit openmusic1(31365604,"你从未离去","白挺","熊出没之雪岭熊风 电影原声带",0,false);
        }
        emit openmusicwidget(4);
    });

}

Homeitem1::~Homeitem1()
{
    delete ui;
}

void Homeitem1::enterEvent(QEnterEvent *event)
{
    QWidget::enterEvent(event);
    ui->pushButton->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(255, 255, 255, 0);"
        "border-image: url(:/icon/112.png);}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255, 0);"
        "border-image: url(:/icon/113.png);"
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(255, 255, 255, 0);"
        "border-image: url(:/icon/114.png);}"
        "QPushButton:hover {"
        "background-color: rgba(255, 255, 255, 0);"
        "border-image: url(:/icon/115.png);"
        "}"
        );
}

void Homeitem1::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    ui->pushButton->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(255, 255, 255, 0);"
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(255, 255, 255, 0);"
        "}"
        );
}

void Homeitem1::on_pushButton_2_clicked()//点击往右划按钮直接自动划到底
{
    QScrollBar *horizontalScrollBar = ui->scrollArea->horizontalScrollBar();
    maxvalue=horizontalScrollBar->maximum();
    timer->start(5);
}

void Homeitem1::do_start()//往右划的槽函数
{
    QScrollBar *horizontalScrollBar = ui->scrollArea->horizontalScrollBar();
    int currentValue = horizontalScrollBar->value();
    int newValue = currentValue + 10;
    if (newValue >= maxvalue) {
        newValue = maxvalue;
        timer->stop(); // 停止定时器
    }
    horizontalScrollBar->setValue(newValue);
}


void Homeitem1::on_pushButton_clicked()//点击往左划按钮直接自动划到底
{
    QScrollBar *horizontalScrollBar = ui->scrollArea->horizontalScrollBar();
    minvalue=horizontalScrollBar->minimum();
    timer2->start(5);
}

void Homeitem1::do_start2()
{
    QScrollBar *horizontalScrollBar = ui->scrollArea->horizontalScrollBar();
    int currentValue = horizontalScrollBar->value();
    int newValue = currentValue - 10;
    if (newValue <= minvalue) {
        newValue = minvalue;
        timer2->stop();
    }
    horizontalScrollBar->setValue(newValue);
}



