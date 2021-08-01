#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QThread>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("-服务器-");
    ContentListWidget = new QListWidget;
    PortLabel = new QLabel("端口号：");
    PortLineEdit = new QLineEdit;
    CreateBtn = new  QPushButton("-开启-");
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);
    port=2314;
    PortLineEdit->setText(QString::number(port));
    PortLineEdit->setDisabled(true);
    connect(CreateBtn,SIGNAL(clicked()),this,SLOT(slotCreateServer()));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::timerEvent(QTimerEvent *event)
{
    if(flashsql)
    {
        QSqlQuery query;
        QString s= "select * from user where account=0;";
        if(query.exec(s))
        {
            //ContentListWidget->addItem(QDateTime::currentDateTime().toString(Qt::ISODate)+":数据库活动刷新！");
        }else
        {
            ContentListWidget->addItem(QDateTime::currentDateTime().toString(Qt::ISODate)+":数据库活动丢失！\n尝试再次连接...");
            mysql->trytoconnect("QODBC","localhost","Mychatserver","root","+2314Wyx");
        }
    }
    flashsql=true;
}

void MainWidget::slotCreateServer()
{
    server = new class::server(this,port);
    connect(server,SIGNAL(updataServer(QString,int,int)),this,SLOT(updataServer(QString,int,int)));
    mysql = new SQL(this);
    connect(mysql,SIGNAL(connecttomysql(int)),this,SLOT(connecttomysql(int)));
    mysql->trytoconnect("QODBC","localhost","Mychatserver","root","+2314Wyx");
    //mysql->trytoconnect("QODBC","localhost","QTMYSQL","root","+2314Wyx");
    CreateBtn->setEnabled(false);
    flashsql=true;
    this->startTimer(60000);
}

void MainWidget::connecttomysql(int type)
{
    if(type==1)
    {
        ContentListWidget->addItem(QString("数据库连接成功！"));
    }
    else
    {
        ContentListWidget->addItem(QString("数据库连接失败！"));
    }
}

void MainWidget::updataServer(QString msg,int length,int descriptor)
{
    ContentListWidget->addItem(msg+QString("-----%1").arg(descriptor));
    if(msg[0]=='Q')//用户退出
    {
        QString account="";
        ContentListWidget->addItem(msg);
        msg.remove(0,1);
        for(int i=0 ; msg[i]!="\b"; i++)
        {
            account+=msg[i];
        }
        ContentListWidget->addItem(account);
        int acc=account.toInt();
        QSqlQuery query;
        QString s= QString("UPDATE `user` SET `isLogin`=isLogin-1 WHERE (`account`='%1');").arg(acc);
        query.exec(s);
        send("0\0",descriptor);
        if(user.find(acc)!=user.end())
        {
            user.remove(acc);
        }
        ContentListWidget->addItem(QString("%1:退出！").arg(acc));
    }
    else if(msg[0]=='1')//获取昵称与签名
    {
        msg.remove(0,1);
        QString account;
        for(int j=0;j<msg.length();j++)
        {
            if(msg[j]>='0'&&msg[j]<='9')
            {
                account+=msg[j];
            }
            else
            {
                continue;
            }
        }
        ContentListWidget->addItem(account+":获取昵称和签名");
        qDebug()<<account;
        QSqlQuery query;
        QString s= QString("select name,word from user where account=%1;").arg(account);
        qDebug()<<s;
        flashsql=false;
        if(query.exec(s))
        {
            query.next();
            QString backmsg;
            QString name,word;
            name=query.value(0).toString()+'\n';
            word=query.value(1).toString();
            backmsg='1'+name+word;
            for(int i=0;i<server->tcpclientSocketlist.count();i++)
            {
                QTcpSocket *item = server->tcpclientSocketlist.at(i);
                if(item->socketDescriptor()==descriptor)
                {
                    item->write(backmsg.toUtf8().data(),backmsg.toUtf8().length());
                    qDebug()<<backmsg;
                    return;
                }
            }
        }
    }
    else if(msg[0]=='2')//获取好友
    {
        msg.remove(0,1);
        QString account;
        //得到账号
        for(int j=0;j<msg.length();j++)
        {
            if(msg[j]>='0'&&msg[j]<='9')
            {
                account+=msg[j];
            }
            else
            {
                break;
            }
        }
        ContentListWidget->addItem(account+":获取好友");
        qDebug()<<account;
        QSqlQuery query;
        QString s= QString("select friendsaccount,friendsname,friendsgroup,groupname,lastword,notAcceptWordCount from `%1` ORDER BY `friendsgroup`;").arg(account);
        qDebug()<<s;
        flashsql=false;
        if(query.exec(s))
        {
            QString backmsg;
            QString f[5];
            int isread;
            backmsg="";
            while(query.next())
            {
                for(int i=0;i<5;i++)
                {
                    f[i]="";
                }
                backmsg="";
                for(int i=0;i<5;i++)
                {
                    f[i]=query.value(i).toString()+'\a';
                }
                isread=query.value(5).toInt();
                backmsg=QString("2%1%2%3%4%5%6\a\t").arg(f[0]).arg(f[1]).arg(f[2]).arg(f[3]).arg(f[4]).arg(isread);//依次代表好友账号、好友名称、好友分组、好友分组名、最后一条消息
                send(backmsg,descriptor);
            }
            return;
        }
    }
    else if(msg[0]=='3')//获取聊天记录
    {
        msg.remove(0,1);
        int time,data;
        //time=QTime::currentTime().hour()*10000+QTime::currentTime().minute()*100+QTime::currentTime().second();
        //data=QDate::currentDate().year()*10000+QDate::currentDate().month()*100+QDate::currentDate().day();
        QString account,faccount;
        //得到账号
        int i;
        for(i=0 ; msg[i]!='\n' ; i++)
        {
            account+=msg[i];
        }
        for(++i;msg[i]!='\0'&&(msg[i]>='0'&&msg[i]<='9');i++)
        {
            faccount+=msg[i];
        }
        ContentListWidget->addItem(account+":获取"+faccount+"聊天记录");
        qDebug()<<account;
        QSqlQuery query;
        QString s;
        s= QString("UPDATE `%1` SET `notAcceptWordCount`='0' WHERE (`friendsaccount`='%2')").arg(account.toInt()).arg(faccount.toInt());
        qDebug()<<s;
        flashsql=false;
        query.exec(s);
        s= QString("SELECT friendaccount,word,`datetime` from %1chat WHERE friendaccount=%2 ORDER BY `datetime` DESC LIMIT 0, 30;").arg(account).arg(faccount);
        qDebug()<<s;
        flashsql=false;
        if(query.exec(s))
        {
            int acc;
            QString wo;
            QDateTime datatime;
            QTime tim;
            QDate dat;
            while(query.next())
            {
                acc=query.value(0).toInt();
                wo=query.value(1).toString();
                datatime=query.value(2).toDateTime();
                dat=datatime.date();
                tim=datatime.time();
                time=tim.hour()*10000+tim.minute()*100+tim.second();
                data=dat.year()*10000+dat.month()*100+dat.day();
                chathis.push_back(chatwords(acc,time,data,wo));
            }
            while(!chathis.empty())
            {
                send(chathis.last().send(),descriptor);
                chathis.pop_back();
            }
        }
    }
    else if(msg[0]=='4')//确认已读
    {
        msg.remove(0,1);
        QString m[2];
        int i,acc,facc;
        int j=0;
        for(i=0;i<msg.length();i++)
        {
            if(msg[i]=='\a')
            {
                j++;
                continue;
            }
            if(msg[i]=='\t')
            {
                break;
            }
            m[j]+=msg[i];
        }
        acc=m[0].toInt();
        facc=m[1].toInt();
        QSqlQuery query;
        QString s= QString("UPDATE `%1` SET `notAcceptWordCount`='0' WHERE (`friendsaccount`='%2')").arg(acc).arg(facc);
        qDebug()<<s;
        flashsql=false;
        query.exec(s);
    }
    else if(msg[0]=='5')//搜索好友
    {
        msg.remove(0,1);
        if(msg[0]=='a')//通过账号搜索
        {
            msg.remove(0,1);
            QString account;
            //得到账号
            for(int j=0;j<msg.length()&&msg[j]!='\b';j++)
            {
                if(msg[j]>='0'&&msg[j]<='9')
                {
                    account+=msg[j];
                }
                else
                {
                    break;
                }
            }
            ContentListWidget->addItem("账号搜索："+account);
            QSqlQuery query;
            QString s= QString("select `account`,`name`,`word`,`isLogin` from `user` where account like '\%\%%1\%\%';").arg(account);
            qDebug()<<s;
            flashsql=false;
            if(query.exec(s))
            {
                qDebug()<<"yes";
                QString backmsg;
                QString f[4];
                bool isnull=true;
                backmsg="";
                while(query.next())
                {
                    isnull=false;
                    for(int i=0;i<4;i++)
                    {
                        f[i]="";
                    }
                    backmsg="";
                    for(int i=0;i<4;i++)
                    {
                        f[i]=query.value(i).toString()+'\a';
                    }
                    qDebug()<<"yes";
                    backmsg=QString("51%1%2%3%4\b").arg(f[0]).arg(f[1]).arg(f[2]).arg(f[3]);//依次代表好友账号、好友名称、好友签名、好友在线状态
                    send(backmsg,descriptor);
                }
                if(isnull)
                {
                    backmsg="53\b";
                    send(backmsg,descriptor);
                }
                return;
            }
        }else if(msg[0]=='n')//通过昵称搜索
        {
            msg.remove(0,1);
            QString word="";
            //得到账号
            for(int j=0;j<msg.length()&&msg[j]!='\b';j++)
            {
                word+=msg[j];
            }
            ContentListWidget->addItem("昵称搜索："+word);
            QSqlQuery query;
            QString s= QString("select `account`,`name`,`word`,`isLogin` from `user` where name like '\%%1\%';").arg(word);
            qDebug()<<s;
            flashsql=false;
            if(query.exec(s))
            {
                QString backmsg;
                QString f[4];
                bool isnull=true;
                backmsg="";
                while(query.next())
                {
                    isnull=false;
                    for(int i=0;i<4;i++)
                    {
                        f[i]="";
                    }
                    backmsg="";
                    for(int i=0;i<4;i++)
                    {
                        f[i]=query.value(i).toString()+'\a';
                    }
                    backmsg=QString("52%1%2%3%4\b").arg(f[0]).arg(f[1]).arg(f[2]).arg(f[3]);//依次代表好友账号、好友名称、好友签名、好友在线状态
                    send(backmsg,descriptor);
                }
                if(isnull)
                {
                    backmsg="53\b";
                    send(backmsg,descriptor);
                }
                return;
            }
        }
    }
    else if(msg[0]=='6')//获取好友详情信息
    {
        msg.remove(0,1);
        QString account;
        //得到账号
        for(int j=0;j<msg.length()&&msg[j]!='\b';j++)
        {
            if(msg[j]>='0'&&msg[j]<='9')
            {
                account+=msg[j];
            }
            else
            {
                break;
            }
        }

    }
    else if(msg[0]=='9')//发送消息
    {
        msg.remove(0,1);
        QString m[3];
        QDateTime datetime;
        QDate date;
        QTime time;
        qDebug()<<msg;
        //得到账号
        int i;
        int j=0;
        for(i=0;i<msg.length();i++)
        {
            if(msg[i]=='\a')
            {
                j++;
                continue;
            }
            if(msg[i]=='\b')
            {
                break;
            }
            m[j]+=msg[i];
        }
        ContentListWidget->addItem(m[0]+"->"+m[1]+":"+m[2]);
        qDebug()<<m[0].toInt()<<"->"<<m[1].toInt()<<":"+m[2];
        QSqlQuery query;
        datetime=QDateTime::currentDateTime();
        date=datetime.date();
        time=datetime.time();
        QString s= QString("INSERT INTO `%1chat` (`friendaccount`, `word`, `datetime`) VALUES ('%2', '%3', '%4')").arg(m[0].toInt()).arg(m[1].toInt()).arg(m[2]).arg(datetime.toString(Qt::ISODate));
        qDebug()<<s;
        flashsql=false;
        if(query.exec(s))
        {
            qDebug()<<"secusse!";
            s = QString("UPDATE `%1` SET `lastword`='%2', `notAcceptWordCount`='0' WHERE (`friendsaccount`='%3')").arg(m[0].toInt()).arg(m[2]).arg(m[1].toInt());
            qDebug()<<s;
            flashsql=false;
            query.exec(s);
            int d,t;
            d=QDate::currentDate().year()*10000+QDate::currentDate().month()*100+QDate::currentDate().day();
            t=QTime::currentTime().hour()*10000+QTime::currentTime().minute()*100+QTime::currentTime().second();
            send(QString("4%1\a%2\a%3\a%4\a\b").arg(m[1].toInt()).arg(m[2]).arg(d).arg(t),descriptor);
            if(user.find(m[1].toInt())!=user.end())
            {
                m[2][0]='g';
                s= QString("INSERT INTO `%1chat` (`friendaccount`, `word`, `datetime`) VALUES ('%2', '%3', '%6')").arg(m[1].toInt()).arg(m[0].toInt()).arg(m[2]).arg(datetime.toString(Qt::ISODate));
                qDebug()<<s;
                flashsql=false;
                if(query.exec(s))
                {
                    s = QString("UPDATE `%1` SET `lastword`='%2', `notAcceptWordCount`=notAcceptWordCount+1 WHERE (`friendsaccount`='%3')").arg(m[1].toInt()).arg(m[2]).arg(m[0].toInt());
                    qDebug()<<s;
                    flashsql=false;
                    query.exec(s);
                    send(QString("4%1\a%2\a%3\a%4\a\b").arg(m[0].toInt()).arg(m[2]).arg(d).arg(t),user.value(m[1].toInt()));
                }
            }
            else
            {
                m[2][0]='g';
                s= QString("INSERT INTO `%1chat` (`friendaccount`, `word`, `datetime`) VALUES ('%2', '%3', '%6')").arg(m[1].toInt()).arg(m[0].toInt()).arg(m[2]).arg(datetime.toString(Qt::ISODate));
                qDebug()<<s;
                flashsql=false;
                if(query.exec(s))
                {
                    s = QString("UPDATE `%1` SET `lastword`='%2', `notAcceptWordCount`=notAcceptWordCount+1 WHERE (`friendsaccount`='%3')").arg(m[1].toInt()).arg(m[2]).arg(m[0].toInt());
                    qDebug()<<s;
                    flashsql=false;
                    query.exec(s);
                }
            }

        }
    }
    else if(msg[0]=='U')//用户登录
    {
        msg.remove(0,1);
        QString account,password;
        int i;
        for(i=0 ; msg[i]!='\n' ; i++)
        {
            account+=msg[i];
        }
        for(++i;msg[i]!='#'&&i<msg.length();i++)
        {
            password+=msg[i];
        }
        qDebug()<<account;
        qDebug()<<password;
        QSqlQuery query;
        QString s= QString("select password from user where account=%1;").arg(account);
        qDebug()<<s;
        flashsql=false;
        if(query.exec(s))
        {
            query.next();
            if(query.value(0).toString()=="")
            {
                for(int i=0;i<server->tcpclientSocketlist.count();i++)
                {
                    QTcpSocket *item = server->tcpclientSocketlist.at(i);
                    if(item->socketDescriptor()==descriptor)
                    {
                        item->write("false1",6);
                        ContentListWidget->addItem(account+":密码错误！");
                        return;
                    }
                }
            }
            else if(query.value(0).toString()==password)
            {
                for(int i=0;i<server->tcpclientSocketlist.count();i++)
                {
                    QTcpSocket *item = server->tcpclientSocketlist.at(i);
                    if(item->socketDescriptor()==descriptor)
                    {
                        item->write("OK",2);
                        ContentListWidget->addItem(account+":登录成功");
                        s= QString("UPDATE `user` SET `isLogin`=isLogin+1 WHERE (`account`='%1');").arg(account);
                        query.exec(s);
                        user.insert(account.toInt(),descriptor);
                        return;
                    }
                }
            }
            else
            {
                for(int i=0;i<server->tcpclientSocketlist.count();i++)
                {
                    QTcpSocket *item = server->tcpclientSocketlist.at(i);
                    if(item->socketDescriptor()==descriptor)
                    {
                        item->write("false2",6);
                        ContentListWidget->addItem(account+":账号错误！");
                        return;
                    }
                }
            }

        }
    }
    else if(msg[0]=='K')
    {
        msg.remove(0,1);
        QString key;
        int i;
        for(i=0 ; msg[i]!='\n' ; i++)
        {
            key+=msg[i];
        }
        for (auto i = users.begin();i!=users.end() ;i++ )
        {
            if(i.value() == key && i.key() != descriptor )
            {
                send("#OK!#\0",i.key());
                send("#OK!#\0",descriptor);
            }
        }
        users.insert(descriptor,key);

    }
    else if(msg[0]=='M')
    {
        msg.remove(0,1);
        QString key = users.find(descriptor).value();
        ContentListWidget->addItem(key);
        for (auto i = users.begin();i!=users.end() ;i++ )
        {
            if(i.value() == key && i.key() != descriptor )
            {
                send(msg,i.key());
            }
        }

    }else if(msg[0]=='E')
    {
        QString key = users.find(descriptor).value();
        for (auto i = users.begin();i!=users.end() ;i++ )
        {
            if(i.value() == key && i.key() != descriptor )
            {
                send("#Q#\0",i.key());
            }
        }
        users.erase(users.find(descriptor));

    }
    else//状态刷新
    {
        msg.remove(0,1);
        ContentListWidget->addItem(msg+":连接状态刷新");
        send("alive",descriptor);
    }
    ContentListWidget->scrollToBottom();
}

void MainWidget::send(QString backmsg,int descriptor)
{
    for(int i=0;i<server->tcpclientSocketlist.count();i++)
    {
        QTcpSocket *item = server->tcpclientSocketlist.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            item->write(backmsg.toUtf8().data(),backmsg.toUtf8().length());
            ContentListWidget->addItem(backmsg+QString("-----%1").arg(descriptor));
            qDebug()<<backmsg;
            return;
        }
    }
}

