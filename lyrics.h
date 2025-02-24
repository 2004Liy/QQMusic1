#ifndef LYRICS_H
#define LYRICS_H

#include <QWidget>
#include<QPropertyAnimation>
#include<QPainter>
#include<map>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include<QList>
#include<QLabel>
#include "musicsound.h"
using namespace std;

namespace Ui {
class Lyrics;
}

class Lyrics : public QWidget
{
    Q_OBJECT

public:
    explicit Lyrics(QWidget *parent = nullptr);
    void startRiseAnimation();
    void startFallAnimation();
    ~Lyrics();

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    void getmusic(long long id,QString name,QString author,QPixmap pix);

    void getnewtime(qint64 t);

    void getmaxvalue(qint64 t);

    void setmusicvol(int vol);

private slots:
    void on_pushButton_clicked();

    void noReplied(QNetworkReply *reply);

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_16_clicked();

    void setmusicsound(int p);

private:
    QNetworkAccessManager *manager;
    map<int,QString>ma;
    QPropertyAnimation *animation;//升起动画
    QPropertyAnimation *fallAnimation;//下落动画
    void initbutton();
    void initmap(QString s);

private:
    QList<int>timelist;
    int index=0;//记录到哪个歌词的索引
    int loop=0;//判断循环类型
    bool ismax=0;//判断窗口是否最大
    bool isstop=0;//判断是否暂停

    Musicsound *musicsound;//声音界面
    Ui::Lyrics *ui;

public:signals:
    void fallwidget();
    void thisdelete();
    void nextmusic();
    void begmusic();
    void musicstop();
    void musicopen();
    void setmin();
    void setclose();
    void cancelmax();
    void widgetsetmax();
    void my_horizontalSlider_sliderMoved(int x);
    void soundchanged(int p);
};

#endif // LYRICS_H
