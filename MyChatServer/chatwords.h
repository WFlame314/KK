#ifndef CHATWORDS_H
#define CHATWORDS_H

#include <QString>

class chatwords
{
public:
    chatwords(int,int,int,QString);
    int account,time,data;
    QString words;
    QString send();
};

#endif // CHATWORDS_H
