#ifndef MUSICSOUND_H
#define MUSICSOUND_H

#include <QWidget>

namespace Ui {
class Musicsound;
}

class Musicsound : public QWidget
{
    Q_OBJECT

public:
    explicit Musicsound(QWidget *parent = nullptr);
    ~Musicsound();

private:
    Ui::Musicsound *ui;

public:
    void my_setsound(int i);//根据音量设置音量调的值

public: signals:
    void soundchanged(int p);

private slots:
    void do_valuechanged(int p);


protected:
    void leaveEvent(QEvent *event) override;//鼠标离开此界面
};

#endif // MUSICSOUND_H
