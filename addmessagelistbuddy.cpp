#include "addmessagelistbuddy.h"
#include <QDebug>

addmessagelistbuddy::addmessagelistbuddy(QWidget *parent) : QWidget(parent)
{
    InitObject();
}

void addmessagelistbuddy::InitObject()
{
    nametext= new QLabel(this);
    head = new QPushButton(this);
    name = new QPushButton(this);
    addbtn = new QPushButton(this);
    refusebtn = new QPushButton(this);
    sign = new QLabel(this);
    head->setFixedSize(70,70);
    name->setFixedSize(200,20);
    nametext->setFixedSize(200,20);
    sign->setFixedSize(200,20);
    addbtn->setFixedSize(45,20);
    refusebtn->setFixedSize(45,20);
    head->move(15,15);
    name->move(100,15);
    nametext->move(100,15);
    sign->move(100,37);
    addbtn->move(100,64);
    addbtn->setText("通过");
    refusebtn->move(150,64);
    refusebtn->setText("拒绝");
    head->setCursor(Qt::PointingHandCursor);
    name->setCursor(Qt::PointingHandCursor);
    addbtn->setCursor(Qt::PointingHandCursor);
    refusebtn->setCursor(Qt::PointingHandCursor);
    addbtn->hide();
    refusebtn->hide();
    connect(name,SIGNAL(clicked()),this,SLOT(showdetail()));
    connect(head,SIGNAL(clicked()),this,SLOT(showdetail()));
    connect(addbtn,SIGNAL(clicked()),this,SLOT(add()));
    connect(refusebtn,SIGNAL(clicked()),this,SLOT(refuseadd()));
}

void addmessagelistbuddy::setperson(int acc, QString tname, QString tsign,int type)
{
    account =acc;
    name->setText("");
    nametext->setText(QString("%1(%2)").arg(acc).arg(tname));
    sign->setText(tsign);
    //样式设置
    {
        QFile file(QString("./files/search/faces/%1.jpg").arg(acc));
        if(file.exists())
        {
            head->setStyleSheet(QString("QPushButton{"
                                        "border-image: url(./files/search/faces/%1.jpg);"
                                        "border-radius: 35px;"
                                        "border: none;"
                                        "}"
                                        "QPushButton:hover{"
                                        "border: 1px solid blue;"
                                        "}").arg(acc));
        }else
        {
            head->setStyleSheet("QPushButton{"
                                "border-image: url(./files/search/faces/face.png);"
                                "border-radius: 35px;"
                                "border: none;"
                                "}"
                                "QPushButton:hover{"
                                "border: 1px solid blue;"
                                "}");
        }

        sign->setStyleSheet("QLabel{"
                            "border-radius: 5px transparent;"
                            "background: rgba(0,0,0,0);"
                            "color: rgb(50,50,50);"
                            "}");
        addbtn->setStyleSheet("QPushButton{"
                              "font-size: 16px;"
                              "background: rgb(100,150,200);"
                              "border:none;"
                              "color: rgb(255,255,255);"
                              "border-radius: 3px;"
                              "}"
                              "QPushButton:hover{"
                              "background: rgb(80,150,220);"
                              "}"
                              "QPushButton:disabled{"
                              "background: rgb(200,50,50);"
                              "}");
        refusebtn->setStyleSheet("QPushButton{"
                                 "font-size: 16px;"
                                 "background: rgb(200,50,50);"
                                 "border:none;"
                                 "color: rgb(255,255,255);"
                                 "border-radius: 3px;"
                                 "}"
                                 "QPushButton:hover{"
                                 "background: rgb(220,40,30);"
                                 "}"
                                 "QPushButton:disabled{"
                                 "background: rgb(50,120,220);"
                                 "}");
        name->setStyleSheet("QPushButton{"
                            "font-size: 16px;"
                            "text-align: left;"
                            "background: rgba(175,175,175,0);"
                            "border:none;"
                            "color: rgb(0,150,100);"
                            "}");
    }

    if(type==0)
    {
        addbtn->show();
        addbtn->setFixedSize(45,20);
        addbtn->setText("通过");
        refusebtn->show();
        refusebtn->setFixedSize(45,20);
        refusebtn->setText("拒绝");
    }else if(type==-1)
    {
        refusebtn->show();
        refusebtn->setFixedSize(80,20);
        refusebtn->move(100,64);
        refusebtn->setText("正在申请");
        refusebtn->setDisabled(true);
    }else if(type==1)
    {
        refusebtn->show();
        refusebtn->setFixedSize(60,20);
        refusebtn->move(100,64);
        refusebtn->setText("已通过");
        refusebtn->setDisabled(true);
    }else if(type==2)
    {
        addbtn->show();
        addbtn->setFixedSize(60,20);
        addbtn->setText("已拒绝");
        addbtn->setDisabled(true);
    }else if(type==3)
    {
        addbtn->show();
        addbtn->setFixedSize(60,20);
        addbtn->setText("未通过");
        addbtn->setDisabled(true);
    }

}

void addmessagelistbuddy::setempty()
{
    head->hide();
    name->hide();
    addbtn->hide();
    sign->move(80,35);
    sign->setFixedSize(200,30);
    sign->setText("暂时没有该类申请！");
    sign->setStyleSheet("QLabel{"
                        "border-radius: 5px transparent;"
                        "font-size: 16px;"
                        "background: rgba(0,0,0,0);"
                        "color: rgb(50,50,50);"
                        "}");
}

void addmessagelistbuddy::showdetail()
{
    //emit Sshowdetail(account);
}

void addmessagelistbuddy::add()
{
    emit Sadd(account);
    return;
}

void addmessagelistbuddy::refuseadd()
{
    emit Srefuse(account);
}
