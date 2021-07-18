#ifndef BASE_H
#define BASE_H

#include <QWidget>
#include <QApplication>
#include <QEvent>
#include <QTcpSocket>
#include <QWebSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QHostInfo>
#include <QFile>
#include <QPainter>
#include <QMouseEvent>
#include <QRegExpValidator>
#include <QDebug>
#include <QTimerEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "logwindow.h"
#include "mainwindow.h"
#include "chatspace.h"
#include "addwindow.h"
#include "dealwindow.h"

class base : public QWidget
{
    Q_OBJECT
public:
    explicit base(QWidget *parent = nullptr);
    void mgetready(int);
    void getchathis(int);
    void showchathis(int,QString,int,int);
    void checkread(int);
    void timerEvent(QTimerEvent *event);
    void checkserver();
    void lostconnect();
    void heartcheck();
    void reconnect();

private:
    QString token,socketurl_T;
    QUrl socketurl;
    int PING_PONG_status;
    logwindow *log;//登录窗口
    MainWindow *mainwindow;//主窗口
    addwindow *addwin;//添加好友窗口
    dealwindow *dealwin;//处理好友申请信息窗口
    bool status,backm;
    int account;
    QString myname,mysign;
    int flashserverid,flashstatusid,reconnecttimer,reconnecttimes;
    QHostAddress *ServerIP,SelfIP;
    QTcpSocket *tcpSocket;
    QWebSocket *webSocket;
    QString localHostName;
    QHostInfo info;
    QMap<int,chatspace *> area;
    QMap<int,Friends> friendapply;
    QMap<int,Friends> myfriends;
    QVector<QString> groupsname;
    QTimer *checktime;
    QNetworkAccessManager *loginaccessManager;
    QNetworkAccessManager *searchaccessManager;
    QNetworkAccessManager *detailaccessManager;
    QNetworkAccessManager *addaccessManager;
    QNetworkAccessManager *dealaddaccessManager;


public slots:
    void slotConnected();
    void dataReceived(const QString &message);
    void loginDataReceived(QNetworkReply *reply);
    void searchDataReceived(QNetworkReply *reply);
    void detailDataReceived(QNetworkReply *reply);
    void addDataReceived(QNetworkReply *reply);
    void dealaddDataReceived(QNetworkReply *reply);
    void flashwin();
    void trylog(int,QString);
    void chatarea(int);
    void windowclose(int);//主界面关闭
    void loginwinclose();//登录界面关闭
    void sendmessage(int,QString,QDate,QTime);
    void mainclose();
    void handleTimeout();
    void openaddwin(int);
    void opendealwin();
    void addwinclose();//添加好友界面关闭
    void dealwinclose();//好友申请界面关闭
    void search(QString,bool);//搜索好友
    void getdetail(int);
    void sendadd(int,int,QString,QString);
    void sendaddback(int,int);
    void sendrefuseback(int);


signals:

};

#endif // BASE_H
