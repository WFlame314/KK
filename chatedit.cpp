#include "chatedit.h"

chatedit::chatedit(QListWidget *parent) :
    QListWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
    Init();
}

void chatedit::Init()
{
    QListWidgetItem *newItem=new QListWidgetItem("");    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),0));//设置宽度、高度
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
    addedit("");
    addedit("");
    addedit("");
    addedit("");
    addedit("");
    addedit("");
    addedit("");
}

void chatedit::addedit(QString cword)
{
    //wordsedit *edit;
    QLineEdit *edit;
    edit = new QLineEdit(cword);
    edit->setStyleSheet("QLineEdit{"
                        "background-color: rgba(255,255,255,0);"
                        "font-size: 16px;"
                        "font-weight: 600;"
                        "border: none;"
                        "}");
    edit->setFixedSize(this->width(),20);
    QList<QListWidgetItem*> temp = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    this->insertItem(row(currentItem)+temp.count(),newItem); //将该newItem插入到后面
    newItem->setSizeHint(QSize(this->width(), 20));
    this->setItemWidget(newItem, edit); //将word赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为气泡，value为时间
}
