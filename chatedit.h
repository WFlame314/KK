 #ifndef CHATEDIT_H
#define CHATEDIT_H

#include <QListWidget>
#include <QLineEdit>
#include "wordsedit.h"

class chatedit : public QListWidget
{
    Q_OBJECT
public:
    explicit chatedit(QListWidget *parent = 0);
    void Init();
    QMap<QListWidgetItem*,QListWidgetItem*> groupMap;
    QListWidgetItem *currentItem;//当前的项
    void addedit(QString);
};

#endif // CHATSEDIT_H
