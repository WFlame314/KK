#include "addmessagelist.h"
#include <QDebug>

addmessagelist::addmessagelist(QListWidget *parent) :
    QListWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
}

void addmessagelist::addgroup(QString type)
{
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/bg/image/show.png"),type.toUtf8());    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),20));//设置宽度、高度
    newItem->setTextAlignment(Qt::AlignBottom);
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
    if(type=="未处理申请")
    {
        undealedItem=newItem;
    }else
    {
        dealedItem=newItem;
    }
}

void addmessagelist::addbuddy(int acc, QString tname, QString tsign,int type)
{

    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    if(type==1||type==-1||type==3||type==2)
    {
        QList<QListWidgetItem*> temp = groupMap.keys(dealedItem);//当前组对应的项（包括组本身和好友）复制给tem
        this->insertItem(row(dealedItem)+temp.count(),newItem); //将该newItem插入到后面
        currentItem=dealedItem;
    }else
    {
        QList<QListWidgetItem*> temp = groupMap.keys(undealedItem);//当前组对应的项（包括组本身和好友）复制给tem
        this->insertItem(row(undealedItem)+temp.count(),newItem); //将该newItem插入到后面
        currentItem=undealedItem;
    }
    addmessagelistbuddy *buddy=new addmessagelistbuddy();//创建一个自己定义的信息类
    buddy->setperson(acc,tname,tsign,type);
    newItem->setSizeHint(QSize(this->width(), 100));
    this->setItemWidget(newItem, buddy); //将word赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为气泡，value为时间
    //connect(buddy,SIGNAL(Sshowdetail(int)),this,SLOT(pressshow(int)));
    connect(buddy,SIGNAL(Sadd(int)),this,SLOT(pressadd(int)));
    connect(buddy,SIGNAL(Srefuse(int)),this,SLOT(pressrefuse(int)));
}

void addmessagelist::addempty(int type)
{
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    if(type==1)
    {
        QList<QListWidgetItem*> temp = groupMap.keys(dealedItem);//当前组对应的项（包括组本身和好友）复制给tem
        this->insertItem(row(dealedItem)+temp.count(),newItem); //将该newItem插入到后面
        currentItem=dealedItem;
    }else
    {
        QList<QListWidgetItem*> temp = groupMap.keys(undealedItem);//当前组对应的项（包括组本身和好友）复制给tem
        this->insertItem(row(undealedItem)+temp.count(),newItem); //将该newItem插入到后面
        currentItem=undealedItem;
    }
    addmessagelistbuddy *buddy=new addmessagelistbuddy();//创建一个自己定义的信息类
    buddy->setempty();
    newItem->setSizeHint(QSize(this->width(), 100));
    this->setItemWidget(newItem, buddy); //将word赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为气泡，value为时间
}

void addmessagelist::pressadd(int acc)
{
    emit add(acc);
}

void addmessagelist::pressrefuse(int acc)
{
    emit refuseadd(acc);
}

void addmessagelist::pressshow(int acc)
{
    emit showdetail(acc);
}

void addmessagelist::chat(int acc)
{
    emit startchat(acc);
}
