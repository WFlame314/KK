#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>
#include <QVector>


class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel();
    void setText(int,QString,QString,int);
    QVector<int> buildNextArray(const QString& s);
    int strStr(QString haystack, QString needle);
};

#endif // MYLABEL_H
