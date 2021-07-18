#include "personfindlistbuddy.h"
#include <QDebug>

personfindlistbuddy::personfindlistbuddy(QWidget *parent) : QWidget(parent)
{
    InitObject();
}

void personfindlistbuddy::InitObject()
{
    nametext= new QLabel(this);
    head = new QPushButton(this);
    name = new QPushButton(this);
    addbtn = new QPushButton(this);
    sign = new QLabel(this);
    onlinetag = new QLabel(this);
    head->setFixedSize(70,70);
    name->setFixedSize(200,20);
    nametext->setFixedSize(200,20);
    sign->setFixedSize(200,20);
    addbtn->setFixedSize(45,20);
    head->move(15,15);
    name->move(100,15);
    nametext->move(100,15);
    sign->move(100,37);
    addbtn->move(100,64);
    addbtn->setText("+好友");
    head->setCursor(Qt::PointingHandCursor);
    name->setCursor(Qt::PointingHandCursor);
    addbtn->setCursor(Qt::PointingHandCursor);
    onlinetag->setFixedSize(16,16);
    onlinetag->move(67,67);
    connect(name,SIGNAL(clicked()),this,SLOT(showdetail()));
    connect(head,SIGNAL(clicked()),this,SLOT(showdetail()));
    connect(addbtn,SIGNAL(clicked()),this,SLOT(add()));
}

void personfindlistbuddy::setperson(int acc,QString search, QString tname, QString tsign, bool onlion,int type)
{
    account =acc;
    name->setText("");
    setnametext(acc,tname,search,type);
    sign->setText(tsign);
    //样式设置
    {
        QFile file(QString("./files/search/faces/%1.jpg").arg(acc));
        if(file.exists())
        {
            head->setStyleSheet(QString("QPushButton{"
                                        "border-image: url(./files/search/faces/%1.jpg);"
                                        "border-radius: 35px;"
                                        "border: none;"
                                        "}"
                                        "QPushButton:hover{"
                                        "border: 1px solid blue;"
                                        "}").arg(acc));
        }else
        {
            head->setStyleSheet("QPushButton{"
                                "border-image: url(./files/search/faces/face.png);"
                                "border-radius: 35px;"
                                "border: none;"
                                "}"
                                "QPushButton:hover{"
                                "border: 1px solid blue;"
                                "}");
        }

        sign->setStyleSheet("QLabel{"
                            "border-radius: 5px transparent;"
                            "background: rgba(0,0,0,0);"
                            "color: rgb(50,50,50);"
                            "}");
        addbtn->setStyleSheet("QPushButton{"
                              "font-size: 16px;"
                              "background: rgb(100,150,200);"
                              "border:none;"
                              "color: rgb(255,255,255);"
                              "border-radius: 3px;"
                              "}"
                              "QPushButton:hover{"
                              "background: rgb(80,150,220);"
                              "}"
                              "QPushButton:disabled{"
                              "background: rgb(200,50,50);"
                              "}");
        name->setStyleSheet("QPushButton{"
                            "font-size: 16px;"
                            "text-align: left;"
                            "background: rgba(175,175,175,0);"
                            "border:none;"
                            "color: rgb(0,150,100);"
                            "}");
    }

    if(type==1||type==2)
    {
        onlinetag->show();
        if(onlion)
        {

            onlinetag->setStyleSheet("QLabel{"
                                     "border-radius: 8px;"
                                     "border: none;"
                                     "background: rgb(0,240,120);"
                                     "}");

        }
        else
        {
            onlinetag->setStyleSheet("QLabel{"
                                     "border-radius: 8px;"
                                     "border: none;"
                                     "background: rgb(80,80,80);"
                                     "}");
        }
        addbtn->setFixedSize(45,20);
        addbtn->setText("+好友");
    }else if(type==3)
    {
        addbtn->setFixedSize(80,20);
        addbtn->setText("正在申请");
        addbtn->setDisabled("true");
        onlinetag->hide();
    }else if(type==4)
    {
        addbtn->setFixedSize(60,20);
        addbtn->setText("发消息");
        onlinetag->hide();
    }

}

void personfindlistbuddy::setempty()
{
    head->hide();
    name->hide();
    addbtn->hide();
    sign->move(50,35);
    sign->setFixedSize(200,30);
    sign->setText("没有找的符合条件的用户！");
    sign->setStyleSheet("QLabel{"
                        "border-radius: 5px transparent;"
                        "font-size: 16px;"
                        "background: rgba(0,0,0,0);"
                        "color: rgb(50,50,50);"
                        "}");
}

void personfindlistbuddy::setnametext(int acc,QString name, QString key,int type)
{
    fname=name;
    QString words="<p style=\"color: rgb(0,0,0);font-size: 16px;\">";
    if(type==1||type==3||type==4)
    {
        QString taccount=QString("%1").arg(acc);
        int starti,endi;
        starti=strStr(taccount,key);
        endi=starti+key.length()-1;
        for(int i=0;i<taccount.length();i++)
        {
            if(i<starti)
            {
                words+=taccount[i];
            }
            else if(i==starti)
            {
                words+="<span style=\"color: rgb(0,150,240);font-size: 16px;\">";
                words+=taccount[i];
            }
            else if(i==endi)
            {
                words+=taccount[i];
                words+="</span>";
            }
            else
            {
                words+=taccount[i];
            }
        }
        words=words+"("+name+")";
        words+="</p>";
    }else
    {
        int starti,endi;
        starti=strStr(name,key);
        endi=starti+key.length();
        for(int i=0;i<name.length();i++)
        {
            if(i<starti)
            {
                words+=name[i];
            }
            else if(i==starti)
            {
                words+="<span style=\"color: rgb(0,150,240);font-size: 16px;\">";
                words+=name[i];
            }
            else if(i==endi)
            {
                words+="</span>";
                words+=name[i];
            }
            else
            {
                words+=name[i];
            }
        }
        words+=QString("(%1)").arg(acc);
        words+="</p>";
    }
    nametext->setText(words);
}

void personfindlistbuddy::showdetail()
{
    emit Sshowdetail(account);
}

void personfindlistbuddy::add()
{
    if(addbtn->text()=="+好友")
    {
        emit Sadd(account,fname,sign->text());
        return;
    }else if(addbtn->text()=="发消息")
    {
        emit sendchat(account);
        return;
    }

}

QVector<int> personfindlistbuddy::buildNextArray(const QString &s)
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

int personfindlistbuddy::strStr(QString haystack, QString needle)
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

