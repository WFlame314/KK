#ifndef MYTOOLS_H
#define MYTOOLS_H

#include <QColor>
#include <QPixmap>
#include <QImage>
#include <QMap>

class Friends
{
public:
    int account;
    QString name;
    QString sign;
    QString lastword;
    int groupindex;
    int relationship;
    Friends() = default;
    Friends(int a,QString b,QString c,QString l,int d,int e):account(a),name(b),sign(c),lastword(l),groupindex(d),relationship(e){};
};

class MyTools
{
public:
    MyTools();

    static QColor MainColor(QPixmap p, double bright);
};

#endif // MYTOOLS_H
