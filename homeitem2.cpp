#include "homeitem2.h"
#include "ui_homeitem2.h"

Homeitem2::Homeitem2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Homeitem2)
{
    ui->setupUi(this);

    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer=new QTimer(this);
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&Homeitem2::do_start2);
    connect(timer,&QTimer::timeout,this,&Homeitem2::do_start);

    QHBoxLayout *layout=new QHBoxLayout(ui->widget);
    layout->setSpacing(20);

    btn1=new MyBtn(this);
    btn1->setFixedSize(150,150);
    btn1->setIconSize(QSize(200,200));
    btn1->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/155.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/156.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab1=new QLabel(this);
    lab1->setWordWrap(1);
    lab1->setText("山楂树之恋 - 程佳佳");

    btn2=new MyBtn(this);
    btn2->setFixedSize(150,150);
    btn2->setIconSize(QSize(200,200));
    btn2->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/133.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/134.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab2=new QLabel(this);
    lab2->setWordWrap(1);
    lab2->setText("他不懂 - 王贰浪/俞天时");

    QVBoxLayout *vlayout1=new QVBoxLayout;
    vlayout1->setSpacing(2);
    vlayout1->addWidget(btn1);
    vlayout1->addWidget(lab1);
    vlayout1->addWidget(btn2);
    vlayout1->addWidget(lab2);
    layout->addLayout(vlayout1);


    btn3=new MyBtn(this);
    btn3->setFixedSize(150,150);
    btn3->setIconSize(QSize(200,200));
    btn3->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/135.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/136.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab3=new QLabel(this);
    lab3->setWordWrap(1);
    lab3->setText("这一生关于你的风景 - 隔壁老樊");

    btn4=new MyBtn(this);
    btn4->setFixedSize(150,150);
    btn4->setIconSize(QSize(200,200));
    btn4->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/137.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/138.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab4=new QLabel(this);
    lab4->setWordWrap(1);
    lab4->setText("小半 - 陈粒");

    QVBoxLayout *vlayout2=new QVBoxLayout;
    vlayout2->setSpacing(2);
    vlayout2->addWidget(btn3);
    vlayout2->addWidget(lab3);
    vlayout2->addWidget(btn4);
    vlayout2->addWidget(lab4);
    layout->addLayout(vlayout2);


    btn5=new MyBtn(this);
    btn5->setFixedSize(150,150);
    btn5->setIconSize(QSize(200,200));
    btn5->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/139.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/140.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab5=new QLabel(this);
    lab5->setWordWrap(1);
    lab5->setText("童话镇 - 暗杠");

    btn6=new MyBtn(this);
    btn6->setFixedSize(150,150);
    btn6->setIconSize(QSize(200,200));
    btn6->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/141.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/142.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab6=new QLabel(this);
    lab6->setWordWrap(1);
    lab6->setText("消散对白 - 杜宣达");

    QVBoxLayout *vlayout3=new QVBoxLayout;
    vlayout3->setSpacing(2);
    vlayout3->addWidget(btn5);
    vlayout3->addWidget(lab5);
    vlayout3->addWidget(btn6);
    vlayout3->addWidget(lab6);
    layout->addLayout(vlayout3);


    btn7=new MyBtn(this);
    btn7->setFixedSize(150,150);
    btn7->setIconSize(QSize(200,200));
    btn7->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/143.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/144.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab7=new QLabel(this);
    lab7->setWordWrap(1);
    lab7->setText("予你 - 队长");

    btn8=new MyBtn(this);
    btn8->setFixedSize(150,150);
    btn8->setIconSize(QSize(200,200));
    btn8->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/145.png) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/146.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab8=new QLabel(this);
    lab8->setWordWrap(1);
    lab8->setText("有些 - 颜人中");

    QVBoxLayout *vlayout4=new QVBoxLayout;
    vlayout4->setSpacing(2);
    vlayout4->addWidget(btn7);
    vlayout4->addWidget(lab7);
    vlayout4->addWidget(btn8);
    vlayout4->addWidget(lab8);
    layout->addLayout(vlayout4);


    btn9=new MyBtn(this);
    btn9->setFixedSize(150,150);
    btn9->setIconSize(QSize(200,200));
    btn9->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/147.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/148.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab9=new QLabel(this);
    lab9->setWordWrap(1);
    lab9->setText("凄美地 - 郭顶");

    btn10=new MyBtn(this);
    btn10->setFixedSize(150,150);
    btn10->setIconSize(QSize(200,200));
    btn10->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/149.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/150.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab10=new QLabel(this);
    lab10->setWordWrap(1);
    lab10->setText("在你的身边 - 盛哲");

    QVBoxLayout *vlayout5=new QVBoxLayout;
    vlayout5->setSpacing(2);
    vlayout5->addWidget(btn9);
    vlayout5->addWidget(lab9);
    vlayout5->addWidget(btn10);
    vlayout5->addWidget(lab10);
    layout->addLayout(vlayout5);


    btn11=new MyBtn(this);
    btn11->setFixedSize(150,150);
    btn11->setIconSize(QSize(200,200));
    btn11->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/151.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/152.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab11=new QLabel(this);
    lab11->setWordWrap(1);
    lab11->setText("世间美好与你环环相扣 - 柏松");

    btn12=new MyBtn(this);
    btn12->setFixedSize(150,150);
    btn12->setIconSize(QSize(200,200));
    btn12->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/153.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/154.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab12=new QLabel(this);
    lab12->setWordWrap(1);
    lab12->setText("你曾是少年 - 焦迈奇");

    QVBoxLayout *vlayout6=new QVBoxLayout;
    vlayout6->setSpacing(2);
    vlayout6->addWidget(btn11);
    vlayout6->addWidget(lab11);
    vlayout6->addWidget(btn12);
    vlayout6->addWidget(lab12);
    layout->addLayout(vlayout6);


    btn13=new MyBtn(this);
    btn13->setFixedSize(150,150);
    btn13->setIconSize(QSize(200,200));
    btn13->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/131.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/132.png);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab13=new QLabel(this);
    lab13->setWordWrap(1);
    lab13->setText("人间城 - 王贰浪");

    btn14=new MyBtn(this);
    btn14->setFixedSize(150,150);
    btn14->setIconSize(QSize(200,200));
    btn14->setStyleSheet(
        "QPushButton {"
        "border-image: url(:/icon/157.jpg) 0 0 0 0 stretch stretch;"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 12px;"
        "border: none;"
        "mask-image: radial-gradient(circle, white, transparent);"
        "}"
        "QPushButton:hover {"
        "border-image: url(:/icon/158.jpg);}"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "border-radius: 10px;"
        "border: none;"
        "}"
        );
    lab14=new QLabel(this);
    lab14->setWordWrap(1);
    lab14->setText("我的一个道姑朋友 - 双笙（陈元汐）");

    QVBoxLayout *vlayout7=new QVBoxLayout;
    vlayout7->setSpacing(2);
    vlayout7->addWidget(btn13);
    vlayout7->addWidget(lab13);
    vlayout7->addWidget(btn14);
    vlayout7->addWidget(lab14);
    layout->addLayout(vlayout7);


    connect(btn1,&QPushButton::clicked,[&](){//点击第一首歌的按钮
        if(LinkQSL::lovemusic[1381755293]){
            emit openmusic1(1381755293,"山楂树之恋","程佳佳","山楂树之恋 (完整版)",0,true);
        }else{
            emit openmusic1(1381755293,"山楂树之恋","程佳佳","山楂树之恋 (完整版)",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn2,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[2042256453]){
            emit openmusic1(2042256453,"他不懂","王贰浪/俞天时","他不懂",0,true);
        }else{
            emit openmusic1(2042256453,"他不懂","王贰浪/俞天时","他不懂",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn3,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1383927243]){
            emit openmusic1(1383927243,"这一生关于你的风景","隔壁老樊","这一生关于你的风景",0,true);
        }else{
            emit openmusic1(1383927243,"这一生关于你的风景","隔壁老樊","这一生关于你的风景",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn4,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[421423806]){
            emit openmusic1(421423806,"小半","陈粒","小梦大半",0,true);
        }else{
            emit openmusic1(421423806,"小半","陈粒","小梦大半",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn5,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[413829859]){
            emit openmusic1(413829859,"童话镇","暗杠","童话镇",0,true);
        }else{
            emit openmusic1(413829859,"童话镇","暗杠","童话镇",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn6,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[2645495145]){
            emit openmusic1(2645495145,"消散对白","杜宣达","消散对白",0,true);
        }else{
            emit openmusic1(2645495145,"消散对白","杜宣达","消散对白",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn7,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1895330088]){
            emit openmusic1(1895330088,"予你","队长","予你",0,true);
        }else{
            emit openmusic1(1895330088,"予你","队长","予你",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn8,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1406649619]){
            emit openmusic1(1406649619,"有些","颜人中","失眠症候群",0,true);
        }else{
            emit openmusic1(1406649619,"有些","颜人中","失眠症候群",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn9,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[436346833]){
            emit openmusic1(436346833,"凄美地","郭顶","飞行器的执行周期",0,true);
        }else{
            emit openmusic1(436346833,"凄美地","郭顶","飞行器的执行周期",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn10,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[475479888]){
            emit openmusic1(475479888,"在你的身边","盛哲","在你的身边",0,true);
        }else{
            emit openmusic1(475479888,"在你的身边","盛哲","在你的身边",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn11,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1363948882]){
            emit openmusic1(1363948882,"世间美好与你环环相扣","柏松","听闻余生",0,true);
        }else{
            emit openmusic1(1363948882,"世间美好与你环环相扣","柏松","听闻余生",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn12,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1368371706]){
            emit openmusic1(1368371706,"你曾是少年","焦迈奇","你曾是少年",0,true);
        }else{
            emit openmusic1(1368371706,"你曾是少年","焦迈奇","你曾是少年",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn13,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1377574592]){
            emit openmusic1(1377574592,"人间城","王贰浪","人间城",0,true);
        }else{
            emit openmusic1(1377574592,"人间城","王贰浪","人间城",0,false);
        }
        emit openmusicwidget(4);
    });
    connect(btn14,&QPushButton::clicked,[&](){
        if(LinkQSL::lovemusic[1367452194]){
            emit openmusic1(1367452194,"我的一个道姑朋友","双笙（陈元汐）","我的一个道姑朋友",0,true);
        }else{
            emit openmusic1(1367452194,"我的一个道姑朋友","双笙（陈元汐）","我的一个道姑朋友",0,false);
        }
        emit openmusicwidget(4);
    });
}

Homeitem2::~Homeitem2()
{
    delete ui;
}

void Homeitem2::enterEvent(QEnterEvent *event)
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

void Homeitem2::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    ui->pushButton_2->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(255, 255, 255, 0);"
        "}"
        );
    ui->pushButton->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(255, 255, 255, 0);"
        "}"
        );
}

void Homeitem2::on_pushButton_2_clicked()
{
    QScrollBar *horizontalScrollBar = ui->scrollArea->horizontalScrollBar();
    maxvalue=horizontalScrollBar->maximum();
    timer->start(5);
}

void Homeitem2::do_start()
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

void Homeitem2::on_pushButton_clicked()
{
    QScrollBar *horizontalScrollBar = ui->scrollArea->horizontalScrollBar();
    minvalue=horizontalScrollBar->minimum();
    timer2->start(5);
}

void Homeitem2::do_start2()
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
