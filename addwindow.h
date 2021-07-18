#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include <QMessageBox>
#include "personfindlist.h"
#include "Loading.h"
#include "mytools.h"


namespace Ui {
class addwindow;
}

class addwindow : public QWidget
{
    Q_OBJECT

public:
    explicit addwindow(int,QVector<QString> &,QMap<int,Friends> &,QMap<int,Friends> &,QWidget *parent = nullptr);
    ~addwindow();
    void Initstyle();
    void InitObject();
    void Initresultarea();
    void addtitle();
    void addbuddy(int,QString,QString,bool,int);
    void addempty();
    void setempty();
    void showdetails(int acc,QString name,QString sign);
    void addback(bool);


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void startloading();
    void stoploading();

private slots:
    void on_searcbtn_clicked();

    void on_closebtn_clicked();

    void on_hidebtn_clicked();

    void showdetail(int);

    void sendadd(int,QString,QString);

    void chat(int);

    void on_hidedetailbtn_clicked();

    void on_group1btn_clicked();

    void on_group2btn_clicked();

    void on_group3btn_clicked();

    void on_group4btn_clicked();

    void on_okbtn_clicked();

    void on_backbtn_clicked();

    void on_addbtn_clicked();

signals:
    void readytoclose();
    void search(QString,bool);
    void getdetail(int);
    void sendaddinfo(int,int,QString,QString);
    void startchat(int);

private:
    Ui::addwindow *ui;
    int account;
    QString qname,qsign;
    QPixmap LOGO,colo;
    QColor bgcolor;
    QPoint p;
    personfindlist *resultarea;
    QListWidget *wi;
    int groupindex,addaccount;
    QVector<QString> &groups;
    Loading *loading;
    QMap<int,Friends> &friendapply;
    QMap<int,Friends> &myfriends;
};

#endif // ADDWINDOW_H
