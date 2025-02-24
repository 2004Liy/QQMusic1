#ifndef ITEMMUSIC_H
#define ITEMMUSIC_H

#include <QWidget>

namespace Ui {
class Itemmusic;
}

class Itemmusic : public QWidget
{
    Q_OBJECT

public:
    explicit Itemmusic(QWidget *parent = nullptr);
    ~Itemmusic();

public:
    long long id;
    QString name;
    QString author;//作者
    QString album;//专辑
    int fee;//判断是否要会员
    bool islove=0;//判断是否在喜欢列表

public:
    void setinit(long long m_id,QString m_name,QString m_author,QString m_album,int m_fee,bool love);
    void changedlove();
    void changedunlove();

private:
    Ui::Itemmusic *ui;

};

#endif // ITEMMUSIC_H
