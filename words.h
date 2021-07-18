#ifndef WORDS_H
#define WORDS_H

#include <QWidget>
#include <QLabel>

class words : public QWidget
{
    Q_OBJECT
public:
    explicit words(int l,QWidget *parent = nullptr);
    void InitObject();
    void setword(QString,int,int,int,bool);
    void setjustword(QString,int,int,int,bool);

private:
    QLabel *head;
    QLabel *word;
    int len;

signals:

};

#endif // WORDS_H
