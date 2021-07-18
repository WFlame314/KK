#include "addwindow.h"
#include "ui_addwindow.h"

addwindow::addwindow(int acc,QVector<QString> &a,QMap<int,Friends> &b,QMap<int,Friends> &c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addwindow),
    groups(a),
    friendapply(b),
    myfriends(c)
{
    ui->setupUi(this);
    //窗口去边框
    setWindowFlag(Qt::FramelessWindowHint);
    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //设置窗口大小
    setFixedSize(300,600);
    account=acc;
    setWindowTitle("查找");
    LOGO.load("./files/logwin/images/logo.png");
    colo.load(QString("./files/search/bgimage/defbgimage.jpg"));
    //bgcolor=colo.toImage().pixelColor(qrand()%colo.width(),qrand()%colo.height());
    bgcolor=QColor(41,59,95);
    ui->mask->hide();
    loading=NULL;
    Initresultarea();
    InitObject();
    Initstyle();
}

addwindow::~addwindow()
{
    delete ui;
}

void addwindow::InitObject()
{
    ui->logo->setFixedSize(30,20);
    ui->logo->move(10,9);
    ui->searchlabel->setFixedSize(40,20);
    ui->searchlabel->move(45,9);
    ui->hidebtn->setFixedSize(25,25);
    ui->hidebtn->move(this->width()-55,5);
    ui->hidebtn->setText("—");
    ui->closebtn->setFixedSize(25,25);
    ui->closebtn->move(this->width()-30,5);
    ui->closebtn->setText("×");
    ui->hidedetailbtn->setFixedSize(25,25);
    ui->hidedetailbtn->setText("<<");
    ui->hidedetailbtn->hide();
    ui->searcedit->setFixedSize(250,30);
    ui->searcedit->move(25,55);
    ui->Exact_btn->move(200,60);
    ui->searcbtn->setFixedSize(this->width()-20,30);
    ui->searcbtn->move(10,130);
    ui->locatedbtn->setFixedSize(120,25);
    ui->locatedbtn->setText("所在地:中国,不限,不限");
    ui->sex->setFixedSize(60,25);
    ui->sexlabel->setFixedSize(35,25);
    ui->age->setFixedSize(60,25);
    ui->agelabel->setFixedSize(35,25);
    ui->locatedbtn->move(15,95);
    ui->sex->move(150,95);
    ui->age->move(225,95);
    ui->sexlabel->move(155,95);
    ui->agelabel->move(230,95);
    wi->setFixedSize(this->width()-10,this->height()-170);
    wi->move(5,165);
    ui->addbtn->hide();
    ui->bgimage->hide();
    ui->facebtn->hide();
    ui->namelabel->hide();
    ui->signlabel->hide();
    ui->line->hide();
    ui->groupch->hide();

}

void addwindow::Initstyle()
{
    ui->agelabel->setStyleSheet("QLabel{"
                                "background: rgba(255,255,255,0);"
                                "font-size:14px;"
                                "}");
    ui->sexlabel->setStyleSheet("QLabel{"
                                "background: rgba(255,255,255,0);"
                                "font-size:14px;"
                                "}");
    ui->searchlabel->setStyleSheet("QLabel{"
                                   "font-size:20px;"
                                   "font-weight: 500;"
                                   "color: rgb(255,255,255);"
                                   "}");
    ui->searcedit->setStyleSheet("QLineEdit{"
                                 "border: 1px;"
                                 "border-radius: 5px;"
                                 "font-size: 20PX;"
                                 "padding-left: 5px;"
                                 "background: rgb(255,255,255);"
                                 "font-family: inherit;"
                                 "color: black;"
                                 "}");
    ui->locatedbtn->setStyleSheet("QPushButton{"
                                  "background-color: rgb(240,240,240);"
                                  "border-radius: 3px;"
                                  "font-size:12px;"
                                  "color: black;"
                                  "}"
                                  "QPushButton:hover{"
                                  "background-color: rgb(220,220,220);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "background-color: rgb(200,200,200);"
                                  "}");
    ui->sex->setStyleSheet("QComboBox{"
                                  "background-color: rgb(240,240,240);"
                                  "border-radius: 3px;"
                                  "font-size:12px;"
                                  "color: black;"
                                  "}"
                                  "QPushButton:hover{"
                                  "background-color: rgb(220,220,220);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "background-color: rgb(200,200,200);"
                                  "}");
    ui->age->setStyleSheet("QComboBox{"
                                  "background-color: rgb(240,240,240);"
                                  "border-radius: 3px;"
                                  "font-size:12px;"
                                  "color: black;"
                                  "}"
                                  "QPushButton:hover{"
                                  "background-color: rgb(220,220,220);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "background-color: rgb(200,200,200);"
                                  "}");
    ui->searcbtn->setStyleSheet("QPushButton{"
                                "background-color: #47597E;"
                                "font-size:20px;"
                                "font-weight: 500;"
                                "color: rgb(255,255,255);"
                                "border-radius: 3px;"
                                "border: none;"
                                "}"
                                "QPushButton:hover{"
                                "background-color: rgb(179,186,206);"
                                "font-size:20px;"
                                "}"
                                "QPushButton:pressed{"
                                "background-color: rgb(179,186,206);"
                                "font-size:20px;"
                                "}");
    ui->closebtn->setStyleSheet("QPushButton{"
                                "background-color: rgba(255,255,255,0);"
                                "font-size:20px;"
                                "font-weight: 500;"
                                "color: rgb(255,255,255);"
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
    ui->hidedetailbtn->setStyleSheet("QPushButton{"
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
    ui->logo->setStyleSheet("QLabel{"
                            "border-image:url(./files/logwin/images/logo.png);"
                            "}");
    wi->setStyleSheet("QListWidget{"
                      "background: rgba(200,200,200,0.8);"
                      "}");
}

void addwindow::Initresultarea()
{
    wi = new QListWidget(this);
    wi->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    resultarea = new personfindlist(wi);
    QFile qss(":/styles/searchstyle.qss");
    qss.open(QFile::ReadOnly);
    resultarea->setStyleSheet(qss.readAll());
    qss.close();
    resultarea->setFixedSize(this->width()-10,this->height()-170);
    resultarea->move(0,0);
    connect(resultarea,SIGNAL(showdetail(int)),this,SLOT(showdetail(int)));
    connect(resultarea,SIGNAL(add(int,QString,QString)),this,SLOT(sendadd(int,QString,QString)));
    connect(resultarea,SIGNAL(startchat(int)),this,SLOT(chat(int)));
}

void addwindow::paintEvent(QPaintEvent *)
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width()-10, this->height()-10);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(bgcolor));

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

    if(this->width()>500)
    {
        QColor bgcolor = MyTools::MainColor(colo,1);
        painter.setPen(bgcolor);
        painter.setBrush(bgcolor);
        painter.drawRect(295,30,400,565);
    }

}

void addwindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos()-p);
    }
}

void addwindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->x()<<event->y();
    if(event->button()==Qt::LeftButton)
    {
        p=event->globalPos()-frameGeometry().topLeft();
    }
}

void addwindow::addtitle()
{
    resultarea->addgroup("搜索："+ui->searcedit->text()+" | "+ui->locatedbtn->text());
}

void addwindow::addbuddy(int acc, QString name, QString sign, bool onlion, int type)
{
    resultarea->addbuddy(acc,ui->searcedit->text(),name,sign,onlion,type);
}

void addwindow::addempty()
{
    resultarea->addempty();
}

void addwindow::setempty()
{
    resultarea->clear();
}

//槽函数发送获取详情信号
void addwindow::showdetail(int acc)
{
    qDebug()<<"getsignal2";
    this->setFixedSize(700,600);
    ui->hidebtn->move(this->width()-55,5);
    ui->closebtn->move(this->width()-30,5);
    ui->hidedetailbtn->move(295,5);
    ui->hidedetailbtn->show();
    startloading();
    emit getdetail(acc);
}

//显示详情
void addwindow::showdetails(int acc, QString name, QString sign)
{
    addaccount=acc;
    qname = name;
    qsign = sign;
    ui->addbtn->show();
    ui->bgimage->show();
    ui->facebtn->show();
    ui->namelabel->show();
    ui->signlabel->show();
    ui->line->show();
    QFile file(QString("./files/search/bgimage/%1_bgimage.jpg").arg(acc));
    if(file.exists())
    {
        colo.load(QString("./files/search/bgimage/%1_bgimage.jpg").arg(acc));
        ui->bgimage->setStyleSheet(QString("QLabel{"
                                           "border-image:url(./files/search/bgimage/%1_bgimage.jpg);"
                                           "}").arg(acc));
    }else
    {
        colo.load("./files/search/bgimage/defbgimage.jpg");
        ui->bgimage->setStyleSheet("QLabel{"
                                   "border-image:url(./files/search/bgimage/defbgimage.jpg);"
                                   "}");
    }
    file.close();
    ui->bgimage->setFixedSize(400,400);
    ui->bgimage->move(295,5);
    ui->facebtn->setFixedSize(70,70);
    ui->facebtn->move(350,430);
    ui->namelabel->setFixedSize(180,40);
    ui->namelabel->move(430,430);
    ui->namelabel->setText(name);
    ui->line->setFixedWidth(200);
    ui->line->move(430,470);
    ui->signlabel->setText(sign);
    ui->signlabel->setFixedSize(200,30);
    ui->signlabel->move(430,470);
    ui->addbtn->setFixedSize(300,30);
    ui->addbtn->move(345,510);
    QFile file2(QString("./files/search/faces/%1.jpg").arg(acc));
    if(file2.exists())
    {
        ui->facebtn->setStyleSheet(QString("QPushButton{"
                                           "border-image: url(./files/search/faces/%1.jpg);"
                                           "border-radius: 35px;"
                                           "border: 3px solid rgb(255,255,255);"
                                           "}"
                                           "QPushButton:hover{"
                                           "border: 4px solid rgb(255,255,255);"
                                           "}").arg(acc));
    }else
    {
        ui->facebtn->setStyleSheet("QPushButton{"
                                   "border-image: url(./files/search/faces/face.png);"
                                   "border-radius: 35px;"
                                   "border: 3px solid rgb(255,255,255);"
                                   "}"
                                   "QPushButton:hover{"
                                   "border: 4px solid rgb(255,255,255);"
                                   "}");
    }
    file2.close();
    ui->namelabel->setStyleSheet("QLabel{"
                                 "color: rgb(255,255,255);"
                                 "font-size: 32px;"
                                 "font-weight: 800;"
                                 "}");
    ui->signlabel->setStyleSheet("QLabel{"
                                 "color: rgb(255,255,255);"
                                 "font-size: 12px;"
                                 "font-weight: 300;"
                                 "}");
    ui->addbtn->setStyleSheet("QPushButton{"
                              "font-size: 24px;"
                              "background: rgba(200,200,200,0.5);"
                              "border:none;"
                              "color: rgb(0,0,0);"
                              "border-radius: 3px;"
                              "}"
                              "QPushButton:hover{"
                              "background: rgba(200,200,200,0.8);"
                              "}"
                              "QPushButton:disabled{"
                              "background: rgb(200,50,50);"
                              "}");

    if(friendapply.find(ui->searcedit->text().toInt())!=friendapply.end())
    {
        ui->addbtn->setText("正在申请...");
        ui->addbtn->setDisabled(true);
    }
    else if(myfriends.find(ui->searcedit->text().toInt())!=myfriends.end())
    {
        ui->addbtn->setDisabled(false);
        ui->addbtn->setText("发消息");
    }else
    {
        ui->addbtn->setDisabled(false);
        ui->addbtn->setText("加好友");
    }
    stoploading();
    this->update();

}

void addwindow::sendadd(int acc,QString name,QString sign)
{
    addaccount=acc;
    qname = name;
    qsign = sign;
    groupindex=1;
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

void addwindow::addback(bool status)
{
    if(status)
    {
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
}

void addwindow::on_searcbtn_clicked()
{

    if(friendapply.find(ui->searcedit->text().toInt())!=friendapply.end())
    {
        Friends temp = friendapply.value(ui->searcedit->text().toInt());
        setempty();
        addtitle();
        addbuddy(temp.account,temp.name,temp.sign,false,3);
    }
    else if(myfriends.find(ui->searcedit->text().toInt())!=myfriends.end())
    {
        Friends temp =myfriends.value(ui->searcedit->text().toInt());
        setempty();
        addtitle();
        addbuddy(temp.account,temp.name,temp.sign,false,4);
    }else
    {
        emit search(ui->searcedit->text(),ui->Exact_btn->isChecked());
        return;
    }

}

//关闭窗口
void addwindow::on_closebtn_clicked()
{
    emit readytoclose();
}

//最小化
void addwindow::on_hidebtn_clicked()
{
    showMinimized();
}

void addwindow::chat(int acc)
{
    emit startchat(acc);
}

void addwindow::on_hidedetailbtn_clicked()
{
    ui->line->hide();
    ui->addbtn->hide();
    ui->bgimage->hide();
    ui->facebtn->hide();
    ui->namelabel->hide();
    ui->signlabel->hide();
    this->setFixedSize(300,600);
    ui->hidebtn->move(this->width()-55,5);
    ui->closebtn->move(this->width()-30,5);
    ui->hidedetailbtn->hide();
    stoploading();
}

//加载动画
void addwindow::startloading()
{
    if(loading!=NULL)
    {
        delete loading;
        loading = NULL;
    }
    loading=new Loading(this);
    loading->setDotColor(Qt::gray);
    loading->move(460,260);
    loading->setFixedSize(80,80);
    loading->setDotCount(10);
    loading->setMaxDiameter(13);
    loading->setMinDiameter(5);
    loading->start();
    loading->show();
}

void addwindow::stoploading()
{
    delete loading;
    loading=NULL;
}

void addwindow::on_group1btn_clicked()
{
    groupindex=1;
}

void addwindow::on_group2btn_clicked()
{
    groupindex=2;
}

void addwindow::on_group3btn_clicked()
{
    groupindex=3;
}

void addwindow::on_group4btn_clicked()
{
    groupindex=4;
}

void addwindow::on_okbtn_clicked()
{
    ui->mask->hide();
    if(ui->okbtn->text()=="确定")
    {
        ui->backbtn->hide();
        emit sendaddinfo(addaccount,groupindex,qname,qsign);
    }else
    {
        ui->group1btn->show();
        ui->group2btn->show();
        ui->group3btn->show();
        ui->group4btn->show();
        ui->status->hide();
        ui->okbtn->setText("确定");
        ui->groupch->hide();
    }

}

void addwindow::on_backbtn_clicked()
{
    ui->mask->hide();
    ui->groupch->hide();
}

void addwindow::on_addbtn_clicked()
{
    if(ui->addbtn->text()=="加好友")
    {
        sendadd(addaccount,qname,qsign);
    }else if(ui->addbtn->text()=="发消息")
    {
        emit startchat(addaccount);
    }

}
