#ifndef WORDSEDIT_H
#define WORDSEDIT_H

#include <QWidget>
#include <QLabel>

class wordsedit : public QWidget
{
    Q_OBJECT
public:
    explicit wordsedit(QWidget *parent = nullptr);
    void InitObject();
    void setword(QString,int,int,int);
    void setjustword(QString,int,int,int);

private:
    QLabel *head;
    QLabel *word;

signals:

};

#endif // WORDSEDIT_H
