#ifndef ADDMESSAGELIST_H
#define ADDMESSAGELIST_H

#include <QListWidget>
#include "addmessagelistbuddy.h"

class addmessagelist : public QListWidget
{
    Q_OBJECT
public:
    explicit addmessagelist(QListWidget *parent = 0);

    QMap<QListWidgetItem*,QListWidgetItem*> groupMap;
    QListWidgetItem *currentItem;//当前的项
    QListWidgetItem *undealedItem;
    QListWidgetItem *dealedItem;
    void addgroup(QString);
    void addbuddy(int, QString, QString,int);
    void addempty(int);

public slots:
    void pressshow(int);
    void pressadd(int);
    void pressrefuse(int);
    void chat(int);
signals:
    void showdetail(int);
    void add(int);
    void refuseadd(int);
    void startchat(int);
};

#endif // ADDMESSAGELIST_H
