#ifndef HOSTWIDGET_H
#define HOSTWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QListWidget>
#include<QLayout>
#include<QListWidgetItem>
#include "hotitem.h"

class HostWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HostWidget(QWidget *parent = nullptr);

private slots:
    void do_itemClicked(QListWidgetItem *item);

private:
    void initlistwidget();

public:
    QLabel *label;
    QListWidget *listwidget;

    QStringList namelist;

public: signals:
    void search(QString name);

signals:
};

#endif // HOSTWIDGET_H
