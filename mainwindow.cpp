#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int taccount,QMap<int,Friends> &b,QMap<int,Friends> &c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    friendapply(b),
    myfriends(c)
{
    ui->setupUi(this);
    //窗口去边框
    //setWindowFlag(Qt::FramelessWindowHint,true);
    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //设置窗口大小
    setFixedSize(400,800);
    //置顶且去边框
    setWindowFlags(Qt::WindowStaysOnTopHint |Qt::FramelessWindowHint |Qt::Tool);
    setWindowTitle("KK3.2");
    account=taccount;
    hidetype=-1;
    showtype=-1;
    bg.load(QString("./files/%1/images/bg-def.jpg").arg(account));
    LOGO.load(QString("./files/logwin/images/logo.png"));
    face.load(QString("./files/%1/faces/%2.jpg").arg(account).arg(account));
    //face.load(":/bg/image/face.png");

    //托盘图标
    {
        QIcon icon = QIcon("./files/logwin/images/logoico.png");
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(icon);
        trayIcon->setToolTip(QString("KK:%1(%2)\n状态:在线").arg(ui->name->text()).arg(account));
        trayIcon->show();
        connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    }

    //托盘右键菜单
    {
        openAction = new QAction("打开主面板", this);
        connect(openAction, SIGNAL(triggered()), this, SLOT(myshowNormal()));
        quitAction = new QAction("退出", this);
        connect(quitAction, SIGNAL(triggered()), this, SLOT(on_closebtn_clicked()));
        trayIconMenu = new QMenu(this);
        trayIconMenu->addAction(openAction);
        trayIconMenu->addSeparator();
        trayIconMenu->addAction(quitAction);
        trayIcon->setContextMenu(trayIconMenu);
    }


    //屏幕边缘隐藏
    showwin = new QTimer(this);
    connect(showwin, SIGNAL(timeout()), this, SLOT(showTimeout()));
    hidewin = new QTimer(this);
    connect(hidewin, SIGNAL(timeout()), this, SLOT(hideTimeout()));


    QDesktopWidget* desktopWidget =QApplication::desktop();
    deskRect =desktopWidget->availableGeometry();
    theight=this->height();


    Initfriends();
    InitObject();
    Initstyle();
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:

    case QSystemTrayIcon::DoubleClick:
        if(showtype>=0)
        {
            if(showtype==0)
            {
                qDebug()<<"showleft";
                showwin->start(2);

            }else if(showtype==1)
            {
                qDebug()<<"showtop";
                showwin->start(2);
            }
        }
        if(this->isHidden())
        {
            this->show();
        }
        break;
    default:
        break;
    }
}

void MainWindow::myshowNormal()
{
    if(showtype>=0)
    {
        if(showtype==0)
        {
            qDebug()<<"showleft";
            showwin->start(2);

        }else if(showtype==1)
        {
            qDebug()<<"showtop";
            showwin->start(2);
        }
    }
    if(this->isHidden())
    {
        this->show();
    }
}

void MainWindow::InitObject()
{
    ui->closebtn->setFixedSize(30,30);
    ui->closebtn->setText("×");
    ui->closebtn->move(this->width()-30,0);
    ui->hidebtn->setFixedSize(30,30);
    ui->hidebtn->setText("—");
    ui->hidebtn->move(this->width()-60,0);
    ui->logo->setText("");
    ui->logo->setFixedSize(45,30);
    ui->logo->move(5,4);
    ui->facebtn->setFixedSize(80,80);
    ui->facebtn->setText("");
    ui->facebtn->move(10,50);
    ui->name->move(100,60);
    ui->tag->move(98,90);
    ui->tag->setFixedSize(this->width()-150,25);
    ui->search->move(0,140);
    ui->search->setFixedSize(this->width(),35);
    ui->search->setText("🔍搜索");
    ui->search->setReadOnly(true);
    wi->setFixedSize(this->width(),this->height()-215);
    wi->move(0,175);
    person->setFixedSize(this->width(),this->height()-215);
    person->move(0,0);
    ui->mask->setFixedSize(this->width(),40);
    ui->mask->move(0,this->height()-40);
    ui->menubtn->setFixedSize(30,30);
    ui->menubtn->move(5,this->height()-35);
    ui->addbtn->setFixedSize(30,30);
    ui->addbtn->move(40,this->height()-35);
    ui->menubtn->setToolTip("菜单");
    ui->addbtn->setToolTip("加好友");
    ui->addmessagebtn->setFixedSize(30,30);
    ui->addmessagebtn->move(75,this->height()-35);
    ui->addmessagebtn->setToolTip("无好友申请");

}

void MainWindow::Initstyle()
{
    ui->closebtn->setStyleSheet("QPushButton{"
                                "background-color: rgba(255,255,255,0);"
                                "font-size:20px;"
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
                               "background-color: rgba(255,255,255,0);"
                               "font-size:16px;"
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
    ui->facebtn->setStyleSheet(QString("QPushButton{"
                                       "border-image: url(./files/%1/faces/%2.jpg);"
                                       "border-radius: 40px transparent;"
                                       "}"
                                       "QPushButton:hover{"
                                       "border: 3px solid rgba(255,255,255,0.5);"
                                       "}").arg(account).arg(account));
    ui->tag->setStyleSheet("QLineEdit{"
                           "background-color: rgba(255,255,255,0);"
                           "color: rgb(255,255,255);"
                           "border: 0;"
                           "font-size: 15px;"
                           "font-weight:300;"
                           "}"
                           "QLineEdit:hover{"
                           "border: 1px solid rgba(0,0,0,0.5);"
                           "}");
    ui->name->setStyleSheet("QLabel{"
                            "color: rgb(255,255,255);"
                            "font-size: 16px;"
                            "font-weight: 500;"
                            "}");
    ui->search->setStyleSheet("QLineEdit{"
                              "background-color: rgba(255,255,255,0.3);"
                              "color: rgb(255,255,255);"
                              "border: 0;"
                              "font-size: 15px;"
                              "border-left: 15px solid rgba(255,255,255,0);"
                              "}");
    //ui->chatfriendarea->viewport()->setStyleSheet("background: rgba(255,255,255,0.5);");
    wi->setStyleSheet("QListWidget{"
                      "background: rgba(255,255,255,0.5);"
                      "}");
    ui->mask->setStyleSheet("QLineEdit{"
                            "background-color: rgba(255,255,255,0.7);"
                            "font-size: 16px;"
                            "font-weight: 600;"
                            "border: 1px 0px 0px 0px solid gray;"
                            "}");
    ui->menubtn->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0);"
                               "font-size:16px;"
                               "border-image: url(./files/logwin/images/menu.png);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}");
    ui->addbtn->setStyleSheet("QPushButton{"
                              "background-color: rgba(255,255,255,0);"
                              "font-size:16px;"
                              "border-image: url(./files/logwin/images/addbtn.png);"
                              "}"
                              "QPushButton:hover{"
                              "background-color: rgba(255,255,255,0.3);"
                              "font-size:16px;"
                              "border-radius: 5px;"
                              "border:1px solid gray;"
                              "}"
                              "QPushButton:pressed{"
                              "background-color: rgba(255,255,255,0.5);"
                              "font-size:16px;"
                              "border-radius: 5px;"
                              "border:1px solid gray;"
                              "}");
    ui->addmessagebtn->setStyleSheet("QPushButton{"
                                     "background-color: rgba(255,255,255,0);"
                                     "font-size:16px;"
                                     "border-image: url(./files/logwin/images/addmessage_none.png);"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgba(255,255,255,0.3);"
                                     "font-size:16px;"
                                     "border-radius: 5px;"
                                     "border:1px solid gray;"
                                     "}"
                                     "QPushButton:pressed{"
                                     "background-color: rgba(255,255,255,0.5);"
                                     "font-size:16px;"
                                     "border-radius: 5px;"
                                     "border:1px solid gray;"
                                     "}");
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter pain;
    pain.begin(this);
    pain.drawPixmap(0,0,width(),height(),bg);
    pain.end();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        if(hidetype>=0)
        {
            if(event->globalY()<5)
            {
                move(event->globalX()-p.x(),0);
            }
            else if(event->globalX()<5)
            {
                move(0,0);
            }
            else
            {
                hidetype=-1;
                this->setFixedSize(this->width(),theight);
                wi->setFixedSize(this->width(),this->height()-215);
                person->setFixedSize(this->width(),this->height()-215);
                ui->mask->move(0,this->height()-40);
                ui->menubtn->move(5,this->height()-35);
                ui->addbtn->move(40,this->height()-35);
                p=event->globalPos()-frameGeometry().topLeft();
            }
        }else
        {
            move(event->globalPos()-p);
            if(event->globalX()==0)
            {

                qDebug()<<"left";
                hidetype=0;
                this->setFixedSize(this->width(),deskRect.height());
                wi->setFixedSize(this->width(),this->height()-215);
                person->setFixedSize(this->width(),this->height()-215);
                ui->mask->move(0,this->height()-40);
                ui->menubtn->move(5,this->height()-35);
                ui->addbtn->move(40,this->height()-35);
            }else if(event->globalY()==0)
            {
                qDebug()<<"top";
                hidetype=1;
            }
        }

    }
}

void MainWindow::leaveEvent(QEvent *)
{
    if(hidetype>=0)
    {
        if(hidetype==0)
        {
            qDebug()<<"hideleft";
            hidewin->start(2);
        }else if(hidetype==1)
        {
            qDebug()<<"hidetop";
            hidewin->start(2);
        }
    }
}

void MainWindow::enterEvent(QEvent *)
{
    if(showtype>=0)
    {
        if(showtype==0)
        {
            qDebug()<<"showleft";
            showwin->start(2);

        }else if(showtype==1)
        {
            qDebug()<<"showtop";
            showwin->start(2);
        }
    }
}

void MainWindow::showTimeout()
{
    if(showtype==0)
    {
        if(this->x()>=0)
        {
            showwin->stop();
            this->move(0,0);
            showtype=-1;
            hidetype=0;
        }else
        {
            this->move(this->x()+5,0);
        }
    }
    else if(showtype == 1)
    {
        if(this->y() >= 0)
        {
            showwin->stop();
            this->move(this->x(),0);
            showtype=-1;
            hidetype=1;
        }
        else
        {
            this->move(this->x(),this->y()+5);
        }
    }
}

void MainWindow::hideTimeout()
{
    if(hidetype==0)
    {
        if(this->x()<(this->width()*-1)+6)
        {
            hidewin->stop();
            qDebug()<<"kill";
            hidetype=-1;
            showtype=0;
            this->move(0-this->width()+1,0);
        }else
        {
            this->move(this->x()-5,0);
        }
    }else if(hidetype==1)
    {
        if(this->y()<=(this->height()*-1)+6)
        {
            hidewin->stop();
            qDebug()<<"kill";
            hidetype=-1;
            showtype=1;
            this->move(this->x(),0-this->height()+1);
        }else
        {
            this->move(this->x(),this->y()-5);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->x()<<event->y();
    if(event->button()==Qt::LeftButton)
    {
        p=event->globalPos()-frameGeometry().topLeft();
    }
}

void MainWindow::setclear()
{
    person->clear();
}

//关闭程序
void MainWindow::on_closebtn_clicked()
{
    delete trayIcon;
    emit readyclose();
}

//最小化到托盘
void MainWindow::on_hidebtn_clicked()
{
    this->hide();
    //showMinimized();
}

//初始化好友列表控件
void MainWindow::Initfriends()
{
    wi = new QListWidget(this);
    wi->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    person = new personList(account,wi);
    QFile qss(":/styles/buty.qss");
    qss.open(QFile::ReadOnly);
    person->setStyleSheet(qss.readAll());
    qss.close();
    connect(person,SIGNAL(openchat(int)),this,SLOT(startchat(int)));
}

void MainWindow::setaddmessage(bool status)
{
    if(status)
    {
        ui->addmessagebtn->setFixedSize(30,30);
        ui->addmessagebtn->move(75,this->height()-35);
        ui->addmessagebtn->setToolTip(QString("%1条好友申请").arg(friendapply.size()));
        ui->addmessagebtn->setStyleSheet("QPushButton{"
                                         "background-color: rgba(255,255,255,0);"
                                         "font-size:16px;"
                                         "border-image: url(./files/logwin/images/addmessage_have.png);"
                                         "}"
                                         "QPushButton:hover{"
                                         "background-color: rgba(255,255,255,0.3);"
                                         "font-size:16px;"
                                         "border-radius: 5px;"
                                         "border:1px solid gray;"
                                         "}"
                                         "QPushButton:pressed{"
                                         "background-color: rgba(255,255,255,0.5);"
                                         "font-size:16px;"
                                         "border-radius: 5px;"
                                         "border:1px solid gray;"
                                         "}");
    }else
    {
        ui->addmessagebtn->setFixedSize(30,30);
        ui->addmessagebtn->move(75,this->height()-35);
        ui->addmessagebtn->setToolTip("无好友申请");
        ui->addmessagebtn->setStyleSheet("QPushButton{"
                                         "background-color: rgba(255,255,255,0);"
                                         "font-size:16px;"
                                         "border-image: url(./files/logwin/images/addmessage_none.png);"
                                         "}"
                                         "QPushButton:hover{"
                                         "background-color: rgba(255,255,255,0.3);"
                                         "font-size:16px;"
                                         "border-radius: 5px;"
                                         "border:1px solid gray;"
                                         "}"
                                         "QPushButton:pressed{"
                                         "background-color: rgba(255,255,255,0.5);"
                                         "font-size:16px;"
                                         "border-radius: 5px;"
                                         "border:1px solid gray;"
                                         "}");
    }
}

void MainWindow::startchat(int a)
{
    qDebug()<<"Mainwindow"<<a;
    emit openchatarea(a);
}

void MainWindow::setfriends(QString name ,QString sign,int facc,int isread,int index)
{
    person->AddFriend(name,sign,account,facc,isread,index);
}

void MainWindow::setgroup(QString groupname,int index)
{
    static int groupn=0;
    person->AddGroup(groupname,index);
    groupn++;
}

void MainWindow::setstart(QString name, QString sign)
{
    ui->name->setFixedSize(name.length()*19,30);
    ui->name->setText(name);
    ui->tag->setText(sign);
}

void MainWindow::getnewmessage(int facc, QString wo, int isread)
{
    person->newmessage(facc,wo.toUtf8(),isread);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addbtn_clicked()
{
    emit openaddwin(account);
}

void MainWindow::on_addmessagebtn_clicked()
{
    emit opendealwin();
}
