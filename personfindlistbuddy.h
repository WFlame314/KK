#ifndef PERSONFINDLISTBUDDY_H
#define PERSONFINDLISTBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFile>

class personfindlistbuddy : public QWidget
{
    Q_OBJECT
public:
    explicit personfindlistbuddy(QWidget *parent = nullptr);
    void InitObject();
    void setperson(int,QString,QString,QString,bool,int);
    void setempty();
    void setnametext(int,QString,QString,int);
    QVector<int> buildNextArray(const QString& s);
    int strStr(QString haystack, QString needle);

public slots:
    void showdetail();
    void add();

signals:
    void Sshowdetail(int);
    void Sadd(int,QString,QString);
    void sendchat(int);


private:
    int account;
    QPushButton *head;
    QPushButton *name;
    QPushButton *addbtn;
    QString fname;
    QLabel *sign;
    QLabel *nametext;
    QLabel *onlinetag;

signals:

};

#endif // PERSONFINDLISTBUDDY_H
