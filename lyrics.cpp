#include "lyrics.h"
#include "ui_lyrics.h"

Lyrics::Lyrics(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lyrics)
{
    ui->setupUi(this);
    musicsound=new Musicsound(this);//调节音量界面
    connect(musicsound,&Musicsound::soundchanged,this,&Lyrics::setmusicsound);
    musicsound->hide();
    manager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&Lyrics::noReplied);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    animation = new QPropertyAnimation(this, "pos", this);
    animation->setDuration(300); // 动画持续时间

    fallAnimation = new QPropertyAnimation(this, "pos", this);
    fallAnimation->setDuration(300); // 下落动画持续时间

    initbutton();

    connect(fallAnimation, &QPropertyAnimation::finished, this, [this]() {
        emit thisdelete();
    });

}

void Lyrics::startRiseAnimation()
{
    QWidget *parentWidget = qobject_cast<QWidget*>(parent());
    if (parentWidget) {
        QRect parentRect = parentWidget->geometry();
        int parentX = parentRect.x();
        int parentY = parentRect.y();
        int parentWidth = parentRect.width();
        int parentHeight = parentRect.height();

        // 初始位置在主窗口下方
        setGeometry(parentX, parentY + parentHeight, parentWidth, parentHeight);

        // 动画起始和结束位置
        animation->setStartValue(QPoint(parentX, parentY + parentHeight));
        animation->setEndValue(QPoint(parentX, parentY));

        show();
        animation->start();
    }
}

void Lyrics::startFallAnimation()
{
    QWidget *parentWidget = qobject_cast<QWidget*>(parent());
    if (parentWidget) {
        QRect parentRect = parentWidget->geometry();
        int parentX = parentRect.x();
        int parentY = parentRect.y();
        int parentHeight = parentRect.height();

        // 动画起始和结束位置
        fallAnimation->setStartValue(QPoint(parentX, parentY));
        fallAnimation->setEndValue(QPoint(parentX, parentY + parentHeight));

        connect(fallAnimation, &QPropertyAnimation::finished, this, &QWidget::deleteLater);
        fallAnimation->start();
    }

}

Lyrics::~Lyrics()
{
    delete ui;
}

void Lyrics::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}

void Lyrics::getmusic(long long id, QString name, QString author,QPixmap pix)
{
    ui->label_4->setText(name);
    ui->label_5->setText(author);
    ui->label_2->setText(name+" - "+author);
    ui->label_3->setPixmap(pix);
    QString s="https://music.163.com/api/song/lyric?id="+QString::number(id)+"&lv=1&kv=1&tv=-1";
    QUrl url(s);
    manager->get(QNetworkRequest(url));
}

void Lyrics::getnewtime(qint64 t)//更新时间
{
    int sumtime=t/1000;
    int m=sumtime/60;
    int s=sumtime%60;
    if(s<10){
        ui->label_10->setText(QString::asprintf("%d",m)+":0"+QString::asprintf("%d",s));
    }else{
        ui->label_10->setText(QString::asprintf("%d",m)+':'+QString::asprintf("%d",s));
    }
    ui->horizontalSlider->setValue(t);
    if(index<timelist.count()&&t>=timelist[index]){//更新歌词
        ui->label_8->setText(ma[timelist[index]]);

        int befindex=index;
        int aftindex=index;
        int sum=timelist.count()-1;

        if(befindex!=0){
            befindex--;
            ui->label_7->setText(ma[timelist[befindex]]);
            if(befindex!=0){
                befindex--;
                ui->label_6->setText(ma[timelist[befindex]]);
            }
        }

        if(aftindex!=sum){
            aftindex++;
            ui->label_9->setText(ma[timelist[aftindex]]);
            if(aftindex!=sum){
                aftindex++;
                ui->label_16->setText(ma[timelist[aftindex]]);
                if(aftindex!=sum){
                    aftindex++;
                    ui->label_17->setText(ma[timelist[aftindex]]);
                    if(aftindex!=sum){
                        aftindex++;
                        ui->label_18->setText(ma[timelist[aftindex]]);
                        if(aftindex!=sum){
                            aftindex++;
                            ui->label_19->setText(ma[timelist[aftindex]]);
                        }else{
                            ui->label_19->setText("");
                        }
                    }else{
                        ui->label_18->setText("");
                        ui->label_19->setText("");
                    }
                }else{
                    ui->label_17->setText("");
                    ui->label_18->setText("");
                    ui->label_19->setText("");
                }
            }else{
                ui->label_16->setText("");
                ui->label_17->setText("");
                ui->label_18->setText("");
                ui->label_19->setText("");
            }
        }else{
            ui->label_9->setText("");
            ui->label_16->setText("");
            ui->label_17->setText("");
            ui->label_18->setText("");
            ui->label_19->setText("");
        }

        index++;
    }
}

void Lyrics::getmaxvalue(qint64 t)//更新最大时间
{
    //先清空数据
    index=0;
    ma.clear();
    timelist.clear();
    ui->label_6->setText("");
    ui->label_7->setText("");
    ui->label_8->setText("");
    ui->label_9->setText("");
    ui->label_16->setText("");
    ui->label_17->setText("");
    ui->label_18->setText("");
    ui->label_19->setText("");


    int sumtime=t/1000;
    int m=sumtime/60;
    int s=sumtime%60;
    if(s<10){
        ui->label_111->setText(QString::asprintf("%d",m)+":0"+QString::asprintf("%d",s));
    }else{
        ui->label_111->setText(QString::asprintf("%d",m)+':'+QString::asprintf("%d",s));
    }
    ui->horizontalSlider->setMaximum(t);
}

void Lyrics::setmusicvol(int vol)
{
    musicsound->my_setsound(vol);
}

void Lyrics::initbutton()//初始化控件
{
    ui->pushButton->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/59.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/60.png);"
        "}"
        );

    ui->pushButton_2->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/61.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/62.png);"
        "}"
        );

    ui->pushButton_3->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/63.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/64.png);"
        "}"
        );

    ui->pushButton_4->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/65.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/66.png);"
        "}"
        );

    ui->pushButton_5->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/67.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/68.png);"
        "}"
        );

    ui->pushButton_6->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/69.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/70.png);"
        "}"
        );

    ui->pushButton_12->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/77.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/78.png);"
        "}"
        );

    ui->pushButton_13->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/83.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/84.png);"
        "}"
        );

    ui->pushButton_15->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/85.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/86.png);"
        "}"
        );

    ui->pushButton_16->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/87.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/88.png);"
        "}"
        );

    ui->pushButton_7->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/73.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/74.png);"
        "}"
        );

    ui->pushButton_8->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/71.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/72.png);"
        "}"
        );

    ui->pushButton_9->setStyleSheet(
        "QPushButton{"
        "border-image: url(:/icon/75.png);}"
        "QPushButton:hover {"
        "border-image: url(:/icon/76.png);"
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
}

void Lyrics::initmap(QString s)//初始化map
{
    QStringList lines = s.split('\n');
    QRegularExpression regex(R"(\[(\d{2}):(\d{2})\.(\d{2,3})\]\s*(.*))");
    for (const QString& line : lines){
        QRegularExpressionMatch match = regex.match(line);
        if (match.hasMatch()) {
            // 提取时间信息
            int minutes = match.captured(1).toInt();
            int seconds = match.captured(2).toInt();
            int milliseconds = match.captured(3).toInt();

            // 计算总毫秒数
            int totalMilliseconds = minutes * 60 * 1000 + seconds * 1000 + milliseconds;

            // 提取歌词内容
            QString lyricsText = match.captured(4);
            qDebug()<<totalMilliseconds<<"   "<<lyricsText<<'\n';

            // 存储到 map 中
            if (!lyricsText.isEmpty()) {
                timelist<<totalMilliseconds;
                ma[totalMilliseconds] = lyricsText;
            }
        }
    }
    if(timelist.count()==0){
        ui->label_8->setText("此歌曲没有歌词");
    }
}

void Lyrics::on_pushButton_clicked()//点击下放歌词按钮
{
    emit fallwidget();
}

void Lyrics::noReplied(QNetworkReply *reply)
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
    QJsonObject lrcobj=rootobj.value("lrc").toObject();
    QString s=lrcobj.value("lyric").toString();

    qDebug()<<s<<'\n';

    initmap(s);
    reply->deleteLater();

}


void Lyrics::on_pushButton_15_clicked()//点击下一首
{
    emit nextmusic();
}


void Lyrics::on_pushButton_13_clicked()//点击上一首
{
    emit begmusic();
}


void Lyrics::on_pushButton_14_clicked()
{
    if(isstop){
        ui->pushButton_14->setIcon(QIcon(":/icon/43.png"));
        emit musicopen();
        isstop=0;
    }else{
        ui->pushButton_14->setIcon(QIcon(":/icon/42.png"));
        emit musicstop();
        isstop=1;
    }
}


void Lyrics::on_pushButton_2_clicked()//最小化按钮
{
    emit setmin();
}


void Lyrics::on_pushButton_4_clicked()//关闭窗口按钮
{
    emit setclose();
}


void Lyrics::on_pushButton_3_clicked()
{
    if(ismax){
        ui->pushButton_3->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/63.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/64.png);"
            "}"
            );
        ismax=0;
        emit cancelmax();
    }else{
        ui->pushButton_3->setStyleSheet(
            "QPushButton{"
            "border-image: url(:/icon/90.png);}"
            "QPushButton:hover {"
            "border-image: url(:/icon/91.png);"
            "}"
            );
        ismax=1;
        emit widgetsetmax();
    }
}


void Lyrics::on_horizontalSlider_sliderMoved(int position)
{
    for(int i=0;i<timelist.count();i++){//更新歌词
        if(timelist[i]>=position){
            if(i==0){
                index=0;
            }else{
                index=i-1;
            }
            break;
        }
    }
    emit my_horizontalSlider_sliderMoved(position);
}


void Lyrics::on_pushButton_16_clicked()//点击声音按钮
{
    QPoint btn_16point=ui->pushButton_16->mapToGlobal(QPoint(0, 0));
    QPoint newpoint(btn_16point.x()-10,btn_16point.y()-180);
    QPoint newPosInParent = musicsound->parentWidget()->mapFromGlobal(newpoint);
    musicsound->move(newPosInParent);
    musicsound->show();
}

void Lyrics::setmusicsound(int p)
{
    emit soundchanged(p);
}

