#ifndef MUSCI_H
#define MUSCI_H

#include <QWidget>
#include<QListWidget>
#include<QLayout>

class Musci : public QWidget
{
    Q_OBJECT
public:
    explicit Musci(QWidget *parent = nullptr);

public:
    QListWidget *listwidget;

signals:
};

#endif // MUSCI_H
