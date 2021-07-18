#ifndef PERSONFINDLIST_H
#define PERSONFINDLIST_H

#include <QListWidget>
#include "personfindlistbuddy.h"

class personfindlist : public QListWidget
{
    Q_OBJECT
public:
    explicit personfindlist(QListWidget *parent = 0);

    QMap<QListWidgetItem*,QListWidgetItem*> groupMap;
    QListWidgetItem *currentItem;//当前的项
    void addgroup(QString);
    void addbuddy(int, QString, QString, QString, bool,int);
    void addempty();

public slots:
    void pressshow(int);
    void pressadd(int,QString,QString);
    void chat(int);
signals:
    void showdetail(int);
    void add(int,QString,QString);
    void startchat(int);
};

#endif // PERSONFINDLIST_H
