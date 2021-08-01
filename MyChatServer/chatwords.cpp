#include "chatwords.h"

chatwords::chatwords(int a,int t,int d,QString w)
{
    account=a;
    time=t;
    data=d;
    words=w;
}

QString chatwords::send()
{
    return QString("3%1\a%2\a%3\a%4\a\t").arg(account).arg(words).arg(data).arg(time);
}
