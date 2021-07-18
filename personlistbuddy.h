#ifndef PERSONLISTBUDDY_H
#define PERSONLISTBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QPainter>
#include <QDebug>

class personListBuddy : public QWidget
{
    Q_OBJECT
public:
    explicit personListBuddy(QWidget *parent = nullptr);
    void initUi();//初始化Ui
    void settips();
    void mouseDoubleClickEvent(QMouseEvent *event);
    int account;
    QWidget *head;  //头像
    QLabel *name;  //用户名
    QLabel *sign;  //个性签名
    QString headPath;//头像路径
    bool eventFilter(QObject *obj, QEvent *event);//事件过滤器
    void setread(int);
    void newmessage(QString,int);
    void setlength(int);
    void sethead(int,int);


public slots:
    void windowclose(int);


private:
    //QMap<int,chatspace *> area;

signals:
    void doubleclick(int);
};

#endif // PERSONLISTBUDDY_H
