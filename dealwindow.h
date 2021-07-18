#ifndef DEALWINDOW_H
#define DEALWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include "mytools.h"
#include "addmessagelist.h"


namespace Ui {
class dealwindow;
}

class dealwindow : public QWidget
{
    Q_OBJECT

public:
    explicit dealwindow(QVector<QString> &,QMap<int,Friends> &,QMap<int,Friends> &,QWidget *parent = nullptr);
    ~dealwindow();
    void Initstyle();
    void InitObject();
    void Initmessagearea();
    void Initmessage();
    void addmessage();
    void delmessage();
    void dealaddback(bool);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_closebtn_clicked();

    void on_hidebtn_clicked();

    void sendadd(int);

    void sendrefuse(int);

    void on_okbtn_clicked();

    void on_group1btn_clicked();

    void on_group2btn_clicked();

    void on_group3btn_clicked();

    void on_group4btn_clicked();

    void on_backbtn_clicked();

signals:
    void readytoclose();

    void sendaddback(int,int);

    void sendrefuseback(int);

    void flashwin();

private:
    Ui::dealwindow *ui;
    addmessagelist *messagearea;
    int dealaccount;
    int groupindex;
    QListWidget *wi;
    QPoint p;
    QVector<QString> &groups;
    QMap<int,Friends> &friendapply;
    QMap<int,Friends> &myfriends;
};

#endif // DEALWINDOW_H
