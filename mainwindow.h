#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QDesktopWidget>
#include <QTimerEvent>
#include <QTimer>
#include <QSystemTrayIcon>
#include "personlist.h"
#include "mytools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(int,QMap<int,Friends> &b,QMap<int,Friends> &c,QWidget *parent = nullptr);
    ~MainWindow();
    void Initstyle();
    void InitObject();
    void setstart(QString,QString);
    void setfriends(QString,QString,int,int,int);
    void setgroup(QString,int);
    void getnewmessage(int,QString,int);
    void setaddmessage(bool);
    void setclear();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *);
    void enterEvent(QEvent *);
    void Initfriends();


private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void on_closebtn_clicked();

    void on_hidebtn_clicked();

    void myshowNormal();

    void startchat(int);

    void showTimeout();

    void hideTimeout();

    void on_addbtn_clicked();

    void on_addmessagebtn_clicked();

signals:
    void getfriends();
    void openchatarea(int);
    void readyclose();
    void openaddwin(int);
    void opendealwin();


private:
    int account;
    int hidetype,showtype;
    int theight;
    QRect deskRect;
    QTimer *showwin,*hidewin;
    Ui::MainWindow *ui;
    QPixmap bg,LOGO,face;
    QPoint p;
    personList *person;
    QListWidget *wi;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *openAction;
    QAction *quitAction;
    QMap<int,Friends> &friendapply;
    QMap<int,Friends> &myfriends;

};

#endif // MAINWINDOW_H
