#ifndef CHATSPACE_H
#define CHATSPACE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include <QScrollBar>
#include <QKeyEvent>
#include <QEvent>
#include "chatshow.h"

namespace Ui {
class chatspace;
}

class chatspace : public QWidget
{
    Q_OBJECT

public:
    explicit chatspace(int,int,QString,QWidget *parent = nullptr);
    ~chatspace();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool eventFilter(QObject *target, QEvent *event);//事件过滤器
    void Initstyle();
    void InitObject();
    void addchathis(int,int,int,QString,int,int);

signals:
    void myclose(int);
    void sendmessage(int,QString,QDate,QTime);

private slots:

    void on_closebtn_clicked();

    void on_sendbtn_clicked();

    void on_minbtn_clicked();

    void on_closebtn2_clicked();

    void on_editmax_clicked();

private:
    Ui::chatspace *ui;
    int account,faccount;
    QPixmap bg;
    QPoint p;
    QString fname;
    chatshow *showchatarea;
    QListWidget *wi;
    QMap<QString,QString> timesmap;
    int data;
    QTime time;
    bool ismax;
};

#endif // CHATSPACE_H
