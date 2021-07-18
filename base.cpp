#include "base.h"

base::base(QWidget *parent) : QWidget(parent)
{
    status=false;
    checktime = new QTimer(this);
    connect(checktime, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    addwin=NULL;
    dealwin=NULL;
    log = new logwindow();
    connect(log,SIGNAL(login(int,QString)),this,SLOT(trylog(int,QString)));
    connect(log,SIGNAL(loginwinclose()),this,SLOT(loginwinclose()));
    log->show();
    log->readytolog();
    dealaddaccessManager = NULL;
    webSocket = new QWebSocket;
    webSocket->setParent(this);
    connect(webSocket,SIGNAL(textMessageReceived(const QString &)),this,SLOT(dataReceived(const QString &)));
    connect(webSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
    socketurl_T="ws://119.29.189.246:5500/chat";
    //socketurl.setUrl("ws://119.29.189.246:5500/chat");
    reconnecttimes=6;
}

void base::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==flashserverid)
    {
        qDebug()<<"timer";
        checkserver();
    }
    if(event->timerId()==reconnecttimer)
    {
        qDebug()<<reconnecttimes;
        if(reconnecttimes==-1)
        {
            qDebug()<<"ok";
            heartcheck();
            reconnecttimes=5;
            killTimer(reconnecttimer);
        }else if(reconnecttimes--)
        {
            reconnect();
        }else{
            qDebug()<<"lost";
            killTimer(reconnecttimer);
        }

    }
}

void base::handleTimeout()
{
    qDebug()<<"timeout";
    if(!backm)
    {
        lostconnect();
        killTimer(flashserverid);
    }
}


void base::slotConnected()
{
    qDebug()<<"connected";
    if(reconnecttimes==6)
    {
        reconnecttimes=5;
        heartcheck();
    }else
    {
        reconnecttimes=-1;
    }
}

void base::heartcheck()
{
    PING_PONG_status = 0;
    flashserverid=this->startTimer(30000);
}

//收到服务器消息
void base::dataReceived(const QString &message)
{
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(message.toUtf8(),&parseJsonErr);

    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug()<<tr("解析json文件错误！");
        return;
    }
    qDebug()<<message;
    QJsonObject jsonObject = document.object();

    if(jsonObject["type"].toString() == "pingpong")
    {
        if(jsonObject["data"].toString() == "pong")
        {
            PING_PONG_status = 0;
            qDebug() << "pong";
            backm = true;
            checktime->stop();
        }else
        {
            PING_PONG_status = 1;
            checkserver();
        }
    }else if(jsonObject["type"].toString()=="PRIVATE_CHAT_RECEIVE")
    {
        QJsonObject data = jsonObject["data"].toObject();
        int fa = data["fromAccount"].toInt();
        QString mess = data["message"].toString();
        qDebug()<<data["receiveTime"].toString();
        QDateTime datatime = QDateTime::fromString(data["receiveTime"].toString(),Qt::ISODateWithMs);
        int da = datatime.date().year()*10000+datatime.date().month()*100+datatime.date().day();
        int ti = datatime.time().hour()*10000+datatime.time().minute()*100+datatime.time().second();
        qDebug() << fa<<mess<<datatime;
        if(area.find(fa)!=area.end())
        {
            qDebug() << "yes";
            area.value(fa)->addchathis(0,account,fa,mess,da,ti);
        }
        myfriends.find(fa).value().lastword=mess;
        flashwin();
    }

    //backm=true;
    /*while(tcpSocket->bytesAvailable()>0)
    {
        QByteArray backinfom;
        backinfom.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(backinfom.data(),backinfom.size());
        QString msg=backinfom.data();
        else//已登录的情况
        {

            re:
            int type;
            type=msg[0].toLatin1()-'0';
            else if(type==3)//得到聊天记录
            {
                int acc,tim,dat;
                QString wo,f[4];
                int i;
                int j=0;
                for(i=1;i<msg.length();i++)
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
                    f[j]+=msg[i];
                }
                acc=f[0].toInt();
                wo=f[1];
                dat=f[2].toInt();
                tim=f[3].toInt();
                msg.remove(0,i+1);
                qDebug()<<acc<<wo<<dat<<tim;
                showchathis(acc,wo,dat,tim);
                qDebug()<<msg.length();
                if(msg.length()!=0)
                {
                    goto re;
                }
            }
            else if(type==4)//得到新消息
            {
                int acc,tim,dat;
                QString wo,f[4];
                int i;
                int j=0;
                for(i=1;i<msg.length();i++)
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
                    f[j]+=msg[i];
                }
                acc=f[0].toInt();
                wo=f[1];
                dat=f[2].toInt();
                tim=f[3].toInt();
                msg.remove(0,i+1);
                qDebug()<<acc<<wo<<dat<<tim;
                if(area.find(acc)!=area.end())
                {
                    showchathis(acc,wo,dat,tim);
                    checkread(acc);
                    wo.remove(0,1);
                    mainwindow->getnewmessage(acc,wo,0);
                }
                else
                {
                    wo.remove(0,1);
                    mainwindow->getnewmessage(acc,wo,1);
                }
                qDebug()<<msg.length();
                if(msg.length()!=0)
                {
                    goto re;
                }
            }

        }
    }*/
}

//收到登录信息返回
void base::loginDataReceived(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        qDebug() << bytes;
        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&parseJsonErr);
        if(!(parseJsonErr.error == QJsonParseError::NoError))
        {
            qDebug()<<tr("解析json文件错误！");
            return;
        }

        QJsonObject jsonObject = document.object();


        if(jsonObject["loginStatus"].toBool() && status==false)
        {
            status = true;

            log->hide();

            token = jsonObject["token"].toString();
            qDebug() << "token:" <<token ;



            account = jsonObject["account"].toInt();
            qDebug() << "account:" <<account;

            socketurl_T = socketurl_T+"?account="+QString("%1").arg(account)+"&device=1";
            socketurl.setUrl(socketurl_T);
            qDebug()<<socketurl;
            webSocket->open(socketurl);

            mainwindow = new MainWindow(account,friendapply,myfriends);
            connect(mainwindow,SIGNAL(openchatarea(int)),this,SLOT(chatarea(int)));
            connect(mainwindow,SIGNAL(readyclose()),this,SLOT(mainclose()));
            connect(mainwindow,SIGNAL(openaddwin(int)),this,SLOT(openaddwin(int)));
            connect(mainwindow,SIGNAL(opendealwin()),this,SLOT(opendealwin()));
            mainwindow->show();


            QString name = jsonObject["name"].toString();
            qDebug() << "name:" <<name;
            myname = name;

            QString words = jsonObject["word"].toString();
            qDebug() << "words:" <<words;
            mysign = words;

            mainwindow->setstart(name,words);
            //好友申请信息
            if(jsonObject.contains(QStringLiteral("applyRecords")))
            {
                int n=0;
                QJsonValue applyRecordsarrayValue = jsonObject.value(QStringLiteral("applyRecords"));
                if(applyRecordsarrayValue.isArray())
                {
                    QJsonArray applyRecordsarray = applyRecordsarrayValue.toArray();
                    qDebug() <<"[";
                    for(int i=0;i<applyRecordsarray.size();i++)
                    {
                        QJsonValue applyArray = applyRecordsarray.at(i);
                        QJsonObject apply = applyArray.toObject();
                        int account = apply["account"].toInt();
                        QString name = apply["name"].toString();
                        QString signature = apply["signature"].toString();
                        int relationship = apply["relationship"].toInt();
                        if(relationship==0)
                        {
                            n++;
                        }
                        qDebug() <<account<<","<<name <<","<<signature<<","<<relationship;
                        friendapply.insert(account,Friends(account,name,signature,"",-1,relationship));
                    }
                    qDebug() <<"]";
                    if(n>0)
                    {
                        mainwindow->setaddmessage(true);
                    }else
                    {
                        mainwindow->setaddmessage(false);
                    }
                }

            }


            //好友分组信息
            if(jsonObject.contains(QStringLiteral("groupNames")))
            {
                QJsonValue groupNamesValue = jsonObject.value(QStringLiteral("groupNames"));
                if(groupNamesValue.isArray())
                {
                    QJsonArray applyRecordsarray = groupNamesValue.toArray();
                    qDebug() <<"[";
                    for(int i=0;i<applyRecordsarray.size();i++)
                    {
                        QJsonValue groupNamesArray = applyRecordsarray.at(i);
                        QString groupname = groupNamesArray.toString();
                        qDebug() <<groupname;
                        groupsname.push_back(groupname);
                        mainwindow->setgroup(groupname,i+1);
                    }
                    qDebug() <<"]";
                }
            }

            //各分组好友信息
            if(jsonObject.contains(QStringLiteral("groups")))
            {
                QJsonValue groupsValue = jsonObject.value(QStringLiteral("groups"));
                if(groupsValue.isArray())
                {
                    QJsonArray groupsArray = groupsValue.toArray();
                    qDebug() <<"[";
                    for(int i=0;i<groupsArray.size();i++)
                    {
                        QJsonValue groupValue = groupsArray.at(i);
                        QJsonArray groupArray = groupValue.toArray();
                        qDebug() <<"[";
                        for (int j=0; j<groupArray.size() ;j++ )
                        {
                            QJsonValue groupJson = groupArray.at(j);
                            QJsonObject group = groupJson.toObject();
                            int account = group["account"].toInt();
                            QString name = group["name"].toString();
                            QString lastword = group["lastword"].toString();
                            QString signature = group["signature"].toString();
                            int groupIndex = group["groupIndex"].toInt();
                            qDebug() <<account<<","<<name <<lastword<<","<<signature<<","<<groupIndex;
                            mainwindow->setfriends(name,lastword,account,0,groupIndex);
                            myfriends.insert(account,Friends(account,name,signature,lastword,groupIndex,1));
                        }
                        qDebug() <<"]";
                    }
                    qDebug() <<"]";
                }
            }

        }else
        {
            QMessageBox::information(this,tr("登陆失败"),tr("账号或密码错误！"));
        }
    }
    else
    {
        qDebug() << "loginfinishedSlot errors here";
        qDebug( "found error .... code: %.1f\n", (double)reply->error());
        qDebug() << reply->errorString();
    }
    reply->deleteLater();
}

//收到好友搜索信息返回
void base::searchDataReceived(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        if(addwin!=NULL)
        {
            addwin->setempty();
            addwin->addtitle();
        }

        QByteArray bytes = reply->readAll();
        qDebug() << bytes;
        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&parseJsonErr);
        if(!(parseJsonErr.error == QJsonParseError::NoError))
        {
            qDebug()<<tr("解析json文件错误！");
            return;
        }


        QJsonObject jsonObject = document.object();

        if(jsonObject["searchResult"].toBool())
        {

            QString name = jsonObject["name"].toString();

            QString sign = jsonObject["word"].toString();

            int acc = jsonObject["account"].toString().toInt();

            if(addwin!=NULL)
            {
                addwin->addbuddy(acc,name,sign,false,1);
            }
        }else
        {
            if(addwin!=NULL)
            {
                addwin->addempty();
            }
        }
    }
    else
    {
        qDebug() << "searchfinishedSlot errors here";
        qDebug( "found error .... code: %.1f\n", (double)reply->error());
        qDebug() << reply->errorString();
    }
    reply->deleteLater();
}

//收到好友搜索详情返回
void base::detailDataReceived(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {

        QByteArray bytes = reply->readAll();
        qDebug() << bytes;
        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&parseJsonErr);
        if(!(parseJsonErr.error == QJsonParseError::NoError))
        {
            qDebug()<<tr("解析json文件错误！");
            return;
        }


        QJsonObject jsonObject = document.object();

        if(jsonObject["searchResult"].toBool())
        {

            QString name = jsonObject["name"].toString();

            QString sign = jsonObject["word"].toString();

            int acc = jsonObject["account"].toString().toInt();

            qDebug()<<"getback";

            addwin->showdetails(acc,name,sign);

        }
    }
    else
    {
        qDebug() << "detailfinishedSlot errors here";
        qDebug( "found error .... code: %.1f\n", (double)reply->error());
        qDebug() << reply->errorString();
    }
    reply->deleteLater();
}

//收到添加好友返回
void base::addDataReceived(QNetworkReply*reply){
    if (reply->error() == QNetworkReply::NoError)
    {

        QByteArray bytes = reply->readAll();
        qDebug() << bytes;
        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&parseJsonErr);
        if(!(parseJsonErr.error == QJsonParseError::NoError))
        {
            qDebug()<<tr("解析json文件错误！");
            return;
        }


        QJsonObject jsonObject = document.object();

        if(jsonObject["addStatus"].toBool())
        {
            addwin->addback(true);
        }else
        {
            addwin->addback(false);
        }
    }
    else
    {
        qDebug() << "addfinishedSlot errors here";
        qDebug( "found error .... code: %.1f\n", (double)reply->error());
        qDebug() << reply->errorString();
    }
    reply->deleteLater();
}

//收到处理添加好友返回
void base::dealaddDataReceived(QNetworkReply*reply){
    if (reply->error() == QNetworkReply::NoError)
    {
        dealwin->dealaddback(true);
    }
    else
    {
        dealwin->dealaddback(false);
        qDebug() << "adddealfinishedSlot errors here";
        qDebug( "found error .... code: %.1f\n", (double)reply->error());
        qDebug() << reply->errorString();
    }
    reply->deleteLater();
}

//发送登录报文
void base::trylog(int acc,QString pass)
{
    loginaccessManager = new QNetworkAccessManager(this);
    connect(loginaccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginDataReceived(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl("http://119.29.189.246:6000/login"));

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json; charset=UTF-8");
    QJsonObject test;
    test.insert("account",acc);
    test.insert("password",pass);
    test.insert("device",1);
    //仅测试
    /*test.insert("account",10000);
    test.insert("password","123456");
    test.insert("device",1);*/
    QJsonDocument tr;
    tr.setObject(test);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);
    qDebug()<<postData;

    loginaccessManager->post(request,postData);


}

//发送获取聊天记录报文
void base::getchathis(int faccount)
{
    /*QJsonObject test;
    test.insert("account",10000);
    test.insert("password","123456");
    test.insert("device",1);
    QJsonDocument tr;
    tr.setObject(test);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);
    qDebug()<<postData;*/

}

//获取好友详情信息
void base::getdetail(int acc)
{
    detailaccessManager = new QNetworkAccessManager(this);
    connect(detailaccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(detailDataReceived(QNetworkReply*)));

    QNetworkRequest request;
    QString  url="http://119.29.189.246:6000/friendship/search";

    url=url+QString("?account=%1&exatsearch=1").arg(acc);

    request.setUrl(QUrl(url));

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json; charset=UTF-8");

    request.setRawHeader(QByteArray("Authorization"),token.toUtf8());

    qDebug()<<url;
    detailaccessManager->get(request);
}

//打开聊天窗口
void base::chatarea(int a)
{
    qDebug()<<account<<"->"<<a<<"chat";
    if(area.find(a)==area.end())
    {
        qDebug()<<"o1";
        chatspace *temp= new chatspace(account,a,myfriends.find(a)->name);
        area.insert(a,temp);
        //获取聊天技记录
        getchathis(a);
        temp->show();
        connect(area.value(a),SIGNAL(myclose(int)),this,SLOT(windowclose(int)));
        connect(area.value(a),SIGNAL(sendmessage(int,QString,QDate,QTime)),this,SLOT(sendmessage(int,QString,QDate,QTime)));
    }
    else
    {
        qDebug()<<"o2";
        if(area.value(a)->isMinimized())
        {
            area.value(a)->showNormal();
        }
        area.value(a)->raise();
        area.value(a)->activateWindow();
    }
}

//聊天窗口关闭
void base::windowclose(int faccount)
{
    area.value(faccount)->close();
    area.remove(faccount);
}

//显示聊天记录
void base::showchathis(int faccount, QString words, int data,int time)
{
    if(area.find(faccount)!=area.end())
    {
        if(words[0]=='s')
        {
            words.remove(0,1);
            area.value(faccount)->addchathis(1,account,faccount,words,data,time);
        }
        else
        {
            words.remove(0,1);
            area.value(faccount)->addchathis(0,account,faccount,words,data,time);
        }
    }
}

//发送信息
void base::sendmessage(int fa,QString w,QDate da,QTime ti)
{
    QJsonObject data;
    data.insert("fromAccount",account);
    data.insert("toAccount",fa);
    data.insert("message",w);
    data.insert("device",1);
    QJsonObject mess;
    mess.insert("type","PRIVATE_CHAT_SEND");
    mess.insert("data",data);
    QJsonDocument tr;
    tr.setObject(mess);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);
    qDebug()<<postData;
    area.value(fa)->addchathis(1,account,fa,w,da.year()*10000+da.month()*100+da.day(),ti.hour()*10000+ti.minute()*100+ti.second());
    myfriends.find(fa).value().lastword=w;
    flashwin();
    webSocket->sendBinaryMessage(postData);
}

//发送已读消息
void base::checkread(int fa)
{
    int length=0;
    QString msg=QString("4%1\a%2\a\t").arg(account).arg(fa);
    qDebug()<<msg.toUtf8();
    length=tcpSocket->write(msg.toUtf8().data(),msg.toUtf8().length());
    checktime->start(10000);
    backm=false;
    if(length!=msg.length())
    {
        return;
    }
}

//发送状态更新消息
void base::checkserver()
{
    QJsonObject test;
    test.insert("type","pingpong");

    if(PING_PONG_status == 0 )
    {
        test.insert("data","ping");
    }else
    {
        test.insert("data","pong");
        PING_PONG_status = 0;
    }

    QJsonDocument tr;
    tr.setObject(test);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);

    backm = false;

    qDebug()<< postData;
    checktime->start(10000);

    webSocket->sendBinaryMessage(postData);
}

//与服务器断开连接
void base::lostconnect()
{
    qDebug()<<"服务器已断开连接";
    checktime->stop();
    reconnecttimer = this->startTimer(20000);
    reconnect();
}

void base::reconnect()
{
    webSocket->close();

    qDebug()<<"reconnect";

    webSocket->open(socketurl);
}

//打开添加好友窗口
void base::openaddwin(int acc)
{
    if(addwin==NULL)
    {
        addwin = new addwindow(acc,groupsname,friendapply,myfriends);
        connect(addwin,SIGNAL(readytoclose()),this,SLOT(addwinclose()));
        connect(addwin,SIGNAL(search(QString,bool)),this,SLOT(search(QString,bool)));
        connect(addwin,SIGNAL(getdetail(int)),this,SLOT(getdetail(int)));
        connect(addwin,SIGNAL(sendaddinfo(int,int,QString,QString)),this,SLOT(sendadd(int,int,QString,QString)));
        connect(addwin,SIGNAL(startchat(int)),this,SLOT(chatarea(int)));
        addwin->show();
    }else
    {
        if(addwin->isMinimized())
        {
            addwin->showNormal();
        }else
        {
            addwin->raise();
            addwin->activateWindow();
        }
    }
}

//关闭添加好友窗口
void base::addwinclose()
{
    addwin->close();
    delete addwin;
    addwin=NULL;
}

//关闭好友申请界面
void base::dealwinclose()
{
    dealwin->close();
    delete dealwin;
    dealwin = NULL;
}

//发送添加好友信息
void base::sendadd(int facc,int groupindex,QString fname,QString fsign)
{
    addaccessManager = new QNetworkAccessManager(this);
    connect(addaccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(addDataReceived(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl("http://119.29.189.246:6000/friendship/apply"));

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json; charset=UTF-8");
    request.setRawHeader(QByteArray("Authorization"),token.toUtf8());
    QJsonObject test;
    test.insert("account",account);
    test.insert("addAccount",facc);
    test.insert("name",myname);
    test.insert("addName",fname);
    test.insert("group",groupindex);
    test.insert("signature",mysign);
    test.insert("friendSignature",fsign);
    QJsonDocument tr;
    tr.setObject(test);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);
    qDebug()<<postData;

    addaccessManager->post(request,postData);
}

//发送好友查询报文
void base::search(QString word,bool exat)
{
    searchaccessManager = new QNetworkAccessManager(this);
    connect(searchaccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(searchDataReceived(QNetworkReply*)));

    QNetworkRequest request;
    QString  url="http://119.29.189.246:6000/friendship/search";

    url=url+"?account="+word+"&exatsearch="+(exat?"1":"0");

    request.setUrl(QUrl(url));

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json; charset=UTF-8");

    request.setRawHeader(QByteArray("Authorization"),token.toUtf8());

    qDebug()<<url;
    searchaccessManager->get(request);
}

//打开处理好友申请信息窗口
void base::opendealwin()
{
    qDebug()<<"open";
    if(dealwin==NULL)
    {
        dealwin = new dealwindow(groupsname,friendapply,myfriends);
        connect(dealwin,SIGNAL(readytoclose()),this,SLOT(dealwinclose()));
        connect(dealwin,SIGNAL(sendaddback(int,int)),this,SLOT(sendaddback(int,int)));
        connect(dealwin,SIGNAL(sendrefuseback(int)),this,SLOT(sendrefuseback(int)));
        connect(dealwin,SIGNAL(flashwin()),this,SLOT(flashwin()));
        dealwin->show();
    }else
    {
        if(dealwin->isMinimized())
        {
            dealwin->showNormal();
        }else
        {
            dealwin->raise();
            dealwin->activateWindow();
        }
    }
}

//发送好友申请同意信息
void base::sendaddback(int facc,int groupindex)
{
    if(dealaddaccessManager==NULL)
    {
        dealaddaccessManager = new QNetworkAccessManager(this);
        connect(dealaddaccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dealaddDataReceived(QNetworkReply*)));
    }

    QNetworkRequest request;
    request.setUrl(QUrl("http://119.29.189.246:6000/friendship/handle"));

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json; charset=UTF-8");
    request.setRawHeader(QByteArray("Authorization"),token.toUtf8());
    QJsonObject test;
    test.insert("account",account);
    test.insert("addAccount",facc);
    test.insert("type",1);
    QJsonObject option;
    option.insert("groupIndex",groupindex);
    test.insert("options",option);
    QJsonDocument tr;
    tr.setObject(test);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);
    qDebug()<<postData;

    dealaddaccessManager->post(request,postData);
}

//发送好友申请拒绝信息
void base::sendrefuseback(int facc)
{
    if(dealaddaccessManager==NULL)
    {
        dealaddaccessManager = new QNetworkAccessManager(this);
        connect(dealaddaccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dealaddDataReceived(QNetworkReply*)));
    }

    QNetworkRequest request;
    request.setUrl(QUrl("http://119.29.189.246:6000/friendship/handle"));

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json; charset=UTF-8");
    request.setRawHeader(QByteArray("Authorization"),token.toUtf8());
    QJsonObject test;
    test.insert("account",account);
    test.insert("addAccount",facc);
    test.insert("type",0);
    QJsonDocument tr;
    tr.setObject(test);
    QByteArray postData;
    postData = tr.toJson(QJsonDocument::Compact);
    qDebug()<<postData;
    dealaddaccessManager->post(request,postData);
}

//刷新显示
void base::flashwin()
{
    mainwindow->setclear();
    int n=0;
    for(auto i = friendapply.begin();i!=friendapply.end();i++)
    {
        if(i->relationship==0)
        {
            n++;
        }
    }
    if(n>0)
    {
        mainwindow->setaddmessage(true);
    }else
    {
        mainwindow->setaddmessage(false);
    }
    for(int i = 0; i<5 ;i++)
    {
        mainwindow->setgroup(groupsname.at(i),i+1);
    }
    for(auto i = myfriends.begin();i!=myfriends.end();i++)
    {
        mainwindow->setfriends(i->name,i->lastword,i->account,0,i->groupindex);
    }
}

//程序退出
void base::mainclose()
{
    webSocket->close();
    auto p=area.begin();
    while(p!=area.end())
    {
        p.value()->close();
        p++;
    }
    area.clear();
    mainwindow->close();
    if(addwin!=NULL)
    {
        addwin->close();
    }
    if(dealwin!=NULL)
    {
        dealwin->close();
    }

    qApp->exit();

}

//聊天窗口关闭
void base::loginwinclose()
{
    qApp->exit();
}




