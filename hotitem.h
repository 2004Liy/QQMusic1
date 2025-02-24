#ifndef HOTITEM_H
#define HOTITEM_H

#include <QWidget>
#include <random>

namespace Ui {
class Hotitem;
}

class Hotitem : public QWidget
{
    Q_OBJECT

public:
    explicit Hotitem(QWidget *parent = nullptr);
    ~Hotitem();

public:
    void changedtext(QString m_name);

    QString name;

private:
    Ui::Hotitem *ui;
};

#endif // HOTITEM_H
