#include "hotitem.h"
#include "ui_hotitem.h"

Hotitem::Hotitem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Hotitem)
{
    ui->setupUi(this);

}

Hotitem::~Hotitem()
{
    delete ui;
}

void Hotitem::changedtext(QString m_name)
{
    name=m_name;
    ui->label->setText(name);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);
    int b=dis(gen);
    int s=dis(gen);
    int g=dis(gen);
    ui->label_2->setText(QString::number(b)+QString::number(s)+QString::number(g)+"万");
}
