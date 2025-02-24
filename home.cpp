#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout *layout=new QVBoxLayout(ui->widget);
    layout->setContentsMargins(0, 0, 0, 0);
    homeitem1=new Homeitem1(ui->widget);
    layout->addWidget(homeitem1);

    homeitem2=new Homeitem2(ui->widget);
    layout->addWidget(homeitem2);

    QSpacerItem *spacer =new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addSpacerItem(spacer);

}

Home::~Home()
{
    delete ui;
}
