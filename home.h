#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include<QLayout>
#include<QSpacerItem>
#include"homeitem1.h"
#include "homeitem2.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

public:
    Homeitem1 *homeitem1;
    Homeitem2 *homeitem2;


private:
    Ui::Home *ui;
};

#endif // HOME_H
