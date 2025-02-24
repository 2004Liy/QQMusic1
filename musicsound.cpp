#include "musicsound.h"
#include "ui_musicsound.h"

Musicsound::Musicsound(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Musicsound)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置为无边框

    ui->verticalSlider->setStyleSheet(
        "QSlider::groove:vertical {"
        "    width: 4px;"
        "    background: #CCCCCC;"
        "    margin: 0 6px;"
        "    border-radius: 2px;"
        "}"
        "QSlider::handle:vertical {"
        "    background: #1cc95a;"
        "    width: 16px;"
        "    height: 16px;"
        "    margin: 0 -6px;"
        "    border-radius: 8px;"
        "    border: none;"
        "}"
        "QSlider::add-page:vertical {"
        "    background: #1cc95a;"
        "    width: 4px;"
        "    margin: 0 6px;"
        "}"
        );

    ui->verticalSlider->setMaximum(100);
    connect(ui->verticalSlider,&QSlider::valueChanged,this,&Musicsound::do_valuechanged);
}

Musicsound::~Musicsound()
{
    delete ui;

}

void Musicsound::my_setsound(int i)
{
    ui->verticalSlider->setValue(i);
}

void Musicsound::do_valuechanged(int p)
{
    emit soundchanged(p);
}

void Musicsound::leaveEvent(QEvent *event)
{
    this->hide();
    QWidget::leaveEvent(event);
}
