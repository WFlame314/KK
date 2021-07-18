#include "mylabel.h"

MyLabel::MyLabel()
{

}

void MyLabel::setText(int acc,QString name, QString key,int type)
{
    QString words="<p>";
    if(type==1)
    {

    }else
    {
        int starti,endi;
        starti=strStr(name,key);
        endi=starti+key.length()-1;
        for(int i=0;i<name.length();i++)
        {
            if(i<starti)
            {
                words+=name[i];
            }
            else if(i==starti)
            {
                words+="<span style=\"color: rgb(0,150,240)\">";
                words+=name[i];
            }
            else if(i==endi)
            {
                words+=name[i];
                words+="</span>";
            }
            else
            {
                words+=name[i];
            }
        }
        words+="</p>";
    }
}

QVector<int> MyLabel::buildNextArray(const QString &s)
{
    QVector<int> next(s.size());
    int i = 2, j = 0;
    next[0] = -1;
    if(s.size() > 1)
        next[1] = 0;
    while(i < s.size())
    {
        if(s[i-1] == s[j])
            next[i++] = ++j;
        else if(j > 0)
            j = next[j];
        else
            next[i++] = 0;
    }
    return next;
}

int MyLabel::strStr(QString haystack, QString needle)
{
    int start = 0, i = 0, hSize = haystack.size(), nSize = needle.size();
    if(hSize < nSize)
        return -1;
    if(nSize == 0)
        return 0;
    //kmp算法
    QVector<int> next = buildNextArray(needle);
    while(start <= hSize - nSize)
    {
        if(haystack[start + i] == needle[i])
        {
            if(++i == nSize)
                return start;
        }
        else
        {
            start = start + i - next[i];
            i = i > 0 ? next[i] : 0;
        }
    }
    return -1;
}
