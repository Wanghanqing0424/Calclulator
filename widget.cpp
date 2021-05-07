#include "widget.h"
#include "ui_widget.h"
#include "QDebug"


//B站手把手
//人工智能与自动化  王涵情
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    a.clear();
    b.clear();
    //绑定按键0与处理函数
    connect(ui->pushButton_0,&QPushButton::clicked,[=](){btn_logic(0);});
    //绑定按键1与处理函数
    connect(ui->pushButton_1,&QPushButton::clicked,[=](){btn_logic(1);});
    //绑定按键2与处理函数
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){btn_logic(2);});
    //绑定按键3与处理函数
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){btn_logic(3);});
    //绑定按键4与处理函数
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){btn_logic(4);});
    //绑定按键5与处理函数
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){btn_logic(5);});
    //绑定按键6与处理函数
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){btn_logic(6);});
    //绑定按键7与处理函数
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){btn_logic(7);});
    //绑定按键8与处理函数
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){btn_logic(8);});
    //绑定按键9与处理函数
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){btn_logic(9);});
    //绑定按键+与处理函数
    connect(ui->pushButton_jia,&QPushButton::clicked,[=](){btn_logic(0,"+");});
    //绑定按键-与处理函数
     connect(ui->pushButton_jian,&QPushButton::clicked,[=](){btn_logic(0,"-");});
    //绑定按键X与处理函数
     connect(ui->pushButton_che,&QPushButton::clicked,[=](){btn_logic(0,"X");});
    //绑定按键/与处理函数
    connect(ui->pushButton_chu,&QPushButton::clicked,[=](){btn_logic(0,"/");});
    //绑定按键=与处理函数
    connect(ui->pushButton_den,&QPushButton::clicked,[=](){btn_logic(0,"=");});
    //绑定按键%与处理函数
    connect(ui->pushButton_quyu,&QPushButton::clicked,[=](){btn_logic(0,"%");});
    //绑定按键C与处理函数
    connect(ui->pushButton_gui,&QPushButton::clicked,[=](){
      a.clear();
      b.clear();
      ui->lineEdit->setText(a);

    });

}


void Widget:: btn_logic(int x,QString i)
{
    if(i==" ")
    {
        a+=QString::number(x);
    }
    else  if(x==0)
    {
        if(i!="=")
        {
        b.insert(0,a);
        a.clear();
        b.insert(1,i);
       }
        else{
            b.insert(2,a);
            den_logic();
        }
    }



    ui->lineEdit->setText(a);
}


void Widget:: den_logic()
{
    a.clear();
    if(b.at(1)=="+")
    {

        a+=QString::number(QString(b.at(0)).toInt()+QString(b.at(2)).toInt());
    }
    else   if(b.at(1)=="-")
    {

        a+=QString::number(QString(b.at(0)).toInt()-QString(b.at(2)).toInt());
    }
    else   if(b.at(1)=="X")
    {

        a+=QString::number(QString(b.at(0)).toInt()*QString(b.at(2)).toInt());
    }
    else   if(b.at(1)=="/")
    {

        a+=QString::number(QString(b.at(0)).toInt()/QString(b.at(2)).toInt());
    }
    else   if(b.at(1)=="%")
    {

        a+=QString::number(QString(b.at(0)).toInt()%QString(b.at(2)).toInt());
    }
    ui->lineEdit->setText(a);
}
Widget::~Widget()
{
    delete ui;
}

