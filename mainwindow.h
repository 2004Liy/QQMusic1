#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QAction>
#include<QToolButton>
#include<QMouseEvent>
#include<QPoint>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QDebug>
#include<QListWidgetItem>
#include<QTimer>
#include<vector>
#include<string>
#include<time.h>
#include"curmusic.h"
#include "musicsound.h"
#include "audittion.h"
#include "mylove.h"
#include "itemmusic.h"
#include "lately.h"
#include "hostwidget.h"
#include "mysearchwidget.h"
#include "lyrics.h"
#include "themewidget.h"
#include "linkqsl.h"
#include "home.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    void changestate();//改变按钮状态

private slots:
    void changeactiocn();//当鼠标掠过时改变收索按钮图片


    void on_pushButton_4_clicked();

    void do_sourceChanged(const QUrl &media);//当前播放的歌发生变化

    void do_durationChanged(qint64 duration);//当前歌的总长度变化

    void do_positionChanged(qint64 position);//播放到不同位置

    void do_mediaStatusChanged(QMediaPlayer::MediaStatus status);//当前歌播放完了

    void on_pushButton_14_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_16_clicked();

    void setmusicsound(int p);//改变音量

    void noReplied(QNetworkReply *reply);//当接收到数据

    void nopixsReplied(QNetworkReply *reply);

    void startopenmusic(long long id,QString m_name,QString m_author,QString m_album,int m_fee,bool islove);//当收到点击歌曲item的信号

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void do_openmusicwidget(int p);//更新当前放歌的窗口

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_selectionChanged();

    void on_lineEdit_editingFinished();

    void do_triggered();//点击搜索按钮

    void do_search(QString name);//当点击热歌榜中的歌时

    void on_pushButton_2_clicked();

    void onImageDownloaded();

    void on_pushButton_19_clicked();

    void do_lyrics();//显示下落动画

    void deletelyrics();//清除歌词界面

    void do_musicopen();

    void do_musicstop();

    void do_widgetsetmax();

    void do_cancelmax();

    void do_lyricssoundchanged(int p);

    void on_pushButton_21_clicked();

    void on_pushButton_11_clicked();

protected:
    void mouseMoveEvent(QMouseEvent *event)override;//鼠标移动
    void mousePressEvent(QMouseEvent *event) override;//鼠标点击事件

    void paintEvent(QPaintEvent *event)override;

private:

private:
    int themenum=0;//拥于判断要换哪个背景

    qint64 curmusictime;
    QPixmap musicpix=QPixmap(":/icon/130.png");//歌曲的图片
    QNetworkAccessManager *musicmanager;
    QNetworkReply *reply1;

    vector<string>m_widgetlist;//记录按返回按钮后要出现的界面
    QNetworkAccessManager *manager;
    QNetworkAccessManager *pixsmanager;
    QMediaPlayer *mediaplayer;
    QAction *searchact;
    bool ishovered=0;//记录鼠标是否在收索按钮上
    bool havesound=1;//判断是否有声音
    int loop=0;//0是顺序播放，1是随机播放，3是单曲循环
    bool ispause=1;//暂停为1，播放为0
    bool ismax=0;//记录窗口是否全屏
    CurMusic curmusic;//当前播放的歌的信息
    Musicsound *musicsound=NULL;//调节音量界面

    QWidget *curwidget=NULL;//指向当前widget_3中的界面
    QWidget *musicwidget=NULL;//指向正在放歌的页面
    MySearchWidget *mysearch=NULL;//搜索界面
    Lyrics *lyrics=NULL;//歌词界面
    Themewidget *theme=NULL;//换肤界面
    Audittion *audittion=NULL;//试听列表界面
    MyLove *mylove=NULL;
    Lately *lately=NULL;

    LinkQSL mysql;

    Home *home=NULL;//home界面

    HostWidget *hostwidget=NULL;
    Ui::MainWindow *ui;
        //vector<int>w;
};
#endif // MAINWINDOW_H
