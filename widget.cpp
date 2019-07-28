#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    int money{0};
    ui->Pbcoke->setEnabled((bool) false);
    ui->Pbtea->setEnabled((bool)false);
    ui->PbCoffee->setEnabled((bool)false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(double n){
    money+=n;
    ui->lcdNumber->display((double) money);

    //coffee//tea//coke
    if(money>=200){
        ui->Pbcoke->setEnabled((bool) true);
        ui->Pbtea->setEnabled((bool)true);
        ui->PbCoffee->setEnabled((bool)true);
    }

    else if(money>=150){
        ui->Pbcoke->setEnabled((bool) true);
        ui->Pbtea->setEnabled((bool)true);
        ui->PbCoffee->setEnabled((bool)true);
    }
    else if(money>=100){
        ui->Pbcoke->setEnabled( (bool)false);
        ui->Pbtea->setEnabled((bool) false);
        ui->PbCoffee->setEnabled((bool) true);
    }

    else{
        ui->Pbcoke->setEnabled((bool) false);
        ui->Pbtea->setEnabled((bool)false);
        ui->PbCoffee->setEnabled((bool)false);
    }

}

void Widget::on_pb10_clicked()
{
    Widget::changeMoney((double) 10);
}void Widget::on_pb50_clicked()
{

    Widget::changeMoney((double) 50);
}
void Widget::on_pb100_clicked()
{

    Widget::changeMoney((double) 100);
}
void Widget::on_pb500_clicked()
{

     Widget::changeMoney((double)500);
}

void Widget::on_PbCoffee_clicked()
{
    Widget::changeMoney((double) -100);
}

void Widget::on_Pbtea_clicked()
{
     Widget::changeMoney((double) -150);
}

void Widget::on_Pbcoke_clicked()
{
    Widget::changeMoney((double) -200);
}
//1. change status enable or disable
//ui->Pbcoke->setEnabled( (bool)false);
//2. reset button
//  message box to show output money
//  https://norux.me/33

void Widget::on_pushButton_clicked()
{
    double c500;
    double c100;
    double c50;
    double c10;
    char alert[0x100];
    c500=money/(double)500;
    money=((int)money%500);
    c100=money/(double)100;
    money=(int)money%100;
    c50=money/(double)50;
    money=(int)money%50;
    c10=money/(double)10;
    money=(int)money%10;
    money=0;
    sprintf(alert,"500 : %.0lf\n100 :%.0lf\n50 : %.0lf\n10 : %.0lf",c500,c100,c50,c10);
    QMessageBox msg;
    msg.information(nullptr,"Changes",alert);

}
