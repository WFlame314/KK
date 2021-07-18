#include "personfindlist.h"
#include <QDebug>

personfindlist::personfindlist(QListWidget *parent) :
    QListWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
}

void personfindlist::addgroup(QString type)
{
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/bg/image/show.png"),type.toUtf8());    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),20));//设置宽度、高度
    newItem->setTextAlignment(Qt::AlignBottom);
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
}

void personfindlist::addbuddy(int acc,QString search, QString tname, QString tsign, bool onlion,int type)
{
    QList<QListWidgetItem*> temp = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    this->insertItem(row(currentItem)+temp.count(),newItem); //将该newItem插入到后面
    personfindlistbuddy *buddy=new personfindlistbuddy();//创建一个自己定义的信息类
    buddy->setperson(acc,search,tname,tsign,onlion,type);
    newItem->setSizeHint(QSize(this->width(), 100));
    this->setItemWidget(newItem, buddy); //将word赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为气泡，value为时间
    connect(buddy,SIGNAL(Sshowdetail(int)),this,SLOT(pressshow(int)));
    connect(buddy,SIGNAL(Sadd(int,QString,QString)),this,SLOT(pressadd(int,QString,QString)));
    connect(buddy,SIGNAL(sendchat(int)),this,SLOT(chat(int)));
}

void personfindlist::addempty()
{
    QList<QListWidgetItem*> temp = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    this->insertItem(row(currentItem)+temp.count(),newItem); //将该newItem插入到后面
    personfindlistbuddy *buddy=new personfindlistbuddy();//创建一个自己定义的信息类
    buddy->setempty();
    newItem->setSizeHint(QSize(this->width(), 100));
    this->setItemWidget(newItem, buddy); //将word赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为气泡，value为时间
}

void personfindlist::pressadd(int acc,QString name,QString sign)
{
    emit add(acc,name,sign);

}

void personfindlist::pressshow(int acc)
{
    emit showdetail(acc);
}

void personfindlist::chat(int acc)
{
    emit startchat(acc);
}
