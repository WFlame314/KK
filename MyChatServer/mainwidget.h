#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QTimerEvent>
#include <QVector>
#include "server.h"
#include "sql.h"
#include "chatwords.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void send(QString,int);
    void sendface(QString,int);
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWidget *ui;
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;
    int port;
    server *server;
    SQL *mysql;
    QString Filepath;
    QFile file;
    QVector<chatwords> chathis;
    QMap<int,int> user;
    QMap<int,QString>users;
    bool flashsql;

public slots:
    void slotCreateServer();
    void connecttomysql(int);
    void updataServer(QString,int,int);
};
#endif // MAINWIDGET_H
