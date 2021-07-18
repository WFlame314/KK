#include "dealwindow.h"
#include "ui_dealwindow.h"

dealwindow::dealwindow(QVector<QString> &g,QMap<int,Friends> &a,QMap<int,Friends> &b,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dealwindow),
    groups(g),
    friendapply(a),
    myfriends(b)
{
    ui->setupUi(this);
    //窗口去边框
    setWindowFlag(Qt::FramelessWindowHint);
    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //设置窗口大小
    setFixedSize(300,400);
    setWindowTitle("好友申请");
    ui->mask->hide();
    Initmessagearea();
    InitObject();
    Initstyle();
    Initmessage();
    dealaccount = -1;
    groupindex = 1;
}

dealwindow::~dealwindow()
{
    delete ui;
}

void dealwindow::paintEvent(QPaintEvent *)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width()-10, this->height()-10);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(QColor(255,255,255,180)));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<5; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(5-i, 5-i, this->width()-(5-i)*2, this->height()-(5-i)*2);
        color.setAlpha(100 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void dealwindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos()-p);
    }
}

void dealwindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->x()<<event->y();
    if(event->button()==Qt::LeftButton)
    {
        p=event->globalPos()-frameGeometry().topLeft();
    }
}

void dealwindow::InitObject()
{
    ui->hidebtn->setFixedSize(25,25);
    ui->hidebtn->move(this->width()-55,5);
    ui->hidebtn->setText("—");
    ui->closebtn->setFixedSize(25,25);
    ui->closebtn->move(this->width()-30,5);
    ui->closebtn->setText("×");
    wi->setFixedSize(this->width()-10,this->height()-35);
    wi->move(5,30);
    ui->groupch->hide();
    ui->chacklabel->hide();
}

void dealwindow::Initstyle()
{
    ui->closebtn->setStyleSheet("QPushButton{"
                                "background-color: rgba(255,255,255,0);"
                                "font-size:20px;"
                                "font-weight: 800;"
                                "color: rgb(0,0,0);"
                                "}"
                                "QPushButton:hover{"
                                "background-color: rgba(175,0,0,0.3);"
                                "font-size:20px;"
                                "}"
                                "QPushButton:pressed{"
                                "background-color: rgba(255,0,0,0.3);"
                                "font-size:20px;"
                                "}");
    ui->hidebtn->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0);"
                               "font-size:16px;"
                               "font-weight: 800;"
                               "color: rgb(0,0,0);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(200,230,250,0.3);"
                               "font-size:16px;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(200,230,250,0.5);"
                               "font-size:16px;"
                               "}");
    wi->setStyleSheet("QListWidget{"
                      "background: rgba(200,200,200,0.1);"
                      "}");
}

void dealwindow::Initmessagearea()
{
    wi = new QListWidget(this);
    wi->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    messagearea = new addmessagelist(wi);
    QFile qss(":/styles/searchstyle.qss");
    qss.open(QFile::ReadOnly);
    messagearea->setStyleSheet(qss.readAll());
    qss.close();
    messagearea->setFixedSize(this->width()-10,this->height()-35);
    messagearea->move(0,0);
    connect(messagearea,SIGNAL(add(int)),this,SLOT(sendadd(int)));
    connect(messagearea,SIGNAL(refuseadd(int)),this,SLOT(sendrefuse(int)));
    /*connect(messagearea,SIGNAL(showdetail(int)),this,SLOT(showdetail(int)));
    connect(messagearea,SIGNAL(add(int,QString,QString)),this,SLOT(sendadd(int,QString,QString)));
    connect(messagearea,SIGNAL(startchat(int)),this,SLOT(chat(int)));*/

}

void dealwindow::sendadd(int acc)
{
    dealaccount = acc;
    ui->groupch->show();
    ui->groupch->setFixedSize(200,200);
    ui->groupch->move(this->width()/2-100,this->height()/2-100);
    for(int i = 0;i<4;i++)
    {
        switch (i) {
        case 0:
            ui->group1btn->setText(groups.at(i));
            break;
        case 1:
            ui->group2btn->setText(groups.at(i));
            break;
        case 2:
            ui->group3btn->setText(groups.at(i));
            break;
        case 3:
            ui->group4btn->setText(groups.at(i));
            break;
        default:
            break;
        }

    }

    ui->groupch->setStyleSheet("QWidget{"
                               "background: rgba(255,255,255,0.8);"
                               "border-radius: 4px;"
                               "}");
    //单选按钮设置
    {
        ui->group1btn->setFixedSize(110,30);
        ui->group1btn->setStyleSheet("QRadioButton::indicator:unchecked { "
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_unchecked.png);"
                                     "}"
                                     "QRadioButton::indicator:unchecked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton::indicator:checked {"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_checked.png);"
                                     "}"
                                     "QRadioButton::indicator:checked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton {"
                                     "font-size: 14px;"
                                     "}");
        ui->group2btn->setFixedSize(110,30);
        ui->group2btn->setStyleSheet("QRadioButton::indicator:unchecked { "
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_unchecked.png);"
                                     "}"
                                     "QRadioButton::indicator:unchecked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton::indicator:checked {"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_checked.png);"
                                     "}"
                                     "QRadioButton::indicator:checked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton {"
                                     "font-size: 14px;"
                                     "}");
        ui->group3btn->setFixedSize(110,30);
        ui->group3btn->setStyleSheet("QRadioButton::indicator:unchecked { "
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_unchecked.png);"
                                     "}"
                                     "QRadioButton::indicator:unchecked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton::indicator:checked {"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_checked.png);"
                                     "}"
                                     "QRadioButton::indicator:checked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton {"
                                     "font-size: 14px;"
                                     "}");
        ui->group4btn->setFixedSize(110,30);
        ui->group4btn->setStyleSheet("QRadioButton::indicator:unchecked { "
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_unchecked.png);"
                                     "}"
                                     "QRadioButton::indicator:unchecked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton::indicator:checked {"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_checked.png);"
                                     "}"
                                     "QRadioButton::indicator:checked:hover{"
                                     "width: 28px;"
                                     "height: 28px;"
                                     "image: url(./files/logwin/radio_hover.png);"
                                     "}"
                                     "QRadioButton {"
                                     "font-size: 14px;"
                                     "}");
    }

    ui->group1btn->move(45,7);
    ui->group2btn->move(45,43);
    ui->group3btn->move(45,79);
    ui->group4btn->move(45,115);
    ui->status->hide();
    ui->okbtn->move(10,151);
    ui->okbtn->setFixedSize(180,40);
    ui->okbtn->setStyleSheet("QPushButton{"
                             "font-size: 16px;"
                             "border-radius: 3px;"
                             "}"
                             "QPushButton:hover{"
                             "background: rgb(200,200,200);"
                             "}");
    ui->backbtn->setFixedSize(20,20);
    ui->backbtn->move(180,0);
    ui->backbtn->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0.1);"
                               "font-size:16px;"
                               "font-weight: 500;"
                               "color: rgb(255,255,255);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "}");
    ui->mask->setFixedSize(this->width(),this->height());
    ui->mask->move(0,0);
    ui->mask->show();
    ui->mask->raise();
    ui->groupch->raise();
}

void dealwindow::sendrefuse(int acc)
{
    dealaccount = acc;
    ui->groupch->show();
    ui->groupch->setFixedSize(200,200);
    ui->groupch->move(this->width()/2-100,this->height()/2-100);
    ui->groupch->setStyleSheet("QWidget{"
                               "background: rgba(255,255,255,0.8);"
                               "border-radius: 4px;"
                               "}");
    ui->group1btn->hide();
    ui->group2btn->hide();
    ui->group3btn->hide();
    ui->group4btn->hide();
    ui->status->hide();
    ui->chacklabel->show();
    ui->chacklabel->setFixedSize(100,50);
    ui->chacklabel->move(50,50);
    ui->chacklabel->setStyleSheet("QLabel{"
                                  "color: rgb(0,0,0);"
                                  "font-size: 16px;"
                                  "font-weight: 500;"
                                  "}");
    ui->okbtn->move(10,151);
    ui->okbtn->setFixedSize(180,40);
    ui->okbtn->setStyleSheet("QPushButton{"
                             "font-size: 16px;"
                             "border-radius: 3px;"
                             "}"
                             "QPushButton:hover{"
                             "background: rgb(200,200,200);"
                             "}");
    ui->okbtn->setText("确认拒绝");
    ui->backbtn->setFixedSize(20,20);
    ui->backbtn->move(180,0);
    ui->backbtn->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0.1);"
                               "font-size:16px;"
                               "font-weight: 500;"
                               "color: rgb(255,255,255);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "}");
    ui->mask->setFixedSize(this->width(),this->height());
    ui->mask->move(0,0);
    ui->mask->show();
    ui->mask->raise();
    ui->groupch->raise();
}

void dealwindow::Initmessage()
{
    int un=0,d=0;
    messagearea->clear();
    messagearea->addgroup("未处理申请");
    messagearea->addgroup("已处理申请");
    for(auto i=friendapply.begin();i!=friendapply.end();i++)
    {
        Friends temp = i.value();
        if(temp.relationship==1||temp.relationship==-1||temp.relationship==3||temp.relationship==2)
        {
            d++;
        }else
        {
            un++;
        }
        messagearea->addbuddy(temp.account,temp.name,temp.sign,temp.relationship);
    }
    if(d==0)
    {
        messagearea->addempty(1);
    }
    if(un==0)
    {
        messagearea->addempty(0);
    }
}

void dealwindow::on_closebtn_clicked()
{
    emit readytoclose();
}

void dealwindow::on_hidebtn_clicked()
{
    showMinimized();
}

void dealwindow::on_okbtn_clicked()
{
    if(ui->okbtn->text()=="确定")
    {
        ui->backbtn->hide();
        friendapply.find(dealaccount)->relationship=1;
        friendapply.find(dealaccount)->groupindex=groupindex;
        myfriends.insert(dealaccount,*(friendapply.find(dealaccount)));
        emit sendaddback(dealaccount,groupindex);
    }else if(ui->okbtn->text()=="确认拒绝")
    {
        ui->backbtn->hide();
        friendapply.find(dealaccount)->relationship=2;
        emit sendrefuseback(dealaccount);
    }
    else
    {
        ui->mask->hide();
        ui->group1btn->show();
        ui->group2btn->show();
        ui->group3btn->show();
        ui->group4btn->show();
        ui->status->hide();
        ui->okbtn->setText("确定");
        ui->groupch->hide();
    }
}

void dealwindow::dealaddback(bool status)
{
    if(status)
    {
        ui->chacklabel->hide();
        ui->group1btn->hide();
        ui->group2btn->hide();
        ui->group3btn->hide();
        ui->group4btn->hide();
        ui->status->show();
        ui->status->setFixedSize(70,70);
        ui->status->move(65,40);
        ui->status->setStyleSheet("QLabel{"
                                  "background: rgba(255,255,255,0);"
                                  "border-image:url(./files/logwin/OK.png);"
                                  "}");
        ui->okbtn->setText("返回");

    }else
    {
        ui->chacklabel->hide();
        ui->group1btn->hide();
        ui->group2btn->hide();
        ui->group3btn->hide();
        ui->group4btn->hide();
        ui->status->show();
        ui->status->setFixedSize(70,70);
        ui->status->move(65,40);
        ui->status->setStyleSheet("QLabel{"
                                  "border-image:url(./files/logwin/false.png);"
                                  "}");
        ui->okbtn->setText("返回");
    }
    Initmessage();
    emit flashwin();
}

void dealwindow::on_group1btn_clicked()
{
    groupindex=1;
}

void dealwindow::on_group2btn_clicked()
{
    groupindex=2;
}

void dealwindow::on_group3btn_clicked()
{
    groupindex=3;
}

void dealwindow::on_group4btn_clicked()
{
    groupindex=4;
}

void dealwindow::on_backbtn_clicked()
{
    ui->mask->hide();
    ui->groupch->hide();
}
