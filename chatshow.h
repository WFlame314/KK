#ifndef CHATSHOW_H
#define CHATSHOW_H

#include <QListWidget>
#include "words.h"

class chatshow : public QListWidget
{
    Q_OBJECT
public:
    explicit chatshow(QListWidget *parent = 0);

    QMap<QListWidgetItem*,QListWidgetItem*> groupMap;
    QListWidgetItem *currentItem;//当前的项
    void addtime(QString);
    void addchat(int,int,int,QString);
};

#endif // CHATSHOW_H
