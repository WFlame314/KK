#ifndef ADDMESSAGELISTBUDDY_H
#define ADDMESSAGELISTBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFile>

class addmessagelistbuddy : public QWidget
{
    Q_OBJECT
public:
    explicit addmessagelistbuddy(QWidget *parent = nullptr);
    void InitObject();
    void setperson(int,QString,QString,int);
    void setempty();
    void setnametext(int,QString,QString,int);
    QVector<int> buildNextArray(const QString& s);
    int strStr(QString haystack, QString needle);

public slots:
    void showdetail();
    void add();
    void refuseadd();

signals:
    void Sadd(int);
    void sendchat(int);
    void Srefuse(int);


private:
    int account;
    QPushButton *head;
    QPushButton *name;
    QPushButton *addbtn;
    QPushButton *refusebtn;
    QString fname;
    QLabel *sign;
    QLabel *nametext;

signals:

};

#endif // ADDMESSAGELISTBUDDY_H
