#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框

    //this->setStyleSheet("background-color:rgb(190,0,0)");
    srand((unsigned int)time(NULL));

    QVBoxLayout *layout = new QVBoxLayout(ui->widget_3);
    ui->widget_3->setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);

    manager=new QNetworkAccessManager(this);
    pixsmanager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::noReplied);
    connect(pixsmanager,&QNetworkAccessManager::finished,this,&MainWindow::nopixsReplied);

    hostwidget=new HostWidget(this);//创建搜索的时候的热歌界面
    audittion=new Audittion(ui->widget_3);//创建试听列表界面
    mylove=new MyLove(ui->widget_3);//创建喜欢界面
    lately=new Lately(ui->widget_3);//创建最近播放界面
    theme=new Themewidget(this);//创建换肤界面
    home=new Home(this);//创建home界面
    mysearch=new MySearchWidget(ui->widget_3);//创建搜索界面

    hostwidget->resize(300,350);
    mylove->hide();
    audittion->hide();
    lately->hide();
    hostwidget->hide();
    hostwidget->move(255,60);
    mysearch->hide();
    theme->hide();
    home->hide();

    //换肤界面信号槽
    connect(theme,&Themewidget::themenum1,[&](){
        themenum=1;
        this->update();
    });
    connect(theme,&Themewidget::themenum2,[&](){
        themenum=2;
        this->update();
    });
    connect(theme,&Themewidget::themenum3,[&](){
        themenum=3;
        this->update();
    });
    connect(theme,&Themewidget::themenum4,[&](){
        themenum=4;
        this->update();
    });
    connect(theme,&Themewidget::themenum5,[&](){
        themenum=5;
        this->update();
    });
    connect(theme,&Themewidget::themenum6,[&](){
        themenum=6;
        this->update();
    });
    connect(theme,&Themewidget::themenum7,[&](){
        themenum=7;
        this->update();
    });
    connect(theme,&Themewidget::themenum8,[&](){
        themenum=8;
        this->update();
    });
    connect(theme,&Themewidget::themenum9,[&](){
        themenum=9;
        this->update();
    });
    connect(theme,&Themewidget::themenum10,[&](){
        themenum=0;
        this->update();
    });

    connect(audittion,&Audittion::getid,this,&MainWindow::startopenmusic);//尝试列表的信号槽
    connect(mylove,&MyLove::getid,this,&MainWindow::startopenmusic);//喜欢界面的信号槽
    connect(lately,&Lately::getid,this,&MainWindow::startopenmusic);//最近播放界面的信号槽
    connect(mysearch,&MySearchWidget::getid,this,&MainWindow::startopenmusic);//搜索界面的信号槽
    connect(home->homeitem1,&Homeitem1::openmusic1,this,&MainWindow::startopenmusic);//home界面的信号槽
    connect(home->homeitem2,&Homeitem2::openmusic1,this,&MainWindow::startopenmusic);
    connect(hostwidget,&HostWidget::search,this,&MainWindow::do_search);
    //更新musicwidget的信号槽
    connect(mylove,&MyLove::openmusicwidget,this,&MainWindow::do_openmusicwidget);
    connect(audittion,&Audittion::openmusicwidget,this,&MainWindow::do_openmusicwidget);
    connect(lately,&Lately::openmusicwidget,this,&MainWindow::do_openmusicwidget);
    connect(mysearch,&MySearchWidget::openmusicwidget,this,&MainWindow::do_openmusicwidget);
    connect(home->homeitem1,&Homeitem1::openmusicwidget,this,&MainWindow::do_openmusicwidget);
    connect(home->homeitem2,&Homeitem2::openmusicwidget,this,&MainWindow::do_openmusicwidget);

    ui->pushButton->setStyleSheet("QPushButton{"
        "border-image: url(:/icon/1.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/2.png);"
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/3.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/4.png);"
        "}"
        );
    ui->pushButton_3->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/5.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/6.png);"
        "}"
        );
    ui->pushButton_4->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/9.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/10.png);"
        "}"
        );

    ui->pushButton_12->setStyleSheet(
                         "QPushButton{"
                         "border-image: url(:/icon/36.png);}"
                         "QPushButton:hover {"
                         "border-image: url(:/icon/37.png);"
                         "}"
        );

    ui->pushButton_13->setStyleSheet(
                         "QPushButton{"
                         "border-image: url(:/icon/44.png);}"
                         "QPushButton:hover {"
                         "border-image: url(:/icon/45.png);"
                         "}"
        );

    ui->pushButton_15->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/46.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/47.png);"
        "}"
        );

    ui->pushButton_16->setStyleSheet(
                         "QPushButton{"
                         "border-image: url(:/icon/33.png);}"
                         "QPushButton:hover {"
                         "border-image: url(:/icon/34.png);"
                         "}"
        );

    ui->pushButton_17->setStyleSheet(
                         "QPushButton{"
                         "border-image: url(:/icon/31.png);}"
                         "QPushButton:hover {"
                         "border-image: url(:/icon/32.png);"
                         "}"
        );

    ui->pushButton_18->setStyleSheet(
                         "QPushButton{"
                         "border-image: url(:/icon/29.png);}"
                         "QPushButton:hover {"
                         "border-image: url(:/icon/30.png);"
                         "}"
        );

    ui->horizontalSlider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "    height: 4px;"
        "    background: #CCCCCC;"
        "    margin: 0 0px;"
        "}"
        "QSlider::handle:horizontal {"
        "    background: #1cc95a;"
        "    width: 12px;"
        "    height: 12px;"
        "    margin: -4px 0;"
        "    border-radius: 6px;"
        "    border: none;"
        "}"
        "QSlider::sub-page:horizontal {"
        "    background: #1cc95a;"
        "}"
        );

    ui->label_4->setStyleSheet(
        "border-radius: 50%;"  // 设置为圆形
        "background-color: transparent;"  // 可选：设置背景透明
        );
    QPixmap pixmap(":/icon/16.png");
    pixmap = pixmap.scaled(ui->label_4->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);  // 缩放图片以适应标签大小
    // 创建一个圆形遮罩
    QPixmap circularPixmap(ui->label_4->size());
    circularPixmap.fill(Qt::transparent);  // 填充透明背景
    QPainter painter(&circularPixmap);
    painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿
    painter.setBrush(QBrush(pixmap));  // 使用图片作为画刷
    painter.setPen(Qt::NoPen);  // 无边框
    painter.drawEllipse(0, 0, ui->label_4->width(), ui->label_4->height());  // 绘制圆形
    // 设置裁剪后的圆形图片
    ui->label_4->setPixmap(circularPixmap);
    ui->label_4->setAlignment(Qt::AlignCenter);  // 将图片居中显示

    //创建一个action按钮
    searchact=new QAction(QIcon(":/icon/26.png"), QString("搜索"), ui->lineEdit);
    ui->lineEdit->addAction(searchact, QLineEdit::TrailingPosition);
    connect(searchact,&QAction::hovered,this,&MainWindow::changeactiocn);
    connect(searchact,&QAction::triggered,this,&MainWindow::do_triggered);

    changestate();

    curmusic.musicid=1830448879;
    curmusic.name="年轮";
    curmusic.author="不是花火呀";



    mediaplayer=new QMediaPlayer(this);//设置播放器
    QAudioOutput *output=new QAudioOutput(this);
    mediaplayer->setAudioOutput(output);//设置输出设备为本地的设备

    connect(mediaplayer,&QMediaPlayer::sourceChanged,this,&MainWindow::do_sourceChanged);//播放源发生变化
    connect(mediaplayer,&QMediaPlayer::durationChanged,this,&MainWindow::do_durationChanged);//播放源总长度发生变化
    connect(mediaplayer,&QMediaPlayer::positionChanged,this,&MainWindow::do_positionChanged);//播放到不同位置
    connect(mediaplayer,&QMediaPlayer::mediaStatusChanged,this,&MainWindow::do_mediaStatusChanged);//当前歌播放完


    connect(ui->pushButton_7,&QPushButton::clicked,[&](){
        m_widgetlist.push_back("mylove");
    });
    connect(ui->pushButton_10,&QPushButton::clicked,[&](){
        m_widgetlist.push_back("audittion");
    });
    connect(ui->pushButton_8,&QPushButton::clicked,[&](){
        m_widgetlist.push_back("lately");
    });
    connect(ui->pushButton_21,&QPushButton::clicked,[&](){
        m_widgetlist.push_back("theme");
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[&](){
        m_widgetlist.push_back("home");
    });

    musicsound=new Musicsound(this);
    musicsound->my_setsound(mediaplayer->audioOutput()->volume()*100);
    connect(musicsound,&Musicsound::soundchanged,this,&MainWindow::setmusicsound);//改变音量的信号槽
    musicsound->hide();

    m_widgetlist.push_back("home");
    on_pushButton_5_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changestate()//初始化按钮状态
{
    ui->pushButton_5->setStyleSheet(
        "QPushButton{"
        "border-radius:10px;"
        "background-color: rgba(0, 0, 0,10);}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0, 20);"
        "}"
        );
    ui->pushButton_5->setIcon(QIcon(":/icon/11.png"));
    ui->pushButton_5->setIconSize(QSize(30,30));

    ui->pushButton_6->setIcon(QIcon(":/icon/13.png"));
    ui->pushButton_6->setIconSize(QSize(30,30));
    ui->pushButton_6->setStyleSheet(
        "QPushButton{"
        "border-radius:10px;"
        "background-color: rgba(0, 0, 0,10);}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0, 20);"
        "}"
        );

    ui->pushButton_7->setIcon(QIcon(":/icon/18.png"));
    ui->pushButton_7->setIconSize(QSize(25,25));
    ui->pushButton_7->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"  // 文本居左
        "padding-left: 10px;"// 设置左边距，避免图标和文本紧贴边缘
        "background-color: rgba(0, 0, 0,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0, 20);"
        "}"
        );

    ui->pushButton_8->setIcon(QIcon(":/icon/20.png"));
    ui->pushButton_8->setIconSize(QSize(25,25));
    ui->pushButton_8->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"  // 文本居左
        "padding-left: 10px;"// 设置左边距，避免图标和文本紧贴边缘
        "background-color: rgba(0, 0, 0,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0, 20);"
        "}"
        );

    ui->pushButton_9->setIcon(QIcon(":/icon/22.png"));
    ui->pushButton_9->setIconSize(QSize(25,25));
    ui->pushButton_9->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"  // 文本居左
        "padding-left: 10px;"// 设置左边距，避免图标和文本紧贴边缘
        "background-color: rgba(0, 0, 0,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0, 20);"
        "}"
        );

    ui->pushButton_10->setIcon(QIcon(":/icon/24.png"));
    ui->pushButton_10->setIconSize(QSize(25,25));
    ui->pushButton_10->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"  // 文本居左
        "padding-left: 10px;"// 设置左边距，避免图标和文本紧贴边缘
        "background-color: rgba(0, 0, 0,0);"
        "}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0, 20);"
        "}"
        );

    ui->pushButton_20->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(0, 0, 0,0);"
        "border-image: url(:/icon/95.png);}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0,0);"
        "border-image: url(:/icon/96.png);"
        "}"
        );

    ui->pushButton_21->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(0, 0, 0,0);"
        "border-image: url(:/icon/93.png);}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0,0);"
        "border-image: url(:/icon/94.png);"
        "}"
        );

    ui->pushButton_22->setStyleSheet(
        "QPushButton{"
        "background-color: rgba(0, 0, 0,0);"
        "border-image: url(:/icon/97.png);}"
        "QPushButton:hover {"
        "background-color: rgba(0, 0, 0,0);"
        "border-image: url(:/icon/98.png);"
        "}"
        );
}

void MainWindow::changeactiocn()//当鼠标掠过时改变收索按钮图片
{
    if(!ishovered){
        searchact->setIcon(QIcon(":/icon/27.png"));
        ishovered=1;
    }else{
        searchact->setIcon(QIcon(":/icon/26.png"));
        ishovered=0;
    }
}

void MainWindow::on_pushButton_5_clicked()//点击home按钮
{
    changestate();
    ui->pushButton_5->setStyleSheet(
        "border-radius:10px;"
        "background-color: rgba(0, 0, 0,50);"
        );
    ui->pushButton_5->setIcon(QIcon(":/icon/12.png"));
    ui->pushButton_5->setIconSize(QSize(30,30));

    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }
    ui->widget_3->layout()->addWidget(home);
    home->show();
    curwidget=home;
}


void MainWindow::on_pushButton_6_clicked()//点击乐馆
{
    changestate();
    ui->pushButton_6->setIcon(QIcon(":/icon/14.png"));
    ui->pushButton_6->setIconSize(QSize(30,30));
    ui->pushButton_6->setStyleSheet(
        "border-radius:10px;"
        "background-color: rgba(0, 0, 0,50);"
        );
}


void MainWindow::on_pushButton_7_clicked()//点击喜欢按钮
{
    changestate();
    ui->pushButton_7->setIcon(QIcon(":/icon/19.png"));
    ui->pushButton_7->setIconSize(QSize(25,25));
    ui->pushButton_7->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"
        "padding-left: 10px;"
        "background-color: rgba(0, 0, 0,50);"
        "}"
        );



    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }
    ui->widget_3->layout()->addWidget(mylove);
    mylove->show();
    curwidget=mylove;

}


void MainWindow::on_pushButton_8_clicked()//点击最近播放按钮
{
    changestate();
    ui->pushButton_8->setIcon(QIcon(":/icon/21.png"));
    ui->pushButton_8->setIconSize(QSize(25,25));
    ui->pushButton_8->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"
        "padding-left: 10px;"
        "background-color: rgba(0, 0, 0,50);"
        "}"
        );

    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }
    ui->widget_3->layout()->addWidget(lately);
    lately->show();
    curwidget=lately;
}


void MainWindow::on_pushButton_9_clicked()//点击本地音乐
{
    changestate();
    ui->pushButton_9->setIcon(QIcon(":/icon/23.png"));
    ui->pushButton_9->setIconSize(QSize(25,25));
    ui->pushButton_9->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"
        "padding-left: 10px;"
        "background-color: rgba(0, 0, 0,50);"
        "}"
        );

}


void MainWindow::on_pushButton_10_clicked()//点击试听列表
{
    changestate();
    ui->pushButton_10->setIcon(QIcon(":/icon/25.png"));
    ui->pushButton_10->setIconSize(QSize(25,25));
    ui->pushButton_10->setStyleSheet(
        "QPushButton {"
        "border-radius:10px;"
        "font: 10pt \"Microsoft YaHei UI\";"
        "text-align: left;"
        "padding-left: 10px;"
        "background-color: rgba(0, 0, 0,50);"
        "}"
        );

    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }
    ui->widget_3->layout()->addWidget(audittion);
    audittion->show();
    curwidget=audittion;

}


void MainWindow::on_pushButton_4_clicked()//关闭程序
{
    this->close();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)//鼠标移动
{
    // QPoint point=event->globalPos();
    // if(ishovered&&point.x()>)
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标点击事件,用于判断是否要隐藏hostwidget界面
{
    if(event->button()!=Qt::LeftButton){
        return;
    }
    QPoint point=event->pos();
    if(!hostwidget->geometry().contains(point)){
        hostwidget->hide();
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::paintEvent(QPaintEvent *event)//窗口绘制事件，用于换肤
{
    QMainWindow::paintEvent(event);

    if(themenum==0){
        return;
    }
    QPainter painter(this);
    QPixmap pixmap;
    if(themenum==1){
        pixmap=QPixmap(":/icon/99.png");
    }else if(themenum==2){
        pixmap=QPixmap(":/icon/100.png");
    }else if(themenum==3){
        pixmap=QPixmap(":/icon/92.png");
    }else if(themenum==4){
        pixmap=QPixmap(":/icon/101.png");
    }else if(themenum==5){
        pixmap=QPixmap(":/icon/1102.jpg");
    }else if(themenum==6){
        pixmap=QPixmap(":/icon/1103.jpg");
    }else if(themenum==7){
        pixmap=QPixmap(":/icon/1104.jpg");
    }else if(themenum==8){
        pixmap=QPixmap(":/icon/1105.jpg");
    }else if(themenum==9){
        pixmap=QPixmap(":/icon/1106.jpg");
    }
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 绘制背景图片
    painter.drawPixmap(0, 0, width(), height(), pixmap);
}



void MainWindow::do_sourceChanged(const QUrl &media)//音乐播放源发生变化
{
    Q_UNUSED(media);
    ui->label_9->setText(curmusic.name+"-"+curmusic.author);
}



void MainWindow::do_durationChanged(qint64 duration)//播放源总长度发生变化
{
    curmusictime=duration;
    int sumtime=duration/1000;
    int m=sumtime/60;
    int s=sumtime%60;
    if(s<10){
        ui->label_11->setText(QString::asprintf("%d",m)+":0"+QString::asprintf("%d",s));
    }else{
        ui->label_11->setText(QString::asprintf("%d",m)+':'+QString::asprintf("%d",s));
    }
    ui->horizontalSlider->setMaximum(duration);
    if(lyrics!=NULL){
        lyrics->getmaxvalue(duration);
    }
}

void MainWindow::do_positionChanged(qint64 position)//播放到不同位置
{
    int sumtime=position/1000;
    int m=sumtime/60;
    int s=sumtime%60;
    if(s<10){
        ui->label_10->setText(QString::asprintf("%d",m)+":0"+QString::asprintf("%d",s));
    }else{
        ui->label_10->setText(QString::asprintf("%d",m)+':'+QString::asprintf("%d",s));
    }
    ui->horizontalSlider->setValue(position);
    if(lyrics!=NULL){
        lyrics->getnewtime(position);
    }
}



void MainWindow::do_mediaStatusChanged(QMediaPlayer::MediaStatus status)//当前歌播放完
{
    if(status!=QMediaPlayer::EndOfMedia){
        return;
    }
    if(musicwidget==audittion){
        return;
    }
    if(musicwidget==mylove){
        if(loop==0){//顺序播放下一首
            on_pushButton_15_clicked();
        }else if(loop==1){//随机播放下一首
            int nextindex=rand()%mylove->listwidget->count();
            mylove->listwidget->setCurrentRow(nextindex);
            QListWidgetItem *item=mylove->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mylove->listwidget->itemWidget(item));
            emit mylove->getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
        }else if(loop==2){//单曲循环
            mediaplayer->setPosition(0);
            mediaplayer->play();
            if(lyrics!=NULL){
                lyrics->getmusic(curmusic.musicid,curmusic.name,curmusic.author,musicpix);
            }
        }
    }
    if(musicwidget==lately){
        if(loop==0){//顺序播放下一首
            on_pushButton_15_clicked();
        }else if(loop==1){//随机播放下一首
            int nextindex=rand()%lately->listwidget->count();
            lately->listwidget->setCurrentRow(nextindex);
            QListWidgetItem *item=lately->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(lately->listwidget->itemWidget(item));
            emit lately->getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
        }else if(loop==2){//单曲循环
            mediaplayer->setPosition(0);
            mediaplayer->play();
            if(lyrics!=NULL){
                lyrics->getmusic(curmusic.musicid,curmusic.name,curmusic.author,musicpix);
            }
        }
    }
    if(musicwidget==mysearch){
        if(loop==0){
            on_pushButton_15_clicked();
        }else if(loop==1){
            int nextindex=rand()%mysearch->music->listwidget->count();
            QListWidgetItem *item=mysearch->music->listwidget->item(nextindex);
            mysearch->do_itemClicked(item);
        }else if(loop==2){
            mediaplayer->setPosition(0);
            mediaplayer->play();
            if(lyrics!=NULL){
                lyrics->getmusic(curmusic.musicid,curmusic.name,curmusic.author,musicpix);
            }
        }
    }
    if(musicwidget==home){
        mediaplayer->setPosition(0);
        mediaplayer->play();
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    if(!ispause){
        ispause=1;
        mediaplayer->pause();
        ui->pushButton_14->setIcon(QIcon(":/icon/42.png"));
    }else{
        ispause=0;
        mediaplayer->play();
        ui->pushButton_14->setIcon(QIcon(":/icon/43.png"));
    }
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)//拖动进度条
{
    mediaplayer->setPosition(position);
}


void MainWindow::on_pushButton_16_clicked()//点击音量键
{
    QPoint btn_16point=ui->pushButton_16->mapToGlobal(QPoint(0, 0));
    QPoint newpoint(btn_16point.x()-10,btn_16point.y()-180);
    QPoint newPosInParent = musicsound->parentWidget()->mapFromGlobal(newpoint);
    musicsound->move(newPosInParent);
    musicsound->show();

}

void MainWindow::setmusicsound(int p)//改变音量的槽函数
{
    mediaplayer->audioOutput()->setVolume(p/100.0);
}



void MainWindow::noReplied(QNetworkReply *reply)//接收完数据的槽函数
{


    reply->deleteLater();
}

void MainWindow::nopixsReplied(QNetworkReply *reply)
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
    QJsonArray songsarr=rootobj.value("songs").toArray();
    QJsonObject itemobj=songsarr.at(0).toObject();
    QJsonObject albumobj=itemobj.value("album").toObject();
    QString s=albumobj.value("picUrl").toString();
    musicmanager=new QNetworkAccessManager(this);
    QUrl url(s);
    QNetworkRequest request(url);
    reply1 = musicmanager->get(request);
    connect(reply1, &QNetworkReply::finished, this, &MainWindow::onImageDownloaded);
}

void MainWindow::startopenmusic(long long m_id,QString m_name,QString m_author,QString m_album,int m_fee,bool m_islove)
{
    curmusic.musicid=m_id;
    curmusic.name=m_name;
    curmusic.author=m_author;
    curmusic.islove=m_islove;
    curmusic.album=m_album;
    curmusic.fee=m_fee;

    if(!LinkQSL::heardmusic[m_id]){
        LinkQSL::heardmusic[m_id]=1;
        mysql.insertheardmusic(m_id,m_name,m_author);
        QListWidgetItem *item=new QListWidgetItem(lately->listwidget);
        Itemmusic *newitem=new Itemmusic(lately->listwidget);
        newitem->setinit(m_id,m_name,m_author,m_album,m_fee,m_islove);
        lately->listwidget->setItemWidget(item,newitem);
        item->setSizeHint(QSize(lately->listwidget->width(),50));
    }

    if(m_islove){
        ui->pushButton_11->setIcon(QIcon(":/icon/58.png"));
    }else{
        ui->pushButton_11->setIcon(QIcon(":/icon/18.png"));
    }

    QString pixurl="http://music.163.com/api/song/detail/?id="+QString::number(curmusic.musicid)+"&ids=%5B"+QString::number(curmusic.musicid)+"%5D";
    QUrl url(pixurl);
    pixsmanager->get(QNetworkRequest(url));

    QString s=QString("https://music.163.com/song/media/outer/url?id=%0").arg(QString::number(curmusic.musicid));
    mediaplayer->setSource(QUrl(s));
    ispause=0;
    mediaplayer->play();
    ui->pushButton_14->setIcon(QIcon(":/icon/43.png"));
}


void MainWindow::on_pushButton_15_clicked()//点击下一首
{
    if(musicwidget==audittion){
        return;
    }
    if(musicwidget==mylove){
        QListWidgetItem *item=mylove->listwidget->currentItem();
        if(item){
            int index=mylove->listwidget->row(item);
            int nextindex=(index+1)%mylove->listwidget->count();
            mylove->listwidget->setCurrentRow(nextindex);
        }
        item=mylove->listwidget->currentItem();
        Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mylove->listwidget->itemWidget(item));
        emit mylove->getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
    }
    if(musicwidget==lately){
        QListWidgetItem *item=lately->listwidget->currentItem();
        if(item){
            int index=lately->listwidget->row(item);
            int nextindex=(index+1)%lately->listwidget->count();
            lately->listwidget->setCurrentRow(nextindex);
        }
        item=lately->listwidget->currentItem();
        Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(lately->listwidget->itemWidget(item));
        emit lately->getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
    }
    if(musicwidget==mysearch){
        int row = mysearch->music->listwidget->row(mysearch->music->listwidget->currentItem())+1;
        if(row==mysearch->music->listwidget->count()){
            row=0;
        }
        QListWidgetItem *item=mysearch->music->listwidget->item(row);
        mysearch->do_itemClicked(item);
    }
}


void MainWindow::on_pushButton_13_clicked()//点击上一首
{
    if(musicwidget==audittion){
        return;
    }
    if(musicwidget==mylove){
        QListWidgetItem *item=mylove->listwidget->currentItem();
        if(item){
            int index=mylove->listwidget->row(item);
            int nextindex=(index-1);
            if(nextindex<0){
                nextindex=mylove->listwidget->count()-1;
            }
            mylove->listwidget->setCurrentRow(nextindex);
        }
        item=mylove->listwidget->currentItem();
        Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mylove->listwidget->itemWidget(item));
        emit mylove->getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
    }if(musicwidget==lately){
        QListWidgetItem *item=lately->listwidget->currentItem();
        if(item){
            int index=lately->listwidget->row(item);
            int nextindex=(index-1);
            if(nextindex<0){
                nextindex=lately->listwidget->count()-1;
            }
            lately->listwidget->setCurrentRow(nextindex);
        }
        item=lately->listwidget->currentItem();
        Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(lately->listwidget->itemWidget(item));
        emit lately->getid(m_itemmusic->id,m_itemmusic->name,m_itemmusic->author,m_itemmusic->album,m_itemmusic->fee,m_itemmusic->islove);
    }
    if(musicwidget==mysearch){
        int row = mysearch->music->listwidget->row(mysearch->music->listwidget->currentItem())-1;
        if(row<0){
            row=mysearch->music->listwidget->count()-1;
        }
        QListWidgetItem *item=mysearch->music->listwidget->item(row);
        mysearch->do_itemClicked(item);
    }
}


void MainWindow::on_pushButton_12_clicked()//点击循环按钮
{
    loop+=1;
    loop%=3;
    if(loop==0){
        ui->pushButton_12->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/36.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/37.png);"
            "}"
            );
    }else if(loop==1){
        ui->pushButton_12->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/38.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/39.png);"
            "}"
            );
    }else if(loop==2){
        ui->pushButton_12->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/40.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/41.png);"
            "}"
            );
    }
}

void MainWindow::do_openmusicwidget(int p)
{
    if(musicwidget==audittion){

    }else if(musicwidget==mylove&&p!=1){
        mylove->listwidget->currentItem()->setSelected(false);
    }else if(musicwidget==lately&&p!=2){
        lately->listwidget->currentItem()->setSelected(0);
    }else if(musicwidget==mysearch&&p!=3){
        mysearch->music->listwidget->currentItem()->setSelected(0);
    }

    if(p==0){
        musicwidget=audittion;
    }else if(p==1){
        musicwidget=mylove;
    }else if(p==2){
        musicwidget=lately;
    }else if(p==3){
        musicwidget=mysearch;
    }else if(p==4){
        musicwidget=home;
    }
}


void MainWindow::on_pushButton_clicked()//按返回键
{
    int sum=m_widgetlist.size();
    if(sum<=1){
        return;
    }
    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }
    m_widgetlist.pop_back();
    if(m_widgetlist[sum-2]=="mylove"){
        on_pushButton_7_clicked();
    }else if(m_widgetlist[sum-2]=="audittion"){
        on_pushButton_10_clicked();
    }else if(m_widgetlist[sum-2]=="lately"){
        on_pushButton_8_clicked();
    }else if(m_widgetlist[sum-2]=="mysearch"){
        if(curwidget){
            ui->widget_3->layout()->removeWidget(curwidget);//清空布局
            curwidget->hide();
        }

        changestate();

        ui->widget_3->layout()->addWidget(mysearch);
        mysearch->show();
        curwidget=mysearch;
    }else if(m_widgetlist[sum-2]=="theme"){
        on_pushButton_21_clicked();
    }else if(m_widgetlist[sum-2]=="home"){
        on_pushButton_5_clicked();
    }

}


void MainWindow::on_pushButton_3_clicked()//点击放大窗口
{
    if(ismax){
        ui->pushButton_3->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/5.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/6.png);"
            "}"
            );
        this->resize(1050,700);
        QTimer::singleShot(10, [this]() {
            this->move(200, 100);
        });
        ismax=0;

    }else{
        ui->pushButton_3->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/7.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/8.png);"
            "}"
            );
        this->showFullScreen();
        ismax=1;
    }
}


void MainWindow::on_lineEdit_selectionChanged()//当lineedit获得焦点时
{
    hostwidget->listwidget->clearSelection();
    hostwidget->show();
}


void MainWindow::on_lineEdit_editingFinished()//当lineedit失去焦点时
{

    hostwidget->hide();
}

void MainWindow::do_triggered()//点击搜索按钮
{
    QString s=ui->lineEdit->text();
    if(s.isEmpty()){
        return;
    }
    hostwidget->hide();

    changestate();
    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }

    ui->widget_3->layout()->addWidget(mysearch);
    mysearch->show();
    curwidget=mysearch;
    mysearch->getname(s);

    m_widgetlist.push_back("mysearch");

}

void MainWindow::do_search(QString name)
{
    ui->lineEdit->setText(name);
    do_triggered();
}


void MainWindow::on_pushButton_2_clicked()//最小化窗口按钮
{
    this->showMinimized();
}

void MainWindow::onImageDownloaded()
{
    if (reply1->error() == QNetworkReply::NoError) {
        // 获取响应数据
        QByteArray data = reply1->readAll();
        // 将数据转换为 QPixmap
        musicpix.loadFromData(data);

        if(lyrics!=NULL){//如果处于歌词界面，更新歌词界面
            on_pushButton_19_clicked();
        }
    }
    musicmanager->deleteLater();

    reply1->deleteLater();
    reply1=NULL;
    ui->pushButton_19->setIconSize(QSize(50,50));
    ui->pushButton_19->setIcon(musicpix);
    ui->pushButton_19->showOverlay=0;
    ui->pushButton_19->update();
}


void MainWindow::on_pushButton_19_clicked()//点击歌词界面
{
    if(lyrics==NULL){
        lyrics=new Lyrics(this);
        connect(lyrics,&Lyrics::fallwidget,this,&MainWindow::do_lyrics);
        connect(lyrics,&Lyrics::thisdelete,this,&MainWindow::deletelyrics);
        connect(lyrics,&Lyrics::nextmusic,this,&MainWindow::on_pushButton_15_clicked);
        connect(lyrics,&Lyrics::begmusic,this,&MainWindow::on_pushButton_13_clicked);
        connect(lyrics,&Lyrics::musicopen,this,&MainWindow::do_musicopen);
        connect(lyrics,&Lyrics::musicstop,this,&MainWindow::do_musicstop);
        connect(lyrics,&Lyrics::setmin,this,&MainWindow::on_pushButton_2_clicked);
        connect(lyrics,&Lyrics::setclose,this,&MainWindow::on_pushButton_4_clicked);
        connect(lyrics,&Lyrics::widgetsetmax,this,&MainWindow::do_widgetsetmax);
        connect(lyrics,&Lyrics::cancelmax,this,&MainWindow::do_cancelmax);
        connect(lyrics,&Lyrics::my_horizontalSlider_sliderMoved,this,&MainWindow::on_horizontalSlider_sliderMoved);
        connect(lyrics,&Lyrics::soundchanged,this,&MainWindow::do_lyricssoundchanged);
        lyrics->startRiseAnimation();
        lyrics->setmusicvol(mediaplayer->audioOutput()->volume()*100);
    }
    lyrics->getmaxvalue(curmusictime);
    lyrics->getmusic(curmusic.musicid,curmusic.name,curmusic.author,musicpix);
}

void MainWindow::deletelyrics()//歌词退出动画放完的槽函数
{
    lyrics->deleteLater();
    lyrics=NULL;
}

void MainWindow::do_musicopen()//歌词界面实现音乐继续播放槽函数
{
    ispause=1;
    on_pushButton_14_clicked();
}

void MainWindow::do_musicstop()//歌词界面实现音乐暂停槽函数
{
    ispause=0;
    on_pushButton_14_clicked();
}

void MainWindow::do_widgetsetmax()//歌词界面实现放大窗口的槽函数
{
    ismax=0;
    lyrics->showFullScreen();
    QTimer::singleShot(10, [this]() {
        lyrics->move(0, 0);
    });
    on_pushButton_3_clicked();
}

void MainWindow::do_cancelmax()//歌词界面恢复窗口正常大小的槽函数
{
    ismax=1;
    lyrics->resize(1050,700);
    QTimer::singleShot(10, [this]() {
        lyrics->move(0, 0);
    });
    on_pushButton_3_clicked();
}

void MainWindow::do_lyricssoundchanged(int p)//歌词界面改变音量的槽函数
{
    musicsound->my_setsound(p);
    mediaplayer->audioOutput()->setVolume(p/100.0);
}

void MainWindow::do_lyrics()//收到歌词界面退出的槽函数
{
    lyrics->startFallAnimation();
}


void MainWindow::on_pushButton_21_clicked()//点击换肤按钮
{
    changestate();
    if(curwidget){
        ui->widget_3->layout()->removeWidget(curwidget);//清空布局
        curwidget->hide();
    }
    ui->widget_3->layout()->addWidget(theme);
    theme->show();
    curwidget=theme;
}


void MainWindow::on_pushButton_11_clicked()//添加和取消喜欢歌曲按钮
{
    if(curmusic.islove){
        ui->pushButton_11->setIcon(QIcon(":/icon/18.png"));
        curmusic.islove=0;
        if(musicwidget==audittion){
            audittion->changedunlove();
            return;
        }
        if(musicwidget==mylove){
            QListWidgetItem *item=mylove->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mylove->listwidget->itemWidget(item));
            if(curmusic.musicid==m_itemmusic->id){
                m_itemmusic->changedunlove();
            }
        }
        if(musicwidget==lately){
            QListWidgetItem *item=lately->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(lately->listwidget->itemWidget(item));
            m_itemmusic->changedunlove();
        }
        if(musicwidget==mysearch){
            QListWidgetItem *item=mysearch->music->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mysearch->music->listwidget->itemWidget(item));
            m_itemmusic->changedunlove();
        }
        for(int i=0;i<mylove->listwidget->count();i++){
            QListWidgetItem *item=mylove->listwidget->item(i);
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mylove->listwidget->itemWidget(item));
            if(m_itemmusic->id==curmusic.musicid){
                QListWidgetItem *delitem= mylove->listwidget->takeItem(i);
                delete delitem;
                mysql.deletelovemusic(curmusic.musicid);
                break;
            }
        }
        LinkQSL::lovemusic[curmusic.musicid]=0;
    }else{
        ui->pushButton_11->setIcon(QIcon(":/icon/58.png"));
        curmusic.islove=1;
        if(musicwidget==audittion){
            audittion->changedlove();
        }
        if(musicwidget==mylove){
            QListWidgetItem *item=mylove->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mylove->listwidget->itemWidget(item));
            m_itemmusic->changedlove();
        }
        if(musicwidget==lately){
            QListWidgetItem *item=lately->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(lately->listwidget->itemWidget(item));
            m_itemmusic->changedlove();
        }
        if(musicwidget==mysearch){
            QListWidgetItem *item=mysearch->music->listwidget->currentItem();
            Itemmusic *m_itemmusic=dynamic_cast<Itemmusic*>(mysearch->music->listwidget->itemWidget(item));
            //newitem=m_itemmusic;
            m_itemmusic->changedlove();
        }
        if(!LinkQSL::lovemusic[curmusic.musicid]&&musicwidget!=audittion){
            Itemmusic *newitem=new Itemmusic(mylove->listwidget);
            newitem->setinit(curmusic.musicid,curmusic.name,curmusic.author,curmusic.album,curmusic.fee,curmusic.islove);
            QListWidgetItem *item=new QListWidgetItem(mylove->listwidget);
            mylove->listwidget->setItemWidget(item,newitem);
            item->setSizeHint(QSize(mylove->listwidget->width(),50));

            mysql.insertlovemusic(curmusic.musicid,curmusic.name,curmusic.author);
            LinkQSL::lovemusic[curmusic.musicid]=1;
        }
    }
}

