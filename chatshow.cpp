#include "chatshow.h"
#include <QDebug>

chatshow::chatshow(QListWidget *parent) :
    QListWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
}

void chatshow::addtime(QString time)
{
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/bg/image/hide.png"),time.toUtf8());    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),25));//设置宽度、高度
    newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
}

void chatshow::addchat(int type,int faccount,int account,QString cword)
{
    bool first=true;
    int counti=0,len=0,max=0;
    QString tempw;
    QVector<QString> chatline;
    while(!cword.isEmpty())
    {
        if(cword[0]!='\n'&&counti<20)
        {
            if(cword[0]<127)
            {
                len+=1;
            }else
            {
                len+=2;
            }
            tempw+=cword[0];
            counti++;
            cword.remove(0,1);
            continue;
        }
        else
        {
            if(counti>=20)
            {
                if(cword[0]=='\n')
                {
                    cword.remove(0,1);
                }
            }
            else
            {
                cword.remove(0,1);
            }
            QString *te;
            te= new QString(tempw);
            chatline.push_back(*te);
            tempw.remove(0,tempw.length());
            if(len>max)
            {
                max=len;
            }
            len=0;
            counti=0;
        }
    }
    if(len>max)
    {
        max=len;
    }
    chatline.push_back(tempw);
    auto p=chatline.begin();
    for(;p!=chatline.end();p++)
    {
        qDebug()<<*p;
        if(p->isEmpty())
        {
            bool clear=true;
            for(auto tp=p;tp!=chatline.end();tp++)
            {
                if(!tp->isEmpty())
                {
                    clear=false;
                    p=tp;
                }
            }
            if(clear)
            {
                chatline.erase(p,chatline.end());
                p=chatline.begin();
            }
        }
    }
    QVector<QString>::iterator t;
    for(p=chatline.begin();p!=chatline.end();p++)
    {
        QList<QListWidgetItem*> temp = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
        //关键代码
        QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
        this->insertItem(row(currentItem)+temp.count(),newItem); //将该newItem插入到后面
        words *word=new words(max);//创建一个自己定义的信息类
        t=p;
        if(first)
        {
            t++;
            if(t==chatline.end())
            {
                word->setword(*p,account,faccount,type,true);
            }
            else
            {
                word->setword(*p,account,faccount,type,false);
            }
            newItem->setSizeHint(QSize(this->width(), 37));
            first=false;
        }
        else
        {
            t++;
            if(t==chatline.end())
            {
                word->setjustword(*p,account,faccount,type,true);
            }
            else
            {
                word->setjustword(*p,account,faccount,type,false);
            }
            newItem->setSizeHint(QSize(this->width(), 27));
        }
        this->setItemWidget(newItem, word); //将word赋给该newItem
        groupMap.insert(newItem,currentItem);   //加进容器，key为气泡，value为时间
    }
}
