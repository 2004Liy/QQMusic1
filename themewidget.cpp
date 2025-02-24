#include "themewidget.h"
#include "ui_themewidget.h"

Themewidget::Themewidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Themewidget)
{
    ui->setupUi(this);

    timer=new QTimer(this);
    connect(timer, &QTimer::timeout,[&](){
        if(num){
            emit ui->radioButton->click();
            num=0;
        }else{
            emit ui->radioButton_2->click();
            num=1;
        }
    });

    ui->radioButton->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 6px;"
        "    height: 6px;"
        "    border-radius: 3px;"
        "    border: 2px solid gray;"
        "    background-color: white;"
        "}"
        "QRadioButton::indicator:checked {"
        "    background-color: rgb(28,201,90);"
        "    border: 2px solid rgb(28,201,90);"
        "}"
        );

    ui->radioButton_2->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 6px;"
        "    height: 6px;"
        "    border-radius: 3px;"
        "    border: 2px solid gray;"
        "    background-color: white;"
        "}"
        "QRadioButton::indicator:checked {"
        "    background-color: rgb(28,201,90);"
        "    border: 2px solid rgb(28,201,90);"
        "}"
        );

    emit ui->radioButton->click();

    timer->start(3000);
}

Themewidget::~Themewidget()
{
    delete ui;
}

void Themewidget::on_radioButton_clicked()
{
    ui->pushButton->setIcon(QIcon(":/icon/109.png"));
    ui->pushButton_2->setIcon(QIcon(":/icon/108.png"));
}


void Themewidget::on_radioButton_2_clicked()
{
    ui->pushButton->setIcon(QIcon(":/icon/108.png"));
    ui->pushButton_2->setIcon(QIcon(":/icon/107.png"));
}


void Themewidget::on_pushButton_clicked()//按第一个按钮换肤
{
    if(ui->radioButton->isChecked()){
        emit themenum1();
    }else{
        emit themenum2();
    }
}


void Themewidget::on_pushButton_2_clicked()
{
    if(ui->radioButton_2->isChecked()){
        emit themenum3();
    }else{
        emit themenum2();
    }
}


void Themewidget::on_pushButton_3_clicked()
{
    emit themenum4();
}


void Themewidget::on_pushButton_4_clicked()
{
    emit themenum5();
}


void Themewidget::on_pushButton_5_clicked()
{
    emit themenum6();
}


void Themewidget::on_pushButton_6_clicked()
{
    emit themenum7();
}


void Themewidget::on_pushButton_7_clicked()
{
    emit themenum8();
}


void Themewidget::on_pushButton_8_clicked()
{
    emit themenum9();
}


void Themewidget::on_pushButton_9_clicked()
{
    emit themenum10();
}



